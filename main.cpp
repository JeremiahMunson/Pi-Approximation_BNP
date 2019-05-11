#include <iostream>
#include "Grid.h"

using namespace std;

int main(){
    float lineSep;
    float needleLen;
    int numTrials;
    char tryAgain;

    while(true)
    {
        cout << "Line Separation = ";
        cin >> lineSep;

        cout << "Needle Length = ";
        cin >> needleLen;
    
        Grid test = Grid(&lineSep, &needleLen);

        cout << "Number of Trials = ";
        cin >> numTrials;

        float approxPi = test.approximatePi(numTrials);
        cout << "Approximate Pi: " << approxPi << endl;

        cout << "Would you like to try again (y/n)?" << endl;
        cin >> tryAgain;

        if(tryAgain != 'y' && tryAgain != 'Y')
        {
            break;
        }
    }

}