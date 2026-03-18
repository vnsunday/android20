#include <stdio.h>
#include <stdlib.h>

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
    double dR = 290.0 / 210.0;
    int nW = 1600;
    int nH = nW * dR;

    int nMT = 50; // Margin-Top
    int nML = 50; // Margin-Left 
    int nLW = 5; // Line Width
    int nLCV = 9; // Vertically Line Count
    int nLCH = 10; // Horizontally Line Count 

    /*==================================================
        Calibration Veritcally.

        MUST HAVE: 
            Central-Line Must in the middle of Board.

        Output:
            CMR-CML.
                CMR: Calibrated Margin Right
                CML: Calibrated Margin Left 
     *==================================================*/
    int nW_0m = nW - nML * 2; // With without Magin (0-margin)
    int nSp_bl = nW_0m / (nLCV - 1);
    int nCMR = nML;
    int nCML = nML;

    int nMid = center_position_lp(nW);
    int nLC_xs = (nLW % 2 == 0) ? nMid - (nLW /2) + 1 : nMid - (nLW - 1) / 2; // Line-Center startX
    int nLC_xe = nLC_xs + nLW;

    int nBr_xs = nLC_xs - 4 * nSp_bl;  // Board X start (Left-most)
    int nBr_xe = nLC_xe + 4 * nSp_bl;  // Board X End (Right most)

    nCML = nBr_xs - 1;
    nCMR = nW - nBr_xe;
    printf("Calibrated: CMR=%d; CML=%d; Diff=%d\r\n", nCMR, nCML, (nCMR - nCML));

    return 0;
}