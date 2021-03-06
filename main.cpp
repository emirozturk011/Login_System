#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool isLoggedIn() {
    string username, password, un, pw;
    cout << "Enter username:";
    cin >> username;
    cout << "Enter password:";
    cin >> password;
    ifstream read( username + ".txt");
    getline(read, un);
    getline(read, pw);
    if (un == username && pw == password) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int choice;
    string username;
    string password;

    cout<<"1.Registration\n2.Login\nSelect your choice:";cin>>choice;
    if(choice==1){
        cout<<"username:";cin>>username;
        cout<<"password:";cin>>password;
        ofstream file;
        file.open(username+".txt");
        file << username << endl << password;
        file.close();
        cout<<"You registered successfully"<<endl;
        main();
    }
    else if(choice==2){
        bool stat=isLoggedIn();
        if(!stat){
            cout<<"wrong username or password."<<endl;
            system("PAUSE");
            return 0;
        }
        else{
            cout<<"You logged in successfully"<<endl;
            system("PAUSE");
            return 1;
        }
    }
    return 0;
}


