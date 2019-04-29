//File Name: assign7_gma23.cpp
//Author: Gentry Atkinson
//Date: 4/30/2019
//Assignment Number: 7
//CS 1428.253 Spring 2019
//Instructor: Jill Seaman
//This program will compute the final average and letter grade for a roster of 5
//  students, calculate the class average, and find the student with the highest
//  final grade.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Student{
    float finalAvg;
    char letterGrade;

    Student(){
        finalAvg = 0;
        letterGrade = 'U';
    }
};

const float MID_WEIGHT = 0.4;
const float FINAL_WEIGHT = 0.6;
const int NUM_STUDENTS = 5;
const float A_CUTOFF = 89.5;
const float B_CUTOFF = 79.5;
string names[NUM_STUDENTS] = {"Cooper", "Fields", "Garcia", "Newton", "Ortega"};

void calculateAvg(Student[]);
void showData(Student[]);
float calcClassAvg(Student[]);
int findHighest(Student[]);

int main(){
    Student students[NUM_STUDENTS];
    calculateAvg(students);
    showData(students);

    return 0;
}
//***********************************************************
// calculateAvg: takes input from user and stores it in the students array after
//  calculating the final avg and letter
// students: an array of Students representing the class
// returns: none
//***********************************************************
void calculateAvg(Student students[]){
    cout << "Enter the midterm and final exam score for each student: " << endl;
    for (int i = 0; i < NUM_STUDENTS; ++i){
        float m = 0,f=0;
        cout << names[i] << ": ";
        cin >> m >> f;
        students[i].finalAvg = m*MID_WEIGHT + f*FINAL_WEIGHT;
        if (students[i].finalAvg >= A_CUTOFF)
            students[i].letterGrade = 'A';
        else if (students[i].finalAvg >= B_CUTOFF)
            students[i].letterGrade = 'B';
        else
            students[i].letterGrade = 'C';
        if (m>100 || f>100){
            i -= 1;
            cout << "Grades should not be greater than 100." << endl;
        }
    }
}

//***********************************************************
// calcClassAvg: computes the avg for the total class
// students: an array of Students representing the class
// returns: the class avg
//***********************************************************
float calcClassAvg(Student students[]){
    float total = 0;
    for (int i = 0; i < NUM_STUDENTS; ++i)
        total += students[i].finalAvg;
    return total/NUM_STUDENTS;
}

//***********************************************************
// findHighest: finds the student with the highest final avg
// students: an array of Students representing the class
// returns: the index of the highest student in students
//***********************************************************
int findHighest(Student students[]){
    int best = 0;
    for (int i = 1; i < NUM_STUDENTS; ++i){
        if (students[i].finalAvg > students[best].finalAvg)
            best = i;
    }
    return best;
}

//***********************************************************
// showData: prints a formatted table of student grades, the class avg, and
//  the grade of the highest student.
// students: an array of Students representing the class
// returns: none
//***********************************************************
void showData(Student students[]){
    cout << "Class Roster:" << endl;
    cout << fixed << setprecision(1);
    for(int i = 0; i < NUM_STUDENTS; ++i){
        cout << names[i] << "..." << students[i].finalAvg << "..."
            << students[i].letterGrade << endl;
    }
    cout << endl <<endl << "The class average: " << calcClassAvg(students)
        << endl;
    int best = findHighest(students);
    cout << endl << "The student who earned the highest grade is: "
        << names[best] << " " << students[best].finalAvg << endl;
}
