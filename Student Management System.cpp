#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <conio.h>

using namespace std;

// Student structure for linked list
struct student    
{
	int id, age;
	char name[100];
	char phone[100];
	char address[100];
	char department[100];
	char date[100];
	student *next; // Pointer
};
student *head; //Head Pointer

// Function For Loading !
void fordelay(int j)
{   
	int i,k;
    for(i=0; i<j; i++){
    	k=i;
	}
}

// Add Record Of A Student //
void add(int id, char* name, char* phone, int age, char* address, char* department)    
{
	// current date/time based on current system
   	time_t now = time(0); 
	     
   	// convert now to string form
   	char* dt = ctime(&now);

	student *stu = NULL;
	stu = (struct student *) malloc(sizeof(struct student));
	
	stu -> id = id;
	strcpy(stu -> name, name);
	strcpy(stu -> phone, phone);
	strcpy(stu -> address, address);
	strcpy(stu -> department, department);
	strcpy(stu -> date, dt);
	stu -> age = age;
	stu -> next = NULL;
	
	if(head == NULL){
		head = stu;  // set student as the new head
	}
	else{
		stu -> next = head;  // insert student in beginning of head
		head = stu;
	}
	cout<<"\nYour Record Have been Added !";
	cout<<"\nPress Any Key To Continue . . . ";
	getch();
}

// Update Record Of A Student //
void update(int id)   
{
	student *temp = head;
	while(temp != NULL)
	{
		if(temp -> id == id) {
			cout<<"\tRecord with Student ID "<<id<<" is Found !!!"<<endl;
			cout<<"\t==============================================="<<endl;
			cout<<"\tStudent Name: ";
			cin.ignore();
            cin.getline(temp -> name, 100);
            cout<<"\tStudent Phone Number: ";
            cin>>temp -> phone;
            cout<<"\tStudent Age: ";
            cin>>temp -> age;
            cout<<"\tStudent Address: ";
            cin.ignore();
            cin.getline(temp -> address, 100);               
            cout<<"\tDepartment: ";
            cin>>temp -> department;
			printf("\tUpdation Successful!!!\n");
			cout<<"\nPress Any Key To Continue . . . ";
			getch();
			return;
		}
		temp = temp -> next;
	}
	cout<<"Record with Student ID "<<id<<" is not found !!!";
	cout<<"\n\nPress Any Key To Continue . . . "<<endl;
	getch();
}

// Searches Record Of A Student //
void search(int id)   
{
	student *temp = head;
	while(temp != NULL){
		if(temp -> id == id){
			cout<<"\n\tName: "<<temp -> name;
			cout<<"\n\tPhone No: "<<temp -> phone;
			cout<<"\n\tAge: "<<temp -> age;
			cout<<"\n\tAddress: "<<temp -> address;
			cout<<"\n\tDepartment: "<<temp -> department;
			cout<<"\n\tDate: "<<temp -> date;
			cout<<"\n\nPress Any Key To Continue . . . ";
			getch();
			return;
		}
		temp = temp -> next;
	}
	cout<<"Record with Student ID "<<id<<" is not found !!!";		
	cout<<"\n\nPress Any Key To Continue . . . ";
    getch();
}

// Deletes Record Of A Student //
void del(int id)    
{
	student *temp1 = head;
	student *temp2 = head; 
	while(temp1 != NULL)
	{	
		if(temp1 -> id == id){
			cout<<"\tRecord with Student ID "<<id<<" is Found !!!"<<endl;
			cout<<"\t=========================================== \t"<<endl;
			if(temp1 == temp2)
			{
				// this condition will run if
				// the record that we need to delete is the first node
				// of the linked list
				head = head -> next;
				free(temp1);
			}
			else{
				// temp1 is the node we need to delete
				// temp2 is the node previous to temp1
				temp2 -> next = temp1 -> next;
				free(temp1); 
			}
			cout<<"\nRecord Successfully Deleted !!!";
			cout<<"\nPress Any Key To Continue . . . ";
			getch();
			return;
		}
		temp2 = temp1;
		temp1 = temp1 -> next;
	}
	cout<<"Record with Student ID "<<id<<" is not found !!!";
	cout<<"\nPress Any Key To Continue . . . ";
	getch();
}

