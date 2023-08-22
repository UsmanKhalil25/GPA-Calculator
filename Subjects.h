#pragma once
#include<iostream>
#include<string>

using namespace std;



void printSpace(const int space) {
    for (int i = 0; i < space; i++)
        cout << " ";
}

class Subjects {
private:
    string* subjectNames;
    string* grade;
    float* points;
    int* creditHours;
    float SGPA;
    int size;
public:
    Subjects() {
        this->subjectNames = nullptr;
        this->grade = nullptr;
        this->points = nullptr;
        this->creditHours = nullptr;
        this->size = 0;
        this->SGPA = 0;
    }
    explicit Subjects(const int size) {
        this->size = size;
        this->SGPA = 0;
        this->subjectNames = new string[this->size];
        this->grade = new string[this->size];
        this->points = new float[this->size];
        this->creditHours = new int[this->size];
    }
    [[nodiscard]] string subjectAt(const int index)const {
        if (index >= 0 && index < this->size)
            return this->subjectNames[index];
        return "Error: Out of bound";
    }
    string& subjectAt(const int index) {
        if (index >= 0 && index < this->size)
            return this->subjectNames[index];
        static string error = "Error: Out of bound";
        return error;
    }
    [[nodiscard]] string gradeAt(const int index)const {
        if (index >= 0 && index < this->size)
            return this->grade[index];
        return "Error: Out of bound";
    }
    string& gradeAt(const int index) {
        if (index >= 0 && index < this->size)
            return this->grade[index];
        static string e = "Error: Out of bound";
        return e;
    }

    [[nodiscard]] float pointsAt(const int index)const {
        if (index >= 0 && index < this->size)
            return this->points[index];
        return -1;
    }
    float& pointsAt(const int index) {
        if (index >= 0 && index < this->size)
            return this->points[index];
        static float e = -1;
        return e;

    }

    [[nodiscard]] int creditAt(const int index)const {
        if (index >= 0 && index < this->size)
            return this->creditHours[index];
        return -1;
    }
    int& creditAt(const int index) {
        if (index >= 0 && index < this->size)
            return this->creditHours[index];
        static int e = -1;
        return e;

    }




    void allocator(const int numberOfSubjects) {
        delete[]this->subjectNames;
        delete[]this->creditHours;
        delete[]this->points;
        delete[]this->grade;
        this->size = numberOfSubjects;
        this->SGPA = 0;
        this->subjectNames = new string[this->size];
        this->grade = new string[this->size];
        this->points = new float[this->size];
        this->creditHours = new int[this->size];
    }
    [[nodiscard]] float getSGPA() {
        int totalCredit = 0;
        for (int i = 0; i < this->size; i++) {
            totalCredit += creditHours[i];
        }
        float temp = 0;
        for (int i = 0; i < this->size; i++) {
            temp += static_cast<float>(creditHours[i]) * points[i];
        }
        return temp / static_cast<float>(totalCredit);

    }

    void gradeSetter(const int index) {
        if (this->points[index] <= 4 && this->points[index] > 3.67)
            this->grade[index] = 'A';
        else if (this->points[index] <= 3.67 && this->points[index] > 3.33)
            this->grade[index] = "A-";
        else if (this->points[index] <= 3.33 && this->points[index] > 3.00)
            this->grade[index] = "B+";
        else if (this->points[index] <= 3.00 && this->points[index] > 2.67)
            this->grade[index] = "B";
        else if (this->points[index] <= 2.67 && this->points[index] > 2.33)
            this->grade[index] = "B-";
        else if (this->points[index] <= 2.33 && this->points[index] > 2.00)
            this->grade[index] = "C+";
        else if (this->points[index] <= 2.00 && this->points[index] > 1.67)
            this->grade[index] = "C";
        else if (this->points[index] <= 1.67 && this->points[index] > 1.33)
            this->grade[index] = "C-";
        else if (this->points[index] <= 1.33 && this->points[index] > 1.00)
            this->grade[index] = "D+";
        else if (this->points[index] == 1.00)
            this->grade[index] = "D";
        else
            this->grade[index] = "F";


    }

    [[nodiscard]] int indexFinder()const {
        int index = -1;
        int max = 0;
        for (int i = 0; i < this->size; i++) {
            if (this->subjectNames[i].length() > max) {
                max = subjectNames[i].length();
                index = i;
            }
        }
        return index;

    }


    ~Subjects() {
        delete[]this->subjectNames;
        delete[]this->creditHours;
        delete[]this->points;
        delete[]this->grade;
        this->subjectNames = nullptr;
        this->creditHours = nullptr;
        this->points = nullptr;
        this->grade = nullptr;


    }

    friend ostream& operator<<(ostream& COUT, const Subjects& obj);
    friend istream& operator>>(istream& CIN, Subjects& obj);
};


istream& operator>>(istream& cin, Subjects& obj) {
    for (int i = 0; i < obj.size; i++) {
        cout << "Subject # " << i + 1 << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, obj.subjectNames[i]);
        cout << "Credit Hours: ";
        cin >> obj.creditHours[i];
        cout << "Points Earned: ";
        cin >> obj.points[i];
        obj.gradeSetter(i);
        cout << "Grade: " << obj.grade[i] << endl;


    }
    return cin;
}

ostream& operator<<(ostream& cout, const Subjects& obj) {

    int index = obj.indexFinder();
    int space = obj.subjectNames[index].length() - 8;
    cout << "\nSubjects";
    if (obj.subjectNames[index].length() > 8)
        printSpace(space);
    else
        cout << "\t";
    cout << "\tCredit Hours\tGrade\tPoints\n\n";
    for (int i = 0; i < obj.size; i++) {
        space = obj.subjectNames[index].length() - obj.subjectNames[i].length();
        cout << obj.subjectNames[i];
        printSpace(space);
        cout << "\t" << obj.creditHours[i] << "\t\t" << obj.grade[i] << "\t" << obj.points[i] << endl;
    }


    return cout;
}
