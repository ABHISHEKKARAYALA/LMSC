#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<conio.h>
using namespace std;
class Library{
	public:
	char b_name[100],a_name[20],namee[30],AutherName[40],name[20];
	int reg_no,num,books,ISBN_NO,admin_no,fin,date,count; 
	void input_Book();
	void show_data();
	void student();
	void lib();
	void input_student();
	void show_student();
	void input();
	void issue();
	void Return();
	void fine();
	void main_menu();
};
void Library::input_Book(){
	    int a,isbn,i;
	    fstream obj;
	    obj.open("Books.txt",ios::app);
        cout<<"Please enter the name of the Book:";
        cin.ignore();
        cin.getline(b_name,100);
        obj<<b_name<<"\n";
        cout<<"\nEnter Auther Name:";
        cin.getline(a_name,40);
        obj<<a_name<<"\n";
		cout<<"Enter the ISBN:";
		cin>>isbn;
		obj<<isbn<<endl<<endl;
		cout<<"Book added Successfully"<<endl;
		obj.close();
		cout<<"***********";
		cout<<"\n\n1.Add More Books\n\n2.Main Menu\n\n3.exit from the application\n\n";
        cout<<"Please enter your choice: ";
        cin>>a;
        if(a == 1){
        system("cls");
        input_Book();
		}
		else if(a == 2){
			system("cls");
			input();
		}
		else {
			exit(1);
	    }  
}

void Library::input_student(){
			int f;
			fstream file;
			file.open("student.txt",ios::out);
			if(!file){
				 cout<<"\n\t\tFile Not Found.";
			}
			else{
			file.seekp(0);
			cout<<"Enter the Registration Number of the student: \n";
			cin>>reg_no;
			file<<reg_no<<"\n";
			cout<<"Enter the name of the Student: ";
			cin.ignore();
			cin.getline(name,20);
			file<<name;
		}
		file.close();
			cout<<"\n\nPlease select the choice: "<<endl;
			cout<<"\n\n1.View total Books Issued\n\n2.Return Book";
			cout<<"\nPlease enter your choice: ";
			cin>>f;
			if(f==1){
				show_student();
			
			}
			else if(f == 2){
				Return();
			}
			
			else{
				cout<<"please enter correct choice: ";
				input_student();
				
			}

		}
void Library::show_student(){
	        int count;
			fstream obb;
			obb.open("Issue.txt",ios::in);
			char ch;
			ch = obb.get();
			while(ch!=EOF){
				if(ch == '1'&&ch=='1'&&ch=='7'){
					count++;
				}
					ch = obb.get();
			}
			obb.close();
			cout<<"\nNumber of issued Books are: \n";
			cout<<count<<endl;

		}



	
void Library::lib(){
			cout<<"please enter the admin id: ";
			cin>>admin_no;
			
			if(admin_no == 1234){
				cout<<"\nyou sucessfully logged in\n\n";
				input();
			}
            else{
				cout<<"\nplease enter the correct admin id\n";
				lib();

			}
	    }
void Library::input(){
		        int a;
		        system("cls");
                cout<<"****************************************************************"<<endl;
				cout<<"\nSelect your choice: "<<endl;
				cout<<"\n1.Add Books\n\n2.Issue Books\n\n3.fine manage\n\n4.exit from the application\n\n"<<endl;
				cout<<"\nEnter your Choice: ";
				cin>>num;
				if(num == 1){
                         system("cls");
                         input_Book();
                         cout<<"\n\n1.Main Menu\n\n2.exit from the application\n\n";
                         cout<<"Please enter your choice: ";
                         cin>>a;
                         if(a == 1){
                                system("cls");
                                input();
                         }
                         else{
                            exit(1);
                         }
				}
				else if(num == 2){
                        issue();

				}
				else if(num == 3){
                        fine();

				}
				else if(num == 4){
                    exit(1);
				}
				else{
                    cout<<"Please enter the correct choice"<<endl;
                    input();
				}

			}

