#include<iostream>
#include<string>
using namespace std;


struct book {
    int barcode;
    string title;
    int year;
    int rating;
};

void input(book s[], int numBooks);
void display(book s[], int numBooks);

int main() {
    int numBooks;
    char choice;

    do {
        cout << "Enter how many books: ";
        cin >> numBooks;
        cin.ignore();


        book obj[numBooks];

        input(obj, numBooks);
        display(obj, numBooks);

        cout << "\nAgain?(Y/y): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}

void input(book s[], int numBooks) {
    for (int i = 0; i < numBooks; i++) {
        cout << "\nEnter Barcode: ";
        cin >> s[i].barcode;

        for (int j = 0; j < i; j++) {
            if (s[i].barcode == s[j].barcode) {
                cout << "Barcode taken, please enter a new one: ";
                cin >> s[i].barcode;
                j = -1;
            }
        }

        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, s[i].title);
        cout << "Enter Year Published: ";
        cin >> s[i].year;
        cout << "Enter Rating(0-5): ";
        cin >> s[i].rating;
        cin.ignore();
    }
}

void display(book s[], int numBooks) {
    cout << "\nBarcode\t\tTitle\t\tYear\t\tRating\t\tCategory\n";
    for (int i = 0; i < numBooks; i++) {
        cout << s[i].barcode << "\t\t"
             << s[i].title << "\t\t"
             << s[i].year << "\t\t"
             << s[i].rating << "\t\t";

        switch (s[i].rating) {
            case 5: cout << "Excellent"; break;
            case 4: cout << "Very Good"; break;
            case 3: cout << "Good"; break;
            case 2: cout << "Fair"; break;
            case 1: cout << "Poor"; break;
            case 0: cout << "No Rating"; break;
            default: cout << "Not in options!"; break;
        }
        cout << endl;
    }
}
