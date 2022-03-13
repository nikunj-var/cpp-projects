  
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<conio.h>
using namespace std;

class student{

char s_name[30];
int age;
char f_name[30];
char m_name[30];
char address[100];
char date_of_birth[30];
char email[30];
char course[30];
int serialno=0;
public:
    void setdata(){
    cout<<"serail no of the student is"<<serialno++;    
    cout<<"ENTER NAME OF STUDENT"<<endl;  
    cin.ignore();
    cin.getline(s_name,30);
    
    cout<<"ENTER MOTHER'S NAME OF THE STUDENT"<<endl;
   
    cin.getline(m_name,30);
  
    cout<<"ENTER FATHER'S NAME OF THE STUDENT"<<endl;
   
    cin.getline(f_name,30);
    
    cout<<"ENTER DATE OF BIRTH"<<endl;
    cin.getline(date_of_birth,30);
    
    
    cout<<"ENTER AGE"<<endl;
    cin>>age;
    
    cout<<"ENTER ADDRESS :"<<endl;
    cin.ignore();
    cin.getline(address,100);
   
    cout<<"ENTER COURSE ENROLLED BY THE STUDENT"<<endl;
    cin.getline(course,30);
    
    cout<<"ENTER MAIL ID OF THE STUDENT"<<endl;
    cin.getline(email,30);
    }
    
    void show(){
        cout<<endl<<endl;
        cout<<"..........STUDENT DETAILS.........."<<endl<<endl;
        cout<<"NAME                           :"<<s_name<<endl;
        cout<<"MOTHER'S NAME                  :"<<m_name<<endl;
        cout<<"FATHER'S NAME                  :"<<f_name<<endl;
        cout<<"DATE OF BIRTH                  :"<<date_of_birth<<endl;
        cout<<"AGE                            :"<<age<<endl;
        cout<<"ADDRESS                        :"<<address<<endl;
        cout<<"COURSE ENROLLLED               :"<<course<<endl;
        cout<<"MAIL ID                        :"<<email<<endl;
    }
    int getno(){
        return serialno;
    }
}stu;
void adddetails(){
    fstream f;
    f.open("student.txt",ios::binary|ios::out|ios::app);
    if(!f){
        cout<<"FILE IS NOT OPEN";
        return;
    }
    else{
        stu.setdata();
        f.write((char*)&stu,sizeof(stu));
    }
    f.close();
    cout<<endl<<endl;
    cout<<"............DATA ADDED SUCCESSFULLY............";
}
void showdetails(){


   fstream f;
   f.open("student.txt",ios::in);
   while( f.read((char *)&stu,sizeof(stu))){
      
       stu.show();
   }
   f.close();
   cout<<endl<<endl;
   cout<<"........ DATA READED SUCCESSFULLY...........";
}
/*void searchdetails(){
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
        cout<<"SERIAL NO DOES'NT FOUND!";
    }
    if(n==1){
    cout<<"details searched";
    }
}*/
void updatedetails(){
    cout<<"details update";
}
void deletedetails(){
    cout<<"details deleted";    
}
void mainmenu(){
    system("cls");
    int ch;
    do{
  
    cout<<endl<<endl;
    cout<<"\t\t\t\tMAIN MENU";
    cout<<endl<<endl;
    cout<<"PRESS 1 TO ADD DETAILS";
    cout<<"\n\nPRESS 2 TO SHOW DETAILS";
    cout<<"\n\nPRESS 3 TO SEARCH DETAILS";
    cout<<"\n\nPRESS 4 TO UPDATE DETAILS";
    cout<<"\n\nPRESS 5 TO DELETE DETAILS";
    cout<<"\n\nPRESS 6 TO EXIT";
    cout<<"\n\nENTER CHOICE";
    cin>>ch;
    switch(ch){
        case 1:adddetails();
                break;
        case 2:showdetails();
                break;
        /*case 3:searchdetails();
                break;*/
        case 4:updatedetails();
                break;
        case 5:deletedetails();
                break;
        
        default:cout<<"WRONG CHOICE";                                 
    }  
    }while(ch!=6);
    system("pause");
}
int main(){
    cout<<".....STUDENT MANAGEMENT SYSTEM.....";
    mainmenu();
}