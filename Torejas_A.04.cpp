#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    fstream file;

    file.open("color.txt", ios::out);

    if (file.is_open()) {
        file << "Crimson Red\n";
        file << "Navy Blue\n";
        file << "Forest Green\n";
        file << "Mustard Yellow\n";
        file << "Royal Purple\n";

        file.close();
        cout << "Write successful!\n";
    } else {
        cout << "Failed to open file.";
        return 1;
    }


    fstream inFile;
    fstream copyFile;

    inFile.open("color.txt", ios::in);

    copyFile.open("color_copy.txt", ios::out);

    if (inFile.is_open() && copyFile.is_open()) {
        string line;

        while (getline(inFile, line)) {
            copyFile << line << "\n";
        }

        inFile.close();
        copyFile.close();
        cout << "Copied successful!\n";
    } else {
        cout << "Failed to open file.";
    }

    return 0;
}
