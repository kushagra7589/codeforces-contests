#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define mp make_pair
#define pb push_back
#define F first
#define S second

string tic[4];
int arr[4][4];
int main()
{
	ios_base::sync_with_stdio(false);
	for(int i=0; i<4; i++)
		cin >> tic[i];
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			if(tic[i][j] == 'x')
				arr[i][j] = 1;
			else if(tic[i][j] == 'o')
				arr[i][j] = -1;
			else
				arr[i][j] == 0;
		}
	}
	int flag = 0;
	int sum = 0;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<2; j++)
		{
			sum = 0;
			for(int k=j; k < j+3; k++)
			{
				sum += arr[i][k];
			}
			if(sum == 2)
			{
				flag = 1;
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<2; j++)
		{
			sum = 0;
			for(int k=j; k < j+3; k++)
			{
				sum += arr[k][i];
			}
			if(sum == 2)
			{
				flag = 1;
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	for(int i=0; i<2; i++)
	{
		sum = 0;
		for(int j=i; j<i+3; j++)
		{
			sum += arr[j][j];
		}
		if(sum == 2)
		{
			flag = 1;
			cout << "YES" << endl;
			return 0;
		}
		sum = 0;
		for(int j=i; j<i+3; j++)
		{
			sum += arr[j][3-j];
		}
		if(sum == 2)
		{
			flag = 1;
			cout << "YES" << endl;
			return 0;
		}
	}
	sum = 0;
	for(int i=1;i<4; i++)
	{
		sum += arr[i][i-1];
	}
	if(sum == 2)
	{
		flag = 1;
		cout << "YES" << endl;
		return 0;
	}
	sum = 0;
	for(int i=1;i<4; i++)
	{
		sum += arr[i][4-i];
	}
	if(sum == 2)
	{
		flag = 1;
		cout << "YES" << endl;
		return 0;
	}
	sum = 0;
	for(int i=0;i<3; i++)
	{
		sum += arr[i][i+1];
	}
	if(sum == 2)
	{
		flag = 1;
		cout << "YES" << endl;
		return 0;
	}
	sum = 0;
	for(int i=0;i<3; i++)
	{
		sum += arr[i][2-i];
	}
	if(sum == 2)
	{
		flag = 1;
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}