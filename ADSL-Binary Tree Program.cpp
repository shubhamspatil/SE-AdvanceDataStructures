/*
 * Problem Statement:Given binary tree with n nodes, assign this tree to
 * another [operator=] and then erase all nodes
 * in a binary tree.
 *
 
 */
#include<iostream>
using namespace std;
class Node	//this class defines the structure of the node(basic element)
{
public:
	int data;
	Node* left;
	Node* right;
};


class NodeStack	//this class defines the structure of  the stack used for
//iterative traversals
{
	int top;
public:
	Node *ptr;
};


class Tree//this class defines the structure of the tree
{

	Node* copy(Node*);
public:
	Tree()
	{
		root=NULL;
	}
	Node* root;
	void create();
	Node* createTree();
	void inorder(Node*);
	void preorder(Node*);
	void postorder(Node*);
	void inorderNonRecursive(Node*);
	void preorderNonRecursive(Node*);
	void postorderNonRecursive(Node*);
	void operator=(Tree);
	void del(Node*);
};

void Tree:: operator=(Tree t)//operator overloaded function to copy tree
{
	root=t.root;
}
//Node* Tree::copy(Node* t)
//{
//	Node* curr;
//	curr=NULL;
//	if(t!=NULL)
//	{
//		curr=new Node();
//		curr->data=t->data;
//		curr->left=copy(t->left);
//		curr->right=copy(t->right);
//	}
//	return curr;
//}
//void Tree::copyTree()
//{
//	Node* root1=new Node();
//	root1=copy(root);
//	cout<<"The tree after copying is"<<endl;
//	inorder(root1);
//}
void Tree::inorderNonRecursive(Node* r)
{
	int top=-1;
	NodeStack s[20];
	Node *temp=new Node();
	temp=r;
	while(1)
	{
		while(temp!=NULL)
		{
			top++;
			s[top].ptr=temp;//push to stack
			temp=temp->left;//traverse left
		}
		if(top==-1)//stack empty
			break;
		if(top>=0)//stack not empty
		{
			temp=s[top].ptr;//pop from stack
			top--;
			cout<<temp->data<<"\t"<<endl;//print the data
		}
		temp=temp->right;//traverse right
	}
}
void Tree::preorderNonRecursive(Node* r)
{
	int top=-1;
	NodeStack s[20];
	Node *temp=new Node();
	temp=r;
	while(1)
	{
		while(temp!=NULL)
		{
			cout<<temp->data<<"\t"<<endl;//print the data first
			top++;
			s[top].ptr=temp;//push to stack
			temp=temp->left;//traverse left
		}
		if(top==-1)//stack empty
		break;
		if(top>=0)//stack not empty
		{
				temp=s[top].ptr;//pop from stack
				top--;
		}
		temp=temp->right;//traverse right
		}
}
void Tree::postorderNonRecursive(Node* r)
{
	NodeStack s1[20],s2[20];
	int top1=-1,top2=-1;
	Node* temp=new Node();
	top1++;
	s1[top1].ptr=r;//Push root to first stack
	while(top1!=-1)//loop while stack is not empty
	{
		temp=s1[top1].ptr;//pop a node from first stack
		top1--;

		top2++;
		s2[top2].ptr=temp;//push the popped node to second stack

		if(temp->left!=NULL)
		{
			top1++;
			s1[top1].ptr=temp->left;//push left child of popped node to first stack
		}

		if(temp->right!=NULL)
		{
			top1++;
			s1[top1].ptr=temp->right;//push right child of popped node to first stack
		}
	}
	while(top2>-1)
	{
		temp=s2[top2].ptr;
		top2--;
		cout<<temp->data<<"\t"<<endl;//print contents of second stack
	}

}
void Tree::create()
{
	root=createTree();
}

Node* Tree::createTree()
{
	Node *p;
	int x;
	cout<<"Enter the data(-1 for data)"<<endl;
	cin>>x;
	if(x==-1)
		return NULL;
	p=new Node();
	p->data=x;
	cout<<"Enter left child of "<<x<<endl;
	p->left=createTree();//recursive call for creation of left subtree
	cout<<"Enter right child of "<<x<<endl;
	p->right=createTree();//recursive call for creation of right subtree
	return p;
}
void Tree::del(Node* r)
{
	if(r==NULL)
	{
		return;
	}
	del(r->left);//recursively traverse left
	del(r->right);//recursively traverse right
	cout<<"Deleting node "<<r->data<<endl;
	delete(r);//deleting node
}
void Tree::inorder(Node* n)
{
	if(n!=NULL)
	{
		inorder(n->left);//left
		cout<<n->data<<"\t"<<endl;//root
		inorder(n->right);//right
	}
}
void Tree::preorder(Node* n)
{
	if(n!=NULL)
	{
		cout<<n->data<<"\t"<<endl;//root
		inorder(n->left);//left
		inorder(n->right);//right
	}
}
void Tree::postorder(Node* n)
{
	if(n!=NULL)
	{
		inorder(n->left);//left
		inorder(n->right);//right
		cout<<n->data<<"\t"<<endl;//data
	}
}
/*
 * Driver program to test various functions of binary tree
 */
