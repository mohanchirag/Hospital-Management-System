#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<cstdio>
#include<stdlib.h>
using namespace std;
struct r{
    char name[50];
    int reg_no;
    int age;
    char gender;
    long long int contact;
    char address[50];

}r;
class hospital
{
public:
    void create();
    void display();
    void update();
    void delet();

};
void hospital::create()
{
    char a;
    int k;
    fstream obj;
    top:
    do {
        obj.open("hospital.txt",ios::in|ios::binary);
        cout<<"Enter the Registration no:";
        cin>>k;
         while(obj.read((char*)&r,sizeof(r)))
            {
                if(r.reg_no==k)
                {
                    cout<<"key is already exist"<<endl;
                    obj.close();
                goto top;
                }
            }
        obj.close();
        obj.open("hospital.txt",ios::app|ios::binary);
        r.reg_no=k;
        cin.ignore();
        cout<<"Enter the Name of Patient:";
        gets(r.name);

        while(1)
        {
        cout<< "Enter gender:M/F/O:";
        cin>> r.gender;
        if(r.gender== 'M' || r.gender== 'F' || r.gender== 'O'  )
        {
           break;
        }
        else
        {
           cout<< "OOPS!!...Invalid Gender"<< endl;
        }
        }

        cout<<"Enter the Age of Patient:";
        cin>>r.age;

       while(1)
       {
           cout<<"Enter contact number:";
           cin>> r.contact;
           if(r.contact < 999999999 || r.contact> 10000000000)
           {
               cout<< "OOPS!!...Invalid Contact No."<<endl;
           }
           else
           {
               break;
           }
       }


        obj.write((char*)&r,sizeof(r));
        cout<<"do you want to add an other [y/n]:";
        cin>>a;
        obj.close();
    }
    while(a!='n');
}
void hospital::display()
{
      int c=0;
     fstream obj;
     obj.open("hospital.txt",ios::in|ios::binary);

    while(obj.read((char*)&r,sizeof(r)))
    {
            cout<<"Registration No.:"<<r.reg_no<< endl;
            cout<<"Name of Patient:"<<r.name<<endl;
            cout<<"Age:"<<r.age<<endl;
            cout<<"Gender:"<<r.gender<< endl;
            cout<<"Contact No.:"<<r.contact<<endl<<endl;
            c++;
    }
    if(c==0)
    {
        cout<<"list is empty"<<endl;
    }
    obj.close();
}
void hospital::update()
{
     int a,p,c=0;
     fstream obj;
     obj.open("hospital.txt",ios::in|ios::out|ios::binary);
    cout<<"enter the Registration Number:";
    cin>>a;
    obj.seekg(0);
    while(obj.read((char*)&r,sizeof(r)))
    {
        if(r.reg_no==a)
        {

            p=obj.tellg()-(sizeof(r));
            obj.seekp(p);
            //cout<<"Enter the Registration No:";
            //cin>>r.reg_no;
            cin.ignore();
            cout<<"Enter the name of patient:";
             gets(r.name);

             while(1)
        {
        cout<< "Enter gender:M/F/O:";
        cin>> r.gender;
        if(r.gender== 'M' || r.gender== 'F' || r.gender== 'O'  )
        {
           break;
        }
        else
        {
           cout<< "OOPS!!...Invalid Gender"<< endl;
        }
        }

        cout<<"Enter the Age of Patient:";
        cin>>r.age;

       while(1)
       {
           cout<<"Enter contact number:";
           cin>> r.contact;
           if(r.contact < 999999999 || r.contact> 10000000000)
           {
               cout<< "OOPS!!...Invalid Contact No."<<endl;
           }
           else
           {
               break;
           }
       }
            obj.write((char*)&r,sizeof(r));
            c++;
           }

        }
        if(c==0)
        {
            cout<<"not found"<<endl;
        }

    obj.close();
}
void hospital::delet()
{
     int a,c;
     fstream obj,obj1;
     obj.open("hospital.txt",ios::in|ios::binary);
     obj1.open("temp.txt",ios::app|ios::binary);
    cout<<"Enter the Registration No:";
    cin>>a;
    while(obj.read((char*)&r,sizeof(r)))
    {
        if(r.reg_no==a)
        {
            c++;

            cout<<"Registration No.:"<<r.reg_no<< endl;
            cout<<"Name of Patient:"<<r.name<<endl;
            cout<<"Age:"<<r.age<<endl;
            cout<<"Record is deleted successfully."<<endl;
        }
        if(r.reg_no!=a)
        {
            obj1.write((char*)&r,sizeof(r));
           }
    }
    obj.close();
    obj1.close();
    if(c==0)
       {
         cout<<"not found"<<endl;
       }
    remove("hospital.txt");
    rename("temp.txt","hospital.txt");
}
struct rd
{
    float checkup_charge;
    float med_charge;
    float total;
    char admit;
    int day;
    float room_charge;
}rd;
class patient:public hospital
{
public:

    void bill();
    void showbill();

};

