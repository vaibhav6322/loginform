#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int c;
    cout << "\t\t\t\t________________________________________________\n\n\n";
  cout << "\t\t\t\t________Code by Vaibhav Tripathi____________________\n\n\n";
    cout << "\t\t\t\t            WELCOME TO THE LOGIN PAGE            \n\n\n";
    cout << "\t\t\t\t____________     MENU           _________________\n\n\n";
    cout << "                                                            \n\n";
    cout << "\t| PRESS 1 to Login                   |" << endl;
    cout << "\t| PRESS 2 to Register                |" << endl;
    cout << "\t| PRESS 3 if you forgot your PASSWORD|" << endl;
    cout << "\t| PRESS 4 to EXIT                    |" << endl;
    cout << "\n\t\t\t Please enter your choice :  ";
    cin >> c;
    cout << endl;

    switch (c)
    {
    case 1:
        login();
        break;

    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << "\t\t\tTHANK YOU! \n\n";
        break;
    default:
        system("cls");
        cout << "\t\t\t Please Select from the options above\n"
             << endl;
        main();
    }
}

void login()
{
    int count = 0;
    string userId, password, id, pass;
    system("cls");
    cout << "\n\t\t\t Please enter username and password :  " << endl;
    cin >> userId;
    cout << "\t\t\t PASSWORD  ";
    cin >> password;

    ifstream input("records.txt"); // check if it already exists in the DB

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close(); // close the file

    if (count == 1)
    {
        cout << userId << "\n Your login is successful \n Thanks for logging in ! \n";
        main();
    }
    else
    {
        cout << "\n LOGIN ERROR \n Please check your username and password \n";
        main();
    }
}

void registration()
{
    string ruserId, rpassword, rid, rpass;
    system("cls");
    cout << "\t\t\t Enter the username : ";
    cin >> ruserId;
    cout << "\t\t\t Enter the password : ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserId << ' ' << rpassword << endl;
    system("cls");
    cout << "\n\t\t\t Registration is successful! \n";
    main();
}

void forgot()
{
    int option;
    system("cls");
    cout << "\t\t\t You forgot the password? Don't take tension \n";
    cout << "Press 1 to search your id by username" << endl;
    cout << "Press 2 to go back to the main menu" << endl;
    cout << "\t\t\t Enter your choice :";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserId, sId, spass;
        cout << "\n\t\t\t Enter the username you remembered :";
        cin >> suserId;

        ifstream f2("records.txt");
        while (f2 >> sId >> spass)
        {
            if (sId == suserId)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "\n\n\n Your account is Found!";
            cout << "\n\n\n Your password is " << spass << endl;
            main();
        }
        else
        {
            cout << "\n\t Sorry! Your account is not found! \n";
            main();
        }
        break;
    }
    case 2:
    {
        main();
    }
    default:
        cout << "\t\t\t Wrong choice! please try again" << endl;
        forgot();
    }
}
