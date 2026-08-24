#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void model_pull_simple() {
    /*========================================
        Modeling (see string-pull-simple.png)
        Input:
            (dx,dy) distance from the end of string to anchor point
            l: length of the string
            (px, py) pull vector
        Output: 
            (fdx, fdy)  Final position (X,Y) when then String is pull at most
     *========================================*/

    // State changes 
    int dx; 
    int dy;
    int l;
    int px;
    int py; 

    double distance = sqrt((dx*dx) + (dy*dy));
    double f_m; // Function of weight of every position of the string

    // 
    double fdx;
    double fdy;
    
    // Line Equation of Pull vector containing the poin (dx,dy)
    
    // Solve the equation 
    //      fdx^2 + fdy^2 = l^2 
    //      vector ((fdx - dx),(fdy - dy)) is parallel to vector (px, py)
}

int main()
{
    /*========================================
        Modeling
        Input:
            Assumption: A and B is horizontal (yA = yB)
            d: X-distance between A and B 
            ds: Y-Distance betwen B and String Head
        (See: string-pull.png)
     *========================================*/
    int d;
    int ds;

    // States: Before Pull


    // States: After pulling the string
    

    return 0;
}