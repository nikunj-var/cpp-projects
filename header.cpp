#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

class student
{

    char s_name[30];
    int age;
    char f_name[30];
    char m_name[30];
    char address[100];
    char date_of_birth[30];
    char email[30];
    char course[30];
    int admno;

public:
        
    void setdata()
    {
        cout << "ENTER ADMISSION NUMBER OF THE STUDENT " ; 
        cin>>admno;
        
        cout << "ENTER NAME OF STUDENT" << endl;
        cin.ignore();
        cin.getline(s_name, 30);

        cout << "ENTER MOTHER'S NAME OF THE STUDENT" << endl;

        cin.getline(m_name, 30);

        cout << "ENTER FATHER'S NAME OF THE STUDENT" << endl;

        cin.getline(f_name, 30);

        cout << "ENTER ADDRESS :" << endl;
        cin.getline(address, 100);

        cout << "ENTER COURSE ENROLLED BY THE STUDENT" << endl;
        cin.getline(course, 30);
        cout << "ENTER DATE OF BIRTH" << endl;
        cin >> date_of_birth;

        cout << "ENTER MAIL ID OF THE STUDENT" << endl;
        cin >> email;

        cout << "ENTER AGE" << endl;
        cin >> age;
    }

    void show()
    {
        cout << endl
             << endl;
        cout << "..........STUDENT DETAILS.........." << endl
             << endl;
        cout << "ADMISSION NUMBER               :" << admno<<endl;     
        cout << "NAME                           :" << s_name << endl;
        cout << "MOTHER'S NAME                  :" << m_name << endl;
        cout << "FATHER'S NAME                  :" << f_name << endl;
        cout << "DATE OF BIRTH                  :" << date_of_birth << endl;
        cout << "AGE                            :" << age << endl;
        cout << "ADDRESS                        :" << address << endl;
        cout << "COURSE ENROLLLED               :" << course << endl;
        cout << "MAIL ID                        :" << email << endl;
    }
    int getno()
    {
        return admno;
    }
} stu;
void adddetails()
{
    fstream f;
    f.open("student.txt", ios::out | ios::app);
    if (!f)
    {
        cout << "FILE IS NOT OPEN";
        return;
    }
    else
    {
        stu.setdata();
        f.write((char *)&stu, sizeof(stu));
    }
    f.close();
    cout << endl
         << endl;
    cout << "............DATA ADDED SUCCESSFULLY............";
}
void showdetails()
{
    fstream f;
    f.open("student.txt", ios::in);
    while (f.read((char *)&stu, sizeof(stu)))
    {

        stu.show();
    }
    f.close();
    cout << endl
         << endl;
    cout << "........ DATA READED SUCCESSFULLY...........";
}
void searchdetails(){
    int n,flag=0;
    cout<<"..........SEARCHING FOR DETAILS.....";
    cout<<endl<<endl;
    cout<<"ENTER THE SERIAL NO OF THE STUDENT TO BE SEARCHED";
    cin>>n;
    fstream f;
    f.open("student.txt",ios::in|ios::binary);
    while(f.read((char*)&stu,sizeof(stu))){
        if(n==stu.getno()){
                cout<<"DETAILS OF THE STUDENT";
                stu.show();
                flag++;
        }
    }
    f.close();
    if(flag==0){
        cout<<"ADMISSION NO DOES'NT FOUND!"<<endl;
    }
    if(flag==1){
    cout<<".....details searched......";
    }
}
void updatedetails()
{
    int n,flag=0;
    int pos;
    fstream f;
    f.open("student.txt",ios::in|ios::out|ios::binary);
    cout<<"......UPDATE STUDENT RECORD......"<<endl<<endl;
    cout<<"ENTER STUDENT SERIAL NO...";
    cin>>n;
    while(f.read((char*)&stu,sizeof(stu))){
        if(n==stu.getno()){
                pos=f.tellg();
                cout<<"STUDENT RECORD AT SERIAL NO"<<n<<" IS READY TO UPDATE"<<endl;
                stu.setdata();
                f.seekg(pos-sizeof(stu));
                f.write((char*)&stu,sizeof(stu));
                flag++;
        }
    }
    f.close();
    if(flag==0){
        cout<<"STUDENT RECORD NOT FOUND.."<<endl;
    }
    if(flag==1){
        cout<<"....RECORD UPDATED SUCCESSFULLY"<<endl<<endl;
    }
}
void deletedetails()
{


    int n,flag=0;
    cout<<"................DELETE STUDENT RECOED.......... ";
    cout<<endl<<endl;
    
    
    
    cout<<"ENTER THE SERIAL NO OF THE STUDENT..";
    cin>>n;
    fstream f,f1,f2;
    f.open("student.txt",ios::in|ios::out|ios::binary);
    f1.open("student1.txt",ios::app|ios::out|ios::binary);
    f2.open("student2.txt",ios::out|ios::binary);
    while(f.read((char*)&stu,sizeof(stu))){
        if(n==stu.getno()){
                cout<<"THE STUDENT RECORD OF SERIAL NO "<<n<<" IS DELETED"<<endl;
                f2.write((char*)&stu,sizeof(stu));
                flag++;

        }
        else{
            f1.write((char*)&stu,sizeof(stu));
        }
    }
    f.close();
    f1.close();
    f2.close();
    if(flag==0){
        cout<<"RECORD NOT FOUND";
    }
    remove("student.txt");
    remove("student2.txt");
    rename("student1.txt","student.txt");
}
void mainmenu()
{
    system("cls");
    int ch;
    do
    {

        cout << endl
             << endl;
        cout << "\t\t\t\tMAIN MENU";
        cout << endl
             << endl;
        cout << "PRESS 1 TO ADD DETAILS";
        cout << "\n\nPRESS 2 TO SHOW DETAILS";
        cout << "\n\nPRESS 3 TO SEARCH DETAILS";
        cout << "\n\nPRESS 4 TO UPDATE DETAILS";
        cout << "\n\nPRESS 5 TO DELETE DETAILS";
        cout << "\n\nPRESS 6 TO EXIT";
        cout << "\n\nENTER CHOICE : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            adddetails();
            break;
        case 2:
            showdetails();
            break;
        case 3:
            searchdetails();
                break;
        case 4:
            updatedetails();
            break;
        case 5:
            deletedetails();
            break;
        case 6: 
            cout<<"EXIT SUCCESSFULLY";
            exit(0);    
        default:
            cout << "WRONG CHOICE";
        }
    } while (ch != 6);
    system("pause");
}
int main()
{
    cout << ".....STUDENT MANAGEMENT SYSTEM.....";
    mainmenu();
}