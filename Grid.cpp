#include <iostream>
#include "Grid.h"
#include <random>
#include <ctime>
#include <math.h>

using namespace std;


Grid::Grid(float* sep, float* len)
{
    lineSeparation = *sep;
    needleLength = *len;
    srand(static_cast<unsigned int>(time(0)));
}

float Grid::approximatePi(int trials)
{    
    numTrials = 0;
    numCrosses = 0;
    for(numTrials; numTrials < trials; numTrials++)
    {
        createNeedlePlace(&needleLocation, &needleAngle);
        checkNeedleCrossLine(&needleLocation, &needleAngle);
    }
    return ((2*needleLength / lineSeparation) * (static_cast<float>(numTrials) / static_cast<float>(numCrosses)));
}

void Grid::createNeedlePlace(float* loc, float* angle)
{
    *loc = static_cast <float> (rand()) / ( static_cast <float> ( RAND_MAX / (10*lineSeparation) ) );
    *angle = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/360.0));
}

void Grid::checkNeedleCrossLine(float* loc, float* angle)
{
    float endNeedle = *loc + needleLength * static_cast<float>(cos(static_cast<double>(*angle) * pi/180));
    int lineLoc = 0;
    for(int i = 0; i < 11; i++)
    {
        lineLoc = i * lineSeparation;
        if((*loc > lineLoc && endNeedle < lineLoc) || (endNeedle > lineLoc && *loc < lineLoc))
        {
            numCrosses++;
            break;
        }
    }
}

