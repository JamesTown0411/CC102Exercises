#include <iostream>
using namespace std;

int main() {
    char choice;

    do {
        int numStudents;
        int numQuizzes;

        cout << "Enter number of students: ";
        cin >> numStudents;

        cout << "Enter number of quizzes: ";
        cin >> numQuizzes;

        const int MAX_STUDENTS = 50;
        const int MAX_QUIZZES = 10;

        double scores[MAX_STUDENTS][MAX_QUIZZES];
        double averages[MAX_STUDENTS] = {0};

        for (int i = 0; i < numStudents; i++) {
            cout << "Student " << (i + 1) << " scores: ";
            double sum = 0;

            for (int j = 0; j < numQuizzes; j++) {
                cin >> scores[i][j];
                sum += scores[i][j];
            }

            averages[i] = sum / numQuizzes;
        }

        cout << "\n";

        cout << "Student\t";
        for (int j = 0; j < numQuizzes; j++) {
            cout << "Q" << (j + 1) << "\t";
        }
        cout << "Average\n";

        for (int i = 0; i < numStudents; i++) {
            cout << (i + 1) << "\t";

            for (int j = 0; j < numQuizzes; j++) {
                cout << scores[i][j] << "\t";
            }
            cout << averages[i] << "\n";
        }

        cout << "\nWould you like to run the program again? (y/n): ";
        cin >> choice;
        cout << "\n";

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
