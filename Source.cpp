#include <iostream>
#include <string>
#include <fstream>
#include<vector>
#include <algorithm>
using namespace std;

void create_account();
void login();
void   adminlogin(void);
void admin_log_create();
void logout();
void back();
void liblogin();
void add_librarian();
void view_librarian();
void modify_librarian();
void delete_librarian();
void add_student();
void view_student();
void modify_student();
void delete_student();
void view_book();
void add_book();
void modify_book();
void delete_book();
void borrow_book();
void student_log();
static bool  sort_book(double p , double q);
void  book_dates_only();


int main ()
{
system("title qnoner first project");
system("cls");
system("color 0B");
//create_account();
//login();

int number;

cout<<"1.Administrators"<<endl;
cout<<"2.Librarian"<<endl;
cout<<"3.Student"<<endl;

cout<<"Please choose your status"<<endl;

cin>>number;

system("cls");

switch(number)
{
 case 1:
    int number1_admin;
    
	cout<<"1.login and create :"<<endl;
	
	cout<<"2.back to main menu :"<<endl;
	cout<<endl;
	
  
    cout<<"1.Select the section: ";
	cin>>number1_admin;


	switch(number1_admin)
	{
	case 1:
	
	adminlogin();
	main();
	break;
	case 2:
		main();
		break;

}
	break;
case 2:
		cout<<"You  are in the section of library"<<endl;
		cout<<"1.log in "<<endl;
		cout<<"2.go back main menu "<<endl;
		
		cout<<"choose what you need"<<endl;
		int switch_number;
		cin>>switch_number;
        switch(switch_number)
        {
		
        case 1 :
				liblogin();
	
    break;
    case 2:
    	main();
    	break;
		}
		break;
    	
		
case 3:
	int foo;
	cout<<"you are in the section of student"<<endl;
	cout<<"1.log in "<<endl;
	cout<<"2. go back main menu"<<endl;
	cin>>foo;
	////////////////////////////////////////////////////////////
	switch(foo)
	{
	case 1:
		student_log();
		break;
		case 2:
			main();
			
			break;
		}
	break;
	
	default:
	cout<<"please choose your real status";
	break;
	
	
}
int nu;
cout<<"if you want to sort book press 1"<<endl;
cout<<"if you want to back main menu press 2"<<endl;
cin>>nu;

if(nu==1){

////////////////////// sorting
fstream myfile;

    // opening file
    myfile.open("book.txt");
    if (myfile.fail())
    {
        cout << "Error Opening File" << endl;
        exit(1);
    }

    // reading data and storing data
    vector<double> x;
    double tmp;
    while (myfile >> tmp)
    {
        x.push_back(tmp);
    }
    myfile.close();
    cout <<"there are "<< x.size() << " books in database of program " << endl;

  

    // sorted print data from vector
    sort(x.begin(), x.end(), sort_book);
    for (vector<double>::iterator it = x.begin(); it != x.end(); ++it)
    {
        cout << *it <<"-year "<< endl;
    }
    
}
if(nu==2)
{

	main();
}

//////////////sorting end
}
	



