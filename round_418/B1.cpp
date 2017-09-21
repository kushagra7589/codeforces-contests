#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e4+10;

int A[MAX_SIZE], B[MAX_SIZE], C[MAX_SIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	set<int> left;
	for(int i = 1; i <= n; i++)
	{
		left.insert(i);
	}

	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> B[i];
	}
	vector<int> mark;

	for(int i = 0; i < n; i++)
	{
		if(A[i] == B[i])
		{
			C[i] = A[i];
 			left.erase(A[i]);
		}
		else
		{
			mark.push_back(i);
		}
	}
	if(left.size() == 2)
	{
		auto a = *left.begin();
		left.erase(*left.begin());
		auto b = *left.begin();
		if(A[mark[0]] == a && B[mark[1]] == b)
		{
			C[mark[0]] = a; C[mark[1]] = b;
		}
		else if(A[mark[0]] == b && B[mark[1]] == a)
		{
			C[mark[0]] = b; C[mark[1]] = a;
		}
		else if(A[mark[1]] == a && B[mark[0]] == b)
		{
			C[mark[0]] = b; C[mark[1]] = a;
		}
		else if(A[mark[1]] == b && B[mark[0]] == a)
		{
			C[mark[0]] = a; C[mark[1]] = b;
		}
	}
	else
	{
		C[mark[0]] = *left.begin();
	}
	for(int i = 0 ; i < n; i++)
	{
		cout << C[i] << " ";
	}
	cout << endl;
	return 0;
}