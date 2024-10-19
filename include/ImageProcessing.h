//
// Created by 13120 on 2024/5/8.
//

#ifndef MOVING_BALL_IMAGEPROCESSING_H
#define MOVING_BALL_IMAGEPROCESSING_H

#include"ImageInformation.h"

class ImageProcessing {
public:
    ImageProcessing();
    static void HU(cv::Mat img, cv::Mat &hus);
    static bool FindhandContour(cv::Mat &frame,cv::Mat &handContour);
    char MatchGesture(cv::Mat &img);
    static double calculateDistance(const cv::Mat& vec1, const cv::Mat& vec2);
private:
    //数据
    ImageInformation image;
    std::vector<cv::Mat> hu0;
    std::vector<cv::Mat> hu1;
    std::vector<cv::Mat> hu5;
    std::vector<cv::Mat> hu8;
    std::vector<cv::Mat> hug;
    std::vector<cv::Mat> huk;

    //函数
    void InitHuinf();


};


#endif //MOVING_BALL_IMAGEPROCESSING_H
