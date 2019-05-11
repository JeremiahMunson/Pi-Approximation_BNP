using namespace std;

class Grid{
public:
    Grid(float* sep, float* len, int* numLines);
    float approximatePi(int trials);
    double accuracy();
    double error();

private:
    float lineSeparation;
    float needleLength;
    int gridSize;
    double approxPi = 0.0;

    void throwNeedle(int* crosses);
    float getLineSeparation();
    float getNeedleLength();
    int getGridSize();
    double getPi();
    void setApproxPi(double appPi);
    double getApproxPi();

    double pi = 3.14159265358979323846;
};