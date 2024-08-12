#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>
using namespace std;
void labelMenu();
void selectMenu();
void registeration(){
	system("CLS");
		cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl
		<<"|                                              PEARL CONTIENTIAL HOTEL                                               |"<<endl
		<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
	string name,checkname,pass;
	bool samename;
	ifstream check_name("username.txt");
	do{
	cout<<"Enter a username : ";
	getline(cin,name);
	samename = false;
	check_name.clear();
	check_name.seekg(0,ios::beg);
	while(check_name.eof()==0){
		getline(check_name,checkname);
		if(checkname==name){
			samename = true;
			cout<<"This username is already taken .";
			Sleep(1000);
			system("CLS");
			break;
		}
	}
	}while(samename);
	check_name.close();
	ofstream savename("username.txt",ios::app);
	savename<<name<<endl;
	savename.close();
	system("CLS");
		cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl
		<<"|                                              PEARL CONTIENTIAL HOTEL                                               |"<<endl
		<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Creat a password : ";
	getline(cin,pass);
	ofstream savepass("password.txt",ios::app);
	savepass<<pass<<endl;
	savepass.close();
	labelMenu();
}
void login(){
	string name,checkname;
	bool samename;
	ifstream check_name("username.txt");
	do{
	system("CLS");
		cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl
		<<"|                                              PEARL CONTIENTIAL HOTEL                                               |"<<endl
		<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Enter a username : ";
	getline(cin,name);
	samename = false;
	check_name.clear();
	check_name.seekg(0,ios::beg);
	while(check_name.eof()==0){
		getline(check_name,checkname);
		if(checkname==name){
			samename = true;
			break;
		}
	}
	if(!(samename)){
		system("CLS");
			cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl
		<<"|                                              PEARL CONTIENTIAL HOTEL                                               |"<<endl
		<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"Wronge Username .";
		Sleep(1000);
	}
	}while(!(samename));
	check_name.close();
	string pass,checkpass;
	bool samepass;
	ifstream check_pass("password.txt");
	do{
		system("CLS");
			cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl
		<<"|                                              PEARL CONTIENTIAL HOTEL                                               |"<<endl
		<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Enter a password : ";
	getline(cin,pass);
	samepass = false;
	check_pass.clear();
	check_pass.seekg(0,ios::beg);
	while(check_pass.eof()==0){
		getline(check_pass,checkpass);
		if(checkpass==pass){
			samepass = true;
			break;
		}
	}
	if(!samepass){
		cout<<"Wronge password";
		Sleep(1000);
		system("CLS");
	}
	}while(!(samepass));
	check_name.close();
	labelMenu();
}
class Room
{
public:
	int  booked_rooms, available_rooms, total_rooms;
	virtual bool features()
	{
		return false;
	}
	
	Room()
	{
		
	}

	Room(int booking, int available_rooms, int total)
	{

		booked_rooms = booking;
		this->available_rooms = available_rooms;
		total_rooms = total;
	}

};

class VIP_Room : public Room
{
	int charges;
	int booked_rooms;
	int available;
	int total;
public:

	VIP_Room()
	{

	}

	VIP_Room(int charges, int booked, int available_room, int total)
	{
		this->charges = charges;
		booked_rooms = booked;
		available = available_room;
		this->total = total;
	}
	bool features(VIP_Room& obj);
};
bool VIP_Room::features(VIP_Room& obj)
{
	system("cls");
		cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl
		<<"|                                              PEARL CONTIENTIAL HOTEL                                               |"<<endl
		<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout << "**Welcome to VIP room**" << endl;
	cout << "The total  vip rooms are : " << obj.total << endl;
	cout << "The booked vip rooms are : " << obj.booked_rooms << endl;
	cout << "The available vip rooms are : " << obj.available << endl;
	cout << "The charges of vip rooms are : " << obj.charges << endl;
label:
	cout << "ARE YOU INTERESTED IN IT!!!!" << endl;
	cout << "y/n" << endl;
	char choice;
	cin >> choice;
	if (choice == 'y' || choice == 'Y')
	{
		cout << "Enter days to checkout!!!!" << endl;
		int days, fares = obj.charges;
		cin >> days;
		fares *= days;
		cout << "Total charges will be : " << fares << endl;
	cout << "Please press y to confirm the transaction!!" << endl;
		char confirmation, confrim;
		cin >> confirmation;
		if (confirmation == 'y' || confirmation == 'Y')
		{
			cout << "The trasaction has been successfull!!!!" << endl;
			cout << "Room is booked!!!!" << endl;
			obj.booked_rooms += 1;
			obj.available -= 1;
			cout << "Press y for home page again!!!" << endl;
			cin >> confrim;
			if (confrim == 'y')
			{
				return false;
			}
		}
		return true;
	}
	else if (choice == 'n' || choice == 'N')
	{
		return false;
	}
	else
	{
		cout << "Wrong input please try again!!!!" << endl;
		goto label;
	}
}

class Suite_Room : public Room
{
	int charges;
	int total;
	int available;
	int booked;
public:

