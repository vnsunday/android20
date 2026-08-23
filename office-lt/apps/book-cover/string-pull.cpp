#include <stdio.h>
#include <stdlib.h>

void model_pull_simple() {
    /*========================================
        Modeling (see string-pull-simple.png)
        Input:
            (dx,dy) distance from the end of string to anchor point
            l: length of the string
            (px, py) pull vector
     *========================================*/

    // State changes 
    int dx; 
    int dy;
    int l;
    int px;
    int py; 

    double distance = sqrt((dx*dx) + (dy*dy));
    double f_m; // Function of weight of every position of the string

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