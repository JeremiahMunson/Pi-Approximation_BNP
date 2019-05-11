#include <iostream>

using namespace std;


class Grid{
public:
    Grid(float* sep, float* len);
    float approximatePi(int trials);
private:
    float lineSeparation;
    float needleLength;
    float needleLocation;
    float needleAngle;
    int numTrials;
    int numCrosses;
    void createNeedlePlace(float* loc, float* angle);
    void checkNeedleCrossLine(float* loc, float* angle);
    double pi = 3.14159265358979323846;
};