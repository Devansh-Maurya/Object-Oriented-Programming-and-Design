#include <iostream>
#include <fstream>

using namespace std;

char skipMultipleSpaces(ifstream&);

int main() {

    //Open file for reading
    ifstream fin;
    //Make new_file.txt and replace multiple spaces by a single space
    ofstream fout;
    char ch;
    char fileName[20];

    cout << "Enter the file name to open: ";
    cin >> fileName;
    fin.open(fileName);     //Open file for reading in default mode

    if (!fin) {
        cout << "Error opening file! Exiting";
        return -1;
    }

    cout << "Enter the new file name: ";
    cin >> fileName;
    fout.open(fileName);     //Open file for writing in default mode

    while (fin) {
        if (fin.get(ch)) {
            fout.put(ch);
            if (ch == ' ')
                fout.put(skipMultipleSpaces(fin));
        }
    }
    
    fin.close();
    fout.close();

    return 0;
}

//Skip through multiple spaces and return the last non-space character
char skipMultipleSpaces(ifstream& fin) {

    char ch = 0;

    while (fin) {
        if (fin.get(ch)) {
            if (ch != ' ')
                break;
        }
    }

    return ch;
}