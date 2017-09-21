#include <bits/stdc++.h>

using namespace std;

struct node
{
	int count;
	struct node *one;
	struct node *zero;
	struct node *parent;
};

node *root;

string convert_binary(int x)
{
	string res = "";
	while(x > 0)
	{
		int y = x%2;
		char c = y+48;
		res = c + res; 
		x = x/2;
	}
	res = string(31-res.length(), '0').append(res);
	return res;
}

void insert(int x)
{
	string binar = convert_binary(x);
	node *temp = root;
	for(int i=0; i<binar.size(); i++)
	{
		temp->count += 1;
		if(binar[i] == '0')
		{
			if(temp->zero == NULL)
			{
				temp->zero = (node *)malloc(sizeof(node));
				temp->zero->parent = temp;
				temp->zero->zero = NULL;
				temp->zero->one = NULL;
				temp->zero->count = 0;
				temp = temp->zero;
			}
			else if(temp->zero)
			{
				temp=temp->zero;
			}
		}
		else if(binar[i] == '1')
		{
			if(temp->one == NULL)
			{
				temp->one = (node *)malloc(sizeof(node));
				temp->one->parent = temp;
				temp->one->zero = NULL;
				temp->one->one = NULL;
				temp->one->count = 0;
				temp = temp->one;
			}
			else if(temp->one)
			{
				temp=temp->one;
			}
		}
	}
}

void display()
{
	node *temp = root;
	while(temp != NULL)
	{
		if (temp->one)
		{
			cout<<temp->count<<" ";
			temp = temp->one;
			cout<<1<<endl;
		}
		else if(temp->zero)
		{	
			cout<<temp->count<<" ";
			temp = temp->zero;
			cout<<0<<endl;
		}
		else
		{
			temp = temp->zero;
		}
	}
	cout<<endl;
}

void delete1(int x)
{
	string binar = convert_binary(x);
	node *temp = root;
	int i = 0;
	while(temp != NULL && temp->count > 1)
	{
		temp->count -= 1;
		if(binar[i] == '0')
		{
			temp = temp->zero;
			i++;
		}
		else if(binar[i] == '1')
		{
			temp=temp->one;
			i++;
		}
	}
	if(temp != NULL)
	{
		temp = NULL;
		// temp->count = 0;
		// temp->one = NULL;
		// temp->zero = NULL;
	}
}

string MAX_XOR(int x)
{
	string res = "";
	string binar = convert_binary(x);
	node *temp = root->zero;
	for(int i=0; i<binar.size(); ++i)
	{
		if(binar[i] == '0')
		{
			if(temp->one)
			{
				res += '1';
				temp = temp->one;
			}
			else if(temp->zero)
			{
				res += '0';
				temp = temp->zero;
			}
		}
		else if(binar[i] == '1')
		{
			if(temp->zero)
			{
				res += '1';
				temp = temp->zero;
			}
			else if(temp->one)
			{
				res += '0';
				temp = temp->one;
			}
		}
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	root = (node *)malloc(sizeof(node));
	root->count = 0;
	root->one = NULL;
	root->zero = NULL;
	root->parent = NULL;
	// insert(3);
	// insert(3);
	// insert(3);
	// // insert(4);
	// display();
	// cout<<"--------------------------------"<<endl;
	// delete1(3);
	// display();
	// cout<<"---------------------------------"<<endl;
	// delete1(3);
	// display();
	// cout<<"---------------------------------"<<endl;
	// delete1(3);
	// display();
	int q;
	cin>>q;
	char ch;
	int x;
	while(q--)
	{
		cin>>ch>>x;
		if(ch == '+')
		{
			insert(x);
			// display();
		}
		else if(ch == '-')
		{
			delete1(x);
			// display();
		}
		else if(ch == '?')
		{
			string ans  = MAX_XOR(x);
			cout<<ans<<endl;
		}
	}
	return 0;
}