// Student_Management_Sysem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<conio.h>
#include<stdlib.h>

using namespace std;

void show_data(int searchkey);
void get_data(int i);
void search_student(int search);
void add_student();
void edit_student(int idnumber);
void fullscreen();
int ts;

struct student { //structure=> farklý tiplerden deðiþken tiplerini tek bir çatý altýnda toplamayý saðlayan veri türü yapýsý
	int rollno;
	string name;
	string fname;
	string address;
	string cell;
	string dob;
};

student rec[50];

int main()
{
	system("CLS");

	int choice;
	int IdNumber;
	int searchkey;


	cout << "Enter The Total Number Students -MAX 50- :";
	cin >> ts;

	while (ts--) {
		cout << "\n\tWhat do you want to do ?" << endl;
		cout << "-------------------------------- - " << endl;
		cout << "\t\t1 - Add Student" << endl;
		cout << "\t\t2 - Edit Student" << endl;
		cout << "\t\t3 - Search Student" << endl;
		cout << "\t\t4 - Exite program" << endl;
		cout << "------------------------------------" << endl;
		cout << "Enter Your Choice : ";

		cin >> choice;

		switch (choice)
		{
		case 1:  //if user  press 1  student adding module would be display
			add_student();
			break;
		case 2:
			if (rec[0].rollno == 0) //if there is no record in array then it will ask to enter the student info
			{
				cout << "<please Add Student First." << endl;
				system("pause");
				main();

			}
			else // dizied kayýtlar varsa tabloda gösterilir
			{
				cout << endl;
				cout << "-----------------------------------------------" << endl;
				cout << "---------student record table-------------------" << endl;
				cout << "--------------------------------------------------" << endl;
				cout << "ID   " << "NAME-SURNAME   " << "FATHER/ TCELL NO   " << "ROLL   " << "DOB   " << "ADDRESS\n\n";
				cout << "-------------------------------------------------;" << endl;

				for (int i = 0; i < ts; i++) {
					show_data(i); //funtion is called with index value for show the data 
				}
				cout << "-----------------------------------------------------" << endl;
				cout << "Which ID Number You Want To Edit ?" << endl;
				cin >> IdNumber;

				if (IdNumber > ts || IdNumber < 0)
				{
					cout << "Invalid ID Number" << endl;
				}
				else {
					edit_student(IdNumber); //düzenleme fonksiyonuna kimlik numarasýnýn aktarýlmasý
				}

			}
			break;

		case 3:
			if (rec[0].rollno == 0) //if there is no record then ask to user add record
			{
				cout << "Please Add Student First." << endl;
				system("pause");
				main();
			}
			else {
				cout << "enter roll number of student you want to search:";
				cin >> searchkey; // roll no as the search key be entered by user.

				search_student(searchkey);
			}
			break;
		case 4:
			return 0; // Terminating the records= kayýtlarýn sonlandýrýlmasý
			break;

		default:  //default value for invalid input
			cout << "Invalid number." << endl;
			system("pause");

			main();
		}
	}
	return 0;
}

void get_data(int i)//Function for receiving data from user and populatiing the variables with values=> kullanýcýdan deðer alma ve bu deðerlerle tabloyu doldurma iþlevi
{
	cout << "Enter student roll number in formal (1XXX): ";
	cin >> rec[i].rollno;
	cout << "Enter student name: ";
	cin >> rec[i].name;
	cout << "Enter student's father name :";
	cin >> rec[i].fname;
	cout << "Enter student's cell phone number :";
	cin >> rec[i].cell;
	cout << "Enter student's date of birth (dd/mm/yyyy)";
	cin >> rec[i].dob;
	cout << "Enter student's address: ";
	cin >> rec[i].address;
}

void show_data(int searchkey) {

	int i = searchkey;
	cout << i << "  ";
	cout << rec[i].rollno << "  ";
	cout << rec[i].name << " ";
	cout << rec[i].fname << "\t ";
	cout << rec[i].cell << " ";
	cout << rec[i].dob << " ";
	cout << rec[i]. address<< " \n\n";

}
void search_student(int searchkey) {
	for (int i = 0; i <= ts; i++) {
		if (rec[i].rollno == searchkey)  //if roll number matches to search number
		{
			cout << "ID  " << "Roll  " << "Name  " << "Father\tCell no  " << "DOB  " << "Address\n\n  ";
			show_data(i);  //a function used inside other funciton 
		}
	}

}

void add_student() //this funciton is for adding new student record 
{
	for (int i = 0; i < ts; i++) {
		get_data(i);
		               //Loop was processed 5 times to get input for 5 students.
		
	}

	system("CLS");
	cout << endl;

	cout << "--------------------------------------------------" << endl;		
	cout << "------------------Student Record Table--------------" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "ID " << "Roll " << "Name " << "Father\tCell no. " << "DOB " << "Address\n\n	" << endl;

	for (int i = 0; i < ts; i++) {
		show_data(i);   // loop was processed for 5 times to show obtained (elde edilmiþ)  record

	}
	cout << "----------------------------------------------------" << endl;
	cout << "--------------------FINISH-----------------------------" << endl;
	cout << "---------------------------------------------------------" << endl;
	system("pause");

	main(); // return to main funciton to again show menu
}

void edit_student(int idnumber) {
	for (int i = 0; i < ts; i++) {
		if (idnumber == i)
		{
			cout << "\nExisted information about record.\n\n";
			cout << "-----------------------------------------------------------" << endl;
			cout << "ID " << "Roll " << "Name " << "Father\tCell no. " << "DOB ";
			cout << "-------------------------------------------------------------" << endl;
			
			show_data(i);
			cout << "\n\nEnter new data for above show record. \n\n";
			get_data(i);
			cout << "\n\nRecord update successfully. " << endl;
			system("pause");
			main();

		}
	}
	
}