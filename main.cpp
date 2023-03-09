#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool PasswordCheck(string username, string password)
{
    ifstream DataFile ("Data.txt");
    if (DataFile.is_open())
    {
        string eUsername, ePassword;
        while (DataFile >> eUsername >> ePassword)
        {
            if(username == eUsername && password == ePassword)
            {
                DataFile.close();
                return true;
            }
        }
        DataFile.close();
    }
    return false;
}

void Register(string username, string password){
    fstream DataFile("Data.txt", ios::app);
    if (DataFile.is_open())
    {
        DataFile << username << " " << password << endl;
        DataFile.close();
        cout << "User added";
    }
}

int main()
{
    string username, password, a;

    cout << "Login [L] or Register[R]?\n";
    cin >> a;

    cout << "Enter a username: ";
    cin >> username;

    cout << "Enter a password: ";
    cin >> password;

    if (a == "L" or a == "l"){
        if(PasswordCheck(username, password))
        {
            cout << "Logged in.";
        }
        else {
            cout << "Error, username or password not found.";
        }
    }
    else if (a == "R" or a == "r")
    {
        Register(username, password);
    }

}
