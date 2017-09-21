#include <bits/stdc++.h>

using namespace std;

struct node
{
	int count;
	node *one;
	node *zero;
};

node *root;

long long pow2[32];

void create_pow2()
{
	pow2[31] = 1;
	for(int i=30; i>= 0; i--)
	{
		pow2[i] = pow2[i+1]*2;
	}
}

void convert_binary(int *A, int x)
{
	int i=31;
	while(x > 0)
	{
		A[i] = x%2;
		x = x/2;
		i--;
	}
	while(i>=0)
	{
		A[i] = 0;
		i--;
	}
}

node *create_node()
{
	node *temp = (node *)malloc(sizeof(node));
	temp->count  = 0;
	temp->one = NULL;
	temp->zero = NULL;
	return temp;
}

void insert(int x)
{
	int binar[32];
	convert_binary(binar, x);
	node *temp = root;
	node *newnode;
	temp->count += 1;
	for(int i=0; i<32; i++)
	{
		if(binar[i] == 0)
		{
			if(temp->zero == NULL)
			{
				temp->zero = create_node();
			}
			temp = temp->zero;
			temp->count += 1;
		}
		else
		{
			if(temp->one == NULL)
			{
				temp->one = create_node();
			}
			temp= temp->one;
			temp->count += 1;
		}
	}
}

void delete1(int x)
{
	int binar[32] = {0};
	convert_binary(binar, x);
	node *temp = root;
	temp->count -= 1;
	for(int i=0; i<32; i++)
	{
		if(binar[i] == 0)
		{
			temp=temp->zero;
			temp->count -= 1;
		}
		else
		{
			temp = temp->one;
			temp->count -=1;
		}
	}
}

long long max_xor(int x)
{
	long long res = 0;
	int binar[32] = {0};
	convert_binary(binar, x);
	node *temp = root;
	for(int i=0; i<32; i++)
	{
		if(binar[i] == 0)
		{
			if(temp->one != NULL && temp->one->count > 0)
			{
				res += pow2[i];
				temp = temp->one;
			}
			else if(temp->zero != NULL && temp->zero->count > 0)
			{
				temp = temp->zero;
			}
		}
		else
		{
			if(temp->zero != NULL && temp->zero->count > 0)
			{
				res += pow2[i];
				temp = temp->zero;
			}
			else if(temp->one != NULL && temp->one->count > 0)
			{
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
	root->one = NULL;
	root->zero = NULL;
	root->count = 0;
	insert(0);
	int q;
	cin>>q;
	int x;
	char ch;
	create_pow2();
	while(q--)
	{
		cin>>ch>>x;
		if(ch == '+')
		{
			insert(x);
		}
		else if(ch == '-')
		{
			delete1(x);
		}
		else
		{
			long long ans = max_xor(x);
			cout<<ans<<endl;
		}
	}
	return 0;
}