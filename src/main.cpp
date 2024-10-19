
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2\imgproc\types_c.h>
#include<iostream>
#include<ctime>
#include "../include/ImageInformation.h"
#include "../include/ImageProcessing.h"
#include "../include/BallMove.h"
using namespace cv;
using namespace std;

int main() {
    ImageInformation image;
    ImageProcessing imageProcessing;

    clock_t NowTime=clock();
    int move1 = -1;  //前两帧动作
    int move2 = -1;  //前一帧动作
    int oriPosx = 500;  //球初始位置
    int oriPosy = 400;
    int lastPosx;    //球前一帧位置
    int lastPosy;

    VideoCapture cap(0);
    if(!cap.isOpened())
    {
        return -1;
    }

    Mat frame;  //摄像头数据
    lastPosx = oriPosx;
    lastPosy = oriPosy;
    bool stop = false; //控制摄像头读取
    bool mode = true;
    char gesture;  //手势
    while(!stop)
    {
        cap>>frame;
        if(!frame.empty())
        {
            cv::flip(frame, frame, 1);
            gesture=imageProcessing.MatchGesture(frame);
            if (lastPosx<30)
                lastPosx = 30;
            if (lastPosx>994)
                lastPosx = 994;
            if (lastPosy<30)
                lastPosy = 30;
            if (lastPosy>930)
                lastPosy= 930;
            waitTime(move1, move2,lastPosx, lastPosy, mode);
            cout << "gesture: " << gesture << endl;
            if(gesture == '0')
            {
                cout<<"0"<<endl;
                putText(frame,"0:nothing happen", Point(0,100),FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255) );
                move1 = move2;
                move2 = 0;
            }
            else if(gesture == '1')
            {
                cout<<"1"<<endl;
                if(mode)
                {
                    putText(frame,"1:move left", Point(0,100),FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255) );
                }
                else
                {
                    putText(frame,"1:move leftup", Point(0,100),FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255) );
                }
                move1 = move2;
                move2 = 1;
            }
            else if(gesture == '5')
            {
                cout<<"5"<<endl;
                if(mode)
                {
                    putText(frame,"5:move right", Point(0,100),FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255) );
                }
                else
                {
                    putText(frame,"5:move rightup", Point(0,100),FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255) );
                }
                move1 = move2;
                move2 = 2;
            }
            else if(gesture == '8')
            {
                cout<<"8"<<endl;
                if(mode)
                {
                    putText(frame,"8:move up", Point(0,100),FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255) );
                }
                else
                {
                    putText(frame,"8:move left down", Point(0,100),FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255) );
                }
                move1 = move2;
                move2 = 3;
            }
            else if(gesture == 'g')
            {
                cout<<"g"<<endl;
                if(mode)
                {
                    putText(frame,"thumb:move down", Point(0,100),FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255) );
                }
                else
                {
                    putText(frame,"thumb:move rightdown", Point(0,100),FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255) );
                }
                move1 = move2;
                move2 = 4;
            }
            else if(gesture == 'k')
            {
                if(clock()-NowTime>5000)
                {
                    NowTime=clock();
                    cout<<"k"<<endl;
                    putText(frame,"OK:transform(vaild)", Point(0,100),FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255) );

                    if(mode==true)
                        mode = false;
                    else
                        mode = true;
                }
                else
                {
                    putText(frame,"OK:transform(unvaild)", Point(0,100),FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255) );
                }
            }


            if (!frame.empty())
                imshow("Frame", frame);
        }

        if(waitKey(30) >=0)
            stop = true;

    }  //while(!stop)

    return 0;


}