void patient::bill()
{
    float fee_per_day= 2000;
     int a,c=0;
     char ch;
     float total=0;
    fstream obj,obj1;

    obj1.open("bill.txt",ios::out|ios::binary);
     //do{
    obj.open("hospital.txt",ios::in|ios::binary);
    cout<<"Enter the Registration No:";
    cin>>a;
    while(obj.read((char*)&r,sizeof(r)))
    {
           if(r.reg_no==a)
           {
            c++;
            while(1)
                {
            cout<<"Checkup Charges:";
            cin>>rd.checkup_charge;
            if(rd.checkup_charge<499)
            {
                cout<<" Invalid Amount"<< endl;
            }
            else
                {
                    break;
                }
                }
            while(1)
                {
            cout<<"Medicinal Charges:";
            cin>> rd.med_charge;
            if(rd.med_charge<0)
            {
                cout<<"Invalid Amount" << endl;
            }
            else
            {
                break;
            }
                }
            cout<< "Was the patient admitted in the hospital? Y/N:";
            cin>> rd.admit;
            if(rd.admit== 'Y'|| rd.admit=='y')
            {
                cout<< "How many days?:";
                cin>>rd.day;
                rd.room_charge= rd.day*2000;
            }
            else
            {
                rd.day=0;
            }
            rd.total=rd.checkup_charge+rd.med_charge+ rd.room_charge;
            system("CLS");
        cout<<" -----------------------------------------------------------------------"<<endl;
        cout<<"|                                                                       |"<<endl;
        cout<<"|           ***   ***   ***  HOSPITL BILL   ***   ***   ***             |"<<endl;
        cout<<"|                                                                       |"<<endl;
        cout<<" -----------------------------------------------------------------------"<<endl;
            cout<< "Registration No:"<< r.reg_no<<endl;
            cout<< "Name           :"<< r.name<<endl;
            cout<< endl<<endl;
            cout<< "Checkup Charges    :"<< rd.checkup_charge<<endl;
            cout<< "Medicinal Charges  :"<< rd.med_charge<< endl;
            cout<< "Room Charges       :"<< rd.room_charge <<endl;
            cout<< "-------------------------------------"<< endl;
            cout<< "Total Charges      :"<< rd.total<< endl;
            cout<<"PRESS ANY KEY TO GO BACK...........";
            getch();
            system("CLS");


           }
        }
        if(c==0)
     {
        cout<<"Record Not Found"<<endl;
     }


    obj.close();
     }



int main()
{
patient obj;
//patient p;
int op1;
char a;
    xyz:

    cout<<" -----------------------------------------------------------------------"<<endl;
    cout<<"|                                                                       |"<<endl;
    cout<<"|     ***   ***   ***  HOSPITL MANAGEMENT SYSYTEM   ***   ***   ***     |"<<endl;
    cout<<"|                                                                       |"<<endl;
    cout<<" -----------------------------------------------------------------------"<<endl;
    cout<<"\n\n1. MAIN MENU\n\n2. Generate Bill\n\n3. Exit"<< endl;
    cout<<"\n\nENTER YOUR CHOICE:";
    //system("CLS");
    cin>>op1;
    if(op1==1){
            abc:
                do{

            cout<<"\n\t\t\t\t\t|||||||||||||||||||||||||||"<<endl;
            cout<<"\t\t\t\t\t\t|                         |"<<endl;
            cout<<"\t\t\t\t\t\t|  1) ADD Records         |"<<endl;
            cout<<"\t\t\t\t\t\t|  2) Display Records     |"<<endl;
            cout<<"\t\t\t\t\t\t|  3) UPDATE              |"<<endl;
            cout<<"\t\t\t\t\t\t|  4) DELETE              |"<<endl;
            cout<<"\t\t\t\t\t\t|  0) EXIT                |"<<endl;
            cout<<"\t\t\t\t\t\t|                         |"<<endl;
            cout<<"\t\t\t\t\t\t|||||||||||||||||||||||||||"<<endl<< endl;
            cout<<"\t\t\t\tENTER YOUR CHOICE:";
            cin>>a;
            switch(a)
            {
            case '0':
                goto xyz;
                break;

            case '1':
                system("CLS");
               obj.create();
               cout<<"PRESS ANY KEY TO GO BACK...........";
               getch();
               system("CLS");
               //goto abc;
                break;
            case '2':
                system("CLS");
               obj.display();
               cout<<"PRESS ANY KEY TO GO BACK...........";
               getch();
               system("CLS");
                //goto abc;
                break;
            case '3':
                system("CLS");
               obj.update();
               cout<<"PRESS ANY KEY TO GO BACK...........";
               getch();
               system("CLS");
                //goto abc;
                break;
            case '4':
                system("CLS");
               obj.delet();
               cout<<"PRESS ANY KEY TO GO BACK...........";
               getch();
               system("CLS");
                //goto abc;
                break;
            }
    }while(a!=5);
    }
    else if(op1==2)
    {
      system("CLS");
      obj.bill();
      goto xyz;
    }
    else
    {
      exit(0);
    }
}


























