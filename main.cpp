#include <iostream>
#include "Grid.h"

using namespace std;

int main(){
    // Distance separating the drawn lines (arbitrary units)
    float lineSep;
    // Length of needle (arbitrary units)
    float needleLen; 
    // Number of trials to calculate probability of needle crossing line
    int numTrials; 
    // Used to check if user wants to do it again or quit the program
    char tryAgain; 
    // Size of the grid. Could be arbitrary but I want users to have 
    // control, like they are doing it by hand.
    int numGridLines; 

    while(true)
    {
        cout << "Line Separation = ";
        cin >> lineSep;

        cout << "Grid Size (Number of Lines) = ";
        cin >> numGridLines;

        cout << "Needle Length = ";
        cin >> needleLen;
    
        Grid test = Grid(&lineSep, &needleLen, &numGridLines);

        cout << "Number of Trials = ";
        cin >> numTrials;

        float approxPi = test.approximatePi(numTrials);
        cout << "Approximate Pi: " << approxPi << endl;

        cout << "Would you like to try again (y/n)?" << endl;
        cin >> tryAgain;

        // If they say 'y' or 'Y' then they want to keep going.
        // Otherwise it assumes you don't want to keep going.
        if(tryAgain != 'y' && tryAgain != 'Y')
        {
            break;
        }

        // Add a blank line between trials
        cout << endl;
    }
}