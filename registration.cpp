#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
    int choice;
    string username, password, storedUser, storedPass;

    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if(choice == 1)
    {
        cout << "\nEnter Username: ";
        cin >> username;

        cout << "Enter Password: ";
        cin >> password;

        ifstream readFile("users.txt");

        bool userExists = false;

        while(readFile >> storedUser >> storedPass)
        {
            if(username == storedUser)
            {
                userExists = true;
                break;
            }
        }

        readFile.close();

        if(userExists)
        {
            cout << "\nUsername already exists!" << endl;
        }        

        else
        {
			    ofstream writeFile("users.txt", ios::app);

            writeFile << username << " " << password << endl;

            writeFile.close();

            cout << "\nRegistration Successful!" << endl;
        }
    }

    else if(choice == 2)
    {
        cout << "\nEnter Username: ";
        cin >> username;

        cout << "Enter Password: ";
        cin >> password;

        ifstream readFile("users.txt");

        bool loginSuccess = false;

        while(readFile >> storedUser >> storedPass)
        {
            if(username == storedUser && password == storedPass)
            {
                loginSuccess = true;
                break;
            }
        }

        readFile.close();

        if(loginSuccess)
        {
            cout << "\nLogin Successful!" << endl;
        }
        else
        {
            cout << "\nInvalid Username or Password!" << endl;
        }
    }

    else
    {
        cout << "\nInvalid Choice!" << endl;
    }

    return 0;
}

