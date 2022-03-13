#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<stdlib.h>
#include<chrono>
#include<thread>
using namespace std;
void mainmenu();
void addmedicine();
void searchmedicine();
void medicinedetails();
class medicine{
    char medname[20];
    float price;   
    char comname[20];
    char mfgdate[20];
    char expdate[20];
    char review[30];
    int itemcode;
public:
 int avail_quant;
    void setdata(){
        cout<<endl<<"ENTER ITEM_CODE OF THE MEDICINE...";
        cin>>itemcode;
        cout<<endl<<"ENTER NAME OF THE MEDICINE...";
        cin>>medname;
        cout<<endl<<"ENTER COMPANY NAME OF THE MEDICINE...";
        cin>>comname;
        cout<<endl<<"ENTER PRICE OF THE MEDICINE...";
        cin>>price;
        cout<<endl<<"ENTER MANUFACTURING DATE...";
        cin>>mfgdate;
        cout<<endl<<"ENTER EXPIRY DATE...";
        cin>>expdate;
        cout<<endl<<"ENTER AVAILABLE QUANTITY...";
        cin>>avail_quant;
        cout<<endl<<"ENTER REVIEW OR INFO OF THE MEDICINE...";
        cin.ignore();
        cin.getline(review,30);
    }
    void show(){
        cout<<".........MEDICINE DETAILS........"<<endl<<endl;
        cout<<"ITEM CODE OF THE MEDICINE....               "<<itemcode   <<endl;
        cout<<"NAME OF THE MEDICINE....                    "<<medname    <<endl;
        cout<<"COMPANY NAME OF THE MEDICINE....            "<< comname   <<endl;
        cout<<"PRICE OF THE MEDICINE....                   "<<  price  <<endl;
        cout<<"MANUFACTURING DATE....                      "<< mfgdate   <<endl;
        cout<<"EXPIRY DATE....                             "<<  expdate  <<endl;
        cout<<"AVAILABLE QUANTITY....                      "<<   avail_quant <<endl;
        cout<<"REVIEW 0R INFO OF THE MEDICINE....          "<< review   <<endl;
    }
    int getno(){
        return itemcode;
    }
    int quan(){
        return avail_quant;
    }
    void newqua(){
        avail_quant=0;
    }
    int upaq(){
        return avail_quant;
    }
    float medpri(){
        return  price;
    }
    char* getname(){
        return medname;
    }
}med;
class company{
    int c_id;
    char cname[30];
    char address[50];
    char license;
    char man_name[20];
    char dir_name[20];
    int noworker;
public:
    void comdata(){
        cout<<"...............ENTER COMPANY DETAILS.............."<<endl;        
        cout<<endl<<"ENTER COMPANY ID...";
        cin>>c_id;
        cout<<endl<<"ENTER NAME OF THE COMPANY...";
        cin.ignore();
        cin.getline(cname,30);
        cout<<endl<<"ENTER ADDRESS OF THE COMPANY..."<<endl;
        cin.getline(address,50);
        cout<<endl<<"ENTER MANAGER NAME...";
        cin.getline(man_name,20);
        cout<<endl<<"ENTER DIRECTOR NAME...";
        cin.getline(dir_name,20);
        cout<<endl<<"ENTER NO. OF WORKER IN THE COMPANY...";
        cin>>noworker;
        cout<<endl<<"IS COMPANY LICENSED OR NOT(Y/N)...";
        cin>>license;
    } 
    void showdata(){
        cout<<endl<<endl<<".......COMPANY DETAILS......."<<endl;
        cout<<" COMPANY ID OF THE COMP........"<<c_id<<endl;
        cout<<" NAME OF THE COMPANY..........."<<cname<<endl;
        cout<<" ADDRESS OF THE COMPANY........"<<address<<endl;
        cout<<" MANAGER OF THE COMPANY........"<<man_name<<endl;
        cout<<" DIRECTOR OF THE COMPANY......."<<dir_name<<endl;
        cout<<" NO. OF WORKER IN THE COM......"<<noworker<<endl;
        cout<<" IS COMPANY LICENSED..........."<<license<<endl;
    }   
    int getid(){
        return c_id;
    }
}com;
void addmedicine(){
   fstream f;
   f.open("medicine.txt",ios::out|ios::app);
   if(!f){
       cout<<"FILE IS NOT OPEN!! TRY AGAIN...";
   }
   else{
       med.setdata();
       f.write((char*)&med,sizeof(med));
   }
   f.close();
   cout<<"....DATA ADDED SUCCESSFULLY...."<<endl<<endl;
}
void searchmedicine(){
    int n,flag=0;  
    cout<<endl<<"...ENTER THE ITEM CODE OF THE MEDICINE WHICH U WANT TO SEARCH..";
    cin>>n;
    fstream f;  
    f.open("medicine.txt",ios::in);
    while(f.read((char*)&med,sizeof(med))){
        if(n==med.getno()){
            cout<<endl<<endl<<"...DETAILS OF THE MEDICINE..."<<endl<<endl;
            med.show();
            flag++;
        }
    }
    f.close();
    if(flag==0){
        cout<<endl<<endl<<"...ITEMCODE DOESN'T FOUND..."<<endl<<endl;
    }
    if(flag==1){
        cout<<endl<<endl<<"...DATA SEARCHED SUCCESSFULLY..."<<endl<<endl;
    }
}
void viewmedicine(){
    fstream f;
    f.open("medicine.txt",ios::in);
    while(f.read((char*)&med,sizeof(med))){
        med.show();
    }
    f.close();
    cout<<endl<<".....DATA READED SUCCSESSFULLY......"<<endl;
}
void editmedicine(){
    int n,flag=0;
    int pos;
    char c;
    fstream f;
    f.open("medicine.txt",ios::in|ios::out);
    cout<<endl<<"ENTER THE ITEMCODE OF THE MEDICINE WHICH U WANT TO EDIT...";
    cin>>n;
    while(f.read((char*)&med,sizeof(med))){
        if(n==med.getno()){
                pos=f.tellg();
                cout<<"....MEDICINE DATA IS READY TO UPDATE...."<<endl;
                med.setdata();
                f.seekg(pos-sizeof(med));
                f.write((char*)&med,sizeof(med));
                flag++;
        }
    }
    f.close();
    if(flag==0){
        cout<<"RECORD IS NOT FOUND"<<endl;
    }
    if(flag==1){
        cout<<endl<<"....RECORD EDITED SUCCESSFULLY...."<<endl;
        cout<<endl<<"..DO U WANT TO CHECK THE EDITED RESULT(Y/N)...";
        cin>>c;
        if(c=='y'||c=='Y'){
            viewmedicine();
        }
        else{
            medicinedetails();
        }
    }
}
void deletemedicine(){
    int n,flag=0;
    fstream f,f1,f2;
    f.open("medicine.txt",ios::in|ios::out);
    f1.open("medicine1.txt",ios::out|ios::app);
    f2.open("medicine2.txt",ios::out);
    cout<<".....DELETION OF DATA...";
    cout<<"ENTER THE ITEMCODE OF THE MEDICINE";
    cin>>n;
    while(f.read((char*)&med,sizeof(med))){
        if(n==med.getno()){
            cout<<"MEDICINE RECORD IS READY FOR DELETE"<<endl;
            f2.write((char*)&med,sizeof(med));
            flag++;
        }
        else{
            f1.write((char*)&med,sizeof(med));
        }
    }
    f.close();
    f1.close();
    f2.close();
    remove("medicine.txt");
    remove("medicine2.txt");
    rename("medicine1.txt","medicine.txt");
    if(flag==0){
        cout<<"...RECORD DOESN'T FOUND"<<endl;
    }
    if(flag==1){
        cout<<"RECORD DELETED SUCCESSFULLY"<<endl;
    }
}
void clearmedicine(){
   char ch;
   cout<<endl<<"...CLEARING FILE REMOVE ALL THE DATA PRESENT INSIDE THE FILE..."<<endl;
   cout<<endl<<"...ARE U SURE TO CLEAR THE MEDICINE LIST(Y/N)";
    cin>>ch;
    if(ch=='y'||ch=='Y'){
        ofstream f("medicine.txt");
        cout<<endl<<"RECORD CLEAR SUCCESSFULLY"<<endl;
    }
    else{
        medicinedetails();
    }
}
void updatemedicine(){
    //this_thread;
    //chrono;
    //sleep_for(10s);
    //  std::this_thread::sleep_for(std::chrono::nanoseconds(10));
    cout<<"updated";
}
void stockenquiry(){
   fstream f;
   int n,flag=0;
   f.open("medicine.txt",ios::in);
    cout<<endl<<endl<<"ENTER THE ITEMCODE OF THE MEDICINE...";
    cin>>n;
   while(f.read((char*)&med,sizeof(med))){
        if(n==med.getno()){
            if(med.quan()<10){
                cout<<"MEDICINE IS OUT OF STOCK!"<<endl;
            }
            else{
                cout<<"IN STOCK"<<endl;
            }
            flag++;
        }
   }
   f.close();
   if(flag==0)
        cout<<endl<<"MEDICINE NOT FOUND";
}
void clearstock(){
    fstream f,f1;
    f.open("medicine.txt",ios::in|ios::out);
    f1.open("medicine1.txt",ios::out);
    while(f.read((char*)&med,sizeof(med))){
        med.avail_quant=0;
        f1.write((char*)&med,sizeof(med));
    }
    f.close();
    f1.close();
    remove("medicine.txt");
    rename("medicine1.txt","medicine.txt");
    cout<<"record cleared";
}
void updatestock(){
   fstream f,f1;
   int n,flag=0,value;
   int pos;
   f.open("medicine.txt",ios::in|ios::out);
   f1.open("medicine1.txt",ios::out);
   cout<<" ENTER THE ITEMCODE OF THE MEDICINE...";
   cin>>n;
   while(f.read((char*)&med,sizeof(med))){
       if(n==med.getno()){
           cout<<endl<<endl<<"...MEDICINE DATA IS READY TO UPDATE...";
           cout<<endl<<"Enter the new value of the stock...";
           cin>>value;
            med.avail_quant=value;
            f1.write((char*)&med,sizeof(med));
            flag++;
       }
       else{
            f1.write((char*)&med,sizeof(med));
       }
   }
   f.close();
   f1.close();
   remove("medicine.txt");
   rename("medicine1.txt","medicine.txt");
   if(flag==0)
    cout<<"ITEM NOT FOUND";
   if(flag==1)
    cout<<"updated"; 
}
void addcompany(){
    fstream c;   
    c.open("company.txt",ios::out|ios::app);
    if(!c){
        cout<<endl<<"..FILE CANNOT OPEN!ERROR.."<<endl;
    }
    else{
        com.comdata();
        c.write((char*)&com,sizeof(com));
    }
    c.close();
    cout<<".......DATA READED SUCCESSFULLY.......";
}
void showcompany(){
    fstream c;
    c.open("company.txt",ios::in);
    if(!c){
        cout<<endl<<"..FILE CANNOT OPEN!ERROR.."<<endl;
    }
    else{
        while(c.read((char*)&com,sizeof(com))){
            com.showdata();
        }
    }
    c.close();
    cout<<"......DATA READED SUCCESSFULLY.......";
}
void deletecompany(){
    fstream c,c1,c2;
    int n,flag=0;
    c.open("company.txt",ios::in|ios::out);
    c1.open("company1.txt",ios::out|ios::app);
    c2.open("company2.txt",ios::out);
    cout<<"ENTER COMPANY ID OF THE MEDICINE...";
    cin>>n; 
    while(c.read((char*)&com,sizeof(com))){
        if(n==com.getid()){
            c2.write((char*)&com,sizeof(com));
            flag++;
        }
        else{
            c1.write((char*)&com,sizeof(com));
        }
    }
    c.close();
    c1.close();
    c2.close();
    remove("company.txt");
    remove("company2.txt");
    rename("company1.txt","company.txt");
    if(flag==0){
        cout<<"COMPANY ID DOESN'T FOUND"<<endl<<endl;
    }
    if(flag==1){
        cout<<endl<<"...DATA DELETED SUCCESSFULLY..."<<endl;
    }
}
void generatebill(){
    fstream f;
    int n,q,pos;
    float p;
    char ch='y';
    float totalprice=0;
    do{
    cout<<"_______________BILL GENERATION_________________";
    cout<<endl<<"ENTER ITEMCODE";
    cin>>n;
    cout<<endl<<"TOTAL NO. OF QUANTITY";
    cin>>q;
    f.open("medicine.txt",ios::in);
    while(f.read((char*)&med,sizeof(med))){
            if(n==med.getno()){
                p=med.medpri();
                cout<<"NAME OF THE MEDICINE"<<med.getname();
                int newd=med.avail_quant-q;
                med.avail_quant=newd;
                f.write((char*)&med,sizeof(med));
            }
    }
    f.close();
    cout<<endl<<"QUANTITY   "<<q;
    cout<<endl<<"PRICE      "<<q*p;
    totalprice+=q*p;
    
    cout<<"do you want to add more(y/n)";
    cin>>ch;
    }while(ch!='n');
    cout<<endl<<"total price"<<totalprice;
}
void searchbill(){
    cout<<"viewed";
}
void totalbill(){
    cout<<"viewed";
}
void printbill(){
    cout<<"viewed";
}
void medicinedetails(){
    int ch;
   do{
       system("cls");     
       cout<<endl<<"_________________________________________________________________________"<<endl;
       cout<<"PRESS 1 FOR ADD MEDICINE"<<endl;
       cout<<"PRESS 2 FOR SEARCH  MEDICINE"<<endl;
       cout<<"PRESS 3 FOR VIEW MEDICINE"<<endl;
       cout<<"PRESS 4 FOR EDIT MEDICINE"<<endl;
       cout<<"PRESS 5 FOR DELETE MEDICINE"<<endl;
       cout<<"PRESS 6 FOR CLEAR MEDICINE"<<endl;
       cout<<"PRESS 7 FOR UPDATE MEDICINE RECORD"<<endl;
       cout<<"PRESS 8 FOR BACK TO MAINMENU"<<endl;
       cout<<"___________________________________________________________________________"<<endl;
       cout<<"ENTER CHOICE..";
       cin>>ch;
       switch(ch){
           case 1:
                addmedicine();
                break;
            case 2:
                searchmedicine();
                break;
            case 3:
                viewmedicine();
                break;
            case 4:
                editmedicine();
                break;    
            case 5:
                deletemedicine();
                break;
            case 6:
                clearmedicine();
                break;
            case 7:
                updatemedicine();
                break;
            case 8:
                mainmenu();
                break;
       }
       system("pause");
   }while(ch!=0);
}
void stockdetails(){
    int ch;
   do{
       system("cls");
       cout<<"........*****************************************************.......";
       cout<<"PRESS 1 FOR STOCK ENQUIRY(IN STOCK OR OUT OF STOCK)";
       cout<<"PRESS 2 FOR CLEAR STOCK HISTORY";
       cout<<"PRESS 3 FOR UPDATE STOCK RECORD";
       cout<<"PRESS 4 FOR BACK TO MAINMENU";
       cout<<"........*****************************************************.......";
       cout<<"ENTER CHOICE..";
       cin>>ch;
       switch(ch){
           case 1:
                stockenquiry();
                break;
            case 2:
                clearstock();
                break;
            case 3:
                updatestock();
            case 4:
                mainmenu();
                break;
       }   
       system("pause");
    }while(ch!=0);
}
void companydetails(){
    int ch;
      do{
       system("cls");
       cout<<"........*****************************************************......."<<endl;
       cout<<"PRESS 1 TO ADD NEW COMPANY MEDICINE"<<endl;
       cout<<"PRESS 2 FOR SHOW LIST OF ALL COMPANIES"<<endl;
       cout<<"PRESS 3 FOR DELETE MEDICINE"<<endl;
       cout<<"PRESS 4 FOR BACK TO MAINMENU"<<endl;
       cout<<"........*****************************************************......."<<endl;
       cout<<"ENTER CHOICE..";
       cin>>ch;
       switch(ch){
            case 1:
                addcompany();
                break;
            case 2:
                showcompany();
                break;
            case 3:
                deletecompany();
                break;
            case 4:
                mainmenu();
                break;            
       }
       system("pause");
    }while(ch!=0);
}
void billdetails(){
     int ch;
    do{
       system("cls");
       cout<<"........*****************************************************......."<<endl;
       cout<<"PRESS 1 TO GENERATE BILL"<<endl;
       cout<<"PRESS 2 TO PRINT BILL"<<endl;
       cout<<"PRESS 3 TO SEARCH BILL"<<endl;
       cout<<"PRESS 4 TO PRINT A DAY BILL"<<endl;
       cout<<"PRESS 5 FOR BACK TO MAINMENU"<<endl;
        cout<<"........*****************************************************......."<<endl;
       cout<<"ENTER CHOICE..";
       cin>>ch;
       switch(ch){
           case 1:
                generatebill();
                break;
            case 2:
                printbill();
                break;
            case 3:
                searchbill();
                break;
            case 4:
                totalbill();
                break;
            case 5:
                mainmenu();
                break;
       } 
       system("pause");
    }while(ch!=0);                       
}
void mainmenu(){
    system("cls");
    int ch;
    do{
        system("cls");  
        cout<<endl<<"_____________________________________________________________________";
        cout<<endl<<"........................MAINMENU........................"<<endl;
        cout<<"_____________________________________________________________________"<<endl;
        cout<<"PRESS 1 FOR MEDICINE DETAILS"<<endl;
        cout<<"PRESS 2 FOR STOCK DETAILS"<<endl;
        cout<<"PRESS 3 FOR SPECIFIC COMPANY DETAILS"<<endl;
        cout<<"PRESS 4 FOR BILL DETAILS"<<endl;
        cout<<"PRESS 5 FOR EXIT"<<endl;
        cout<<"_____________________________________________________________________"<<endl;
        cout<<"ENTER CHOICE.. ";
        cin>>ch;
        switch(ch){
            case 1: 
                medicinedetails();
                break;
            case 2:
                stockdetails();
                break;
            case 3:
                companydetails();
                break;
            case 4:
                billdetails();
                break;
            case 5:                
                exit(0);  
        }
        system("pause");
    }while(ch!=6);
}
int main(){
cout<<"...........PHARMACY MANAGEMENT SYSTEM.......... ";
mainmenu();
cout<<endl<<endl;
}