void adminlogin(void)
{	string name_admin;
	system("CLS");
	int id_admin;
	string password_admin;
cout<<"1.log in system"<<endl;
cout<<"2.create account"<<endl;
  
  int loginnumber;
  cin>>loginnumber;
	system("CLS");
if(loginnumber==1)
{
   ifstream login_admin("newmember.txt");

	
	
		string name1_admin;
	
	int id1_admin;
	
	string password1_admin;
	
	system("CLS");
	
	cout<<"please log in your name :";
	
	cin>>name1_admin;
	cout<<"please log in your id  :";
	cin>>id1_admin;
	cout<<"please log in your password : ";
	cin>>password1_admin;
	
	while(login_admin>>name_admin>>id_admin>>password_admin)
	{
	if(name1_admin==name_admin && id1_admin==id_admin && password_admin==password1_admin)
	{ 
	system("cls");
	  cout<<"welcome Dear "<<name1_admin<<endl;
	  cout<<"please Dear  "<<name1_admin<<"jon  select any one"<<endl;
	  
	   
	  	cout<<"1.view librarians"<<endl;
		cout<<"2.add librarians "<<endl;
		cout<<"3.modify librarian"<<endl;
		cout<<"4.delete librarian"<<endl;
	 int libnumber;
	 cin>>libnumber;
	 switch(libnumber)
	 {
	 		case 1:
				view_librarian();	
					break;
					case 2:
                        add_librarian();
						
						break;
						
						case 3:
							modify_librarian();
							break;
							case 4:
								delete_librarian();
							break;
	  
	  
	}}
/*	else{
	
	cout<<"please create account first"<<endl;

	}*/
	
	}}
if(loginnumber==2)
	{
	
//	string name_admin;
//  int id_admin;
//  string password_admin;
   ofstream newmember("newmember.txt", ios::app);
	cout<<"Please enter your name : ";
	cin>>name_admin;
	cout<<"enter your id :";
	cin>>id_admin;
	cout<<"enter your password :";
	
	cin>>password_admin;
	newmember<<name_admin<<"  "<<id_admin<<"  "<<"  "<<password_admin<<endl;
	newmember.close();

	
//	cin.get();
//	main();
	
}}

/*void create_account()
{ string name;
  int id;
  string password;
   ofstream newmember("newmember.txt", ios::app);
	cout<<"Please enter your name : ";
	cin>>name;
	cout<<"enter your id :";
	cin>>id;
	cout<<"enter your password :";
	
	cin>>password;
	newmember<<name<<"  "<<id<<"  "<<"  "<<password<<endl;
	newmember.close();
  //main();
 
}
*/

/*void login()
{   ifstream login("newmember.txt");
	string name;
	int id;
	string password;
		string name1;
	int id1;
	string password1;
	system("CLS");
	cout<<"please log in your name :";
	
	cin>>name1;
	cout<<"please log in your id  :";
	cin>>id1;
	cout<<"please log in your password : ";
	cin>>password1;
	
	while(login>>name>>id>>password)
	{
	if(name1==name && id1==id && password==password1)
	{ system("cls");
		cout<<"welcome Dear "<<name1;
	}

	}
	cin.get();
	//main();
	
	
}*/




