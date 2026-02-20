#include <iostream>
using namespace std;

int main() {
    char choice;


    do {

        double sales[5][4] = {0};

        int salesperson, product;
        double amount;
        char addAnotherSlip;

        do {
            cout << "Salesperson: ";
            cin >> salesperson;
            cout << "Product: ";
            cin >> product;
            cout << "Amount: ";
            cin >> amount;

            sales[product - 1][salesperson - 1] += amount;

            cout << "Enter another slip? (y/n): ";
            cin >> addAnotherSlip;
            cout << "\n";

        } while (addAnotherSlip == 'y' || addAnotherSlip == 'Y');


        cout << "Product\t1\t2\t3\t4\tTotal\n";


        double colTotals[4] = {0};
        double grandTotal = 0;

        for (int i = 0; i < 5; i++) {
            cout << (i + 1) << "\t";
            double rowTotal = 0;

            for (int j = 0; j < 4; j++) {
                cout << sales[i][j] << "\t";
                rowTotal += sales[i][j];
                colTotals[j] += sales[i][j];
            }

            grandTotal += rowTotal;
            cout << rowTotal << "\n";
        }


        cout << "Total\t";
        for (int j = 0; j < 4; j++) {
            cout << colTotals[j] << "\t";
        }
        cout << grandTotal << "\n";


        cout << "\nWould you like to run the program again? (y/n): ";
        cin >> choice;
        cout << "\n";

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
