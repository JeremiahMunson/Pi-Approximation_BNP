using namespace std;

class Grid{
public:
    Grid(float* sep, float* len, int* numLines);
    float approximatePi(int trials);
private:
    float lineSeparation;
    float needleLength;
    int gridSize;

    void throwNeedle(int* crosses);
    float getLineSeparation();
    float getNeedleLength();
    int getGridSize();

    double pi = 3.14159265358979323846;
};