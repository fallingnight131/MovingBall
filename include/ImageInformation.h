//
// Created by 13120 on 2024/5/8.
//

#ifndef MOVING_BALL_IMAGEINFORMATION_H
#define MOVING_BALL_IMAGEINFORMATION_H

#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2\imgproc\types_c.h>

class ImageInformation {
public:
    ImageInformation();
    cv::Mat GetOneImgInf(char x,int y);

private:
    //数据
    std::vector<cv::Mat> images0;
    std::vector<cv::Mat> images1;
    std::vector<cv::Mat> images5;
    std::vector<cv::Mat> images8;
    std::vector<cv::Mat> imagesg;
    std::vector<cv::Mat> imagesk;

    //函数
    void InitImgInf();
};


#endif //MOVING_BALL_IMAGEINFORMATION_H
