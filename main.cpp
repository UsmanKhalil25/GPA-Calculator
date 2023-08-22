#include"cgpaCalculator.h"

#include<Windows.h>

int main() {
   int semesters = 0;
    cout << "Enter number of semesters: ";
    cin >> semesters;
    CGPA student(semesters);

    cin >> student;
    cout << student;


    return 0;
}


