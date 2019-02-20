
//File Name: assign3_gma23.cpp
//Author: Gentry Atkinson
//Date: 2/20/2019
//Assignment Number: 3
//CS 1428.253 Spring 2019
//Instructor: Jill Seaman
//This program will calculate a users phone bill and advise them if there is a
//cheaper option

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main (){

  //variable declarations
  char planSelection;            //hold user input of plan selected
  char newPlan;                  //hold user input of new plan
  float gigsUsed;                //hold user input of GB used
  float billTotal = 0;           //the user's total bill

  const float ACTIVATION = 10;   //additional charge for new line
  const float PER_GIG = 14;      //cost per gig on b
  const float UNLIMITED = 45;    //cost of unlimited plan

  //print the menu
  cout << "Data Plans:" << endl;
  cout << "A. The unlimited plan ($45)" << endl;
  cout << "B. The By the Gig plan ($14/GB)" << endl;
  cout << "Enter which data plan the customer subscribes to: ";

  //take input of plan selection
  cin >> planSelection;

  //input GB and new line
  cout << "Enter the amount of data used during the month, in gigabytes: ";
  cin >> gigsUsed;
  cout << "Is this a new line(y/n)? ";
  cin >> newPlan;

  //validate user input
  if (planSelection == 'a') planSelection = 'A';
  else if (planSelection == 'b') planSelection = 'B';
  else if (planSelection != 'A' && planSelection != 'B'){
    cerr << "You must selec A or B." << endl;
    return 0;
  }

  if (gigsUsed < 0){
    cerr << "Ammount of data used must be positive." << endl;
    return 0;
  }

  //processing
  if (planSelection == 'A') billTotal += 45;
  else billTotal += (ceil(gigsUsed) * PER_GIG);

  if (newPlan == 'y' || newPlan == 'Y'){
   billTotal += ACTIVATION;
   cout << "You have been charged an activation fee" << endl;
  }

  //print bill ammount
  cout << fixed << setprecision(2);
  cout << "The ammount due for the month is $" << billTotal << endl;

  //print customer warnings
  if (planSelection == 'A'){
    if (UNLIMITED > gigsUsed * PER_GIG)
      cout << "Your bill would be cheaper on plan B" << endl;
    if (gigsUsed > 20)
      cout << "You may have experienced reduced speeds." << endl;
  }
  else {
    if (gigsUsed * PER_GIG > UNLIMITED)
      cout << "Your bill would be cheaper on plan A" << endl;
  }

  return 0;
}