	Suite_Room()
	{

	}
	Suite_Room(int charges, int booking, int available, int total)
	{
		this->charges = charges;
		booked = booking;
		this->available = available;
		this->total = total;
	}
	bool features(Suite_Room& obj)
	{
		system("cls");
			cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl
		<<"|                                              PEARL CONTIENTIAL HOTEL                                               |"<<endl
		<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
		cout << "**Welcome to single room**" << endl;
		cout << "The total     Suite rooms are : " << obj.total << endl;
		cout << "The booked    Suite rooms are : " << obj.booked << endl;
		cout << "The available Suite rooms are : " << obj.available << endl;
		cout << "The charges of Suite rooms are : " << obj.charges << endl;
	label:
		cout << "ARE YOU INTERESTED IN IT!!!!" << endl;
		cout << "y/n" << endl;
		char choice;
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
		{
			cout << "Enter days to checkout!!!!" << endl;
			int days, fares = obj.charges;
			cin >> days;
			fares *= days;
			cout << "Total charges will be : " << fares << endl;
			cout << "Please press y to confirm the transaction!!" << endl;
			char confirmation, confrim;
			cin >> confirmation;
			if (confirmation == 'y' || confirmation == 'Y')
			{
				cout << "The trasaction has been successfull!!!!" << endl;
				cout << "Room is booked!!!!" << endl;
				obj.booked += 1;
				obj.available -= 1;
				cout << "Press y for home page again!!!" << endl;
				cin >> confrim;
				if (confrim == 'y')
				{
					return false;
				}
				return true;
			}
		}
		else if (choice == 'n' || choice == 'N')
		{
			return false;
		}
		else
		{
			cout << "Wrong input please try again!!!!" << endl;
			goto label;
		}
	return true;
	}
};

class Single_room : public Room
	{
		int charge;
		int booking;
		int available;
		int total;
	public:

		Single_room()
		{

		}

		Single_room(int charges, int booking, int available, int total)
		{
			this->charge = charges;
			this->booking = booking;
			this->available = available;
			this->total = total;
		}
		bool features(Single_room& obj)
		{
			system("cls");
				cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl
		<<"|                                              PEARL CONTIENTIAL HOTEL                                               |"<<endl
		<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
			cout << "**Welcome to single room**" << endl;
			cout << "The total single rooms are : " << obj.total << endl;
			cout << "The booked single rooms are : " << obj.booking << endl;
			cout << "The available single rooms are : " << obj.available << endl;
			cout << "The charges single rooms are : " << obj.charge << endl;
		label:
			cout << "ARE YOU INTERESTED IN IT!!!!" << endl;
			cout << "y/n" << endl;
			char choice;
			cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				cout << "Enter days to checkout!!!!" << endl;
				int days, fares = obj.charge;
				cin >> days;
				fares *= days;
				cout << "Total charges will be : " << fares << endl;
				cout << "Please press y to confirm the transaction!!" << endl;
				char confirmation, confrim;
				cin >> confirmation;
				if (confirmation == 'y' || confirmation == 'Y')
				{
					cout << "The trasaction has been successfull!!!!" << endl;
					cout << "Room is booked!!!!" << endl;
					obj.booking += 1;
					obj.available -= 1;
					cout << "Press y for home page again!!!" << endl;
					cin >> confrim;
					if (confrim == 'y')
					{
						return false;
					}
				}
				return true;
			}
			else if (choice == 'n' || choice == 'N')
			{
				return false;
			}
			else
			{
				cout << "Wrong input please try again!!!!" << endl;
				goto label;
			}

		}

	};


void selectMenu(){
	while(true){
	
		system("CLS");
			cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl
		<<"|                                              PEARL CONTIENTIAL HOTEL                                               |"<<endl
		<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
		int ch;
		cout<<"1. Registration."<<endl
		<<"2. Login."<<endl
		<<"3. Exit.";
		switch(ch=getch()){
			case 49:
				registeration();
				break;
			case 50:

				login();
				break;
			case 51:
				exit(0);
			default :
				break;
		}
	}
}

void labelMenu(){
        Single_room obj(5000, 15, 35, 50);
		VIP_Room obj2(8000, 3, 22, 25);
		Suite_Room obj3(10000, 5, 30, 35);
		label:
			system("CLS");
				cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl
		<<"|                                              PEARL CONTIENTIAL HOTEL                                               |"<<endl
		<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
			cout << "**Welcome to Home page**" << endl;
			cout << "1. Single room" << endl;
			cout << "2. Vip room" << endl;
			cout << "3. Suite room" << endl;
			cout << "4. Log Out" << endl;
			int choice;
			switch (choice=getch())
			{
			 case 49:
				while (!obj.features(obj))
				{
					goto label;
				}
	
				break;
			 case 50:
				while (!obj2.features(obj2))
				{
					goto label;
				}
				break;
			 case 51:
				while (!obj3.features(obj3))
				{
					goto label;
				}
				break;
			 case 52:
                selectMenu();
				break;
			 default:
				cout << "Wrong input" << endl;
				break;
			}
	
//			system("pause");	
}
int main()
{
	system("COLOR 0A");
        selectMenu();
			return 0;
}
