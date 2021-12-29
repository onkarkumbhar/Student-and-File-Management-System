#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
void delay(int sec)
{
    for(int i=0;i<sec*3600;i++)
    {
        for(int j=0;j<36000;j++)
        {

        }
    }
}
void typed(string s)
{
    for(int i=0;i<s.length();i++)
    {
        cout<<s.at(i);
        delay(1);
        cout.flush();
    }
    cout<<"\n";
}
void create_batch(string batch_name)
{
    system(("mkdir file_management/"+batch_name).c_str());
}
void create_student(string b1,string b2, string b3){
    string command;
    command="mkdir file_management/"+b1+"/"+b3;
    system(command.c_str());
    string info=b1+"\n"+b2+"\n"+b3;
    FILE * f = fopen(("file_management/"+b1+"/"+b3+"/info.txt").c_str(),"w");
    fprintf(f,info.c_str());
    fclose(f);
    typed("Student created.....");
}
void add_file(string batch_name,string roll_no,string file_path)
{
    string command;
    command="cp "+file_path+" file_management/"+batch_name+"/"+roll_no;
    system(command.c_str());
}
int main(void)
{
    cout<<"////////////////////////////////////////////////////////////////////\n";
    cout<<"//              MANAGEMENT SYSTEM FOR STUDENTS                    //\n";
    cout<<"//@ Onkar Kumbhar            Dec 2021                             //\n";
    cout<<"////////////////////////////////////////////////////////////////////\n";
    typed("Featching all required files and data stored...");
    typed("for help type --help");
    while(1)
    {
        string command;
        cout<<"Command@management.system$ ";
        cin>>command;
        if(command=="--help")
        {
            cout<<"Command Center>>>>>>>>>>>>>>\n";
            cout<<"Command                  Use\n";
            cout<<"--help           getting all commands for application\n";
            cout<<"create_batch     create batch for students\n";
            cout<<"create_student   create student with details\n";
            cout<<"add_file         add file to student folder\n";
            cout<<"fetch_file       fetch stored file...\n";
            cout<<"exit             Exit from console application\n";

        }
        if(command=="create_batch")
        {
            string batch_name;
            cout<<"Please enter batch name(space should not be included):";
            create_batch(batch_name);
            typed("Batch created....");
        }
        if(command=="create_student")
        {
            string batch_name,name,roll_no;
            cout<<"Enter batch name: ";
            cin>>batch_name;
            cout<<"Enter Student name: ";
            cin>>name;
            cout<<"Enter roll number: ";
            cin>>roll_no;
            create_student(batch_name,name,roll_no);
        }
        if(command=="add_file")
        {
            string batch_name,file_path,roll_no;
            cout<<"Enter batch name: ";
            cin>>batch_name;
            cout<<"Enter roll number: ";
            cin>>roll_no;
            cout<<"Enter full path of file: ";
            cin>>file_path;
            add_file(batch_name,roll_no,file_path);
            typed("File added to student folder...");
        }
        if(command=="fetch_file")
        {
            string batch_name,file_path,roll_no;
            cout<<"Enter batch name: ";
            cin>>batch_name;
            cout<<"Enter roll number: ";
            cin>>roll_no;
            string command="rm .temp/output.txt";
            system(command.c_str());
            command="ls file_management/"+batch_name+"/"+roll_no+"/ >> .temp/output.txt";
            system(command.c_str());

            cout<<"Enter full path of file to be stored: ";
            cin>>file_path;
            ifstream MyReadFile(".temp/output.txt");
            string a;
            while (getline(MyReadFile, a)) {
                // Output the text from the file
                cout << a<<"\n";
            }
            MyReadFile.close();
            string file_name;
            cout<<"Enter file name from above: ";
            cin>>file_name;
            command="cp file_management/"+batch_name+"/"+roll_no+"/"+file_name+" .";
            system(command.c_str());
            typed("File copied to this folder...");
        }
        if(command=="exit")
        {
            typed("Storing set of data...");
            typed("Thank You for using our management service!!!");
            exit(1);
        }
    }
}
