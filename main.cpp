#include <iostream>
#include<fstream>
#include<string.h>
#include<cstdlib>

using namespace std;
void login();
void  registration();
void forgot();

int main()
{
    int c;
    cout<<" \t\t\t_______________________________________\n\n\n";
    cout<<"\t\t\t      Welcome to the Login page       \n\n\n";
     cout<<"\t\t\t_______________MENU___________________\n\n\n";
    cout<<" \t\t                                             \n\n";
    cout<<"\t|Press 1 to LOGIN                                |"<<endl;
    cout<<"\t|Press 2 to REGISTER                             |"<<endl;
    cout<<"\t|Press 3 to if you forget your PASSWORD          |"<<endl;
    cout<<"\t|Press 4 to EXIT                                 |"<<endl;
    cout<<"\n\t\t\tPlease enter your choice :";
    cin>>c;
    cout<<endl;

    switch(c)
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
            cout<<"\n\t\t Thank you!\n\n";
            break;
    default:
            system("cls");
            cout<<"\n\t\t Please select from the given option above \n\n";
            main();
    }
}
void login()
{
    int count;
    string userId,password,id,pass;
    system("cls");
    cout<<"/t/t/t Please Enter the user name and password :"<<endl;
    cout<<"/t/t/t USERNAME ";
    cin>>userId;
    cout<<"/t/t/t Password";
    cin>>password;

    ifstream input("record.txt");
    while(input>>id>>pass)
    {

        if(id==userId&&pass==password)
        {
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count==1)
    {
        cout<<userId<<"\n Your Login is successfull \n Thanks for logging in:\n";
        main();

    }
    else
    {
       cout<<"\n  Login error \n Please check your user name and password\n";
        main();
    }

}
void registration()
{
    string ruserId,rpassword,rid,rpass;
    system("cls");
     cout<<"/t/t/t Enter USERNAME ";
    cin>>ruserId;
    cout<<"/t/t/t Enter Password";
    cin>>rpassword;

    ofstream f1("record.txt",ios::app);
    f1<<ruserId<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\t\t\t Registration is suceessfull:\n";
    main();
}
void forgot()
{
    int option;
    system("cls");
    cout<<"\n\t\t\t You forgot the password? No worries \n";
    cout<<"Press 1 to search your id by username "<<endl;
    cout<<"Press 2 to go back to the main menu"<<endl;
    cout<<"\t\tt\ Enter your choice:";
    cin>>option;
    switch(option)
    {

    case 1:
        {
          int count=0;
          string suserid,sId,spass;
          cout<<"Enter the username which you remembered :";
          cin>>suserid;

          ifstream f2("record.txt");
          while(f2>>sId>>spass)
          {
            if(sId==suserid)
            {
                count=1;
            }
          }
          f2.close();
          if(count==1)
          {
            cout<<"\nYour account is found!\n";
            cout<<"\n Your password is :"<<spass;
            main();
          }
          else
          {
              cout<<"\n\t Sorry!your account is not found \n";
              main();
          }
          break;
        }
    case 2:
        {
        main();
        }
    default:
        cout<<"\t\t\t Wrong choice :Please try again:"<<endl;
        forgot();
    }
}

