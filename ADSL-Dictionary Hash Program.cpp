
/*
 * 
 *   
 *      Problem Statement: Implement all the functions of a dictionary (ADT) using
 *      hashing.
		Data: Set of (key, value) pairs, Keys are mapped to values,
		Keys must be comparable, Keys must be unique
		Standard Operations: Insert(key, value), Find(key), Delete(key)
	Author: Amogh Kalyanshetti
	Roll No: 3162522
 */
#include<iostream>
#define MAX 20
using namespace std;
class Node
{
public:
	int key;
	string value;
};
class Dictionary
{
	bool keyExists(int key);
public:
	Node c[MAX];
	int n;
	void initialize();

	void insert(int key,string value);
	void find(int key);
	void del(int key);
	void displayHash();
};
void Dictionary::del(int key)
{
	int loc=key%MAX;
		int i=0;
		while(1)
		{
			if(c[loc].key==key)	//entry found
			{
					c[loc].key=0;
					c[loc].value="";
					cout<<"Entry deleted !"<<endl;
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
void Dictionary::find(int key)
{
	int loc=key%MAX;
	int i=0;
	while(1)
	{
		if(c[loc].key==key)	//entry found
		{
				cout<<"Entry found! "<<endl;
				cout<<loc<<"\t\t\t";
				cout<<c[loc].key<<"\t\t";
				cout<<c[loc].value<<"\t\t\t";
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
bool Dictionary::keyExists(int key)
{
	bool exists=false;
	for(int i=0;i<MAX;i++)
	{
		if(c[i].key==key)
		{
			exists=true;
			return exists;
		}
	}
	return exists;
}

void Dictionary::initialize()//this function initializes the object
{
	for(int i=0;i<MAX;i++)
	{
		c[i].key=0;
		c[i].value="";
	}
}
void Dictionary::insert(int key,string value)//this function creates hash function
{
	if(keyExists(key)==true)//key already present
	{
		cout<<"Key already exists!"<<endl;
		return;
	}
	int loc;
	loc=key%MAX;
	cout<<"Location: "<<loc<<endl;
	while(1)
	{
		if(c[loc].key==0)//empty location
		{
			c[loc].key=key;
			c[loc].value=value;
			cout<<"Record successfully inserted!"<<endl;
			break;//break from inner loop(insertion complete)
		}
		else	//current location is already occupied
		{
			loc=(loc+1)%MAX;//find next empty location
		}
	}
}
/*void Dictionary::searchHash()	//this function searches the hash table to find required entry
{
	long int tempNo;
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
}*/
void Dictionary::displayHash()	//this function displays hash table
{
	cout<<"The hash table is as follows"<<endl;
	cout<<"Index\t\t\tKey\t Value"<<endl;
	for(int i=0;i<MAX;i++)
	{
		cout<<i<<"\t\t\t";
		cout<<c[i].key<<"\t";
		cout<<c[i].value<<"\t\t\t";
		cout<<endl;
	}
}
int main()
{
	Dictionary t;
	t.initialize();
	int option;
	int key;
	string value;
	do
	{
		cout<<"1 Insert record "<<endl;
		cout<<"2 Display record"<<endl;
		cout<<"3 Find record"<<endl;
		cout<<"4 Delete record"<<endl;
		cout<<"5 Exit"<<endl;
		cout<<"Enter correct option"<<endl;
		cin>>option;
		switch(option)
		{
			case 1: cout<<"Enter key"<<endl;
					cin>>key;
					cout<<"Enter value"<<endl;
					cin>>value;
					t.insert(key,value);
					break;
			case 2:	t.displayHash();
					break;
			case 3: cout<<"Enter the key to find"<<endl;
					cin>>key;
					t.find(key);
					break;
			case 4: cout<<"Enter the key to delete"<<endl;
					cin>>key;
					t.del(key);
					break;
			case 5:break;

		}
	}while(option!=5);
	return 0;
}

/*Output
	1 Insert record 
2 Display record
3 Find record
4 Delete record
5 Exit
Enter correct option
1
Enter key
1
Enter value
amogh
Location: 1
Record successfully inserted!
1 Insert record 
2 Display record
3 Find record
4 Delete record
5 Exit
Enter correct option
1
Enter key
8
Enter value
kiran
Location: 8
Record successfully inserted!
1 Insert record 
2 Display record
3 Find record
4 Delete record
5 Exit
Enter correct option
1
Enter key
100
Enter value
vinay
Location: 0
Record successfully inserted!
1 Insert record 
2 Display record
3 Find record
4 Delete record
5 Exit
Enter correct option
2
The hash table is as follows
Index			Key	 Value
0			100	vinay			
1			1	amogh			
2			0				
3			0				
4			0				
5			0				
6			0				
7			0				
8			8	kiran			
9			0				
10			0				
11			0				
12			0				
13			0				
14			0				
15			0				
16			0				
17			0				
18			0				
19			0				
1 Insert record 
2 Display record
3 Find record
4 Delete record
5 Exit
Enter correct option
3
Enter the key to find
100
Entry found! 
0			100		vinay			
1 Insert record 
2 Display record
3 Find record
4 Delete record
5 Exit
Enter correct option
3
Enter the key to find
13
Entry not found!
1 Insert record 
2 Display record
3 Find record
4 Delete record
5 Exit
Enter correct option
4
Enter the key to delete
100
Entry deleted !
1 Insert record 
2 Display record
3 Find record
4 Delete record
5 Exit
Enter correct option
2
The hash table is as follows
Index			Key	 Value
0			0				
1			1	amogh			
2			0				
3			0				
4			0				
5			0				
6			0				
7			0				
8			8	kiran			
9			0				
10			0				
11			0				
12			0				
13			0				
14			0				
15			0				
16			0				
17			0				
18			0				
19			0				
1 Insert record 
2 Display record
3 Find record
4 Delete record
5 Exit
Enter correct option
5
*/





