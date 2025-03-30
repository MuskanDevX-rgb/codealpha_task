#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function for user registration
void registerUser() {
    string username, password;

    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    ofstream outFile("database.txt", ios::app);
    outFile << username << " " << password << endl;
    outFile.close();

    cout << "Registration successful!\n";
}

// Function for user login
void loginUser() {
    string username, password, fileUser, filePass;
    bool loginSuccess = false;

    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ifstream inFile("database.txt");
    while (inFile >> fileUser >> filePass) {
        if (username == fileUser && password == filePass) {
            loginSuccess = true;
            break;
        }
    }
    inFile.close();

    if (loginSuccess) {
        cout << "Login successful!\n";
    } else {
        cout << "Invalid username or password!\n";
    }
}

int main() {
    int choice;

    cout << "1. Register\n2. Login\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        default:
            cout << "Invalid choice!\n";
    }

    return 0;
}