void back()
{
	main();
}
void add_librarian()
{
 string name_librarian;
  int id_librarian;
  string password_librarian;
   ofstream librarian("librarian.txt", ios::app);
	cout<<"Please enter name of librarian : ";
	cin>>name_librarian;
	cout<<"enter id of librarian :";
	cin>>id_librarian;
	cout<<"enter password of librarian :";
	
	cin>>password_librarian;
	librarian<<name_librarian<<"  "<<id_librarian<<"  "<<"  "<<password_librarian<<endl;
	librarian.close();
		
}
void view_librarian()
{
	ifstream librarian("librarian.txt");
	librarian.open("librarian.txt");
	string name_librarian;
	int id_librarian;
	string password_librarian;
	string name1_librarian;
	int id1_librarian;
	string password1_librarian;
	system("CLS");
	cout<<"please log in your name aka :"; 
	librarian>>name_librarian>>id_librarian>>password_librarian;
	cin>>name1_librarian;
	cout<<"please log in your id  :";
	cin>>id1_librarian;
	cout<<"please log in your password : ";
	cin>>password1_librarian;
	
	while(librarian>>name1_librarian>>id1_librarian>>password1_librarian)
	{
	cout<<name1_librarian; cout<<name_librarian;
	if(name1_librarian==name_librarian && id1_librarian==id_librarian && password_librarian==password1_librarian)
	{
		cout<<"welcome Dear "<<name1_librarian<<"  i know you are very good librarian";
	}
	else
	cout<<"there is no any librarian with this name"<<endl;
	}
}
void modify_librarian()
{
	cout<<"1.To change ID"<<endl;
	cout<<"2.To change Password"<<endl;
	int number_modify;
	cin>>number_modify;
	if(number_modify==1)
{
	cout<<"please write your current Id"<<endl;
	int id_librarian;
	int id_librarian_new;
	cin>>id_librarian;
	cout<<"please enter your new Id";
	cin>>id_librarian_new;
	id_librarian=id_librarian_new;
	ifstream mod("librarian.txt");
	mod>>id_librarian_new;
	
	}
	if(number_modify==2)
	{
		cout<<"please write your current Password"<<endl;
		int password_librarian;
		int password_librarian_new;
		cin>>password_librarian;
		cout<<"please enter your new password";
		cin>>password_librarian_new;
		password_librarian=password_librarian_new;	
	}
}
 void delete_librarian()
{ string name_librarian;
  cout<<"Please enter the name of the user to be deleted "<<endl;
  
  string librarian_name; 
 
  cin>>librarian_name;
   
   ofstream librarian("librarian.txt");
  
  ifstream namein;
  
  namein.open("librarian.txt");
  
  ofstream nameout;
  
  nameout.open("new.txt");
  
  namein>>name_librarian; 
  
  while(!namein.eof())
{
if(name_librarian!=librarian_name)
{
	nameout<<name_librarian; 
	}
	namein>>name_librarian;
		
	}
	namein.close();
	
	nameout.close();
	
	remove("librarian.txt");
	
	rename("new.txt","librarian.txt")	;
}
void  view_book()
{
		ifstream librarian("book.txt");
		
		ofstream book("book.txt");
		
		book.open("book.txt");
		
		string book_name;
		string book_name1;
	  //  string book_subject1;
	//    int book_date1;
	
	system("CLS");
	
	cout<<"please enter book name: "; 
	cin>>book_name1;

	
	while(librarian>>book_name1)
	{
		
	if(book_name==book_name1)
	
	{   system("cls");
		cout<<"the book you are searching is  "<<book_name;
	}
	
	else
	
	cout<<"there is no any book with this name"<<endl;

	}
}
void add_book()
{
	string book_name;
    string book_subject;
    int book_date;
  
    ofstream book("book.txt", ios::app);
    
	cout<<"Please enter name of book : ";
	cin>>book_name;
	
	cout<<"enter subject of the book :";
	cin>>book_subject;
	
	cout<<"please enter the published date of the book :";
	cin>>book_date;
	
	book<<book_name<<"  "<<book_subject<<"  "<<"  "<<book_date<<endl;

	
		
}
void modify_book()
{
cout<<"1.To change book subject"<<endl;
	cout<<"2.To change published date "<<endl;
	int number_modify;
	cin>>number_modify;
	if(number_modify==1)
{
	cout<<"please write current subject of the book"<<endl;
	string subject_book;
	string subject_book_new;
	cin>>subject_book;
	cout<<"please enter your new subject of the book ";
	cin>>subject_book_new;
	subject_book=subject_book_new;
	
	}
	if(number_modify==2)
	{
		cout<<"please write published date of the book"<<endl;
		string book_date;
		int book_date_new;
		cin>>book_date;
		cout<<"please enter your new date";
		cin>>book_date_new;
		book_date=book_date_new;	
	}	
}
void delete_book()
{
 string book_name1;
  cout<<"Please enter the name of the book to be deleted "<<endl;
  
  string book_name; 
 
  cin>>book_name;
   
   ofstream librarian("book.txt");
  
  ifstream namein;
  
  namein.open("book.txt");
  
  ofstream nameout;
  
  nameout.open("new.txt");
  
  namein>>book_name; 
  
  while(!namein.eof())
{
if(book_name!=book_name1)
{
	nameout<<book_name; 
	}
	namein>>book_name1;
		
	}
	namein.close();
	
	nameout.close();
	
	remove("book.txt");
	
	rename("new1.txt","book.txt")	;	
}

