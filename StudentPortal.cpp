#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<string>

using namespace std;



class student
{
    public:
    string name,enrollment,fname,mobile,address;
};

bool check( string user)
{
    ifstream in;
    in.open("/Users/princeraj/Desktop/Projects/complete/SD/StudentRecord"+user+".txt");
    string un;
    in>>un;
    if(user==un)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool verify(string us,string pw)
{
    string user,pass;
    ifstream read("/Users/princeraj/Desktop/Projects/complete/SD/StudentRecord"+us+".txt");
    read>>user;
    read>>pass;
    if(user==us && pw==pass) return true;
    else return false;

}

int main()
{
    system("color B5");

    //clear screen
    clrscr();

    cout<<endl<<"*** Welcome ***"<<endl<<endl;
    cout<<endl<<endl;
    cout<<"MAIN MENU"<<endl<<endl;
    cout<<"1. Registration"<<endl;
    cout<<"2. Login"<<endl;
    cout<<"0. Exit"<<endl<<endl;
    cout<<"Choose option : ";
    int choose; cin>>choose;

    //clear screen
    clrscr();

    string username,password;
    s11 : if(choose == 1)
    {
        cout<<endl<<"Choose your username : ";
        cin>>username;
        
        bool status = check(username);
        if(status == true)
        {

            cout<<endl<<username+" ❗️ "<<endl;

            //clear screen
            clrscr();

            cout<<endl<<"Username already taken ❗️"<<endl;
            cout<<"Choose different username"<<endl;
            goto s11;
        }
        else 
        {
            cout<<endl<<username+" ✅ "<<endl<<endl;
            s12 : cout<<"Choose your new password : ";
            cin>>password;
            cout<<"Enter your password again : ";
            string pwd;
            cin>>pwd;
            if(password == pwd)
            {
                cout<<"Password Saved successfully ✅"<<endl<<endl;

                //clear screen
                clrscr();
            }
            else
            {
                //clear screen
                clrscr();

                cout<<endl<<"Password do not match ❗️"<<endl<<endl;
                goto s12;
            }
            student s;
            cin.ignore();
            ofstream write("/Users/princeraj/Desktop/Projects/complete/SD/StudentRecord"+username+".txt");
            write<<username<<" "<<password<<endl<<endl;
            write<<endl<<"STUDENT DETAILS"<<endl<<endl;

            cout<<"Enter your name : ";
            getline(cin, s.name);
            write<<"Name : "<<s.name<<endl;

            cout<<"Enter your Enrollment No : ";
            getline(cin, s.enrollment);
            write<<"Enrollment No : "<<s.enrollment<<endl;

            cout<<"Enter your Father's name : ";
            getline(cin, s.fname);
            write<<"Father's Name : "<<s.fname<<endl;

            cout<<"Enter your Mobile No : ";
            getline(cin, s.mobile);
            write<<"Mobile no : "<<s.mobile<<endl;

            cout<<"Enter your Address : ";
            getline(cin, s.address);
            write<<"Address : "<<s.address<<endl;

            //clear screen
            clrscr();

            cout<<endl<<"Registration Successfully ✅"<<endl;
            cout<<endl<<"Thank You"<<endl<<endl;
            s13 : cout<<"1. Main Menu"<<endl;
            cout<<"0. exit"<<endl;
            cout<<endl<<"Choose your option : ";

            int choose1; cin>>choose1;
            switch(choose1)
            {
                case 1:
                main();
                break;

                case 0:
                goto exit;
                break;

                default :
                cout<<endl<<"Invalid Option ⚠️"<<endl;
                goto s13;
                break;
            }
        }
    }
    else if (choose == 2)
    {
        s21 : cout<<endl<<"Enter your username : ";
        cin>>username;
        cout<<"\nEnter your password : ";
        cin>>password;
        bool status = check(username);
        if(status == true)
        {
            cout<<username+" ✅ "<<endl<<endl;  
            bool status1 = verify(username,password);
            if(status1 == true)
            {  
                 //clear screen 
                clrscr();
                cout<<"Login Successfully"<<endl;
                goto s23;
            }
            else 
            {
                //clear screen 
                clrscr();

                cout<<endl<<"password are incorrect ❌"<<endl;
                cout<<endl<<"----Try again----"<<endl;
                goto s21;
            }
        }
        else
        {
            //clear screen 
            clrscr();

            cout<<endl<<username+" not found ❗️ "<<endl;
            cout<<endl<<"Try again"<<endl;
            goto s21;
        }
            
        
           s23: cout<<endl<<"1. Profile"<<endl;
            cout<<"2. Log Out"<<endl;
            cout<<"0. Exit"<<endl;
            cout<<endl<<"Choose your option : "<<endl;
            int choose21; cin>>choose21;
           
                //clear screen 
                clrscr();
            if(choose21==1)
            {
                ifstream read("/Users/princeraj/Desktop/Projects/complete/SD/StudentRecord"+username+".txt");
                string str1;
                getline(read,str1);
                while(read.eof()==0)
                {
                    string str;
                    getline(read,str);
                    cout<<str<<endl;
                }
                cout<<endl<<"Your Information"<<endl<<endl;
                s22 : cout<<"1. Log Out"<<endl;
                cout<<"0. Exit"<<endl;
                cout<<endl<<"Choose your option : "<<endl;
                int choose22; cin>>choose22;
                
                //clear screen 
                clrscr();
                switch(choose22)
                {
                    case 1:
                    cout<<endl<<"Logged out Successfully"<<endl;
                    main();
                    break;
                    case 0:
                    goto exit;
                    default :
                    cout<<endl<<"Invalid Option ⚠️"<<endl;
                    goto s22;
                    break;
                }
            }
            else if(choose21 == 2)
            {
                cout<<endl<<"Logged out Successfully"<<endl;
                main();
            }
            else if(choose21 == 0)
            {
                goto exit;
            }
        
        
    }
    else if(choose == 0)
    
        goto exit;
    
    else 
    {
        //clear screen 
        clrscr();
        cout<<endl<<"Invalid Option ⚠️"<<endl;
        cout<<endl<<"Try Again"<<endl;
        main();
    }



    exit: cout<<"-------Program closed-------";
    return 0;
}