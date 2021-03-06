 #include <iostream>
#include<fstream>
#include<sstream>
#include<string.h>
#define MAX 100
using namespace std;

class student{
    string usn,name,sem,branch,buffer;
public:
        void read();
        void write();
        void pack();
        int search(string);
        int dele(string);
        void unpack();
        void modify(string);
};
student s;
void student::read()
{
    cout<<"enter your usn"<<endl;
    cin>>usn;
    cout<<"enter your name"<<endl;
    cin>>name;
    cout<<"enter the branch"<<endl;
    cin>>branch;
    cout<<"enter the sem"<<endl;
    cin>>sem;
}
void student::pack()
{
    string temp;
    fstream f1;
    temp+=usn+'|'+name+'|'+branch+'|'+sem;
    temp.resize(100,'$');
    f1.open("data.txt",ios::out|ios::app);
    f1<<temp<<endl;
    f1.close();
}
void student::write()
{
	fstream f1;
	f1.open("data.txt",ios::out|ios::app);
	f1<<buffer;
	f1<<endl;
	f1.close();
}
int student::search(string key)
{
    fstream f1;
    int pos;
    f1.open("data.txt",ios::in);
    while(!f1.eof())
    {
    getline(f1,buffer);
    pos=f1.tellp();
    unpack();

    if(usn==key)
        {cout<<"true";
        return pos;
        }

    else
        cout<<"false";
    }
    f1.close();
    return -1;
}

void student::unpack()
{
    int i=0;
    usn.erase();
        while(buffer[i]!='|')
            usn+=buffer[i++];
            i++;
     name.erase();
       while(buffer[i]!='|')
    	   name+=buffer[i++];
           i++;
      branch.erase();
        while(buffer[i]!='|')
        	branch+=buffer[i++];
           i++;
      sem.erase();
        while(buffer[i]!='$')
        	sem+=buffer[i++];
           i++;


    }

void student::modify(string key)
{
	int ch,pos;
	fstream f1;
	cout<<"enter the key to modify ; "<< endl;
	cin>>key;
	pos=search(key);
	cout<<"enter choice : \n1.usn\n2.name\n3.branch\n4.sem";
	switch(ch)
	{
	case 1:cout<<"usn";
	       cin>>usn;
	       break;
	case 2:cout<<"name";
	       cin>>name;
	       break;
	case 3:cout<<"branch";
	       cin>>branch;
	       break;
	case 4:cout<<"sem";
	       cin>>sem;
	       break;
	default:cout<<"wrong choice";
	}
	pack();
	pos=pos-101;
	f1.open("data.txt");
	f1.seekp(pos,ios::beg);
	f1<<buffer;
}

int main() {
    int choice;
    string key;
    student s;
    while(1)
    {
            cout<<"1.INSERT 2.SEARCH 3.DELETE 4.MODIFY";
            cout<<"enter your choice";
            cin>>choice;
            switch(choice)
            {
              case 1:s.read();
                   s.pack();
                    break;
              case 2:cout<<"enter key";
                    cin>>key;
                    //cout<<key;
                    s.search(key);
                    break;
              case 3:cout<<"enter key";
                    cin>>key;
                    s.modify(key);
                    break;
              default:return 0;
             }
    }

    return 0;
}
