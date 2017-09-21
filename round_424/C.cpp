#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 2e3 + 10;

set<int> S;
set<int> B
int C[MAX_SIZE];
int prefix[MAX_SIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	int x;
	cin >> n >> k;
	int N = n;
	vector<int> A;
	for(int i = 1; i <= n; i++)
	{
		cin >> x;
		if(x != 0)
		{
			A.push_back(x);
		}
		else
		{
			N--;
		}
	}
	for(int i = 0; i < N; i++)
	{
		if(i > 0)
			prefix[i] = prefix[i - 1] + A[i];
		else
			prefix[i] = A[i];
	}
	for(int i = 0; i < k; i++)
	{
		cin >> x;
		B.insert(x);
		C[i] = insert(x);
	}
	for(int c = 0; c < k; c++)
	{
		B.erase(C[c]);
		for(int i = 0; i <= N - k; i++)
		{
			int added = 0;
			for(int j = i + 1; j < N; j++)
			{
				if(B.find(C[c] + prefix[j] - prefix[i]) != B.end())
					added += 1;
			}
			if(added == k - 1)
				S.insert(C[c] - prefix[i]);
		}
		B.insert(C[c]);
	}
	cout << S.size() << endl;
	// for(auto &s: S)
	// 	cout << s << " ";
	// cout << endl;
	return 0;
}