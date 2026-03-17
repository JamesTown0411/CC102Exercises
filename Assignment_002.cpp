#include <iostream>
using namespace std;

const int MAX_SUBJECTS = 10;

void processGrades(int* ptr, int students, int subjects) {
    int highest = 0;

    cout << "\n====Grade Matrix====\n";
    for (int i = 0; i < students; i++) {
        int sum = 0;
        cout << "Student " << (i + 1) << ": ";

        for (int j = 0; j < subjects; j++) {
            int currentGrade = *(ptr + i * MAX_SUBJECTS + j);

            cout << currentGrade << " ";
            sum += currentGrade;

            if (currentGrade > highest) {
                highest = currentGrade;
            }
        }

        double average = static_cast<double>(sum) / subjects;
        cout << "| Average: " << average << endl;
    }

    cout << "\nHighest grade in the matrix: " << highest << endl;
}

int main() {
    int students, subjects;
    int grades[50][MAX_SUBJECTS];

    cout << "Enter the number of students (max 50): ";
    cin >> students;
    cout << "Enter the number of subjects (max 10): ";
    cin >> subjects;

    cout << "\nEnter the grades:\n";
    for (int i = 0; i < students; i++) {
        cout << "Grades for Student " << (i + 1) << ":\n";
        for (int j = 0; j < subjects; j++) {
            cout << "Subject" << (j + 1) << ": ";
            cin >> grades[i][j];
        }
    }

    processGrades(&grades[0][0], students, subjects);

    return 0;
}
