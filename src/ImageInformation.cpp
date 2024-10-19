//
// Created by 13120 on 2024/5/8.
//

#include "../include/ImageInformation.h"

ImageInformation::ImageInformation() {
    InitImgInf();
}

void ImageInformation::InitImgInf() {
    if(images0.empty()&&images1.empty()&&images5.empty()&&images8.empty()&&imagesg.empty()&&imagesk.empty())
    {
        for (int i = 0; i <= 9; ++i) {
            std::string filename = "../Hands/0" + std::to_string(i) + ".jpg";
            cv::Mat image = cv::imread(filename);
            if (!image.empty()) {
                images0.push_back(image);
            } else {
                std::cerr << "Failed to load image: " << filename << std::endl;
            }

            filename = "../Hands//1" + std::to_string(i) + ".jpg";
            image = cv::imread(filename);
            if (!image.empty()) {
                images1.push_back(image);
            } else {
                std::cerr << "Failed to load image: " << filename << std::endl;
            }

            filename = "../Hands//5" + std::to_string(i) + ".jpg";
            image = cv::imread(filename);
            if (!image.empty()) {
                images5.push_back(image);
            } else {
                std::cerr << "Failed to load image: " << filename << std::endl;
            }

            filename = "../Hands//8" + std::to_string(i) + ".jpg";
            image = cv::imread(filename);
            if (!image.empty()) {
                images8.push_back(image);
            } else {
                std::cerr << "Failed to load image: " << filename << std::endl;
            }

            filename = "../Hands//g" + std::to_string(i) + ".jpg";
            image = cv::imread(filename);
            if (!image.empty()) {
                imagesg.push_back(image);
            } else {
                std::cerr << "Failed to load image: " << filename << std::endl;
            }

            filename = "../Hands//k" + std::to_string(i) + ".jpg";
            image = cv::imread(filename);
            if (!image.empty()) {
                imagesk.push_back(image);
            } else {
                std::cerr << "Failed to load image: " << filename << std::endl;
            }
        }
    }
}

cv::Mat ImageInformation::GetOneImgInf(char x, int y) {
    if(x=='0')
    {
        return images0[y];
    }
    else if(x=='1')
    {
        return images1[y];
    }
    else if(x=='5')
    {
        return images5[y];
    }
    else if(x=='8')
    {
        return images8[y];
    }
    else if(x=='g')
    {
        return imagesg[y];
    }
    else if(x=='k')
    {
        return imagesk[y];
    }
    else
    {
        std::cerr<<"Error: No such image!"<<std::endl;
    }
}
