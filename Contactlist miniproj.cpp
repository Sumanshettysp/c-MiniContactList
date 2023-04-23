/*
Contact App Management
1 : Add Contact
2 : Delete Contact
3 : Update Contact
4 : Search Contact
5 : Display Contact
6 : Display All Contact
7 : Sort Contact based on name
8 : reverse sort based on name
9 : exit


*/
#include<iostream>
#include<iomanip>
#include<list>
using namespace std;
class Contact
{
	protected:
		string name,email,phone;
	public:
		void setdata();
		void updateRecord();
		void display();
		string getname();
		string getemail();
};

string Contact::getname()
{
	return name;
}
string Contact::getemail()
{
	return email;
}
void Contact::setdata()
{
	cout<<"\n Enter the name = ";
	getline(cin,name);
	cout<<"\n Enter the email = ";
	getline(cin,email);
	cout<<"\n Enter the phone = ";
	getline(cin,phone);
}
void Contact::updateRecord()
{
	int ch;
	cout<<"\n Do you want to update : ";
	cout<<"\n 1. NAME  \n 2. EMAIL \n 3. PHONE \n CHOICE = ";
	cin>>ch;
	cin.ignore();
	switch(ch)
	{
		case 1:cout<<"\n Enter the name = ";
		       getline(cin,name);
		       break;
	    case 2:cout<<"\n Enter the email = ";
		       getline(cin,email);
		       break;
		case 3:cout<<"\n Enter the phone = ";
		       getline(cin,phone);
		       break;
	}
}
void Contact::display()
{
	cout<<"\n-----------------------------\n";
	cout<<setw(8)<<"NAME:"<<setw(15)<<name<<"|";
	cout<<setw(8)<<"EMAIL:"<<setw(15)<<email<<"|";
	cout<<setw(8)<<"PHONE:"<<setw(15)<<phone<<"\n";
}

class Application
{
	protected:
		list<Contact> contactList;
	public:
		void insertContact(Contact c);
		void deleteContact(string s);
		void searchContact(string s);
		void displayAll();
		void update(string s);
		void sortAscending();
		void revSort();
};
void Application::insertContact(Contact c)
{
	contactList.push_back(c);
	cout<<"\n Insertion completed\n";
}
void Application::deleteContact(string s)
{
	
}
void Application::searchContact(string s)
{
	int f=1;
	for(auto iter = contactList.begin(); iter != contactList.end(); ++iter)
	{
		if(iter->getname() == s);
		{
			f=0;
			iter->display();
		}
	}
	if(f==1)
	  cout<<"\n Contact by the given name does not exist\n";
}
void Application::displayAll()
{
	for(auto iter = contactList.begin(); iter != contactList.end(); ++iter)
	{
		iter->display();
	}
}
void Application::update(string s)
{
	int f=1;
	for(auto iter = contactList.begin(); iter != contactList.end(); ++iter)
	{
		if(iter->getemail() == s);
		{
			f=0;
			iter->updateRecord();
		}
	}
	if(f==1)
	  cout<<"\n Contact by the given name does not exist\n";
}
void Application::sortAscending()
{
	
}
void Application::revSort()
{
	
}
int main()
{
	int ch;
	Application app;
	Contact c;
	string s;
	do
	{
		cout<<"\n Contact App Management";
        cout<<"\n1: Add Contact";
        cout<<"\n2: Delete Contact";
        cout<<"\n3: Update Contact";
        cout<<"\n4: Search Contact";
        cout<<"\n5: Display Contact";
        cout<<"\n6: Display All Contact";
        cout<<"\n7: Sort Contact based on name";
        cout<<"\n8: Reverse sort based on name";
        cout<<"\n9: Exit";
        cout<<"\n Enter the choice = ";
        cin>>ch;
        cin.ignore();
        switch(ch)
        {
        	case 1:c.setdata();
        	       app.insertContact(c);
        	case 3:cout<<"\n Enter contact email to search = ";
				   getline(cin,s);
				   app.update(s);
				   break; 
        	case 4:
        	case 5:cout<<"\n Enter contact name to search = ";
				   getline(cin,s);
				   app.searchContact(s);
				   break; 
        	case 6:app.displayAll();
        	       break;
            case 9:break;
		}
	}
	while(ch!=9);
}
