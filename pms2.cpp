#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<stdlib.h>

using namespace std;
void mainmenu();
void addmedicine();
void searchmedicine();
class medicine{
    char medname[20];
    float price;
    int avail_quant;
    char comname[20];
    char mfgdate[10];
    char expdate[10];
    char review[30];
    int itemcode;
public:
    void setdata(){
        cout<<"ENTER ITEM_CODE OF THE MEDICINE...";
        cin>>itemcode;
        cout<<endl<<endl;
        cout<<"ENTER NAME OF THE MEDICINE...";
        cin>>medname;
        cout<<endl<<endl;
        cout<<"ENTER COMPANY NAME OF THE MEDICINE...";
        cin>>comname;
        cout<<endl<<endl;
        cout<<"ENTER PRICE OF THE MEDICINE...";
        cin>>price;
        cout<<endl<<endl;
        cout<<"ENTER MANUFACTURING DATE...";
        cin.ignore();
        cin>>mfgdate;
        cout<<endl<<endl;
        cout<<"ENTER EXPIRY DATE...";
        cin.ignore();
        cin>>expdate;
        cout<<endl<<endl;
        cout<<"ENTER AVAILABLE QUANTITY...";
        cin>>avail_quant;
        cout<<endl<<endl;
        cout<<"ENTER REVIEW OR INFO OF THE MEDICINE...";
        cin.ignore();
        cin.getline(review,30);
        cout<<endl<<endl;
    }
    void show(){
        cout<<endl<<endl;
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


}med;



void addmedicine(){
   fstream f;
   f.open("medicine1.txt",ios::out|ios::app);
   if(!f){
       cout<<"FILE IS NOT OPEN!! TRY AGAIN...";
   }
   else{
       med.setdata();
       f.write((char*)&med,sizeof(med));
   }
   f.close();
   cout<<endl<<endl;
   cout<<"....DATA ADDED SUCCESSFULLY...."<<endl<<endl;
}
void viewmedicine(){
    fstream f;
    f.open("medicine1.txt",ios::in);
    while(f.read((char*)&med,sizeof(med))){
        med.show();
    }
    f.close();
    cout<<endl<<endl<<".....DATA READED SUCCSESSFULLY......"<<endl<<endl;
}
void searchmedicine(){
    int n,flag=0;
    fstream f;  
    cout<<endl<<"...ENTER THE ITEM CODE OF THE MEDICINE WHICH U WANT TO SEARCH..";
    cin>>n;
    cout<<endl<<endl;
    f.open("medicine1.txt",ios::in|ios::binary);
    if(!f){
        cout<<"file does'nt found"<<endl<<endl;
    }
    else{
    while(f.read((char*)&med,sizeof(med))){
        if(n==med.getno()){
            cout<<endl<<endl<<"...DETAILS OF THE MEDICINE..."<<endl<<endl;
            med.show();
            flag++;
        }
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
void editmedicine(){
    cout<<"viewed";
}
void deletemedicine(){
    cout<<"viewed";
}
void clearmedicine(){
    cout<<"viewed";
}
void updatemedicine(){
    cout<<"viewed";
}
void stockenquiry(){
    cout<<"viewed";
}
void clearstock(){
    cout<<"viewed";
}
void updatestock(){
    cout<<"viewed";
}
void addcompany(){
    cout<<"viewed";
}
void showcompany(){
    cout<<"viewed";
}
void deletecompany(){
    cout<<"viewed";
}
void generatebill(){
    cout<<"viewed";
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
   cout<<endl<<endl;
   do{
       system("cls");
       cout<<endl<<endl<<endl;
       
       cout<<"........*****************************************************......."<<endl<<endl<<endl;
       cout<<"PRESS 1 FOR ADD MEDICINE"<<endl<<endl<<endl;
       cout<<"PRESS 2 FOR SEARCH  MEDICINE"<<endl<<endl<<endl;
       cout<<"PRESS 3 FOR VIEW MEDICINE"<<endl<<endl<<endl;
       cout<<"PRESS 4 FOR EDIT MEDICINE"<<endl<<endl<<endl;
       cout<<"PRESS 5 FOR DELETE MEDICINE"<<endl<<endl<<endl;
       cout<<"PRESS 6 FOR CLEAR MEDICINE"<<endl<<endl<<endl;
       cout<<"PRESS 7 FOR UPDATE MEDICINE RECORD"<<endl<<endl<<endl;
       cout<<"PRESS 8 FOR BACK TO MAINMENU"<<endl<<endl<<endl;
       cout<<"........*****************************************************......."<<endl<<endl<<endl;
       cout<<"ENTER CHOICE..";
       cin>>ch;
       cout<<endl<<endl;
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
        cout<<endl<<endl;
       system("pause");
        cout<<endl<<endl;
   }while(ch!=0);
}
void stockdetails(){
    int ch;
   do{
       system("cls");
       cout<<endl<<endl<<endl;
       cout<<"........*****************************************************......."<<endl<<endl<<endl;
       cout<<"PRESS 1 FOR STOCK ENQUIRY(IN STOCK OR OUT OF STOCK)"<<endl<<endl<<endl;
       cout<<"PRESS 2 FOR CLEAR STOCK HISTORY"<<endl<<endl<<endl;
       cout<<"PRESS 3 FOR UPDATE STOCK RECORD"<<endl<<endl<<endl;
       cout<<"PRESS 4 FOR BACK TO MAINMENU"<<endl<<endl<<endl;
       cout<<"........*****************************************************......."<<endl<<endl<<endl;
       cout<<"ENTER CHOICE..";
       cin>>ch;
       cout<<endl<<endl;
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
        cout<<endl<<endl;
       system("pause");
        cout<<endl<<endl;
    }while(ch!=0);
}
void companydetails(){
    int ch;
      do{
       system("cls");
       cout<<endl<<endl<<endl;
       cout<<"........*****************************************************......."<<endl<<endl<<endl;
       cout<<"PRESS 1 TO ADD NEW COMPANY MEDICINE"<<endl<<endl<<endl;
       cout<<"PRESS 2 FOR SHOW LIST OF ALL COMPANIES"<<endl<<endl<<endl;
       cout<<"PRESS 3 FOR DELETE MEDICINE"<<endl<<endl<<endl;
       cout<<"PRESS 4 FOR BACK TO MAINMENU"<<endl<<endl<<endl;
       cout<<"........*****************************************************......."<<endl<<endl<<endl;
       cout<<"ENTER CHOICE..";
       cin>>ch;
       cout<<endl<<endl;
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
        cout<<endl<<endl;
       system("pause");
        cout<<endl<<endl;
    }while(ch!=0);

}
void billdetails(){
     int ch;
    do{
       system("cls");
       cout<<endl<<endl<<endl;
       cout<<"........*****************************************************......."<<endl<<endl<<endl;
       cout<<"PRESS 1 TO GENERATE BILL"<<endl<<endl<<endl;
       cout<<"PRESS 2 TO PRINT BILL"<<endl<<endl<<endl;
       cout<<"PRESS 3 TO SEARCH BILL"<<endl<<endl<<endl;
       cout<<"PRESS 4 TO PRINT A DAY BILL"<<endl<<endl<<endl;
       cout<<"PRESS 5 FOR BACK TO MAINMENU"<<endl<<endl<<endl;
        cout<<"........*****************************************************......."<<endl<<endl<<endl;
       cout<<"ENTER CHOICE..";
       cin>>ch;
       cout<<endl<<endl;
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
       cout<<endl<<endl;
       system("pause");
       cout<<endl<<endl;
    }while(ch!=0);                       
}

void mainmenu(){
    system("cls");
    cout<<endl<<endl;
    int ch;
    do{
        system("cls");
        cout<<endl;
        cout<<"........*****************************************************.......";
        cout<<endl<<endl<<"........................MAINMENU........................"<<endl<<endl<<endl;
        cout<<"........*****************************************************......."<<endl<<endl<<endl;
        cout<<"PRESS 1 FOR MEDICINE DETAILS"<<endl<<endl<<endl;
        cout<<"PRESS 2 FOR STOCK DETAILS"<<endl<<endl<<endl;
        cout<<"PRESS 3 FOR SPECIFIC COMPANY DETAILS"<<endl<<endl<<endl;
        cout<<"PRESS 4 FOR BILL DETAILS"<<endl<<endl<<endl;
        cout<<"PRESS 5 FOR EXIT"<<endl<<endl<<endl;
        cout<<"........*****************************************************......."<<endl<<endl<<endl;
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
        cout<<endl<<endl;
    }while(ch!=6);
}


int main(){
cout<<"...........PHARMACY MANAGEMENT SYSTEM.......... ";
mainmenu();
cout<<endl<<endl;

}