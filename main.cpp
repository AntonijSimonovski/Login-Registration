#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

string registration(string username, string password);
bool checkCredentials(string uspass);

int main(int argc, const char * argv[]) {

    string username;
    string password;
    string uspass;
    cout<<"If you already have an account please log in, otherwiser type r instead of username to register\n";
    do{
    cout<<"Username: ";
    cin>> username;
    if(username == "r") uspass = registration(username, password);
    else{
        cout<<"Password: ";
        cin>> password;
        uspass = username.append(password);//username and password combined in 1 string
    }
       if (checkCredentials(uspass))
           cout << "Login successful!\n";
       else
           cout << "Login failed, please try again\n";
    }while(!checkCredentials(uspass));
    return 0;
}//end main

string registration(string username, string password)
{
    ofstream loginFile("loginCredentials.txt", ios::app);
    cout<<"Create username: ";
    cin>>username;
    loginFile<<endl;
    loginFile<<username;
    cout<<"Create password: ";
    cin>>password;
    while(password.length() < 7)
    {
        cout << "Please enter a password with 7 characters or more: ";
        cin>>password;
    }
    loginFile<<password;
    loginFile.close();
    return username.append(password);
}//end registration

bool checkCredentials(string uspass)
{
    fstream loginFile("loginCredentials.txt");
    string line;
    while(getline(loginFile, line)) if(line == uspass)
    {
        loginFile.close();
        return true;
    }
    return false;
    
}// end checkCredentials
