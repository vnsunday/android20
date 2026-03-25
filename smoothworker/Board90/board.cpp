#include <stdio.h>
#include <stdlib.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

// Center position: Left prefer
int center_position_lp(int n) {
    if (n % 2 == 0) {
        return n/2;
    } 
    else {
        return (n+1)/2;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    double dR = 297.0 / 210.0;
    int nW = 1600;
    int nH = nW * dR;

    int nMT = 50; // Margin-Top
    int nML = 50; // Margin-Left 
    int nLW = 20; // Line Width
    int nLCV = 9; // Vertically Line Count
    int nLCH = 10; // Horizontally Line Count 

    /*==================================================
        Calibration X coordinates.

        MUST HAVE: 
            Central-Line Must in the middle of Board.

        Output:
            CMR-CML.
                CMR: Calibrated Margin Right
                CML: Calibrated Margin Left 
     *==================================================*/
    int nW_0m = nW - nML * 2; // With without Magin (0-margin)
    int nCGz = nW_0m / (nLCV - 1);  // Cell Gross side
    int nCMR = nML;
    int nCML = nML;

    int nMid = center_position_lp(nW);
    int nLC_xs = (nLW % 2 == 0) ? nMid - (nLW /2) + 1 : nMid - (nLW - 1) / 2; // Line-Center startX
    int nLC_xe = nLC_xs + nLW - 1;

    int nBr_xs = nLC_xs - 4 * nCGz;  // Board X start (Left-most)
    int nBr_xe = nLC_xe + 4 * nCGz;  // Board X End (Right most)

    nCML = nBr_xs - 1;
    nCMR = nW - nBr_xe;

    /*==================================================
        Calibrate Y coordinate

        MUST-HAVE: 
            Middle Line- In the middle 
        Output:
            CMT - CMB 
                CMT: Calibrated Margin Top 
                CMB: Calibrated Margin Bottom
     *==================================================*/
    nMid = center_position_lp(nH);
    int nLPC_Mid = nMid - (nCGz/2); // Pre-Center Line Middle 
    int nLPC_ys = (nLW % 2 == 0) ? nLPC_Mid - (nLW /2) + 1 : nLPC_Mid - (nLW -1)/2; // Pre-Center Line Y start
    int nLPC_ye = nLPC_ys + nLW - 1; // Pre-center Line y end

    int nBr_ys = nLPC_ys - 4 * nCGz; // Board Y start (Top-most)
    int nBr_ye = nLPC_ye + 5 * nCGz; // Board Y end (bottom most)

    int nCMT = nBr_ys - 1;
    int nCMB = nH - nBr_ye ;

    printf("Calibrated: CMR=%d; CML=%d; Diff=%d\r\n", nCMR, nCML, (nCMR - nCML));
    printf("Calibrated: CMT=%d; CMB=%d; Diff=%d\r\n", nCMT, nCMB, (nCMT - nCMB));
    printf("Cell-Gross-size=%d\r\n", nCGz);
    printf("W=%d;H=%d\r\n", nW, nH);

    // Painting
    char azTitle[] = "Board";
    Mat img(nH, nW, CV_8UC4, cv::Scalar(255,255,255, 0)); // With transparency

    // Columns (Vertically)
    double xS = nCML;
    double xE;
    double yS = nCMT;
    double yE = nH - nCMB;

    for (int i=0; i<9; ++i) {
        rectangle(img, 
            Point(xS + i*nCGz, yS),
            Point(xS + (i)*nCGz + nLW - 1, yE),
            Scalar(255,0,0, 255), // Yellow
            FILLED,
            LINE_8);
    }

    // Rows (Horizontally)
    xS = nCML;
    xE = nW - nCMR;
    yS = nCMT;
    for (int i=0; i<10; ++i) {
        rectangle(img,
            Point(xS, yS + i* nCGz),
            Point(xE, yS + (i)*nCGz + nLW - 1),
            Scalar(0,255,0, 255),
            FILLED,
            LINE_8);
    }

    // River (Inside)
    double yRv_S = nCMT + 4 * nCGz + nLW;
    double yRv_E = nCMT + 5 * nCGz - 1;
    double xRv_S = nCML + nLW;
    double xRv_E = nW - nCMR - nLW;
    rectangle(img, Point(xRv_S, yRv_S), Point(xRv_E, yRv_E), Scalar(100,20,0,255), FILLED, LINE_8);

    // imshow(azTitle, img);
    // Rows 
    // waitKey(0);
    imwrite("aaa.png", img);
    return 0;
}