// Display Record Of A Student //
void display()
{
	int no = 1;
	cout<<"\t\t\t\t\t =========================================== \t"<<endl;
	cout<<"\t\t\t\t\t\t STUDENT MANAGEMENT SYSTEM \t"<<endl;	   	
	cout<<"\t\t\t\t\t =========================================== \t"<<endl<<endl;
	
    student * temp = head;
    if(temp != NULL) {
    		cout<<"\n\t\t\t\t\t\t\tSTUDENTS DETAILS: "<<endl;
			cout<<"\t=================================================================================================================="<<endl;
			cout<<"\t S.No\tSTU_ID\tNAME\t\tPHONE\t\tAGE\tADDRESS\t\tDEPARTMENT\tDATE/TIME"<<endl;
			cout<<"\t=================================================================================================================="<<endl;
    	while(temp != NULL) {	
    		cout<<"\t  "<<no;
			cout<<"\t"<<temp -> id;
			cout<<"\t"<<temp -> name;
			cout<<"\t"<<temp -> phone;
			cout<<"\t"<<temp -> age;
			cout<<"\t"<<temp -> address;
			cout<<"\t\t"<<temp -> department;
			cout<<"\t\t"<<temp -> date;
			cout<<endl;
			temp = temp -> next;
			no++;
    	}
    	cout<<"\t=================================================================================================================="<<endl;
    	cout<<endl;
  	}
	else {
    	cout<<"The list is empty.\n";
  	}
	cout<<"\nPress Any Key To Continue . . . ";
	getch();
}

int main()
{
	head = NULL;
    char name[100];
    char phone[100];
    char address[100];
    char department[100];
    int id, age;
	char x;
	
	cout<<"\t\t =========================================== \t"<<endl;
	cout<<"\t\t\t STUDENT MANAGEMENT SYSTEM \t"<<endl;	   	
	cout<<"\t\t =========================================== \t"<<endl;
	cout<<"\n\nPress Any Key To Continue . . . "<<endl;
	getch();
	
	cout<<"loading";
	for(int i=0;i<=6;i++)
	{
		fordelay(100000000);
		cout<<".";
	}
	system("cls");
	
	do{
		system("cls");
		cout<<"\t\t =========================================== \t"<<endl;
		cout<<"\t\t\t STUDENT MANAGEMENT SYSTEM \t"<<endl;	   	
		cout<<"\t\t =========================================== \t"<<endl;
		cout<<"\n\t1: Insert Student Record:"<<endl;
		cout<<"\t2: Search Student Record:"<<endl;
		cout<<"\t3: Update Student Record:"<<endl;
		cout<<"\t4: Delete Student Record:"<<endl;
		cout<<"\t5: Display Students Record:"<<endl;
		cout<<"\t6: Exit:"<<endl;
	  	cout<<"\nEnter Valid Choice: ";
		x=getch();
		
		switch(x){
			case '1':
				system("cls");				
				cout<<"\t\t =========================================== \t"<<endl;
				cout<<"\t\t\t STUDENT MANAGEMENT SYSTEM \t"<<endl;	   	
				cout<<"\t\t =========================================== \t"<<endl<<endl;
				
				cout<<"\tStudent Name: ";
                cin.getline(name, 100);
				cout<<"\tStudent ID: ";
                cin>>id;
                cout<<"\tStudent Phone Number: ";
                cin>>phone;
                cout<<"\tStudent Age: ";
                cin>>age;
                cout<<"\tStudent Address: ";
                cin.ignore();
                cin.get(address, 100);               
                cout<<"\tDepartment: ";
                cin>>department;
                cin.ignore();
				 
                add(id, name, phone, age, address, department);
			break;
			case '2':
				system("cls");
				cout<<"\t\t =========================================== \t"<<endl;
				cout<<"\t\t\t STUDENT MANAGEMENT SYSTEM \t"<<endl;	   	
				cout<<"\t\t =========================================== \t"<<endl<<endl;
				
				cout<<"\tStudent ID: ";
                cin>>id;
		   		search(id);
		   		cin.ignore();
			break;
			case '3':
				system("cls");
				cout<<"\t\t =========================================== \t"<<endl;
				cout<<"\t\t\t STUDENT MANAGEMENT SYSTEM \t"<<endl;	   	
				cout<<"\t\t =========================================== \t"<<endl<<endl;
				
				cout<<"\tStudent ID: ";
                cin>>id;
		   		update(id);
		   		cin.ignore();
	 		break;
			case '4':
				system("cls");
				cout<<"\t\t =========================================== \t"<<endl;
				cout<<"\t\t\t STUDENT MANAGEMENT SYSTEM \t"<<endl;	   	
				cout<<"\t\t =========================================== \t"<<endl<<endl;
				
				cout<<"\tStudent ID: ";
                cin>>id;
		   		del(id);
		   		cin.ignore();
			break;
			case '5':
				system("cls");
		   		display();		
			break;
			case '6':
				system("cls");
		   		exit(0);		
			break;
		}
	}
	while(x != 0);
 
	getch();
	return 0;
}
