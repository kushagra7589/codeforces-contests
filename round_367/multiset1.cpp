#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int count;
	Node *zero;
	Node *one;
	int level;
	Node *parent;
};

Node *root;

int pow2[32] = {0}; 

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


void insert(int);
void delete1(int);
int max_xor1(int);
void display();

int main()
{
	ios_base::sync_with_stdio(false);
	root = (Node *)malloc(sizeof(Node));
	int q;
	cin>>q;
	int x;
	char ch;
	int A[32] = {0};
	pow2[31]=1;
	for(int i=30; i>=0; i--)
	{
		pow2[i] = pow2[i+1]*2;
	}
	while(q--)
	{
		// for(int i=0;i<32; i++)
		// {
		// 	A[i] = 0;
		// }
		// cin>>x;
		// convert_binary(A, x);
		// for(int i=0; i<32; i++)
		// {
		// 	cout<<A[i];
		// }
		// cout<<endl;
		cin>>ch>>x;
		if(ch == '+')
		{
			insert(x);
			display();
		}
		else if(ch == '-')
		{
			delete1(x);
			display();
		}
		else if(ch == '?')
		{
			int ans = max_xor1(x);
			cout<<ans<<endl;
		}
	}
	return 0;
}

void display()
{
	Node *temp = root;
	queue<Node *> q1;
	q1.push(temp);
	while(!q1.empty())
	{
		temp = q1.front();
		q1.pop();
		cout<<temp->count<<" ";
		if(temp->zero)
		{
			cout<<temp->level<<" "<<0<<" |";
			q1.push(temp->zero);
		}
		if(temp->one)
		{
			cout<<temp->level<<" "<<1<<" |";
			q1.push(temp->one);
		}
		cout<<endl;
	}
}

void insert(int x)
{
	int binar[32] = {0};
	convert_binary(binar, x);
	Node *temp = root;
	for(int i=0; i<32; i++)
	{
		temp->count += 1;
		temp->level = i;
		if(binar[i] == 1)
		{
			if(temp->one == NULL)
			{
				temp->one = (Node *)malloc(sizeof(Node));
				temp->one->zero = NULL;
				temp->one->one = NULL;
				temp->one->count  = 0;
				temp->one->parent = temp;
			}
			temp = temp->one;
		}
		else
		{
			if(temp->zero == NULL)
			{
				temp->zero = (Node *)malloc(sizeof(Node));
				temp->zero->zero = NULL;
				temp->zero->one = NULL;
				temp->zero->count = 0;
				temp->zero->parent = temp;
			}
			temp=temp->zero;
		}
	}
}

void delete1(int x)
{
	int binar[32] = {0};
	convert_binary(binar, x);
		
}

int max_xor1(int x)
{
	int binar[32] = {0};
	convert_binary(binar, x);
	Node *temp = root;
	int res = 0;
	for(int i=0; i<32; i++)
	{
		if(binar[i] == 1)
		{
			if(temp->zero)
			{
				res += pow2[i];
				temp = temp->zero;
			}
			else if(temp->one)
			{
				temp = temp->one;
			}
		}
		else
		{
			if(temp->one)
			{
				res += pow2[i];
				temp = temp->one;
			}
			else
			{
				temp = temp->zero;
			}
		}
	}
	return res;
}