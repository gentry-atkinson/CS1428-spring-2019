//File Name: assign2_gma23.cpp
//Author: Gentry Atkinson
//Date: 2/11/2019
//Assignment Number: 1
//CS 1428.253 Spring 2019
//Instructor: Jill Seaman
//Description: This macronutrient calculator takes an input from the user
//  of grams of fat, carbs, and proteind then prints the total grams and
//  percentages of nutrients consumed.

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  float fat;                    //grams of fat
  float carb;                   //grams of carbs
  float protein;                //grams of protein
  float totalCalories;          //the total input grams of nutrients
  const float CPG_Carb = 4.0;    //calories per gram for carbs
  const float CPG_Fat = 9.0;     //calories per gram for fat
  const float CPG_Protein = 4.0; //calories per gram for protein

  //Input from user: grams of carbs, fat, then protein
  cout << "Please enter the amount of carbohydrate in grams: ";
  cin >> carb;
  cout << "Please enter the amount of fat in grams: ";
  cin >> fat;
  cout << "Please enter the amount of protein in grams: ";
  cin >> protein;

  //Calculate total calories
  totalCalories = (CPG_Carb*carb) + (CPG_Fat*fat) + (CPG_Protein*protein);

  //Output values
  cout << endl;
  cout << "Total Grams\t: " << carb + fat + protein << endl;
  cout << "Total Calories\t: " << totalCalories << endl << endl;

  cout << fixed << setprecision(1);
  cout << "Percent of calories from each macronutrient: " << endl;
  cout << "Carbohydrate:\t" << (CPG_Carb*carb) / totalCalories * 100
   << "%" << endl;
  cout << "Fat:\t\t" << (CPG_Fat*fat) / totalCalories * 100 << "%"
   << endl;
  cout << "Protein:\t" << (CPG_Protein*protein) / totalCalories * 100 << "%"
   << endl;

  //Return success
  return 0;
}
