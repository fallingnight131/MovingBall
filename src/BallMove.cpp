//
// Created by 13120 on 2024/5/8.
//

#include "../include/BallMove.h"

cv::Mat ball;
int ballRadius = 30;
cv::Point ballCenter;


void Show(int lastPosx, int lastPosy) {
    ball = cv::imread("../black.jpg");
    ballCenter = cv::Point(lastPosx, lastPosy);
    circle(ball, ballCenter, ballRadius, cv::Scalar(255, 0, 0), -1, 8, 0);
    if (!ball.empty()) {
        imshow("Ball", ball);
    }

}


void ShowLeft(int lastPosx, int lastPosy) {
    ball = cv::imread("../black.jpg");
    ballCenter = cv::Point(lastPosx - 10, lastPosy);
    circle(ball, ballCenter, ballRadius, cv::Scalar(255, 0, 0), -1, 8, 0);

    if (!ball.empty()) {
        imshow("Ball", ball);
    }

}


void ShowRight(int lastPosx, int lastPosy) {
    ball = cv::imread("../black.jpg");
    ballCenter = cv::Point(lastPosx + 10, lastPosy);
    circle(ball, ballCenter, ballRadius, cv::Scalar(255, 0, 0), -1, 8, 0);

    if (!ball.empty()) {
        imshow("Ball", ball);
    }

}


void ShowUp(int lastPosx, int lastPosy) {

    ball = cv::imread("../black.jpg");
    ballCenter = cv::Point(lastPosx, lastPosy - 10);
    circle(ball, ballCenter, ballRadius, cv::Scalar(255, 0, 0), -1, 8, 0);

    if (!ball.empty()) {
        imshow("Ball", ball);
    }

}

//?????????
void ShowDown(int lastPosx, int lastPosy) {

    ball = cv::imread("../black.jpg");
    ballCenter = cv::Point(lastPosx, lastPosy + 10);
    circle(ball, ballCenter, ballRadius, cv::Scalar(255, 0, 0), -1, 8, 0);

    if (!ball.empty()) {
        imshow("Ball", ball);
    }

}

void ShowLeftUp(int lastPosx, int lastPosy) {
    ball = cv::imread("../black.jpg");
    ballCenter = cv::Point(lastPosx - 10, lastPosy - 10);
    circle(ball, ballCenter, ballRadius, cv::Scalar(255, 0, 0), -1, 8, 0);

    if (!ball.empty()) {
        imshow("Ball", ball);
    }

}

void ShowRightUp(int lastPosx, int lastPosy) {
    ball = cv::imread("../black.jpg");
    ballCenter = cv::Point(lastPosx + 10, lastPosy - 10);
    circle(ball, ballCenter, ballRadius, cv::Scalar(255, 0, 0), -1, 8, 0);

    if (!ball.empty()) {
        imshow("Ball", ball);
    }

}

void ShowLeftDown(int lastPosx, int lastPosy) {
    ball = cv::imread("../black.jpg");
    ballCenter = cv::Point(lastPosx - 10, lastPosy + 10);
    circle(ball, ballCenter, ballRadius, cv::Scalar(255, 0, 0), -1, 8, 0);

    if (!ball.empty()) {
        imshow("Ball", ball);
    }

}

void ShowRightDown(int lastPosx, int lastPosy) {
    ball = cv::imread("../black.jpg");
    ballCenter = cv::Point(lastPosx + 10, lastPosy + 10);
    circle(ball, ballCenter, ballRadius, cv::Scalar(255, 0, 0), -1, 8, 0);

    if (!ball.empty()) {
        imshow("Ball", ball);
    }

}


void waitTime(int &move1, int &move2, int &lastPosx, int &lastPosy,bool mode) {

    if (move1 == -1 && move2 == -1) {

    }
    if (move1 == 0 && move2 == 0) {
        Show(lastPosx, lastPosy);
        move1 = -1;
        move2 = -1;
    } // 0
    if(mode)
    {

        if (move1 == 1 && move2 == 1) {
            ShowLeft(lastPosx, lastPosy);
            lastPosx = lastPosx - 30;
            move1 = -1;
            move2 = -1;
        } // 1

        if (move1 == 2 && move2 == 2) {
            ShowRight(lastPosx, lastPosy);
            lastPosx = lastPosx + 30;
            move1 = -1;
            move2 = -1;

        } // 2

        if (move1 == 3 && move2 == 3) {
            ShowUp(lastPosx, lastPosy);
            lastPosy = lastPosy - 30;
            move1 = -1;
            move2 = -1;

        } // 3

        if (move1 == 4 && move2 == 4) {
            ShowDown(lastPosx, lastPosy);
            lastPosy = lastPosy + 30;
            move1 = -1;
            move2 = -1;
        } // 6
    }
    else
    {
        if (move1 == 1 && move2 == 1) {
            ShowLeftUp(lastPosx, lastPosy);
            lastPosx = lastPosx - 30;
            lastPosy = lastPosy - 30;
            move1 = -1;
            move2 = -1;
        } // 1

        if (move1 == 2 && move2 == 2) {
            ShowRightUp(lastPosx, lastPosy);
            lastPosx = lastPosx + 30;
            lastPosy = lastPosy - 30;
            move1 = -1;
            move2 = -1;

        } // 5

        if (move1 == 3 && move2 == 3) {
            ShowLeftDown(lastPosx, lastPosy);
            lastPosx = lastPosx - 30;
            lastPosy = lastPosy + 30;
            move1 = -1;
            move2 = -1;

        } // 8

        if (move1 == 4 && move2 == 4) {
            ShowRightDown(lastPosx, lastPosy);
            lastPosx = lastPosx + 30;
            lastPosy = lastPosy + 30;
            move1 = -1;
            move2 = -1;
        } // g

    }

}