void liblogin()
{
	string name_lib;
	int id_lib;
	string password_lib;
cout<<"1.log in system"<<endl;
cout<<"2.create account"<<endl;
  
  int loginnumber;
  cin>>loginnumber;

if(loginnumber==1)
{
   ifstream login_lib("newmember_lib.txt");

	
	
		string name1_lib;
	
	int id1_lib;
	
	string password1_lib;
	
	system("CLS");
	
	cout<<"please log in your name :";
	
	cin>>name1_lib;
	cout<<"please log in your id  :";
	cin>>id1_lib;
	cout<<"please log in your password : ";
	cin>>password1_lib;
	
	while(login_lib>>name_lib>>id_lib>>password_lib)
	{
	if(name1_lib==name_lib && id1_lib==id_lib && password_lib==password1_lib)
	{ system("cls");
	  cout<<"welcome Dear "<<name1_lib<<endl;
	  cout<<"please Dear  "<<name1_lib<<"jon  select any one"<<endl;
	  
	   
	  	cout<<"1.view librarians"<<endl;
		cout<<"2.add librarians "<<endl;
		cout<<"3.modify librarian"<<endl;
		cout<<"4.delete librarian"<<endl;
	 int libnumber;
	 cin>>libnumber;
	 switch(libnumber)
	 {
	 		case 1:
				view_librarian();	
					break;
					case 2:
                        add_librarian();
						
						break;
						
						case 3:
							modify_librarian();
							break;
							case 4:
								delete_librarian();
							break;
	  
	  
	}
	}
	else{
	
	cout<<"please create account first"<<endl;

	}
	
	}}
if(loginnumber==2)
	{
	
//	string name_admin;
//  int id_admin;
//  string password_admin;
   ofstream newmember_lib("newmember_lib.txt", ios::app);
	cout<<"Please enter your name : ";
	cin>>name_lib;
	cout<<"enter your id :";
	cin>>id_lib;
	cout<<"enter your password :";
	
	cin>>password_lib;
	newmember_lib<<name_lib<<"  "<<id_lib<<"  "<<"  "<<password_lib<<endl;
	newmember_lib.close();

	
//	cin.get();
//	main();
	
}	
}
void student_log()
{
	string name_student;
	int id_student;
	string password_student;
cout<<"1.log in system"<<endl;
cout<<"2.create account"<<endl;
  
  int loginnumber;
  cin>>loginnumber;


if(loginnumber==1)
{
   ifstream login_stu("newmember_stu.txt");

	
	
		string name1_student;
	
	int id1_student;
	
	string password1_student;
	
	system("CLS");
	
	cout<<"please log in your name :";
	
	cin>>name1_student;
	cout<<"please log in your id  :";
	cin>>id1_student;
	cout<<"please log in your password : ";
	cin>>password1_student;
	
	while(login_stu>>name_student>>id_student>>password_student)
	{
	if(name1_student==name_student && id1_student==id_student && password_student==password1_student)
	{ system("cls");
	  cout<<"welcome Dear "<<name1_student<<endl;

	  
	}
	}

	
	}
	
	
if(loginnumber==2)
	{
//	string name_admin;
//  int id_admin;
//  string password_admin;
   ofstream newmember_stu("newmember_stu.txt", ios::app);
	cout<<"Please enter your name : ";
	cin>>name_student;
	cout<<"enter your id :";
	cin>>id_student;
	cout<<"enter your password :";
	
	cin>>password_student;
	newmember_stu<<name_student<<"  "<<id_student<<"  "<<"  "<<password_student<<endl;
	newmember_stu.close();

	
//	cin.get();
//	main();
}
}


static bool sort_book(double p , double q)
{ 
 return p>q;
}

