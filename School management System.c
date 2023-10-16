#include<iostream>
#include<vector>

using namespace std;
class Student{
	private:
		int rollno,age;
		string name;
		public:
			Student(int stdRollno,string stdName,int stdAge){
				rollno=stdRollno;
				name=stdName;
				age=stdAge;
			}
			void setRollno(int stdRollno){
				rollno=stdRollno;
			}
			int getRollno(){
				return rollno;
			}
			void setName(string stdName){
				name=stdName;
			}
			string getName(){
				return name;
			}
			void setAge(int stdAge){
				age=stdAge;
			}
			int getAge(){
				return age;
			}
			void displayStudent(){
				cout<<"Roll No : "<<rollno<<endl;
				cout<<"Name :"<<name<<endl;
				cout<<"Age : "<<age<<endl;
			}
};
void updateStudent(vector<Student>& students){
	string sname;
	bool found=false;
	int choice;
	cout<<"\n\n\t\t\t\t\tEnter Name to Update Record : ";
	cin.ignore();
	getline(cin,sname);
	
	for (int i=0;i<students.size();i++){
		if(students[i].getName()==sname){
			found=true;
//			system ("cls");
	cout<<"\n\n\t\t\t\t\t  |------------------------------|"<<endl;
	cout<<"\t\t\t\t\t  |   Student Managment System   |"<<endl;
	cout<<"\t\t\t\t\t  |------------------------------|"<<endl;
	cout<<"\t\t\t\t\t  |1. Update Rollno              |"<<endl;
	cout<<"\t\t\t\t\t  |2. Update Name                |"<<endl;
	cout<<"\t\t\t\t\t  |3. Update Age                 |"<<endl;
	cout<<"\t\t\t\t\t  |------------------------------|"<<endl;
	cout<<"\n\t\t\t\t\t     Enter your Choice : ";
		cin>>choice;
		
		switch(choice){
			case 1:{
				int rno;
				cout<<"\t\t\t\t\tEnter New Rollno :";
				cin>>rno;
				students[i].setRollno(rno);
				break;
			}
		case 2:{
			string name;
			cout<<"\t\t\t\t\tEnter New Name : ";
			cin.ignore();
			getline(cin,name);
			students[i].setName(name);
			break;
		}
		case 3 :{
			int age;
			cout<<"\t\t\t\t\tEnter New Age : ";
			cin>>age;
			students[i].setAge(age);
			break;
		}
		default:
			cout<<"\t\t\t\t\tInvalid Number"<<endl;
		}
		}
		if(!found){
		cout<<"\t\t\t\t\tRecord Not Found"<<endl;
		return;	
		}
	}
}
void SearchStudent(vector<Student>& student){
	int rollno;
	cout<<"\t\t\t\t\tEnter Rollno : ";
	cin>>rollno;
	for(int i=0; i<student.size();i++){
		if(student[i].getRollno()==rollno){
			cout<<"\t\t\t\t ---------- Student Found ---------"<<endl;
			student[i].displayStudent();
			return;
		}
	}
}
void DisplayAllStudent (vector<Student>& students)
{
	if(students.empty())
	{
	cout<<"\t\t\t\t\t No Student Found"<<endl;
		return;
		
	}
	for(int i=0;i<students.size();i++)
	{
		students[i].displayStudent();
		cout<<endl;
		}
	}
void addNewStudent(vector<Student> &students){
	int rollno,age;
	string name;
	
	cout<<"\n\n\t\t\t\t\t\tEnter Rollno : ";
	cin>>rollno;
	for(int i=0;i<students.size();i++){
		if(students[i].getRollno()==rollno){
			cout<<"\t\t\t\t\t\tStudent Already Exits.."<<endl;
			return;
		}
	}
	cout<<"\t\t\t\t\t\tEnter Name : ";
	cin>>name;
	cout<<"\t\t\t\t\t\tEnter Age : ";
	cin>>age;
	 
	 Student newStudent(rollno,name,age);
	 students.push_back(newStudent);
	 
	 cout<<"\t\t\t\t\t\tStudent Added Sucessfully...."<<endl;
}
void deleteStudent(vector<Student>& students){
	string name;
	cout<<"Enter Name to Delete : ";
	cin.ignore();
	getline(cin,name);
	for(int i=0;i<students.size();i++){
		if(students[i].getName()==name){
		students.erase((students.begin()+i));
		cout<<"\t\t\t\t\tStudents Remove Successfully"<<endl;	
		}
	}
}
main(){
	vector<Student> students;
	students.push_back(Student(1,"Archana",20));
	students.push_back(Student(2,"Lakshita",20));
	students.push_back(Student(3,"Rohit",20));
	students.push_back(Student(4,"Ashutosh",20));
char choice;
	do{
	int op;
	system ("cls");
	cout<<"\n\n\t\t\t\t\t  |------------------------------|"<<endl;
	cout<<"\t\t\t\t\t  |   Student Managment System   |"<<endl;
	cout<<"\t\t\t\t\t  |------------------------------|"<<endl;
	cout<<"\t\t\t\t\t  |1. Add New Student            |"<<endl;
	cout<<"\t\t\t\t\t  |2. Display All Students       |"<<endl;
	cout<<"\t\t\t\t\t  |3. Search Student             |"<<endl;
	cout<<"\t\t\t\t\t  |4. Update student             |"<<endl;
	cout<<"\t\t\t\t\t  |5. Delete Student             |"<<endl;
	cout<<"\t\t\t\t\t  |6. Exit                       |"<<endl;
	cout<<"\t\t\t\t\t  |------------------------------|"<<endl;
	cout<<"\n\t\t\t\t\t     Enter your Choice :";
	cin>>op;
	system("cls");
	switch(op){
		case 1:
			addNewStudent(students);
			break;
		case 2:
			DisplayAllStudent(students);
			break;
		case 3:
			SearchStudent(students);
			break;
		case 4:{
			updateStudent(students);
			break;
		}
		case 5 :
			deleteStudent(students);
			break;
 		case 6 :
		    exit(1);
		default:
		cout<<"\t\t\t\t\tInvalid Number ...."<<endl; 
	}
	
		cout<<"\n\t\t\t\t\tDo You Want to Continue [Yes / No] ? :";

	cin>>choice;
	
	}
	while(choice=='y' || choice=='Y' );

}












