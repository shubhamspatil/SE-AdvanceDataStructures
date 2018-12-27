#include<iostream >
#include<fstream>
using namespace std;

class Student
{
	int rollNo;
	char name[20];
	float marks;
	int status;
};

class Sequential
{
	char master1[30];
	fstream mas;
public:
	Sequential(char* a)
	{
		strcpy(master1,a);
		mas.open(master1,ios::binary|ios::in);
		if(mas.fail())
		{
			mas.open(master1,ios::binary|ios::out);
			mas.close();
		}
	}
	void read();
	void insertRecord(Student rec1);
	int deleteRecord(int rollNo);
	int searchRecord(int rollNo);
	void pack();
	void update();
	void display(int recno)	//display a particular record
	{
		Student rec1;
		mas.open(master1,ios::binary|ios::in);
		mas.seekg(recno*sizeof(Student),ios::beg);
		mas.read((char*)&rec1,sizeof(Student));
		cout<<rec1.rollNo<<endl;
		cout<<rec1.name<<endl;
		cout<<rec1.marks<<endl;
		mas.close();
	}
};
int main()
{
	Sequential object("master.txt");
	int rollNo,op,recNo;
	Student rec1;
	do
	{
		cout<<"1 Read"<<endl;
		cout<<"2 "<<endl;
	}while();
}
