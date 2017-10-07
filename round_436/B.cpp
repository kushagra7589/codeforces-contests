#include <bits/stdc++.h>

using namespace std;;

typedef long long ll;

#define pb push_back
#define F first
#define S second

int cnt[110];

int main()
{
	set<int> A;
	int n;
	cin >> n;
	int a;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		cnt[a] += 1;
		A.insert(a);
	}
	if(A.size() != 2)
	{
		cout << "NO";
		return 0;
	}
	auto i = *A.begin();
	A.erase(i);
	auto j = *A.begin();
	if(cnt[i] == cnt[j])
	{
		cout << "YES" << endl; 
		cout << i << " " << j << endl;
		return 0;
	}
	cout << "NO" ;
	return 0;
}