void Library::issue(){
	int a,dd,mm,yy;
	fstream obj3;
	obj3.open("Issue.txt",ios::app);
	if(!obj3){
		cout<<"File not Found"<<endl;
		exit(1);
	}
	else{
	cout<<"File opened Successfully"<<endl<<endl;
	cout<<"\nEnter Book Name: ";
	cin.ignore();
    cin.getline(namee,30);
    obj3<<namee<<"\n";
    cout<<"\nEnter Book's ISBN Number: ";
    cin>>ISBN_NO;
    obj3<<ISBN_NO<<"\n";
    cout<<"\nEnter Student Name: ";
    cin.ignore();
    cin.getline(name,20);
    obj3<<name<<"\n";
    cout<<"\nEnter Student's Registration number: ";
    cin>>reg_no;
    obj3<<reg_no<<"\n";
    cout<<"\nEnter date in format DDMMYY: ";
    cin>>dd>>mm>>yy;
    obj3<<dd<<"/"<<mm<<"/"<<yy<<endl;
    cout<<dd<<"/"<<mm<<"/"<<yy<<"\n\n";
    cout<<"Book Issued Sccessfully"<<endl;
    } 
    obj3.close();

    	cout<<"***********";
		cout<<"\n\n1.Main Menu\n\n2.exit from the application\n\n";
        cout<<"Please enter your choice: ";
        cin.ignore();
        cin>>a;
        if(a == 1){
        system("cls");
        input();
		}
        else{
        exit(1);
        }
    
}

void Library::Return(){
	int a,isb,j;
	cout<<"\nEnter ISBN Number of the Book: ";
	cin>>isb;
	cout<<"\nEnter days issueed for: ";
	cin>>date;
	cout<<"\nEnter the total days of issueing the book: ";
	cin>>j;
	fin = (j-date) * 10;
	cout<<"Total fine is: "<<fin<<endl;
	cout<<"\nBook returned Seccessfully"<<endl;
	cout<<"***********";
		cout<<"\n\n1.Main Menu\n\n2.exit from the application\n\n";
        cout<<"Please enter your choice: ";
        cin>>a;
        if(a == 1){
        system("cls");
        input();
		}
        else{
        exit(1);
        }
}
void Library::fine(){
	int a,j;
	cout<<"please enter the ISBN no: ";
		cin>>ISBN_NO;
	cout<<"Please enter the Days book have been issued for(1-15): ";
	cin>>date;
	if(date <= 15){
		cout<<"please enter the total days of issue the book: ";
		cin>>j;
		fin = (j - date) * 10;
		if(fin < 0){
			fin = 0;
			cout<<"\nTotal fine is: "<<fin<<endl; 
		}
		else{
		cout<<"\nTotal fine is: "<<fin<<endl;
	}
		cout<<"***********";
		cout<<"\n\n1.Main Menu\n\n2.exit from the application\n\n";
        cout<<"Please enter your choice: ";
        cin>>a;
        if(a == 1){
        system("cls");
        input();
		}
        else{
        exit(1);
        }
	}
	else{
		cout<<"Please enter the days according to Library Standard";
		fine();
	}
}

void Library::main_menu()
{
   int c;
        cout<<"\n\t ############ LIBRARY MANAGEMENT SYSTEM ###########\n";
        cout<<"\nSelect your choice \n";
        cout<<"\n1.Student\n2.Librarian\n3.exit from the Application\n";
        cout<<"\nEnter your choice : ";
        cin>>c;
        if(c==1)
        {
            system("cls");
            input_student();
        }
        else if(c==2)
            lib();

        else if(c==3)
            exit(0);
        else
        {
            cout<<"\n\t\tPlease enter correct option: ";
            system("cls");
           main_menu();
        }
}
int main(){
	Library l;
	l.main_menu();
	getch();
	return 0;
}
