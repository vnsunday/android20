#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

/*============================================================
    Horizontal Line: 
        Y = a number
    Vertical Line:
        X = a number

 *============================================================*/
bool pass_able_2D(int X, int Y, bool bHorizon = true) {

    return true;
}

/*============================================================
    How the line [S,A] position compare to the line [A,B]?
        (a) Clock-wise:
            If (B,S) is clock wise compare to A
        (b) Counter clock-wise
            If (B,S) is counter-clock-wise compare to A
 *============================================================*/
std::string relative_position(int nAX, int nAY, int nBX, int nBY, 
    int nSX,
    int nSY)
{ 
    return "cw"; // Clockwise
}

/*============================================================
    nAX: anchor Point X 
    nAY: anchor Point Y 
    nFX: final Point X 
    nFY: final Point Y
 *============================================================*/
void pull_string(int nAX, int nAY, int nFX, int nFY) {
    int** azPath = NULL;

    int nP; // n path 
    int nA2X;
    int nA2Y;
    
    nAX = 0;
    nAY = 0;

    nA2Y = nAY;
    nA2X = nAX + 10;
}



bool drill_a_hole(int X, int Y, bool bHorizon, int Xh, int Yh) {
    
    return true;
}

// Condition to pass: having a point to the force lay-on
//    
bool pass_able(int V1, int V2, int anchorV, int* path, int npath) {
    /*----------------------------------------
        Assumption:
            existing path is conditioned ()
        Condition:
            new point concatenating to existing path, must:
                + Make sure the edge having tension-force on string
     *----------------------------------------*/
    // Make sure 
    // Obstacle 
    return true;
}

void path_finding() 
{
    /*============================================================
        Input: 
            Physical Node position
        Expectation:
            Finding a path
            At-lest two string-depth at some edges
        Output
            A path
     *============================================================*/
    /* 
        A1    B1
        A2    B2
     */
    int pIA1, pIB1, pIA2, pIB2;
    int pOA1, pOB1, pOA2, pOB2;
    int nstring; // String of thread 

    // Define obstacle 
    int nAC; // Anchor Point
}

int main(int argc, char const *argv[])
{    
    int define2D = 0;
    bool bHorizontal = false;

    // Define 2D line: Horizontal or Vertical
    int X; // 
    int Y; 
    bool bVertical = true;

    int path;
    

    return 0;
}
