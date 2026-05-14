#include <stdlib.h>
#include <conio.h>



// Total Light 
int distribute_2D(int nLE, int x, int y) {

    // Cordinating system 


    // Spreading 10 times 
    int nEnergy = nLE;
    while (nEnergy > 0) {
    }
    return 0;
}

int flow_1D(int nLE, int x) {
    int nLE;
    int nEnergy = nLE;
    int xl = x;
    int xr = x;
    int azNE[500];

    while (nEnergy > 0) {
        // 
        azNE[xl]++;
        nEnergy--;
        xl--;

        azNE[xr]++;
        nEnergy--;
        xr++;

    }

    return 0;
}

int main(int argc, char const *argv[])
{
    int nLE = 1000; // Lighting Energy (particles)
    int pLightSource; 
    
    return 0;
}