using namespace std;

class Grid{
public:
    Grid(float* sep, float* len, int* numLines);
    float approximatePi(int trials);
private:
    float lineSeparation;
    float needleLength;
    int gridSize;
    int numTrials;
    int numCrosses;
    void checkNeedleCrossLine();
    double pi = 3.14159265358979323846;
};