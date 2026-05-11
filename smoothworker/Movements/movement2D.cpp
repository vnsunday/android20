#include <stdio.h>
#include <stdlib.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

#define PI 3.14159265358979323846

int model() {
    int omega;
    double T = 10;
    double dV = 2 * PI * R / T;
    return 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    /*================================================== 
        Configuration
     *==================================================*/
    double dR_M2P = 100.0; // Ratio: Meter 2 Pixel
    double dXc = 1.5; // In Meter 
    double dYc = 1.5;
    double dAlpha = 3.14 / 18.0; // 10 degree

    double dMarginX = 0.2; // Meter 
    double dMarginY = 0.2; // Meter 
    double dRadius = 1; // In Meters (one meter)

    // Styles 
    int stlw = 3; // Line width
    int stlw_h = stlw / 2; // Half of line width



    // Meter 2 Pixel 
    int nW = 0; // Board width
    int nH = 0; // Board Height 

    int npR =  dR_M2P * dRadius; // Radius in pixel
    int npCx = dR_M2P * dXc; // Center X
    int npCy = dR_M2P * dYc; // Center Y
    int npMrgx = dR_M2P * dMarginX; // Margin
    int npMrgy = dR_M2P * dMarginY; 

    nW = npCx + npR + 2 * npMrgx;
    nH = npCy + npR + 2 * npMrgy;

    /*====================*/
    cv::Point pcenter(npCx, npCy);
    cv::Scalar clpen = cv::Scalar(0,0,0);

    Mat img(nH, nW, CV_8UC3, cv::Scalar(255, 255, 255)); // 

    // Central
    cv::rectangle(
        img,
        cv::Point(npCx , npCy),
        cv::Point(npCx, npCy),
        clpen, 
        stlw,
        LINE_8
    );

    // Circle
    cv::circle(img, 
        pcenter, 
        npR, // Radius 
        clpen, 
        stlw, 
        LINE_8
    );

    // 
    cv::line(img, 
                cv::Point(npCx, npCy), 
                cv::Point(npCx, npCy - npR),
                clpen,
                stlw);

    cv::line(img, 
                cv::Point(npCx, npCy), 
                cv::Point(npCx + std::sin(dAlpha) * npR, npCy - std::cos(dAlpha) * npR),
                clpen,
                stlw);

    imwrite("aaa.png", img);
    return 0;
}