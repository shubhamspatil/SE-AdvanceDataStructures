/*Problem Statement:
Beginning with an empty binary search tree, Construct

binary search tree by inserting the values in the order given. After constructing a binary tree -

i. Insert new node

ii. Find number of nodes in longest path

iii. Minimum data value found in the tree

iv. Change a tree so that the roles of the left and right pointers are swapped at every node

v. Search a value

Author: Amogh Kalyanshetti
Roll No: 3162522
 */
#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* left;
	Node* right;
};
class BST
{
	int max(int x,int y)//returns max of x and y
	{
		if(x>=y)
			return x;
		else
			return y;
	}
public:
	Node* root;
	BST()
	{
		root=NULL;
	}
	void createTree();
	void insertToTree();
    void insert(Node*,Node*);
    void display(Node*);
    int height(Node*);
    int minData(Node*);
    void mirrorTree(Node*);
    void search(Node*,int);
};
void BST::createTree()//function to create binary search tree
{
	Node *ptr;
	char ans;
	do
	{
		ptr=new Node();
		cout<<"enter data";
		cin>>ptr->data;
		ptr->left=ptr->right=NULL;
		if (root==NULL)	//tree empty
		{
			root=ptr;	//first node i.e the root of the tree
		}
		else
		{
			insert(root,ptr);
		}
		cout<<"Do you want to continue(y/n)"<<endl;
		cin>>ans;
	}while(ans=='y'||ans=='Y');
}
void BST::insertToTree()//this function inserts  data to the BST
{
	char ans;
	do
	{
		cout<<"Enter data"<<endl;
		int d;
		cin>>d;
		Node *ptr=new Node();
		ptr->data=d;
		insert(root,ptr);
		cout<<"Do you want to continue(y/n)"<<endl;
		cin>>ans;
	}while(ans=='y'||ans=='Y');
}
void BST::insert(Node* root,Node* ptr)	//this function actually inserts data to BST
{
	if(ptr->data	<=	root->data)//if data of ptr is less than root
	{
		if(root->left==NULL)
		{
			root->left=ptr;	//data successfully inserted at left position
		}
		else
		{
			insert(root->left,ptr);	//recursive insert to left
		}
	}
	else
	{
		if(root->right==NULL)
		{
			root->right=ptr;//data successfully inserted at right position
		}
		else
		{
			insert(root->right,ptr);//recursive insert to right
		}
	}
}

void BST::display(Node* n)	//this function displays the BST by inorder traversal
{
		if(n!=NULL)
		{
			display(n->left);//left
			cout<<n->data<<"\t"<<endl;//root
			display(n->right);//right
		}
}
int BST::height(Node* r)//this function finds no of nodes in longest path
{
	if(r==NULL)//leaf node reached
	{
		return -1;
	}
	return max(height(r->left),height(r->right))+1;//recursively calling left
	//and right subtree and finding the max no of nodes in longest path
}
int BST::minData(Node* r)//this function finds the min data of a BST
{
	if(r==NULL)
	{
		return -1;
	}
	else
	{
		while(r->left!=NULL)//traverse farthest left
		{
			r=r->left;
		}
		return r->data;//return farthest left
	}
}
void BST::mirrorTree(Node* r)
{
	Node* temp=new Node();
	if(r==NULL)
	{
		return;
	}
	else
	{
		mirrorTree(r->left);//recursively call mirror function to left subtree
		mirrorTree(r->right);//recursively call mirror function to right subtree

		//exchange pointers
		temp=r->left;
		r->left=r->right;
		r->right=temp;
	}
}
void BST::search(Node* r,int element)
{
	if(r==NULL)//element not found
	{
		cout<<"Element not found"<<endl;
		return;
	}

	else
	{
		if(element==r->data)//element found
		{
			cout<<"Element found"<<endl;
			return;
		}
		else if(element<r->data)//element may exist in left subtree
		{
			search(r->left,element);
		}
		else	//element may exist in right subtree
		{
			search(r->right,element);
		}
	}
}
int main()//driver function to test the functions
{
	BST b1;
	int option;
	do
	{
			cout<<"_________________________________________"<<endl;
			cout<<"1 Create BST"<<endl;
			cout<<"2 Display BST"<<endl;
			cout<<"3 Insert new node"<<endl;
			cout<<"4 Find no of nodes in longest path"<<endl;
			cout<<"5 Find minimum data found in tree"<<endl;
			cout<<"6 Search"<<endl;
			cout<<"7 Swap left and right pointers"<<endl;
			cout<<"8 Exit"<<endl;
			cout<<"Enter correct option"<<endl;
			cout<<"_________________________________________"<<endl;
			cin>>option;
			switch(option)
			{
			case 1:
					b1.createTree();
					break;
			case 2:
					b1.display(b1.root);
					break;
			case 3:
					b1.insertToTree();
					break;
			case 4:	cout<<"No of nodes in longest path are "<<(b1.height(b1.root)+1)<<endl;
					break;
			case 5:
					cout<<" The minimum data of tree is "<<b1.minData(b1.root)<<endl;
					break;
			case 6:
					cout<<"Enter the element to search"<<endl;
					int e;
					cin>>e;
					b1.search(b1.root,e);
					break;

			case 7:
					b1.mirrorTree(b1.root);
					cout<<"The mirror tree is "<<endl;
					b1.display(b1.root);
					break;
			case 8:
					break;
			default:
					cout<<"Enter correct option"<<endl;
					break;
			}
	}while(option!=8);
}

