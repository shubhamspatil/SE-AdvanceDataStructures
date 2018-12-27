/*
 * 
 *	Problem Statement:
 *	You have a business with several offices.You want to lease phonelines to connect them
 *	with each other and the phone company charges
 * 	different amounts of money to connect different pairs of cities.you want a set of lines that
 * 	connects all your offices with minimal total
	costs.Solve the problem by suggesting appropriate data structure
 *  
 *  	Author: Amogh Kalyanshetti
 	Roll No: 3162522
 *
 */


#include <iostream>

using namespace std;

class graph
{
public:
	string city[10];
	int path[10][10];//an array to store the path between cities
	int visited[10];//an array to mark whether the node is visited or not
	int sptree[10][10];
	int n,dist;
public:
	void accept();
	void displaymat();
	void findMST();
	int search(string);
};


void graph::accept()
{

	char ch;
	cout<<"Enter no. of cities:\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter "<<i<<" city name:\n";
		cin>>city[i];
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			path[i][j]=-1;
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(path[i][j]==-1 && path[j][i]==-1)	//no path defined before
			{
				cout<<"Is there a flight from "<<city[i]<<" to "<<city[j]<<":\n";
				cin>>ch;
				if(ch=='y')
					{
						cout<<"Enter distance:\n";
						cin>>dist;
						path[i][j]=dist;
						path[j][i]=dist;//distance from A to B is same as B to A
					}
				else
				{
					path[i][j]=0;//no path
					path[j][i]=0;
				}
			}
		}
	}
}


void graph::displaymat()	//this function displays the adjacency matrix
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<path[i][j]<<"\t ";
		}
		cout<<"\n";
	}
}

int graph::search(string src)	//this function searches for particular index associated with the city name
{
	for(int i=0;i<n;i++)
	{
		if(city[i]==src)
		{
			return i;
		}
	}
}


void graph::findMST()	//this function finds the minimum spanning tree
{
	int s,d;
	string src;
	cout<<"Enter source city:\n";
	cin>>src;

	for(int i=0;i<n;i++)
	{
		visited[i]=0;	//initially none is visited
	}

	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				sptree[i][j]=0;	//initially none is added to spanning tree
			}
		}

	int loc=search(src);	//loc of src
	visited[loc]=1;		//src is visited
	int sum=0;
	int k=0;

	while(k<n)
	{
		int min=999;//dummy value
		for(int i=0;i<n;i++)
		{
			if(visited[i]==1)//if source is visited
			{
				for(int j=0;j<n;j++)
				{
					if(visited[j]==0)//if destination is not visited
					{
						if(path[i][j]!=0)//path exists between source and destination
						{
							if(min>path[i][j])
							{
								min=path[i][j];
								s=i;
								d=j;
							}
						}
					}
				}//j ends
			}
		}//i ends
		if(min!=999)
		{
		sptree[s][d]=min;//minimum path assigned
		sum=sum+min;	//calculate sum
		visited[d]=1;//destination is visited now

		}
		k++;
	}//k ends


	cout<<"spanning tree is:\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{	
			cout<<sptree[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<sum;	//shortest path
}


int main()	//Driver function to test the program
{
			graph g;
			g.accept();
			g.displaymat();
			g.findMST();
			return 0;
}
/*Output:
	Enter no. of cities:
3
Enter 0 city name:
mumbai
Enter 1 city name:
delhi
Enter 2 city name:
pune
Is there a flight from mumbai to mumbai:
n
Is there a flight from mumbai to delhi:
y
Enter distance:
100
Is there a flight from mumbai to pune:
y
Enter distance:
50
Is there a flight from delhi to delhi:
n
Is there a flight from delhi to pune:
y
Enter distance:
150
Is there a flight from pune to pune:
n
0	 100	 50	 
100	 0	 150	 
50	 150	 0	 
Enter source city:
pune
spanning tree is:
0	100	0	
0	0	0	
50	0	0	
150
*/
