#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string userName,Email,password;
    string searchName,searchPass,searchEmail;
    fstream file;
    public:
    void login();
    void signUp();
    void forgot();
}obj;

int main(){
char choice;
cout<<"\n1- Login";
cout<<"\n2- Sign Up";
cout<<"\n3- Forgot Password";
cout<<"\n4- Exit";
cout<<"\n Enter Your Choice :: ";
cin>>choice;

switch(choice){
    case '1':
    obj.login();
    break;
     case '2':
    obj.signUp();
    break;
     case '3':
    obj.forgot();
    break;
     case '4':
    return 0;
    break;
    default:
          cout<<"Invalid Selection";
    }
}

void temp :: signUp(){
    cout<<"\n Enter Your User Name :: ";
    getline(cin,userName);

    cout<<"\n Enter your Email Address :: ";
    getline(cin,Email);

    cout<<"\n Enter Your Password :: ";
    getline(cin,password);

    file.open("loginData.txt",ios :: out | ios :: app);
    file<<userName<<"*"<<Email<<"*"<<password<<endl;
    file.close();

}

void temp :: login(){
   

    cout<<"-------------LOGIN---------------";

    cout<<"Enter Your UserName :: "<<endl;
    getline(cin,searchName);

    cout<<"Enter Your Password :: "<<endl;
    getline(cin,searchPass);

    file.open("loginData.txt",ios :: in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    while(!file.eof()){
        if(userName == searchName){
            if(password == searchPass){
                cout<<"\n Account Login Successful.. !";
                cout<<"\n Username :: " << userName << endl;
                cout<<"\n Email :: " << Email << endl;
            }
            else{
                cout<<"Password is Incorrect...!";
            }
        }
        getline(file,userName,'*');
        getline(file,Email,'*');
        getline(file,password,'\n');
    }
    file.close();
}
void temp :: forgot(){


    cout<<"\n Enter Your Username ::";
    getline(cin,searchName);

    cout<<"\n Enter Your Email Address :: ";
    getline(cin,searchEmail);

    file.open("loginData.txt",ios :: in);
     getline(file,userName,'*');
     getline(file,Email,'*');
     getline(file,password,'\n');

     while(!file.eof()){
        if(userName == searchName){
            if(Email == searchEmail){
                cout<<"\n Account Found !";
                cout<<"your password :: "<<password<<endl;
            }
            else{
                cout<<"Not Found !\n";
            }
        }
        else{
            cout<<"Not Found !";
        }
     }
     file.close();
}