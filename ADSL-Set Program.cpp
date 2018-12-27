/*
 *Problem statement: To create ADT that implements the SET concept.
a. Add (newElement) -Place a value into the set b. Remove (element) Remove the
 value
c. Contains (element) Return true if element is in collection
d. Size () Return number of values in collection Iterator () Return an iterator
used to loop over
collection
e. Intersection of two sets, f. Union of two sets, g. Difference between two
sets, h. Subset
 *      Author: Amogh Kalyanshetti
 *      Roll No:3162522
 */
#include<iostream>
using namespace std;
class Set
{
public:
	int A[20];//set will be stored in A
	int curr,s;
	void add(int);
	bool contains(int);
	int* begin();
	int* end();
	void accept();
	void print();
	int size();
	void remove(int);
	friend Set unionOf(Set,Set);
	friend Set intersectionOf(Set,Set);
	friend void subsetOf(Set,Set);

};
void subsetOf(Set s1,Set s2)//this function checks whether the sets are subsets
{
	int* itr=s1.begin();
	int* itr2=s2.begin();
	//check whether s1 is subset of s2
	bool subset=false;
	while(itr!=s1.end())
	{
		if(s2.contains(*itr)==true)
		{
			subset=true;
		}
		else
		{
			subset=false;
			break;
		}
		itr++;
	}
	if(subset==true)
	{
		cout<<"s1 is subset of s2"<<endl;
	}
	else
	{
		cout<<"s1 is not a subset of s2"<<endl;
	}
	//check whether s2 is subset of s1
	subset=false;
	while(itr2!=s2.end())
	{
		if(s1.contains(*itr2)==true)
		{
			subset=true;
		}
		else
		{
			subset=false;
			break;
		}
		itr2++;
	}
	if(subset==true)
	{
		cout<<"s2 is subset of s1"<<endl;
	}
	else
	{
		cout<<"s2 is not subset of s1"<<endl;
	}
}

Set intersectionOf(Set s1,Set s2)//this function finds the intersection of two sets
{
	Set ans;
	ans.curr=0;
	int* itr=s1.begin();
	int* itr2=s2.begin();
	int* itr3=ans.begin();
	while(itr!=s1.end())
	{
		if(s2.contains(*itr)==true)//common element found
		{
			*itr3=*itr;
			itr3++;
			ans.curr++;
		}
		itr++;
	}
	return ans;
}
Set unionOf(Set s1,Set s2)
{
	Set ans;
	ans.curr=0;
	//step 1 copy Set s1 to ans
	int* itr=s1.begin();
	int* itr2=ans.begin();
	while(itr!=s1.end())
	{
		*itr2=*itr;
		itr++;
		itr2++;
		ans.curr++;
	}
	//step 2 copy the elements from s2 to ans which are unique
	int* itr3=s2.begin();
	while(itr3!=s2.end())
	{
		if(ans.contains(*itr3)==false)
		{
			*itr2=*itr3;
			 itr2++;
			 ans.curr++;
		}
		itr3++;
	}
	cout<<"size of union is"<<ans.curr<<endl;
	return ans;
}
void Set::accept()//this function accepts the set
{
	cout<<"Enter the size"<<endl;
	cin>>s;
	cout<<"Enter "<<s<<" elements"<<endl;
	curr=0;
	for(int i=0;i<s;i++)
	{
		cin>>A[i];
		curr++;
	}
}
void Set::add(int element)//this function adds an element to the set
{
	A[curr]=element;
	curr++;
}
bool Set::contains(int element)// this function checks whether a element exists in a set or not
{
	int *itr;
	itr=begin();
	while(itr!=end())
	{
		if(*itr==element)
		{
			return true;
		}
		itr++;
	}
	return false;
}
int* Set::begin()//goes to beginning of set
{
	return &A[0];
}
int* Set::end()//goes to the end of set
{
	return &A[curr];
}
//int *Set::next()
//{
//	if(curr+1<20)
//		return &A[curr+1];
//}
//int *Set::prev()
//{
//	if(curr-1>0)
//		return &A[curr-1];
//}
int Set::size()
{
	return curr;
}
void Set::print()//this function prints the set
{
	cout<<"The set is "<<endl;
	int* itr=begin();
	while(itr!=end())
	{
		cout<<*itr<<"\t"<<endl;
		itr++;
	}
}
void Set::remove(int element)//this function removes the element from the set
{
	int *itr=begin();
	while(itr!=end())
	{
		if(element==*itr)
		{

			while(itr!=end())
			{
				*itr=*(itr+1);
				 itr++;
			}
			curr--;
			break;
		}
		itr++;
	}
}
/*
 * Driver function to test the set ADT
 */
