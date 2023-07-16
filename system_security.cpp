#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;


int main()
{
	int a, i=0;
	string text, old, password1, password2, pass, name, password0, age, word, word1, user;
	string creds[2], cp[2];
	
	cout<<"      security system       "<<endl;
	
	cout<<"_____________________________"<<endl<<endl;
	cout<<"|       1. Register          "<<endl;
	cout<<"|       2. Login             "<<endl;
	cout<<"|       3. Change password   "<<endl;
	cout<<"|_____4. End program_____"<<endl<<endl;
	
	do{
		cout<<endl<<endl;
		cout<<"Enter your choice:- "<<endl;
		cin>>a;
		switch(a)
		{
			case 1:{
				cout<<"_____________________________"<<endl<<endl;
				cout<<"|---------Register----------|"<<endl;
				cout<<"|                           |"<<endl<<endl;
				
				cout<<"Please  enter your user name"<<endl;
				cin>>name;
				cout<<"Please enter the password"<<endl;
				cin>>password0;
				cout<<"Please enter your age"<<endl;
				cin>>age;
				
				ofstream of1;
				of1.open("file.txt");
				if (of1.is_open()){
					of1<<name<<"\n";
					of1<<password0;
					cout<<"registration successfull"<<endl;
					
				}
				
				
				break;
			}
			case 2:{
				i=0;
				
				cout<<"_____________________________"<<endl<<endl;
				cout<<"|---------Login-------------|"<<endl;
				cout<<"|                           |"<<endl<<endl;
				
				ifstream of2;
				of2.open("file.txt");
				cout<<"Please enter the username:- ";
				cin>>user;
				cout<<"Please enter the password:- ";                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
				cin>>pass;
				
				if (of2.is_open())
				{
				  while(!of2.eof())
				  {
				  	while(getline(of2, text)){
				  		istringstream iss(text);
				  		iss>>word;
				  		creds[i]=word;
				  		i++;
					  }
					  
					  if(user==creds[0] && pass==creds[1])
					  {
					  	cout<<"---------Login successful---------";
					  	cout<<endl<<endl;
					  	cout<<"details"<<endl;
					  	
					  	cout<<" username:- "+ name<<endl;
						cout<<" password:- "+ pass<<endl;
						cout<<" age:- "+ age<<endl;
					  }
					  else{
					  	cout<<endl<<endl;
					  	cout<<" Incorrect credentials"<<endl;
					  	cout<<"|    1. press 2 to login               |"<<endl;
					  	cout<<"|    2. press 3 to change password     |"<<endl;
						  break;
						  
					  }
				}
			}
			break;
			
		}
					  case 3:{
					  	i=0;
					  	
					  	cout<<"           change password          "<<endl;
					  	
					  	
					  	ifstream of0;
					  	of0.open("file.txt");
					  	cout<<"Enter the old password:-  ";
					  	cin>>old;
					  	if(of0.is_open())
					  	{
					  		while(!of0.eof())
					  		{
					  			while(getline(of0, text)){
					  				istringstream iss (text);
					  				iss>>word1;
					  				cp[i]=word1;
					  				i++;
								  }
								  if(old==cp[1])
								  {
								  	of0.close();
								  	
								  	ofstream of1;
									 of1.open("file.txt");
									 if(of1.is_open())
									 {
									 	cout<<"Enter new password"<<endl;
									 	cin>>password1;
									 	cout<<"Enter password again"<<endl;
									 	cin>>password2;
									 	
									 	
									 	if(password1==password2)
									 	{
									 	of1<<cp[0]<<"\n";
									 	of1<<password1;
									 	cout<<"password changed successfully "<<endl;
									 	
									 }
									 
									 else{
									 	of1<<cp[0]<<"\n";
									 	of1<<old;
									 	cout<<"password do not match"<<endl;
									 	
									 }
								
								  }
							  }
					  	
							  else{
							  	cout<<"Please enter valid password:- "<<endl;
							  	break;
							  	
							  }
						  }
					  }
						break;
				  }
					  
					  case 4:{
					  	cout<<"__________thank you___________"<<endl;
						break;
					  }
					  default:
					  	cout<<" Enter the valid choice";                                                                                                                                                         
				
				
			}
		}
		while(a!=4);
				return 0;

	}