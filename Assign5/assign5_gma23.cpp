//File Name: assign5_gma23.cpp
//Author: Gentry Atkinson
//Date: 27 March 2019
//Assignment Number: 5
//CS 1428.253 Spring 2019
//Instructor: Jill Seaman
//This program will calculate some statistics for a production run of 1000
//boxes of Chocolate Frosted Sugar Bombs

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
    string fileName;                //the name of the input file
    ifstream inFile;                //the file to read from
    const int NUM_BOXES = 1000;     //the number of boxes in the file
    const float MIN_WEIGHT = 20.0;  //the lowest legal box weight
    const float FINE = 250000;      //the fine for a light box
    float boxWeights[NUM_BOXES];    //an array to hold the weight of all boxes
    float averageWeight = 0;        //the mean of all box weights
    float stanDev = 0;              //the standard deviation of box weights
    float minWeight;                //the smallest box weight
    float maxWeight;                //the greatest box weights
    int numUnderWeight = 0;         //the number of boxes under 20oz

    //open the input file
    cout << "Please type the name of the file to read: ";
    cin >> fileName;
    inFile.open(fileName);
    if (!inFile.is_open()){
        cout << "Trouble reading file." << endl;
        return 1;
    }

    //read all of the box weights
    int boxCounter = 0;             //a temp value to load box array
    while (!inFile.eof()){
        inFile >> boxWeights[boxCounter];
        boxCounter++;
    }
    cout << boxCounter << " box weights read." << endl;

    //calculate the average box weight
    for(int i = 0; i < NUM_BOXES; i++)
        averageWeight += boxWeights[i];
    averageWeight /= NUM_BOXES;

    //calculate the stan dev
    for(int i = 0; i < NUM_BOXES; i++){
        float dif = (boxWeights[i] - averageWeight);
        dif = pow(dif, 2);
        stanDev += dif;
    }
    stanDev /= NUM_BOXES;
    stanDev = sqrt(stanDev);

    //find the number if light boxes
    for(int i = 0; i < NUM_BOXES; i++)
        if(boxWeights[i] < MIN_WEIGHT)
            numUnderWeight++;

    //find the max and min box weights
    maxWeight = boxWeights[0];
    minWeight = boxWeights[0];
    for(int i = 1; i < NUM_BOXES; i++){
        if (boxWeights[i] > maxWeight)
            maxWeight = boxWeights[i];
        if (boxWeights[i] < minWeight)
            minWeight = boxWeights[i];
    }

    //output the values
    cout << fixed << setprecision(3) << endl;
    cout << "Chocolate Frosted Sugar Bombs statistics:" << endl << endl;
    cout << "Average weights: " << averageWeight << endl;
    cout << "Standard Deviation: " << stanDev << endl << endl;

    cout << "Number of boxes below 20 ounces: " << numUnderWeight << endl;
    cout << "The fine for this is: $" << numUnderWeight * FINE << endl << endl;

    cout << "Maximum weight of all boxes: " << maxWeight << endl;
    cout << "Minimum weight of all boxes: " << minWeight << endl;

    inFile.close();
    return 0;
}
