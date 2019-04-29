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

float calcClassAvg(Student students[]){
    float total = 0;
    for (int i = 0; i < NUM_STUDENTS; ++i)
        total += students[i].finalAvg;
    return total/NUM_STUDENTS;
}

int findHighest(Student students[]){
    int best = 0;
    for (int i = 1; i < NUM_STUDENTS; ++i){
        if (students[i].finalAvg > students[best].finalAvg)
            best = i;
    }
    return best;
}

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
