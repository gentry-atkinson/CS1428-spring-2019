/*******************************************************************************
File Name: assign6_gma23.cpp
Author: Gentry Atkinson
Date: 04/09/2019
Assignment Number: 6
CS 1428.253 Spring 2019
Instructor: Jill Seaman
This program will calculate the growth or loss of a starting population over a
given number of years.
*******************************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void getInput (int&, float&, float&, int&);
float calculatePop (int, float, float);
int yearsToDouble (float);
int yearsToZero (int, float);
void outputTable (int, float, float, int);

int main() {
    int popSize; //the size of the population
    float birthRate; //the rate of birth
    float deathRate; //the rate of death
    int years; //the years to track the pop

    getInput(popSize, birthRate, deathRate, years);
    outputTable(popSize, birthRate, deathRate, years);
    return 0;
}

void getInput (int& popSize, float& birthRate, float& deathRate, int& years){
    do{
        cout << "Enter the initial population (between 100 and 1,000,000): ";
        cin >> popSize;
    }while (popSize < 100 || popSize > 1000000);

    do{
        cout << "Enter the annual birth rate (between 0 and 100): ";
        cin >> birthRate;
    }while (birthRate < 0 || birthRate > 100);
    birthRate /= 100;

    do{
        cout << "Enter the annual death rate (between 0 and 100): ";
        cin >> deathRate;
    }while (deathRate < 0 || deathRate > 100);
    deathRate /= 100;

    do{
        cout << "Enter the number of years to track (greater than 0): ";
        cin >> years;
    }while (years < 0);
    cout << endl;
    return;
}

float calculatePop (int P, float B, float D){
    return floor(P + (B * P) - (D * P));
}

int yearsToDouble (float r){
        return ceil(log(2.0)/ log(1.0 + r));
}

int yearsToZero (int P, float r){
    return ceil(log(1.0/P)/log(1.0 + r));
}

void outputTable (int initPop, float birthRate, float deathRate, int years){
    cout << "Year                 Population" << endl;
    float localPop = initPop;
    cout << "----  -------------------------" << endl;
    for (int i = 0; i <= years; i++){
        cout << right << setw(4) << i << setw(20) << localPop << endl;
        localPop = calculatePop(localPop, birthRate, deathRate);
    }

    float rate = birthRate - deathRate;
    if (rate > 0){
        cout << "Population will double in " << yearsToDouble(rate) << " years"
            << endl;
    }
    else if (rate < 0){
        cout << "Population will be zero in " << yearsToZero(initPop, rate)
            << " years." << endl;
    }
    else {
        cout << "The population is stable." << endl;
    }
    return;
}
