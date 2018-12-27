/*
 * stud.cpp
 *
Name : Swaraj Pawar
Div : SE-B2
Roll no. : 3152096

*/


#include<iostream>
#include<string.h>
#include<fstream>
#include<iomanip>
using namespace std;

class student
{
   string name;
   long roll;
   string div;
   string address;

   public :
     void getdata();
     void display();
     long rroll()
      {
    	 return roll;
      }
     string rname()
      {
    	 return name;
      }
     string rdiv()
     {
    	 return div;
     }
     string radd()
     {
    	 return address;
     }
};

void student :: getdata()
{
  cout<<"\n\t"<<setw(25)<<"Enter the name : ";
  cin>>name;
  cout<<"\t"<<setw(25)<<"Enter the roll number : ";
  cin>>roll;
  cout<<"\t"<<setw(25)<<"Enter the division : ";
  cin>>div;
  cout<<"\t"<<setw(25)<<"Enter the address : ";
  cin>>address;
}

void student :: display()
{
  cout<<setw(15)<<" Roll number : "<<setw(15)<<roll<<endl;
  cout<<setw(15)<<" Name   : "<<setw(15)<<name<<endl;
  cout<<setw(15)<<" Class   : "<<setw(15)<<div<<endl;
  cout<<setw(15)<<" Address   : "<<setw(15)<<address<<endl;

}

class database
{
	student s;
public:
	void write_to_file();
	void search_roll();
	void search_name();
	void display_record();
	void deletestud();
	void modify();
};

void database::write_to_file()
{
  char ch='n';
  ofstream fout;
  fout.open("stud.txt",ios::out);
  do
  {
      s.getdata();
      fout.write((char *)&s,sizeof(student));
      cout<<"\n\tDo you wish to enter more student details? (y/n) : ";
      cin>>ch;
  }
  while(ch=='y');
  fout.close();
}

void database::search_roll()
{
  int flag=0;
  long no;
  cout<<"\n\tEnter roll number  of the student to search : ";
  cin>>no;
  ifstream fin;
  fin.open("stud.txt");
  while(fin.read((char *)&s,sizeof(student)))
    {
      if(no==s.rroll())
        {
          cout<<"\n\tDetails : \n";
          s.display();
          flag=1;
          break;
        }
    }
   if(flag==0)
      cout<<"\n\tNumber does not exist.";
 fin.close();
}

void database::search_name()
{
  int flag=0;
  string tname;
  cout<<"\n\tEnter the name of the student you wish to search : ";
  cin>>tname;
  ifstream fin;
  fin.open("stud.txt");
  while(fin.read((char *)&s,sizeof(student)))
    {
      if(tname==s.rname())
        {
          cout<<"\n\tDetails : \n";
          s.display();
          flag=1;
          break;
        }
    }
   if(flag==0)
      cout<<"\n\tRecord does not exist.";
 fin.close();
}

void database::display_record()
{
  int count=1;
  ifstream fin;
  fin.open("stud.txt");
  if(!fin)
     cout<<"\n\tError opening the file.";
  else
  {
   cout<<"\n\t\tSTUDENT RECORD : \n";
   while(fin.read((char *)&s,sizeof(student)))
    {
        cout<<"\n\t Record "<<count<<" : \n\n";
        s.display();
        count++;
    }
  }
  fin.close();
}

void database::modify()
{
	fstream file;
	string name1;
    cout<<"\n\tEnter the name whose contents are to be updated : ";
    cin>>name1;
	long int pos;
	int flag = 0;
	file.open("stud.txt", ios::in|ios::out);
	file.seekg(0, ios::beg);
	while (!file.eof())
	{
		pos=file.tellg();
		file.read((char*) &s, sizeof(student));
		if(name1==s.rname())
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		s.getdata();
		file.seekg(pos);
		file.write((char*)&s,sizeof(student));
	}
	else
	{
		cout << "\n\tError : Name not found";
	}

}

void database::deletestud()
{
	long int num;
	ifstream file;
	cout<<"\n\tEnter the roll number of student you want to delete : ";
	cin>>num;
	file.open("stud.txt");
	fstream file1;
	file1.open("Temp.txt",ios::app);
	file.seekg(0,ios::beg);
	while(file.read((char*)&s,sizeof(student)))
	{
		if(s.rroll()!=num)
		{
			file1.write((char*)&s,sizeof(student));
		}
	}
	file1.close();
	file.close();
	remove("stud.txt");
	rename("Temp.txt","stud.txt");
	cout<<"\n\tRecord Deleted ..";
}



