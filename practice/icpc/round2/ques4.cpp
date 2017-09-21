#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>

const int M = 1e9+7;
const int MAX_SIZE = 1e5+10;

ll arr[MAX_SIZE];
bool flag[MAX_SIZE];

multiset<pair<ll, int> > all;
multiset<pair<ll, int> > jack;
multiset<pair<ll, int > > other;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> arr[i];
		flag[i] = false;
		all.insert(mp(arr[i], i));
	}
	arr[n+1] = 0;
	flag[n+1]=false;
	int i=1;
	multiset<pair<ll, int> >::iterator it = all.begin();
	for(it; it != all.end(); it++)
	{
		if(i<=n/2)
		{
			other.insert(*it);
		}
		else
			break;
		i++;
	}
	for(it; it!=all.end(); it++)
	{
		jack.insert(*it);
	}
	i=1;
	ll j = 0, o = 0; 
	while(i <= n)
	{
		// cout << "Checking : " << arr[i] << endl;
		if(flag[i] == false)
		{
			if(i == n)
			{
				j += arr[i];				
				// cout << "Added to j : " << arr[i] << " Now j is : " << j << endl;
				i++;
			}
			else
			{
				int x = i+1;
				while(x <= n && flag[x] == true)
					x++;
				if(x <= n)
				{
					if(jack.find(mp(arr[i], i)) != jack.end())
					{
						if(jack.find(mp(arr[x], x)) != jack.end())
						{
							j += max(arr[i], arr[x]);
							// cout << "Added to j : " << max(arr[x+1], arr[i]) << " Now j is : " << j << endl;
							o += min(arr[i], arr[x]);
							// cout << "Added to o : " << min(arr[i], arr[x+1]) << " Now o is : " << o << endl;
							jack.erase(mp(arr[i],i));
							jack.erase(mp(arr[x],x));
							multiset<pair<ll, int> >::iterator del = other.end();
							del--;
							jack.insert(*del);
							other.erase(del);
							flag[i] = true;
							flag[x] = true;
						}
						else
						{
							j += arr[i];
							o += arr[x];
							jack.erase(mp(arr[i], i));
							// cout << "Added to j : " << arr[i] << " Now j is : " << j << endl;
							// cout << "Added to o : " << arr[x] << " Now o is : " << o << endl;
							other.erase(mp(arr[x], x));
							flag[i] = true;
							flag[x] = true;
						}
					}
					else
					{
						int y=x;
						while(y <= n && jack.find(mp(arr[y], y)) == jack.end())
							y++;
						if(y != x)
							x -= 1;
						if(y <= n)
						{
							j += arr[y];
							jack.erase(mp(arr[y], y));
							flag[y] = true;
						}
						o += arr[i];
						// cout << "Added to j : " << arr[y] << " Now j is : " << j << endl;
						// cout << "Added to o : " << arr[i] << " Now o is : " << o << endl;
						other.erase(mp(arr[i], i));
						flag[i] = true;
					}

				}
				i = x+1;
			}
		}
		else
		{
			i++;
		}
	}
	cout << j << " " << o << endl;
	return 0;
}