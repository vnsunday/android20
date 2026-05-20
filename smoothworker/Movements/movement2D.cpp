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
    // double dV = (2 * PI * R) / T;
    return 0;
}

double vector_length(double dx, double dy) {
    return sqrt(dx*dx + dy*dy);
}

cv::Vec2f rotate_vector_cw(cv::Vec2f v, double rad) {
    double dL = vector_length(v[0], v[1]);
    double dRad = v[0] == 0 ? PI/2 : std::atan(v[1]/v[0]);
    return cv::Vec2f( std::cos(dRad + rad) *  dL, std::sin(dRad + rad) * dL);
}

int draw_a_vector(Mat& img,cv::Point2f p1, cv::Point2f p2, int lw, Scalar color) {
    cv::line(img, p1, p2, color, lw);

    // Draw Arrow.
    double dVlen = sqrt( (p1.x - p2.x)*(p1.x - p2.x) + 
                            (p1.y - p2.y) * (p1.y - p2.y) );
    double darrow_ear = std::max(15.0, dVlen/10); // Pixel
    double reverse_vx = p1.x - p2.x;
    double reverse_vy = p1.y - p2.y;



    reverse_vx = reverse_vx * darrow_ear / dVlen;
    reverse_vy = reverse_vy * darrow_ear / dVlen;

    cv::Vec2f vreverse(reverse_vx, reverse_vy);

    cv::Vec2f vear1 = rotate_vector_cw(vreverse, PI/10.0);
    cv::Vec2f vear2 = rotate_vector_cw(vreverse, -PI/10.0);

    cv::line(img, p2, p2 + cv::Point2f(vear1), color, lw);
    cv::line(img, p2, p2 + cv::Point2f(vear2), color, lw);

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

    double dTL = dRadius / 2; // Length of Tangent
    int stlw = 2; // Line width
    int stlw_h = stlw / 2; // Half of line width
    // ---------- END-OF-Configuration ----------

    // [ Meter-2-Pixel ]
    int nW = 0; // Board width
    int nH = 0; // Board Height 

    int npR =  dR_M2P * dRadius; // Radius in pixel
    int npCx = dR_M2P * dXc; // Center X
    int npCy = dR_M2P * dYc; // Center Y
    int npMrgx = dR_M2P * dMarginX; // Margin
    int npMrgy = dR_M2P * dMarginY; 
    int nLvTg = dR_M2P * dTL; // Tangent vector length in pixel
    // END [Meter-2-Pixel]
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

    // Tangent
    // Building tangent vector 
    cv::Vec2f vT(nLvTg, 0);      // Tangent vector 
    cv::Vec2f vC2C(0, -npR);     // Movement vector: Center to Circle
    cv::Point2f p2Center(npCx, npCy);

    cv::Point2f pT1S = p2Center + cv::Point2f(vC2C);
    cv::Point2f pT1E = p2Center + cv::Point2f(vT) + cv::Point2f(vC2C);


    cv::Vec2f vT2 = rotate_vector_cw(vT, dAlpha);      // Tangent vector 
    cv::Vec2f vC2C2 = rotate_vector_cw(vC2C, dAlpha);  // Movement vector: Center to Circle
    cv::Point2f pT2S = p2Center + cv::Point2f(vC2C2);
    cv::Point2f pT2E = p2Center + cv::Point2f(vT2) + cv::Point2f(vC2C2);

    draw_a_vector(img, pT1S, pT1E, stlw, clpen); // Tangent 1
    // draw_a_vector(img, pT2S, pT2E, stlw, clpen); // Tangent 2

    imwrite("aaa.png", img);
    return 0;
}