int main()
{
  char c;
  int ch;
  database d;
  ofstream fout;
  do
  {
	  cout<<"\n\n\t\t(1) Add a new student data.";
	  cout<<"\n\t\t(2) Display entire student record.";
	  cout<<"\n\t\t(3) Search by name.";
	  cout<<"\n\t\t(4) Search by roll number.";
	  cout<<"\n\t\t(5) Append.";
	  cout<<"\n\t\t(6) Delete";
	  cout<<"\n\n\tEnter your choice : ";
	  cin>>ch;
	  switch(ch)
	  {
      	  case 1 : d.write_to_file();
               break;
      	  case 2 : d.display_record();
               break;
      	  case 3 : d.search_name();
               break;
      	  case 4 : d.search_roll();
               break;
      	  case 5 : d.modify();
               break;
      	  case 6:  d.deletestud();
      		  break;
      	  default : cout<<"\n\tWrong choice ! ";
	  }
	  cout<<"\n\n\tDo you want to continue? (y/n) : ";
	  cin>>c;
  	  }
  	  while(c=='y'||c=='Y');
  return 0;
}




/*


        OUTPUT :
        
swaraj@swaraj:~/Desktop/ADS$ g++ stud_9.cpp
swaraj@swaraj:~/Desktop/ADS$ ./a.out


		(1) Add a new student data.
		(2) Display entire student record.
		(3) Search by name.
		(4) Search by roll number.
		(5) Append.
		(6) Delete

	Enter your choice : 1

	        Enter the name : Swaraj
	 Enter the roll number : 3152096
	    Enter the division : SE-B
	     Enter the address : Nashik

	Do you wish to enter more student details? (y/n) : y

	        Enter the name : Swapnil
	 Enter the roll number : 3152000
	    Enter the division : FE-A
	     Enter the address : Pune

	Do you wish to enter more student details? (y/n) : n


	Do you want to continue? (y/n) : y


		(1) Add a new student data.
		(2) Display entire student record.
		(3) Search by name.
		(4) Search by roll number.
		(5) Append.
		(6) Delete

	Enter your choice : 2

		STUDENT RECORD : 

	 Record 1 : 

 Roll number :         3152096
      Name   :          Swaraj
     Class   :            SE-B
   Address   :          Nashik

	 Record 2 : 

 Roll number :         3152000
      Name   :         Swapnil
     Class   :            FE-A
   Address   :            Pune


	Do you want to continue? (y/n) : y


		(1) Add a new student data.
		(2) Display entire student record.
		(3) Search by name.
		(4) Search by roll number.
		(5) Append.
		(6) Delete

	Enter your choice : 3

	Enter the name of the student you wish to search : Swapnil

	Details : 
 Roll number :         3152000
      Name   :         Swapnil
     Class   :            FE-A
   Address   :            Pune


	Do you want to continue? (y/n) : y


		(1) Add a new student data.
		(2) Display entire student record.
		(3) Search by name.
		(4) Search by roll number.
		(5) Append.
		(6) Delete

	Enter your choice : 4

	Enter roll number  of the student to search : 3152096

	Details : 
 Roll number :         3152096
      Name   :          Swaraj
     Class   :            SE-B
   Address   :          Nashik


	Do you want to continue? (y/n) : y


		(1) Add a new student data.
		(2) Display entire student record.
		(3) Search by name.
		(4) Search by roll number.
		(5) Append.
		(6) Delete

	Enter your choice : 5

	Enter the name whose contents are to be updated : Swapnil

	        Enter the name : Shivam
	 Enter the roll number : 3152097
	    Enter the division : SE-B
	     Enter the address : Pune


	Do you want to continue? (y/n) : y


		(1) Add a new student data.
		(2) Display entire student record.
		(3) Search by name.
		(4) Search by roll number.
		(5) Append.
		(6) Delete

	Enter your choice : 2

		STUDENT RECORD : 

	 Record 1 : 

 Roll number :         3152096
      Name   :          Swaraj
     Class   :            SE-B
   Address   :          Nashik

	 Record 2 : 

 Roll number :         3152097
      Name   :          Shivam
     Class   :            SE-B
   Address   :            Pune


	Do you want to continue? (y/n) : y


		(1) Add a new student data.
		(2) Display entire student record.
		(3) Search by name.
		(4) Search by roll number.
		(5) Append.
		(6) Delete

	Enter your choice : 6

	Enter the roll number of student you want to delete : 3152097

	Record Deleted ..

	Do you want to continue? (y/n) : y


		(1) Add a new student data.
		(2) Display entire student record.
		(3) Search by name.
		(4) Search by roll number.
		(5) Append.
		(6) Delete

	Enter your choice : 2

		STUDENT RECORD : 

	 Record 1 : 

 Roll number :         3152096
      Name   :          Swaraj
     Class   :            SE-B
   Address   :          Nashik


	Do you want to continue? (y/n) : n
swaraj@swaraj:~/Desktop/ADS$ 


*/
