#include <bits/stdc++.h>

using namespace std;

multiset<int, greater<int> > A;
set<int> pts;

int main()
{
	int t;
	cin >> t;
	int n;
	while(t--)
	{
		cin >> n;
		A.clear(); pts.clear();
		int x;
		for(int i = 0; i < (n * (n - 1)) / 2; i++)
		{
			cin >> x;
			A.insert(x);
		}
		pts.insert(0);
		pts.insert(*A.begin());
		A.erase(A.begin());
		auto m = pts.end();
		m--;
		int M = *m;
		while(true)
		{
			if(pts.size() == n)
				break;
			auto a = *A.begin();
			if(pts.find(a) == pts.end())
			{
				int new_point = a;
				bool flag = true;
				for(auto &x : pts)
				{					
					if(x == 0 || x == M)
						continue;
					if(A.find(abs(x - a)) == A.end())
					{
						flag = false;
						break;
					}
				}
				if(flag)
				{
					pts.insert(a);
					for(auto &x : pts)
					{
						auto some = A.find(abs(x - a));
						if(some != A.end())
						{
							A.erase(some);
						}
					}
					// cout << "Inserting " << a << endl;
					continue;
				}
			}
			pts.insert(M - a);
			a = M - a;
			for(auto &x : pts)
			{
				auto some = A.find(abs(x - a));
				if(some != A.end())
				{
					A.erase(some);
				}
			}
			// cout << "Inserting " << a << endl;
		}
		for(auto &i : pts)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}