#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define F first
#define S second

int main()
{
	ios_base::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end(), greater<char>());
	string ans(s.length(), '?');
	int n = s.length();
	string s1(n - n/2, '.'), t1(n/2, '.');
	for(int i = 0; i < n/2; i++)
	{
		s1[i] = s[i];
		t1[i] = t[i];
	}
	s1[n - (n/2) - 1] = s[n - (n/2) - 1];
	sort(t1.begin(), t1.end());
	int min_i = 0, max_i = n - (n/2) - 1;
	int min_j = 0, max_j = (n/2) - 1;
	int first = 0;
	int last = n -1;

	for(int x = 0; x < n; x++)
	{
		if(x % 2 == 0)
		{
			if(s1[min_i] >= t1[max_j])
			{
				ans[last] = s1[max_i];
				max_i--;
				last--;
			}
			else
			{
				ans[first] = s1[min_i];
				min_i++;
				first++;
			}
		}
		else
		{
			if(t1[max_j] <= s1[min_i])
			{
				ans[last] = t1[min_j];
				min_j++;
				last--;
			}
			else
			{
				ans[first] = t1[max_j];
				max_j--;
				first++;
			}
		}
	}
	// cout << ans << endl;
	// for(int i = 0, j = 0; i < n; i += 2, j++)
	// {
	// 	ans[i] = s[j];
	// }
	// for(int i = 1, j = 0; i < n; i += 2, j++)
	// {
	// 	ans[i] = t[j];
	// }
	cout << ans << endl;
	return 0;
}