int main()
{
	Tree t,t2;
	t.create();
	cout<<"Root is "<<t.root->data<<endl;
	t.inorder(t.root);
	int option;
	do
	{
		cout<<"1 Create binary tree"<<endl;
		cout<<"2 Inorder traversal(recursive)"<<endl;
		cout<<"3 Preorder traversal(recursive)"<<endl;
		cout<<"4 Postorder traversal(recursive)"<<endl;
		cout<<"5 Inorder traversal(non-recursive)"<<endl;
		cout<<"6 Preorder traversal(non-recursive)"<<endl;
		cout<<"7 Postorder traversal(non-recursive)"<<endl;
		cout<<"8 Copy tree"<<endl;
		cout<<"9 Delete node by node"<<endl;
		cout<<"10 Exit"<<endl;
		cout<<"Enter correct option"<<endl;
		cin>>option;
		switch(option)
		{
			case 1: t.create();
					break;
			case 2: t.inorder(t.root);
					break;
			case 3: t.preorder(t.root);
					break;
			case 4: t.postorder(t.root);
					break;
			case 5:t.inorderNonRecursive(t.root);
					break;
			case 6: t.preorderNonRecursive(t.root);
					break;
			case 7: t.postorderNonRecursive(t.root);
					break;
			case 8: t2=t;//copy tree using assignment operator
					t2.inorder(t2.root);
					break;
			case 9: t.del(t.root);
					break;
			case 10: break;
			default: cout<<"Enter correct option"<<endl;
		break;
		}
	}while(option!=10);
	return 0;
}
/*
 * Output
 * Enter the data(-1 for data)
10
Enter left child of 10
Enter the data(-1 for data)
20
Enter left child of 20
Enter the data(-1 for data)
-1
Enter right child of 20
Enter the data(-1 for data)
-1
Enter right child of 10
Enter the data(-1 for data)
30
Enter left child of 30
Enter the data(-1 for data)
-1
Enter right child of 30
Enter the data(-1 for data)
-1
Root is 10
20
10
30
1 Create binary tree
2 Inorder traversal(recursive)
3 Preorder traversal(recursive)
4 Postorder traversal(recursive)
5 Inorder traversal(non-recursive)
6 Preorder traversal(non-recursive)
7 Postorder traversal(non-recursive)
8 Copy tree
9 Delete node by node
10 Exit
Enter correct option
2
20
10
30
1 Create binary tree
2 Inorder traversal(recursive)
3 Preorder traversal(recursive)
4 Postorder traversal(recursive)
5 Inorder traversal(non-recursive)
6 Preorder traversal(non-recursive)
7 Postorder traversal(non-recursive)
8 Copy tree
9 Delete node by node
10 Exit
Enter correct option
3
10
20
30
1 Create binary tree
2 Inorder traversal(recursive)
3 Preorder traversal(recursive)
4 Postorder traversal(recursive)
5 Inorder traversal(non-recursive)
6 Preorder traversal(non-recursive)
7 Postorder traversal(non-recursive)
8 Copy tree
9 Delete node by node
10 Exit
Enter correct option
4
20
30
10
1 Create binary tree
2 Inorder traversal(recursive)
3 Preorder traversal(recursive)
4 Postorder traversal(recursive)
5 Inorder traversal(non-recursive)
6 Preorder traversal(non-recursive)
7 Postorder traversal(non-recursive)
8 Copy tree
9 Delete node by node
10 Exit
Enter correct option
5
20
10
30
1 Create binary tree
2 Inorder traversal(recursive)
3 Preorder traversal(recursive)
4 Postorder traversal(recursive)
5 Inorder traversal(non-recursive)
6 Preorder traversal(non-recursive)
7 Postorder traversal(non-recursive)
8 Copy tree
9 Delete node by node
10 Exit
Enter correct option
6
10
20
30
1 Create binary tree
2 Inorder traversal(recursive)
3 Preorder traversal(recursive)
4 Postorder traversal(recursive)
5 Inorder traversal(non-recursive)
6 Preorder traversal(non-recursive)
7 Postorder traversal(non-recursive)
8 Copy tree
9 Delete node by node
10 Exit
Enter correct option
7
20
30
10
1 Create binary tree
2 Inorder traversal(recursive)
3 Preorder traversal(recursive)
4 Postorder traversal(recursive)
5 Inorder traversal(non-recursive)
6 Preorder traversal(non-recursive)
7 Postorder traversal(non-recursive)
8 Copy tree
9 Delete node by node
10 Exit
Enter correct option
8
20
10
30
1 Create binary tree
2 Inorder traversal(recursive)
3 Preorder traversal(recursive)
4 Postorder traversal(recursive)
5 Inorder traversal(non-recursive)
6 Preorder traversal(non-recursive)
7 Postorder traversal(non-recursive)
8 Copy tree
9 Delete node by node
10 Exit
Enter correct option
9
Deleting node 20
Deleting node 30
Deleting node 10
1 Create binary tree
2 Inorder traversal(recursive)
3 Preorder traversal(recursive)
4 Postorder traversal(recursive)
5 Inorder traversal(non-recursive)
6 Preorder traversal(non-recursive)
7 Postorder traversal(non-recursive)
8 Copy tree
9 Delete node by node
10 Exit
Enter correct option
10
 *
 *
 */

