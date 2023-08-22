#pragma once

#include"Subjects.h"
#include<iomanip>

class CGPA {
    Subjects* subjectsArr;
    int noOfSemesters;
public:
    CGPA() :subjectsArr() {
        this->noOfSemesters = 0;
        this->subjectsArr = nullptr;
    }
    CGPA(const int size) :subjectsArr() {
        this->noOfSemesters = size;
        this->subjectsArr = new Subjects[this->noOfSemesters];

    }

    float calculate()const {
        float total = 0;
        for (int i = 0; i < this->noOfSemesters; i++)
            total += this->subjectsArr[i].getSGPA();
        return total;
    }
    ~CGPA() {
        delete[]this->subjectsArr;
        subjectsArr = nullptr;

    }

    friend ostream& operator<<(ostream& COUT, const CGPA& obj);
    friend istream& operator>>(istream& CIN, CGPA& obj);

};

ostream& operator<<(ostream& COUT, const CGPA& obj) {
    for (int i = 0; i < obj.noOfSemesters; i++)
        COUT << "Semester # " << i + 1 << "\n" << obj.subjectsArr[i] << endl << "SGPA: " << setprecision(3) << obj.subjectsArr[i].getSGPA() << endl << endl;
    COUT << "CGPA: " << setprecision(3) << obj.calculate() << endl;

    return COUT;
}

istream& operator>>(istream& CIN, CGPA& obj) {

    for (int i = 0; i < obj.noOfSemesters; i++) {
        cout << "Semester # " << i + 1 << endl;
        int size = 0;
        cout << "Number of Courses: ";
        CIN >> size;
        obj.subjectsArr[i].allocator(size);
        CIN >> obj.subjectsArr[i];
    }
    return CIN;


}


