#include <iostream>
#include "Grid.h"
#include <random>
#include <ctime>
#include <math.h>

using namespace std;


Grid::Grid(float* sep, float* len, int* numLines)
{
    lineSeparation = *sep;
    needleLength = *len;
    gridSize = *numLines;
    srand(static_cast<unsigned int>(time(0)));
}

float Grid::approximatePi(int trials)
{    
    int numTrials = 0;
    int numCrosses = 0;
    for(numTrials; numTrials < trials; numTrials++)
    {
        // Chose to keep as method so that it is easier to understand the code.
        // This way it is broken up into important tasks so the approximatePi
        // method isn't too big and confusing.
        checkNeedleCrossLine(&numCrosses);
    }
    return ((2*getNeedleLength() / getLineSeparation()) * (static_cast<float>(numTrials) / static_cast<float>(numCrosses)));
}

/*
    Only checks in one dimmension because the part of the needle parallel to the lines is irrelevant. The important
    part is whether or not it crosses the line. Imagine the lines running vertical. The only part of the needle that 
    matters is the horizontal component because that is how it crosses the grid lines.
*/
void Grid::checkNeedleCrossLine(int* crosses)
{
    // Creates random float between 0.0 and the number of grid lines times line separation distance. 
    // Used for the location of the head of the needle.
    float needleHead = static_cast <float> (rand()) / ( static_cast <float> ( RAND_MAX / (getGridSize()*getLineSeparation()) ) );

    // Creates random double between 0.0 and 360.0 as the angle of the needle.
    double angle = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/360.0));

    // Location of tip of needle calculated from the needle head location and the angle.
    float needleTip = needleHead + getNeedleLength() * static_cast<float>( cos(angle * pi/180) );

    // If you number the regions between the grid lines you can find which region you are in
    // by taking your location divided by the line separation and floor that value.
    float headRegion = floor(needleHead/getLineSeparation());
    float tipRegion = floor(needleTip/getLineSeparation());

    // If the head and tip of the needle are not in the same region, the needle must cross a line.
    if(headRegion != tipRegion)
    {
        (*crosses)++;
    }
}

float Grid::getLineSeparation()
{
    return lineSeparation;
}

float Grid::getNeedleLength()
{
    return needleLength;
}

int Grid::getGridSize()
{
    return gridSize;
}
