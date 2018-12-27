



#include<iostream>
#include<string.h>
using namespace std;

class graph
{
	int adj[10][10];
	int city_num;
	string city[10];
	int visited[10];
	int mst[10][10];
	public:
	void create();
	void display(int a[10][10]);
	void findmst();
	void init_adj();
	void init_mst();
	void init_visit();
	int city_index(string s);
};

void graph::init_adj()
{
	for(int i=0;i<city_num;i++)
	{
		for(int j=0;j<city_num;j++)
		{
			adj[i][j]=0;
		}
	}
}

void graph::init_mst()
{
	for(int i=0;i<city_num;i++)
	{
		for(int j=0;j<city_num;j++)
		{
			mst[i][j]=0;
		}
	}
}

void graph::init_visit()
{
	for(int i=0;i<city_num;i++)
	{
		visited[i]=0;
	}
}

int graph::city_index(string s)
{
	for(int i=0;i<city_num;i++)
	{
		if(city[i]==s)
		{
			return(i);
		}
	}
}

void graph::create()
{
	char ans;
	int cost;
	cout<<"\n\n\tEnter the number of cities : ";
	cin>>city_num;
	cout<<"\n\tEnter the names of the cites : \n";
	for(int i=0;i<city_num;i++)
	{
		cout<<"\t\tCity "<<i+1<<" : ";
		cin>>city[i];
	}
	init_adj();
	for(int i=0;i<city_num;i++)
	{
		for(int j=i+1;j<city_num;j++)
		{
			cout<<"\n\tIs there a phone line between "<<city[i]<<" and "<<city[j]<<" ? (y/n) : ";
			cin>>ans;
			if(ans=='Y'||ans=='y')
			{
				cout<<"\tEnter the cost of phone line between "<<city[i]<<" and "<<city[j]<<" : ";
				cin>>cost;
				adj[i][j]=adj[j][i]=cost;
			}
		}
	}
	cout<<"\n\n\tThe adjacency matrix is : \n";
	display(adj);
}
				
void graph::findmst()
{
	string source_city;				
	int min,k,cost,loc,s,d;
	init_mst();
	init_visit();
	cout<<"\n\tEnter the source city : ";
	cin>>source_city;
	loc=city_index(source_city);
	visited[loc]=1;
	cost=k=0;
	while(k<city_num)
	{
		min=9999;
		for(int i=0;i<city_num;i++)
		{
			if(visited[i]==1)			
			{
				for(int j=0;j<city_num;j++)
				{
					if(visited[j]==0)
					{
						if(adj[i][j]!=0)
						{
							if(min>adj[i][j])
							{
								min=adj[i][j];
								s=i;
								d=j;
							}
						}
					}
				}
			}
		}
		if(min!=9999)
		{
			mst[s][d]=mst[d][s]=min;
			cost=cost+min;
			visited[d]=1;
		}
		k++;
	}
	cout<<"\n\tThe minimum spanning tree matrix is : \n\n";
	display(mst);
	cout<<"\n\tThe minimum cost required is : "<<cost<<endl;
}

void graph::display(int a[10][10])
{
	for(int i=0;i<city_num;i++)
	{
		for(int j=0;j<city_num;j++)
		{
			cout<<"\t"<<a[i][j];
		}
		cout<<"\n";
	}
}
				
int main()
{
	graph g;
	g.create();
	g.findmst();
	return 0;
}				


/*

        OUTPUT : 

swaraj@swaraj:~/Desktop/ADS$ g++ prims.cpp
swaraj@swaraj:~/Desktop/ADS$ ./a.out


	Enter the number of cities : 4

	Enter the names of the cites : 
		City 1 : MUMBAI
		City 2 : DELHI
		City 3 : KOLKATA
		City 4 : CHENNAI

	Is there a phone line between MUMBAI and DELHI ? (y/n) : Y
	Enter the cost of phone line between MUMBAI and DELHI : 450

	Is there a phone line between MUMBAI and KOLKATA ? (y/n) : Y
	Enter the cost of phone line between MUMBAI and KOLKATA : 400

	Is there a phone line between MUMBAI and CHENNAI ? (y/n) : Y
	Enter the cost of phone line between MUMBAI and CHENNAI : 550

	Is there a phone line between DELHI and KOLKATA ? (y/n) : Y
	Enter the cost of phone line between DELHI and KOLKATA : 350

	Is there a phone line between DELHI and CHENNAI ? (y/n) : Y
	Enter the cost of phone line between DELHI and CHENNAI : 600

	Is there a phone line between KOLKATA and CHENNAI ? (y/n) : N


	The adjacency matrix is : 
	0	450	400	550
	450	0	350	600
	400	350	0	0
	550	600	0	0

	Enter the source city : MUMBAI

	The minimum spanning tree matrix is : 

	0	0	400	550
	0	0	350	0
	400	350	0	0
	550	0	0	0

	The minimum cost required is : 1300
swaraj@swaraj:~/Desktop/ADS$ 

*/	
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
