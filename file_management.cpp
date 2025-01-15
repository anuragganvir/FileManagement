#include <iostream>
#include <fstream>
#include <string>
#include <cstdio> // For remove() and rename()
#include <limits> // For numeric_limits

using namespace std;

// Function prototypes
void createFile(const string& filename);
void writeFile(const string& filename);
void readFile(const string& filename);
void appendFile(const string& filename);
void deleteFile(const string& filename);

// Your watermark name
const string WATERMARK = " - by [anurag]";

int main() {
    int choice;
    string filename;

    do {
        // Menu options
        cout << "\n===== File Management System =====\n";
        cout << "1. Create a new file\n";
        cout << "2. Write to a file\n";
        cout << "3. Read from a file\n";
        cout << "4. Append to a file\n";
        cout << "5. Delete a file\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input! Please enter a number between 1 and 6.\n";
            continue; // Restart the loop
        }

        cin.ignore(); // Clear the input buffer

        switch (choice) {
            case 1:
                cout << "Enter filename to create: ";
                getline(cin, filename);
                createFile(filename);
                break;

            case 2:
                cout << "Enter filename to write to: ";
                getline(cin, filename);
                writeFile(filename);
                break;

            case 3:
                cout << "Enter filename to read from: ";
                getline(cin, filename);
                readFile(filename);
                break;

            case 4:
                cout << "Enter filename to append to: ";
                getline(cin, filename);
                appendFile(filename);
                break;

            case 5:
                cout << "Enter filename to delete: ";
                getline(cin, filename);
                deleteFile(filename);
                break;

            case 6:
                cout << "Exiting the program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

// Function to create a file
void createFile(const string& filename) {
    ofstream file(filename);
    if (file) {
        cout << "File \"" << filename << "\" created successfully.\n";
    } else {
        cerr << "Error creating file \"" << filename << "\".\n";
    }
    file.close();
}

// Function to write to a file
void writeFile(const string& filename) {
    ofstream file(filename, ios::trunc);
    if (file) {
        string content;
        cout << "Enter content to write (end with a single # on a new line):\n";
        while (getline(cin, content) && content != "#") {
            file << content << endl; // Write content without watermark for each line
        }
        file << "--- End of File ---" << WATERMARK << endl; // Add watermark at the end
        cout << "Content written to file \"" << filename << "\" successfully.\n";
    } else {
        cerr << "Error writing to file \"" << filename << "\".\n";
    }
    file.close();
}

// Function to read from a file
void readFile(const string& filename) {
    ifstream file(filename);
    if (file) {
        string content;
        cout << "Contents of \"" << filename << "\":\n";
        while (getline(file, content)) {
            cout << content << endl;
        }
    } else {
        cerr << "Error reading file \"" << filename << "\".\n";
    }
    file.close();
}

// Function to append to a file
void appendFile(const string& filename) {
    ofstream file(filename, ios::app);
    if (file) {
        string content;
        cout << "Enter content to append (end with a single # on a new line):\n";
        while (getline(cin, content) && content != "#") {
            file << content << endl; // Append content without watermark for each line
        }
        file << "--- Appended Content ---" << WATERMARK << endl; // Add watermark at the end
        cout << "Content appended to file \"" << filename << "\" successfully.\n";
    } else {
        cerr << "Error appending to file \"" << filename << "\".\n";
    }
    file.close();
}

// Function to delete a file
void deleteFile(const string& filename) {
    if (remove(filename.c_str()) == 0) {
        cout << "File \"" << filename << "\" deleted successfully.\n";
    } else {
        cerr << "Error deleting file \"" << filename << "\".\n";
    }
}