/******************************OUTPUT*******************************/
/*
 _________________________________________
1 Create BST
2 Display BST
3 Insert new node
4 Find no of nodes in longest path
5 Find minimum data found in tree
6 Search
7 Swap left and right pointers
8 Exit
Enter correct option
_________________________________________
1
enter data10
Do you want to continue(y/n)
y
enter data8
Do you want to continue(y/n)
y
enter data11
Do you want to continue(y/n)
n
_________________________________________
1 Create BST
2 Display BST
3 Insert new node
4 Find no of nodes in longest path
5 Find minimum data found in tree
6 Search
7 Swap left and right pointers
8 Exit
Enter correct option
_________________________________________
2
8
10
11
_________________________________________
1 Create BST
2 Display BST
3 Insert new node
4 Find no of nodes in longest path
5 Find minimum data found in tree
6 Search
7 Swap left and right pointers
8 Exit
Enter correct option
_________________________________________
3
Enter data
9
Do you want to continue(y/n)
n
_________________________________________
1 Create BST
2 Display BST
3 Insert new node
4 Find no of nodes in longest path
5 Find minimum data found in tree
6 Search
7 Swap left and right pointers
8 Exit
Enter correct option
_________________________________________
2
8
9
10
11
_________________________________________
1 Create BST
2 Display BST
3 Insert new node
4 Find no of nodes in longest path
5 Find minimum data found in tree
6 Search
7 Swap left and right pointers
8 Exit
Enter correct option
_________________________________________
4
No of nodes in longest path are 3
_________________________________________
1 Create BST
2 Display BST
3 Insert new node
4 Find no of nodes in longest path
5 Find minimum data found in tree
6 Search
7 Swap left and right pointers
8 Exit
Enter correct option
_________________________________________
5
 The minimum data of tree is 8
_________________________________________
1 Create BST
2 Display BST
3 Insert new node
4 Find no of nodes in longest path
5 Find minimum data found in tree
6 Search
7 Swap left and right pointers
8 Exit
Enter correct option
_________________________________________
6
Enter the element to search
9
Element found
_________________________________________
1 Create BST
2 Display BST
3 Insert new node
4 Find no of nodes in longest path
5 Find minimum data found in tree
6 Search
7 Swap left and right pointers
8 Exit
Enter correct option
_________________________________________
6
Enter the element to search
100
Element not found
_________________________________________
1 Create BST
2 Display BST
3 Insert new node
4 Find no of nodes in longest path
5 Find minimum data found in tree
6 Search
7 Swap left and right pointers
8 Exit
Enter correct option
_________________________________________
7
The mirror tree is
11
10
9
8
_________________________________________
1 Create BST
2 Display BST
3 Insert new node
4 Find no of nodes in longest path
5 Find minimum data found in tree
6 Search
7 Swap left and right pointers
8 Exit
Enter correct option
_________________________________________
8
 */

