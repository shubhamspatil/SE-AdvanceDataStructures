
/*
 *Problem Statement:
	There are flight paths between cities
	If there is a flight between city A and city B then there is
	an edge between the cities
	The cost of the edge can be the time that flight takes to reach city
	B from A, or the amount of fuel used for the journey.
	Represent this as a graph. The node can
	be represented by airport name or name of the city. Use adjacency list
	representation of the graph or use adjacency matrix representation of the
	graph.Justify the storage representation used.

 * 
 */
#include<iostream>
using namespace std;
class Node
{
public:
	string cityName;
	int length;
	Node* next;
};
class Flight
{
	int n,adjacencyMatrix[20][20];
	string  cities[20];
	Node* head[20];
	Node* cityNode;
public:
	Flight()	//this constructor initializes the adjacency matrix
	{
		for(int i=0;i<20;i++)
		{
			for(int j=0;j<20;j++)
			{
				if(i==j)
					adjacencyMatrix[i][j]=0;	//0 means 0 length
				else
					adjacencyMatrix[i][j]=-1;	//-1 means no data
			}
		}
	}
	void getData();
	void createMatrix();
	void displayMatrix();
	void createList();
	void displayList();

};
void Flight::getData()//this function gets data from the user
{
	cout<<"Enter the no of cities"<<endl;
	cin>>n;
	cout<<"Enter the names of the cities"<<endl;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		cout<<"Enter city "<<(i+1)<<endl;
		getline(cin,cities[i]);
	}
}
void Flight::createMatrix()//this function will create the adjacency matrix
{

	cout<<"The entered cities are"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<cities[i]<<endl;
	}
	char ch;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(adjacencyMatrix[i][j]==-1 || adjacencyMatrix[j][i]==-1)//fill only unique paths
			{
				cout<<"Is there a path between "<<cities[i]<<" and "<<cities[j]<<"(y/n)"<<endl;
				cin>>ch;
				if(ch=='y'||ch=='Y')
				{
					cout<<"Enter the distance "<<endl;
					cin>>adjacencyMatrix[i][j];
					adjacencyMatrix[j][i]=adjacencyMatrix[i][j];//path from a to b is same as path from b to a
				}
				else//if no path put zero
				{
					adjacencyMatrix[i][j]=0;
					adjacencyMatrix[j][i]=0;//path from a to b is same as path from b to a
				}
			}
		}
	}
}
void Flight::displayMatrix()//this function will display the adjacency matrix
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(adjacencyMatrix[i][j]!=0)//if path exists print 1
			{
				cout<<"1"<<"\t";
			}
			else	//if path des not exist print 0
			{
				cout<<adjacencyMatrix[i][j]<<"\t";
			}
		}
		cout<<endl;
	}
}
void Flight::createList()	//this function will create adjacency list from available data
{

		for(int i=0;i<n;i++)
		{
			head[i]=new Node();
			//initializing the node
			head[i]->cityName=cities[i];//initializing header nodes with city
			head[i]->length=0;//distance from a city to itself is treated as 0
			head[i]->next=NULL;//initially head will contain NULL
		}
		Node* ptr;
		Node* temp;
		for(int i=0;i<n;i++)
		{

			temp=head[i];//temp will contain head node which will be used for further operations
			for(int j=0;j<n;j++)
			{
				if(adjacencyMatrix[i][j]!=0)//condition for finding available paths
				{
					ptr=new Node();//ptr is the node to be inserted at end
					ptr->cityName=head[j]->cityName;
					ptr->length=adjacencyMatrix[i][j];
					ptr->next=NULL;
					while(temp->next!=NULL)//traverse to end
					{
						temp=temp->next;
					}
					temp->next=ptr;//insert at end
				}
			}
		}
}
void Flight::displayList()//this function will display the adjacency list
{
	Node* temp=new Node();
	for(int i=0;i<n;i++)
	{
		temp=head[i];
		while(temp!=NULL)
		{
			cout<<temp->cityName<<" |";
			cout<<temp->length<<" |";
			if(temp->next!=NULL)
				cout<<"->";
			temp=temp->next;

		}
		cout<<endl;
	}
}
int main()//Driver function to test all functions
{
	int option;
	Flight f;
	f.getData();
	do
	{

		f.createMatrix();
		cout<<"1 Adjacency matrix"<<endl;
		cout<<"2 Adjacency list"<<endl;
		cout<<"3 Exit"<<endl;
		cout<<"Enter correct option"<<endl;
		cin>>option;
		switch(option)
		{
			case 1:
					f.displayMatrix();
					break;
			case 2:
					f.createList();
					f.displayList();
					break;
			case 3:	break;
			default:break;

		}
	}while(option!=3);
}
/*Output:
 * Enter the no of cities
4
Enter the names of the cities
Enter city 1
pune
Enter city 2
mumbai
Enter city 3
nashik
Enter city 4
solapur
The entered cities are
pune
mumbai
nashik
solapur
Is there a path between pune and mumbai(y/n)
y
Enter the distance
100
Is there a path between pune and nashik(y/n)
y
Enter the distance
200
Is there a path between pune and solapur(y/n)
n
Is there a path between mumbai and nashik(y/n)
n
Is there a path between mumbai and solapur(y/n)
y
Enter the distance
150
Is there a path between nashik and solapur(y/n)
y
Enter the distance
250
1 Adjacency matrix
2 Adjacency list
3 Exit
Enter correct option
1
0	1	1	0
1	0	0	1
1	0	0	1
0	1	1	0
The entered cities are
pune
mumbai
nashik
solapur
1 Adjacency matrix
2 Adjacency list
3 Exit
Enter correct option
2
pune |0 |->mumbai |100 |->nashik |200 |
mumbai |0 |->pune |100 |->solapur |150 |
nashik |0 |->pune |200 |->solapur |250 |
solapur |0 |->mumbai |150 |->nashik |250 |
The entered cities are
pune
mumbai
nashik
solapur
1 Adjacency matrix
2 Adjacency list
3 Exit
Enter correct option
3
 *
 */



