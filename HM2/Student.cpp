#include <iostream>

using namespace std;

class Student {
public:
    Student(double grade = 2.0) : grade(grade) {
    }

    Student operator+(double percentage) const {
        Student lhs(*this); //Dilyan + (5 * Dilyan) / 100.0
        lhs.grade = lhs.grade + lhs.grade * (percentage / 100.0);
        return lhs; //copy
    }
private:
    double grade;
}

int main() {
    Student dilyan(5.0);
    Student dilyanGrade= dilyan + 5;
    cout << dilyanGrade << endl;
    return 0;
}