#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class student
{
    int adno;
    char sname[30];
    char gender;
    int standard;
    char sec;
    float marks;
    float perc;
    char fname[30];
    char mname[30];
    char dob[10];

public:
    void setdata()
    {
        cout << endl
             << endl
             << "/**********ENTER STUDENT DETAIL**********/" << endl
             << "Enter Admission No :";
        cin >> adno;
        cout << "Enter Student Name :";
        cin.ignore();
        cin.getline(sname, 30);
        cout << "Enter Father Name :";
        cin.getline(fname, 30);
        cout << "Enter Mother Name :";
        cin.getline(mname, 30);
        cout << "Enter Date of Birth (dd/mm/yyyy):";
        cin >> dob;
        cout << "Enter Student gender(M or F) :";
        cin >> gender;
        cout << "Enter Standard :";
        cin >> standard;
        cout << "Enter Section :";
        cin >> sec;
        cout << "Enter marks out of 500 :";
        cin >> marks;
        perc = (marks*100.0)/500.0;
        cout << endl;
    }
    void show()
    {
        cout << endl
             << endl
             << "........STUDENT DETAILS........" << endl
             << "Admission No            : " << adno << endl
             << "Student Name            : " << sname << endl
             << "Father Name             : " << fname << endl
             << "Mother Name             : " << mname << endl
             << "Date of birth           : " << dob << endl
             << "Gender                  : " << gender << endl
             << "Standard                : " << standard << endl
             << "Section                 : " << sec << endl
             << "Marks obtain out of 500 : " << marks << endl
             << "Percentage :" << perc << "%" << endl;
    }
    int getno()
    {
        return adno;
    }
} s;
class teacher
{
    int tid;
    char tname[30];
    char gender;
    char subject[30];
    long int salary;

public:
    void setdata()
    {
        cout << endl
             << endl
             << "/**********ENTER TEACHER DETAIL**********/" << endl
             << "Enter Teacher id :";
        cin >> tid;
        cout << "Enter Teacher Name :";
        cin.ignore();
        cin.getline(tname, 30);
        cout << "Enter Teacher gender(M or F) :";
        cin >> gender;
        cout << "Enter The Subject Teacher Teach :";
        cin.ignore();
        cin.getline(subject, 30);
        cout << "Enter The Teacher salary :";
        cin >> salary;
        cout << endl;
    }
    void show()
    {
        cout << endl
             << endl
             << "........Teacher DETAILS........" << endl
             << "Teacher id            : " << tid << endl
             << "Teacher Name          : " << tname << endl
             << "Gender                : " << gender << endl
             << "Subject               : " << subject << endl
             << "Salary                : " << salary << endl;
    }
    int getid()
    {
        return tid;
    }
} t;
void addstudent()
{
    fstream file;
    file.open("Student.txt", ios::binary | ios::out | ios::app);
    if (!file)
    {
        cout << "The file is not open" << endl;
        return;
    }
    else
    {
        s.setdata();
        file.write((char *)&s, sizeof(s));
    }
    file.close();
    cout << endl
         << endl;
    cout << "........DATA ADDED SUCCESSFULLY........" << endl;
}
void addteacher()
{
    fstream file;
    file.open("Teacher.txt", ios::binary | ios::out | ios::app);

    t.setdata();
    file.write((char *)&t, sizeof(t));

    file.close();
    cout << endl
         << endl;
    cout << "........DATA ADDED SUCCESSFULLY........" << endl;
}
void displaystudent()
{
    fstream file;
    file.open("Student.txt", ios::in);
    while (file.read((char *)&s, sizeof(s)))
    {
        s.show();
    }
    file.close();
    cout << endl
         << endl
         << ".........READING DATA SUCESSFULLY........" << endl;
}
void displayteacher()
{
    fstream file;
    file.open("Teacher.txt", ios::in);
    while (file.read((char *)&t, sizeof(t)))
    {
        t.show();
    }
    file.close();
    cout << endl
         << endl
         << ".........READING DATA SUCESSFULLY........" << endl;
}
void searchstudent()
{
    int n, flag = 0;
    cout << "..........SEARCHING FOR STUDENT.........."<<endl;
    cout << "Enter the Admission no to be searched" << endl;
    cin >> n;
    fstream file;
    file.open("Student.txt", ios::in | ios::binary);
    while (file.read((char *)&s, sizeof(s)))
    {
        if (n == s.getno())
        {
            cout << "The details of the Student : " << endl;
            s.show();
            flag++;
        }
    }
    file.close();
    if (flag == 0)
        cout << "The admission no is not found" << endl;
}
void searchteacher()
{
    int n, flag = 0;
    cout << "..........SEARCHING FOR TEACHER.........."<<endl;
    cout << "Enter the Teacher id to be searched" << endl;
    cin >> n;
    fstream file;
    file.open("Teacher.txt", ios::in | ios::binary);
    while (file.read((char *)&t, sizeof(t)))
    {
        if (n == t.getid())
        {
            cout << "The details of the Teacher : " << endl;
            t.show();
            flag++;
        }
    }
    file.close();
    if (flag == 0)
        cout << "The Teacher id  is not found" << endl;
}
void deletestudent()
{
    int n, flag = 0;
    cout << "..........DELETE STUDENT RECORD.........." << endl
         << endl;
    cout << "Enter The Admission no to delete :";
    cin >> n;
    fstream file, file1, file2;
    file.open("Student.txt", ios::in | ios::binary);
    file1.open("Student1.txt", ios::out | ios::app | ios::binary);
    file2.open("Student2.txt", ios::out | ios::binary);
    while (file.read((char *)&s, sizeof(s)))
    {
        if (n == s.getno())
        {
            cout << "The Student Record at Admission no " << n << " is deleted" << endl;
            file2.write((char *)&s, sizeof(s));
            flag++;
        }
        else
        {
            file1.write((char *)&s, sizeof(s));
        }
    }
    file.close();
    file1.close();
    file2.close();
    if (flag == 0)
        cout << "The record is not found";
    remove("Student.txt");
    remove("Student2.txt");
    rename("Student1.txt", "Student.txt");
}
void deleteteacher()
{

    int n, flag = 0;
    cout << "..........DELETE TEACHER RECORD.........." << endl
         << endl;
    cout << "Enter Teacher id to delete :";
    cin >> n;
    fstream file, file1, file2;
    file.open("Teacher.txt", ios::in | ios::binary);
    file1.open("Teacher1.txt", ios::out | ios::app | ios::binary);
    file2.open("Teacher2.txt", ios::out | ios::binary);
    while (file.read((char *)&t, sizeof(t)))
    {
        if (n == t.getid())
        {
            cout << "The Teacher Record at Teacher id " << n << " is deleted" << endl;
            file2.write((char *)&t, sizeof(t));
            flag++;
        }
        else
        {
            file1.write((char *)&t, sizeof(t));
        }
    }
    file.close();
    file1.close();
    file2.close();
    if (flag == 0)
        cout << "The record is not found";
    remove("Teacher.txt");
    remove("Teacher2.txt");
    rename("Teacher1.txt", "Teacher.txt");
}
void updatestudent()
{
    int n,flag = 0;
    int pos;
    fstream file;
    file.open("Student.txt",ios::in|ios::out|ios::binary);
    cout << "..........UPDATE STUDENT RECORD.........." << endl
         << endl;
    cout << "Enter Student Admission no to update :";
    cin >> n;
    while(file.read((char*)&s,sizeof(s)))
    {
        if(n == s.getno())
        {
            pos = file.tellg();
            cout<<"The Student Record at Admission no "<<n<<" is ready to update"<<endl;
            s.setdata();
            file.seekg(pos-sizeof(s));
            file.write((char*)&s,sizeof(s));
            flag++;
        }
    }
    file.close();
    if(flag == 0) cout<<"the record is not found"<<endl;

}
void updateteacher() {
     int n,flag = 0;
    int pos;
    fstream file;
    file.open("Teacher.txt",ios::in|ios::out|ios::binary);
    cout << "..........UPDATE TEACHER RECORD.........." << endl
         << endl;
    cout << "Enter Teacher id to update :";
    cin >> n;
    while(file.read((char*)&t,sizeof(t)))
    {
        if(n == t.getid())
        {
            pos = file.tellg();
            cout<<"The Student Record at Teacher id "<<n<<" is ready to update"<<endl;
            t.setdata();
            file.seekg(pos-sizeof(t));
            file.write((char*)&t,sizeof(t));
            flag++;
        }
    }
    file.close();
    if(flag == 0) cout<<"the record is not found"<<endl;

}
void studentpanel()
{
    int n;
    do
    {

        system("cls");
        cout << "...............STUDENT MANAGEMENT SYSTEM..............\n";
        cout << "======================================================\n";
        cout << "0. Exit from Program\n";
        cout << "1. Add Data to Record\n";
        cout << "2. Display Data From Record\n";
        cout << "3. Search Data From Record\n";
        cout << "4. Delete Data From Record\n";
        cout << "5. Modify Data in Record\n";
        cout << "Enter your choice  : ";
        cin >> n;
        system("cls");
        switch (n)
        {
        case 1:
            addstudent();
            break;
        case 2:
            displaystudent();
            break;
        case 3:
            searchstudent();
            break;
        case 4:
            deletestudent();
            break;
        case 5:
            updatestudent();
            break;
        }
        system("pause");

    } while (n);
}
void teacherpanel()
{
    int n;
    do
    {

        system("cls");
        cout << "...............TEACHER MANAGEMENT SYSTEM..............\n";
        cout << "======================================================\n";
        cout << "0. Exit from Program\n";
        cout << "1. Add Data to Record\n";
        cout << "2. Display Data From Record\n";
        cout << "3. Search Data From Record\n";
        cout << "4. Delete Data From Record\n";
        cout << "5. Modify Data in Record\n";
        cout << "Enter your choice  : ";
        cin >> n;
        system("cls");
        switch (n)
        {
        case 1:
            addteacher();
            break;
        case 2:
            displayteacher();
            break;
        case 3:
            searchteacher();
            break;
        case 4:
            deleteteacher();
            break;
        case 5:
            updateteacher();
            break;
        }
        system("pause");

    } while (n);
}
int main()
{
    int n;
    do
    {
        system("cls");
        cout << "....................WELCOME TO SCHOOL MANGEMENT SYSTEM...................." << endl;
        cout << "==========================================================================" << endl
             << endl;
        cout << "0. Exit the system\n"
             << "1. Student Management System\n"
             << "2. Teacher Management System\n"
             << endl
             << "Enter your choice....:";
        cin >> n;
        switch (n)
        {
        case 1:
            studentpanel();
            break;
        case 2:
            teacherpanel();
            break;
        }
    } while (n);
    return 0;
}
