/*
 * TBT.cpp
 *Problem statement:
 *				Convert given binary tree into threaded binary tree.
 *				Analyze time and space complexity of the algorithm.
 *      Author: Amogh Kalyanshetti
 *      Roll No: 3162522
 */
#include <iostream>
using namespace std;

class node
{
	public:
	int data;
	node *left, *right;
	int lth,rth;//if lth=1,then left points to inorder predecessor
	//if lth=0 then left points to his left child

};

class inTBT
{
	public:

	node *root;
	node *dummy;
public:
	inTBT()
	{
		root=NULL;
	}
	void create();
	void inorder(node*);
	void display();
	void insert(node*,node*);
};
  void inTBT::create()	//this function will create a threaded binary tree
 {
  node *ptr;
  ptr=new node();
  cout<<"Enter DATA:";
  cin>>ptr->data;
  ptr->lth=ptr->rth=0;


if(root==NULL)
{
	root=ptr;
	dummy=new node();
	dummy->data=-999;
	dummy->right=NULL;
	dummy ->lth=dummy->rth=0;
	dummy->left=root;
	dummy->lth=1;
    root->left=root->right=dummy;
}
else
{
	insert(root,ptr);
}
 }
void inTBT::insert(node *root,node *ptr)//this function will insert node in TBT
{
	if(ptr->data<root->data)//go to left
	{
		if(root->lth==0)//leaf node reached
		{
			ptr->left=root->left;
			root->left=ptr;
			root->lth=1;//root has a left child hence lth=1
			ptr->right=root;
		}
		else
		{
			insert(root->left,ptr);//recursively go to leftmost leaf node
		}
	}
	else	//go to right
	{
		if(root->rth==0)//leaf node reached
		{
			ptr->left=root;
			ptr->right=root->right;
			root->right=ptr;
			root->rth=1;//root has a right child hence rth=1
		}
		else
		{
			insert(root->right,ptr);//recursively go to rightmost leaf node
		}
	}
}
void inTBT::inorder(node *root)//this function traverses the tree in inorder manner
{
	while(root!=dummy)
	{
		while(root->lth==1)//root is leaf
		{
			root=root->left;//go to inorder predecessor
		}
		cout<<root->data<<" ";//print data of root
		while(root->rth==0)//traverse right until dummy node is found
		{
			root=root->right;
			if(root==dummy)
			return;
			cout<<root->data<<" ";
		}
		root=root->right;
	}
}
void inTBT::display()	//this function displays the TBT
{
	inorder(root);
}
int main()//driver program to test all the functions
{
	int ch;
	inTBT t;
	do
	{
		cout<<"\n***************THREADED BINARY TREE**********************";
		cout<<"\n1.Insert TBT \n 2.Display TBT";
		cout<<"\n Enter choice:-";
		cin>>ch;
		switch(ch)
		 {
			case 1:
				t.create();
				break;
			case 2:
				cout<<"Threaded Binary Tree DATA is(ascending order):"<<" ";
				t.display();
				break;
			default:
				cout<<"wrong choice";
				break;
		  }
	}while(ch!=3);
}
/*Output
 *
***************THREADED BINARY TREE**********************
1.Insert TBT
 2.Display TBT
 Enter choice:-1
Enter DATA:20

***************THREADED BINARY TREE**********************
1.Insert TBT
 2.Display TBT
 Enter choice:-2
Threaded Binary Tree DATA is(ascending order): 20
***************THREADED BINARY TREE**********************
1.Insert TBT
 2.Display TBT
 Enter choice:-1
Enter DATA:80

***************THREADED BINARY TREE**********************
1.Insert TBT
 2.Display TBT
 Enter choice:-1
Enter DATA:76

***************THREADED BINARY TREE**********************
1.Insert TBT
 2.Display TBT
 Enter choice:-2
Threaded Binary Tree DATA is(ascending order): 20 76 80
***************THREADED BINARY TREE**********************
1.Insert TBT
 2.Display TBT
 Enter choice:-
 */


