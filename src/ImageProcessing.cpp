//
// Created by 13120 on 2024/5/8.
//

#include "../include/ImageProcessing.h"
#include <vector>
ImageProcessing::ImageProcessing() {
    InitHuinf();
}

void ImageProcessing::InitHuinf() {
    cv::Mat tem;
    for(int i = 0; i < 10; ++i) {
        HU(image.GetOneImgInf('0',i), tem);
        hu0.push_back(tem.clone());
        HU(image.GetOneImgInf('1',i), tem);
        hu1.push_back(tem.clone());
        HU(image.GetOneImgInf('5',i), tem);
        hu5.push_back(tem.clone());
        HU(image.GetOneImgInf('8',i), tem);
        hu8.push_back(tem.clone());
        HU(image.GetOneImgInf('g',i), tem);
        hug.push_back(tem.clone());
        HU(image.GetOneImgInf('k',i), tem);
        huk.push_back(tem.clone());
    }
}

void ImageProcessing::HU(cv::Mat img, cv::Mat &hus) {
    cv::Mat handContour; //手的轮廓
    FindhandContour(img,handContour);
    cv::Moments mymoments;
    mymoments = moments(handContour, 1);
    HuMoments(mymoments, hus);

}

bool ImageProcessing::FindhandContour(cv::Mat &frame, cv::Mat &handContour) {
    //HSV
    if (frame.empty()) {
        return false;
    }
    cv::Mat hsv;
    cv::Mat imb;
    cv::Mat imb2;
    cv::Mat imy;
    cv::Mat img = frame.clone();

    cvtColor(img, hsv, CV_BGR2HSV);
    std::vector<cv::Mat> a;
    cv::Mat tem;
    split(hsv, a);
    cv::Mat h = a[0].clone();
    cv::Mat s = a[1].clone();
    cv::Mat v = a[2].clone();
    inRange(h, 0, 34, a[0]);//红色、橙色、黄色
    inRange(s, 43, 200, a[1]);
    inRange(v, 46, 255, a[2]);
    inRange(h, 156, 180, tem);//红色比较偏僻的一部分

    bitwise_or(a[0], tem, a[0]);
    bitwise_and(a[0], a[1], imb);
    bitwise_and(a[2], imb, imb);
    //??????????????????????????????????????????????????????????????

    erode(imb, imb, cv::Mat(5, 5, CV_8UC1), cv::Point(-1, -1));
    dilate(imb, imb, cv::Mat(6, 6, CV_8UC1), cv::Point(-1, -1));
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;


    findContours(imb, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

    int index = 0;
    double area, maxArea(0);
    for (int i = 0; i < contours.size(); i++) {
        area = contourArea(cv::Mat(contours[i]));
        if (area > maxArea) {
            maxArea = area;
            index = i;
        }
    }

    handContour = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);
    drawContours(handContour, contours, index, cv::Scalar(255, 255, 255), -1, 8, hierarchy);

    return true;


}

char ImageProcessing::MatchGesture(cv::Mat &img) {
    cv::Mat hus;
    char gesture;
    HU(img, hus);
    double MinDist = 100000;

    for(int i = 0; i < 10; ++i) {

        double dist = calculateDistance(hus, hu1[i]);
        if(dist < MinDist) {
            MinDist = dist;
            gesture = '1';
        }
    }
    for(int i = 0; i < 10; ++i) {
        double dist = calculateDistance(hus, hu5[i]);
        if(dist < MinDist) {
            MinDist = dist;
            gesture = '5';
        }
    }
    for(int i = 0; i < 10; ++i) {
        double dist = calculateDistance(hus, hu8[i]);
        if(dist < MinDist) {
            MinDist = dist;
            gesture = '8';
        }
    }
    for(int i = 0; i < 10; ++i) {
        double dist = calculateDistance(hus, hug[i]);
        if(dist < MinDist) {
            MinDist = dist;
            gesture = 'g';
        }
    }
    for(int i = 0; i < 10; ++i) {
        double dist = calculateDistance(hus, huk[i]);
        if(dist < MinDist) {
            MinDist = dist;
            gesture = 'k';
        }
    }
    for(int i = 0; i < 10; ++i) {
        double dist = calculateDistance(hus, hu0[i]);
        if(dist < MinDist) {
            MinDist = dist;
            gesture = '0';

        }
    }
    return gesture;
}

double ImageProcessing::calculateDistance(const cv::Mat &vec1, const cv::Mat &vec2) {
    double dist = 0.0;
    for (int i = 0; i < vec1.rows; ++i) {
        double diff = vec1.at<double>(i, 0) - vec2.at<double>(i, 0);
        dist += diff * diff;
    }
    return sqrt(dist);
}
