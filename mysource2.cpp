*/
  Pass saver is a simple console program that save/retrieve information: domain-password-username-email.  
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void passsaver( string email, string username, string domain, string password){

	ofstream datatosave("savedfile.txt", ios::app);
	if(datatosave.is_open())
	{	
		datatosave<<domain + "-" + password + "-" + username + "-" + email<<endl;
		datatosave.close();
	}else 
	{
		cout<<"***ERROR***"<<endl;
	}
}

void passsearch(string domainsearch){
	string tempdomain;
	ifstream datatosearch("savedfile.txt");
	if(datatosearch.is_open()){
		while(datatosearch.good())
		{
			getline(datatosearch,tempdomain);
			if(tempdomain.find(domainsearch,0)!=-1){
				cout<<tempdomain<<endl;
			}
		}
		datatosearch.close();
	}
}

int main()
{
	// save or retrieve
	char option;
	//names :
	string email;
	string username;
	string domain;

	//password : 
	string password;
	
	cout<<"	******************************************"<<endl;
	cout<<"			**********		"<<endl;
	cout<<"			PASS-SAVER		"<<endl;
	cout<<"			**********		"<<endl;					
	cout<<"	******************************************"<<endl;
	cout<<"Hint ===>";
	cout<<" r to retrieve \tor\ts to saver a password "<<endl;
	cin>>option;

	if(option=='s')
	{
		// Data in names
		cout<<"Enter Email: ";
		getline(cin,email);
		cout<<"Enter username: ";
		getline(cin,username);
		cout<<"Enter Domain: ";
		getline(cin,domain);
		
		// Password data in;
		cout<<"Enter password: ";
		getline(cin,password);
	
		// Pass-saver
		passsaver(email,username,domain,password);	
	}else if (option=='r')
	{
    // Pass-retrieve
		string domainsearch;
		cout<<"Enter the domain your want to retrive information from :";
		cin>>domainsearch;
		passsearch(domainsearch);		
	}
	return 0;
}
