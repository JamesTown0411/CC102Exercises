#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    fstream file;

    file.open("original.txt", ios::out);

    if (file.is_open()) {
        file << "One\n";
        file << "Two\n";
        file << "Three\n";
        file << "Four\n";
        file << "Five\n";
        file << "Six\n";

        file.close();
        cout << "Write to original.txt successful!\n";
    } else {
        cout << "Failed to open original.txt.";
        return 1;
    }

    vector<string> lines;

    file.open("original.txt", ios::in);

    if (file.is_open()) {
        string line;


        while (getline(file, line)) {
            lines.push_back(line);
        }

        file.close();
    } else {
        cout << "Failed to open original.txt for reading.";
        return 1;
    }

    sort(lines.begin(), lines.end());

    file.open("sorted.txt", ios::out);

    if (file.is_open()) {

        for (int i = 0; i < lines.size(); i++) {
            file << lines[i] << "\n";
        }

        file.close();
        cout << "Sorted list written to sorted.txt successfully!\n";
    } else {
        cout << "Failed to open sorted.txt.";
    }

    return 0;
}
