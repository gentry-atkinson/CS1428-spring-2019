#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main () {
    int trialTime; //holds the time for one trial run
    float totalTime; //holds the sum of all runs for one rat
    string ratName; //the name of one rat
    char continueLoop = 'y'; //the conditional to continue the input loop
    ofstream outFile("lab_report.txt");

    const float NUM_TRIALS = 5.0; //each rat will run 5 trials

    outFile << "Name                Time 1 Time 2 Time 3 Time 4 Time 5   Avg "
        << "Rating" << endl;

    while (continueLoop == 'y' || continueLoop == 'Y'){
        totalTime = 0;
        cout << "What is the name of this rat? ";
        cin >> ws;
        getline(cin, ratName);
        outFile << setw(20) << ratName;
        for (int i = 0; i < 5; i++){
            cout << "Enter a time for trial " << i+1 << ": ";
            cin >> trialTime;
            totalTime += trialTime;
            outFile << setw(7) << trialTime;
        }
        totalTime /= NUM_TRIALS;
        outFile << totalTime;
        if (totalTime < 25)
            outFile << "Superiof";
        else if (totalTime < 35)
            outFile << "Normal";
        else
            outFile << "Slow";
        outFile << endl;

        cout << "Would you like to enter another rat?";
        cin >> continueLoop;
    }



    return 0;
}
