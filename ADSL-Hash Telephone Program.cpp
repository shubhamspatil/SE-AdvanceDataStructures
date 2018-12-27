/*
 *      Problem Statement: Consider telephone book db of young clients .
 *      Make use of hash table to quickly look up client's telephone no
 
  	
 */
#include<iostream>
#define MAX 20
using namespace std;
class Client
{
public:
	long long int phoneNo;
	string name,add;
};
class Telephone
{

public:
	Client c[MAX];
	int n;
	void initialize();
	void createHash();
	void searchHash();
	void displayHash();
};
void Telephone::initialize()//this function initializes the object
{
	for(int i=0;i<MAX;i++)
	{
		c[i].phoneNo=0;
		c[i].name="";
		c[i].add="";
	}
}
void Telephone::createHash()//this function creates hash function
{
	cout<<"Enter no of records to insert (records< ="<<MAX<<endl;
	cin>>n;
	int loc;
	long long int tempNo;
	for(int i=0;i<n;i++)
	{
		//

			cout<<"Enter mobile no"<<endl;
			cin>>tempNo;
			cin.ignore();
			loc=tempNo%MAX;
			cout<<"Location: "<<loc<<endl;
			while(1)
			{
				if(c[loc].phoneNo==0)//empty location
				{
					c[loc].phoneNo=tempNo;
					cout<<"Enter name"<<endl;
					cin>>c[loc].name;
					cout<<"Enter address"<<endl;
					cin>>c[loc].add;
					cout<<"Record successfully inserted!"<<endl;
					break;//break from inner loop(insertion complete)
				}
				else	//current location is already occupied
				{
					loc=(loc+1)%MAX;//find next empty location
				}
			}
			continue;	//proceed to insert next record
}
}
void Telephone::searchHash()	//this function searches the hash table to find required entry
{
	long long int tempNo;
	int loc;
	cout<<"Enter the mobile no"<<endl;
	cin>>tempNo;
	loc=tempNo%MAX;
	int i=0;
	while(1)
	{
		if(c[loc].phoneNo==tempNo)	//entry found
		{
			cout<<"Entry found! "<<endl;
			cout<<loc<<"\t\t\t";
			cout<<c[loc].phoneNo<<"\t\t";
			cout<<c[loc].name<<"\t\t\t";
			cout<<c[loc].add<<"\t\t\t";
			cout<<endl;
			break;
		}
		else	//entry not found
		{
			loc=(loc+1)%MAX;
			i++;
			if(i==MAX-1)
			{
				cout<<"Entry not found!"<<endl;
				break;
			}
		}
	}
}
void Telephone::displayHash()	//this function displays hash table
{
	cout<<"The hash table is as follows"<<endl;
	cout<<"Index\t\t\tphoneNo\t\t\t Name\t\t\t Address"<<endl;
	for(int i=0;i<MAX;i++)
	{
		cout<<i<<"\t\t\t";
		cout<<c[i].phoneNo<<"\t\t";
		cout<<c[i].name<<"\t\t\t";
		cout<<c[i].add<<"\t\t\t";
		cout<<endl;
	}
}
int main()
{
	Telephone t;
	t.initialize();
	int option;
	do
	{
		cout<<"1 Insert record "<<endl;
		cout<<"2 Display record"<<endl;
		cout<<"3 Search record by mobile no"<<endl;
		cout<<"4 exit"<<endl;
		cout<<"Enter correct option"<<endl;
		cin>>option;
		switch(option)
		{
			case 1: t.createHash();
					break;
			case 2:	t.displayHash();
					break;
			case 3: t.searchHash();
					break;
			case 4: break;

		}
	}while(option!=4);
	return 0;
}
/*Output:

1 Insert record 
2 Display record
3 Search record by mobile no
4 exit
Enter correct option
1
Enter no of records to insert (records< =20
2
Enter mobile no
9890825812
Location: 12
Enter name
pushpa
Enter address
solapur
Record successfully inserted!
Enter mobile no
7758020747
Location: 7
Enter name
amogh
Enter address
pune
Record successfully inserted!
1 Insert record 
2 Display record
3 Search record by mobile no
4 exit
Enter correct option
2
The hash table is as follows
Index			phoneNo			 Name			 Address
0			0								
1			0								
2			0								
3			0								
4			0								
5			0								
6			0								
7			7758020747		amogh			pune			
8			0								
9			0								
10			0								
11			0								
12			9890825812		pushpa			solapur			
13			0								
14			0								
15			0								
16			0								
17			0								
18			0								
19			0								
1 Insert record 
2 Display record
3 Search record by mobile no
4 exit
Enter correct option
3
Enter the mobile no
9890825812
Entry found! 
12			9890825812		pushpa			solapur			
1 Insert record 
2 Display record
3 Search record by mobile no
4 exit
Enter correct option
3
Enter the mobile no
12345678
Entry not found!
1 Insert record 
2 Display record
3 Search record by mobile no
4 exit
Enter correct option
4

*/
