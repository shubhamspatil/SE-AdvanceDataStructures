
#include<iostream>
using namespace std;

class node
{
public:
	string keyword;
	string meaning;
	node *left;
	node *right;
};

class avl
{
	node *root;
public:
	avl()
	{
		root=NULL;
	}
	void create();
	node* insert(node *curr,node *temp);
	node* balance(node *temp);
	int diff(node *temp);
	int height(node *temp);
	int max(int a,int b);
	node* LL_rot(node *parent);
	node* RR_rot(node *parent);
	node* LR_rot(node *parent);
	node* RL_rot(node *parent);
	void ascending(node *temp);
	node* deletenode(node *root,string key);
	void deleten();
	node* extractmin(node *t);
        void descending(node *temp);
        void display();
        bool search(node *curr,string key);
        void search_val();
};

void avl::create()
{
	char ans;
	node *temp;
	do
	{
		temp=new node();
		cout<<"\n\n\tEnter the keyword : ";
		cin>>temp->keyword;
		cout<<"\tEnter the meaning : ";
		cin>>temp->meaning;
		temp->left=temp->right=NULL;

			root=insert(root,temp);

		cout<<"\n\n\tDo you wish to add another word? (y/n)";
		cin>>ans;
	}
	while(ans=='y'||ans=='Y');
}


node* avl::insert(node *curr,node* temp)
{
	if(curr==NULL)
	{
		return temp;
	}
	if(temp->keyword<curr->keyword)
	{
		curr->left=insert(curr->left,temp);
		curr=balance(curr);
	}
	else if(temp->keyword>curr->keyword)
	{
		curr->right=insert(curr->right,temp);
		curr=balance(curr);
	}
	return curr;
}

node* avl::balance(node *temp)
{
	int bal;
	bal=diff(temp);
	if(bal>=2)
	{
		if(diff(temp->left)<0)
			temp=LR_rot(temp);
		else
			temp=LL_rot(temp);
	}
	else if(bal<=-2)
	{
		if(diff(temp->right)<0)
			temp=RR_rot(temp);
		else
			temp=RL_rot(temp);
	}
	return temp;
}


int avl::diff(node *temp)
{
	int l,r;
	l=height(temp->left);
	r=height(temp->right);
	return(l-r);
}

int avl::height(node *temp)
{
	if(temp==NULL)
		return(-1);
	else
		return(max(height(temp->left),height(temp->right))+1);
}

int avl::max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

node* avl::LL_rot(node *parent)
{
	node *temp,*temp1;
	temp=parent->left;
	temp1=temp->right;
	temp->right=parent;
	parent->left=temp1;
	return temp;
}

node* avl::RR_rot(node *parent)
{
	node *temp,*temp1;
	temp=parent->right;
	temp1=temp->left;
	temp->left=parent;
	parent->right=temp1;
	return temp;
}

node* avl::LR_rot(node *parent)
{
	parent->left=RR_rot(parent->left);
	return(LL_rot(parent));
}

node* avl::RL_rot(node *parent)
{
	parent->right=LL_rot(parent->right);
	return(RR_rot(parent));
}

void avl::ascending(node *temp)
{
        if(temp!=NULL)
        {
                ascending(temp->left);
                cout<<"\n\t"<<temp->keyword<<" : "<<temp->meaning;
                ascending(temp->right);
        }
}

void avl::descending(node *temp)
{
        if(temp!=NULL)
        {
                descending(temp->right);
                cout<<"\n\t"<<temp->keyword<<" : "<<temp->meaning;
                descending(temp->left);
        }
}


void avl::display()
{
        cout<<"\n\n\tThe keywords in ascending order are : \n";
        ascending(root);
        cout<<"\n\n\tThe keywords in descending order are : \n";
        descending(root);
}

bool avl::search(node *curr,string key)
{
	if(curr)
	{
		if(curr->keyword==key)
			return true;
		if(curr->keyword>key)
			return search(curr->left,key);
		else
			return search(curr->right,key);
	}
	return false;
}

void avl::search_val()
{
	string key;
        cout<<"\n\tEnter the keyword you wish to search : ";
        cin>>key;
        if(search(root,key))
                cout<<"\t\tThe entered keyword is present in the AVL tree";
        else
                cout<<"\t\tThe entered keyword is not present in the AVL tree";
}


node* avl::deletenode(node* curr,string key)
{
    if ( !curr)
    	return curr;
    if ( key < curr->keyword )
        curr->left = deletenode(curr->left, key);

    else if( key > curr->keyword )
        curr->right = deletenode(curr->right, key);

    else
    {
        node *l = curr->left;
        node *r = curr->right;
        delete curr;
        if ( !r )
        	return l;
        node *m=r;
        while(m->left)
        	m=m->left;
        m->right = extractmin(r);
        m->left = l;
        return balance(m);
    }
    return balance(curr);
}

    node* avl::extractmin(node *t)
    {
        if ( !t->left ) return t->right;
        t->left = extractmin(t->left);
        return balance(t);
    }

void avl::deleten()
{
	string key;
	cout<<"\n\n\tEnter the keyword to be deleted : ";
	cin>>key;
	root=deletenode(root,key);
}

int main()
{
  char c;
  int ch;
  avl a;
  do
  {
	  cout<<"\n\n\t\t(1) Insert a keyword in AVL tree.";
	  cout<<"\n\t\t(2) Display the AVL tree.";
	  cout<<"\n\t\t(3) Search a keyword";
	  cout<<"\n\t\t(4) Delete a keyword.";
	  cout<<"\n\n\tEnter your choice : ";
	  cin>>ch;
	  switch(ch)
	  {
      	  case 1 : a.create();
               break;
      	  case 2 : a.display();
               break;
      	  case 3 : a.search_val();
               break;
      	  case 4 : a.deleten();
               break;
      	  default : cout<<"\n\tWrong choice ! ";
	  }
	  cout<<"\n\n\tDo you want to continue? (y/n) : ";
	  cin>>c;
  	  }
  	  while(c=='y'||c=='Y');
  return 0;
}




