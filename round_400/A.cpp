#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define F first
#define S second
#define mp make_pair

int main()
{
	ios_base::sync_with_stdio(false);
	set< string > hm;
	string A, B;
	cin >> A >> B;
	hm.insert(A);
	hm.insert(B);
	int N;
	cin >> N;
	for(auto &it : hm)
		cout << it << " ";
	cout << endl;
	for(int i=0; i<N; i++)
	{
		cin >> A >> B;
		hm.erase(A);
		hm.insert(B);
		for(auto &j : hm)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}