int main()
{
	Set s,s1,unionSet,interSet;
	s.accept();
	s.print();
	int op,el;
	do
	{
		cout<<"1 Add element to set"<<endl;
		cout<<"2 Check existence of an element"<<endl;
		cout<<"3 Remove an element"<<endl;
		cout<<"4 Union"<<endl;
		cout<<"5 Intersection"<<endl;
		cout<<"6 Subset checking"<<endl;
		cout<<"7 Exit"<<endl;
		cout<<"Enter the choice"<<endl;
		cin>>op;
		switch(op)
		{
			case 1:
				cout<<"Enter the element to add"<<endl;
				cin>>el;
				s.add(el);
				cout<<"The array is"<<endl;
				s.print();
				break;
			case 2:
				cout<<"enter the element"<<endl;
				cin>>el;
				if(s.contains(el)==true)
				{
					cout<<"Element exists"<<endl;
				}
				else
				{
					cout<<"Element does not exist"<<endl;
				}
				break;
			case 3: cout<<"Enter the element to remove"<<endl;
				cin>>el;
				s.remove(el);
				cout<<"The array is"<<endl;
				s.print();
				break;
			case 4:
				cout<<"Set2"<<endl;
				s1.accept();
				unionSet=unionOf(s,s1);
				unionSet.print();
				break;
			case 5:
				cout<<"Set2"<<endl;
				s1.accept();
				interSet=intersectionOf(s,s1);
				interSet.print();
				break;
			case 6:
				cout<<"Set2"<<endl;
				s1.accept();
				subsetOf(s,s1);
				break;
		}
	}while(op!=7);
}
/*Output
 * Enter the size
4
Enter 4 elements
1 2 3 4
The set is
1
2
3
4
1 Add element to set
2 Check existence of an element
3 Remove an element
4 Union
5 Intersection
6 Subset checking
7 Exit
Enter the choice
1
Enter the element to add
5
The array is
The set is
1
2
3
4
5
1 Add element to set
2 Check existence of an element
3 Remove an element
4 Union
5 Intersection
6 Subset checking
7 Exit
Enter the choice
2
enter the element
3
Element exists
1 Add element to set
2 Check existence of an element
3 Remove an element
4 Union
5 Intersection
6 Subset checking
7 Exit
Enter the choice
3
Enter the element to remove
5
The array is
The set is
1
2
3
4
1 Add element to set
2 Check existence of an element
3 Remove an element
4 Union
5 Intersection
6 Subset checking
7 Exit
Enter the choice
4
Set2
Enter the size
3
Enter 3 elements
6 7 8
size of union is7
The set is
1
2
3
4
6
7
8
1 Add element to set
2 Check existence of an element
3 Remove an element
4 Union
5 Intersection
6 Subset checking
7 Exit
Enter the choice
5
Set2
Enter the size
3
Enter 3 elements
1 2 3
The set is
1
2
3
1 Add element to set
2 Check existence of an element
3 Remove an element
4 Union
5 Intersection
6 Subset checking
7 Exit
Enter the choice
6
Set2
Enter the size
5
Enter 5 elements
1 2 3 4 5
s1 is subset of s2
s2 is not subset of s1
1 Add element to set
2 Check existence of an element
3 Remove an element
4 Union
5 Intersection
6 Subset checking
7 Exit
Enter the choice
6
Set2
Enter the size
2
Enter 2 elements
1 2
s1 is not a subset of s2
s2 is subset of s1
1 Add element to set
2 Check existence of an element
3 Remove an element
4 Union
5 Intersection
6 Subset checking
7 Exit
Enter the choice
7
 *
 */
