//
// Created by 13120 on 2024/5/8.
//

#ifndef MOVING_BALL_BALLMOVE_H
#define MOVING_BALL_BALLMOVE_H
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2\imgproc\types_c.h>


extern int ballRadius;
extern cv::Mat ball;
extern cv::Point ballCenter;

void Show(int lastPosx, int lastPosy);
void ShowLeft(int lastPosx, int lastPosy);
void ShowRight(int lastPosx, int lastPosy);
void ShowUp(int lastPosx, int lastPosy);
void ShowDown(int lastPosx, int lastPosy);
void ShowLeftUp(int lastPosx, int lastPosy);
void ShowRightUp(int lastPosx, int lastPosy);
void ShowLeftDown(int lastPosx, int lastPosy);
void ShowRightDown(int lastPosx, int lastPosy);
void waitTime(int &move1, int &move2, int &lastPosx, int &lastPosy,bool mode);



#endif //MOVING_BALL_BALLMOVE_H
