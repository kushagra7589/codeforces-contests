#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define F first 
#define S second

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		fflush(stdout);
		int n;
		cin >> n;
		vector<int> max_numbers, min_numbers;
		for(int i=1; i<=n; i++)
		{
			max_numbers.pb(i);
			min_numbers.pb(i);
		}
		string res;
		if(n > 1)
		{
			for(int i=1; i<n-1; i+=2)
			{
				cout << "? " << i << " " << i + 1 << endl;
				fflush(stdout);
				cin >> res;
				fflush(stdout);
				if(res == "=")
				{
					min_numbers.erase(find(max_numbers.begin(), max_numbers.end(), i));
					max_numbers.erase(find(min_numbers.begin(), min_numbers.end(), i));
				}
				else if(res == "<")
				{
					max_numbers.erase(find(max_numbers.begin(), max_numbers.end(), i));
					min_numbers.erase(find(min_numbers.begin(), min_numbers.end(), i+1));
				}
				else
				{
					max_numbers.erase(find(max_numbers.begin(), max_numbers.end(), i+1));
					min_numbers.erase(find(min_numbers.begin(), min_numbers.end(), i));
				}
			}
			cout << "? " << n-1 << " " << n << endl;
			fflush(stdout);
			cin >> res;
			fflush(stdout);
			if(res == "=")
			{
				max_numbers.erase(find(max_numbers.begin(), max_numbers.end(), n-1));
				min_numbers.erase(find(min_numbers.begin(), min_numbers.end(), n-1));
			}
			else if(res == "<")
			{
				max_numbers.erase(find(max_numbers.begin(), max_numbers.end(), n-1));
				min_numbers.erase(find(min_numbers.begin(), min_numbers.end(), n));
			}
			else
			{
				max_numbers.erase(find(max_numbers.begin(), max_numbers.end(), n));
				min_numbers.erase(min_numbers.begin() + n-2);
			}
			while(min_numbers.size() > 1)
			{
				int N = min_numbers.size()-1;
				for(int i=0; i<N-1; i+=2)
				{
					cout << "? " << min_numbers[i] << " " << min_numbers[i+1] << endl;
					fflush(stdout);
					cin >> res;
					fflush(stdout);
					if(res == "=")
					{
						min_numbers.erase(min_numbers.begin() + i);
					}
					else if(res == "<")
					{
						min_numbers.erase(min_numbers.begin() + i+1);
					}
					else
					{
						min_numbers.erase(min_numbers.begin() + i);
					}
				}
				cout << "? " << min_numbers[N-1] << " " << min_numbers[N] << endl;
				fflush(stdout);
				cin >> res;
				if(res == "=")
				{
					min_numbers.erase(min_numbers.begin() + N-1);
				}
				else if(res == "<")
				{
					min_numbers.erase(min_numbers.begin() + N);
				}
				else
				{
					min_numbers.erase(min_numbers.begin() + N-1);
				} 
			}
			while(max_numbers.size() > 1)
			{
				int N = max_numbers.size()-1;
				for(int i=0; i<N-1; i+=2)
				{
					cout << "? " << max_numbers[i] << " " << max_numbers[i+1] << endl;
					fflush(stdout);
					cin >> res;
					fflush(stdout);
					if(res == "=")
					{
						max_numbers.erase(find(max_numbers.begin(), max_numbers.end(), max_numbers[i]));
					}
					else if(res == ">")
					{
						max_numbers.erase(find(max_numbers.begin(), max_numbers.end(), max_numbers[i+1]));
					}
					else
					{
						max_numbers.erase(find(max_numbers.begin(), max_numbers.end(), max_numbers[i]));
					}
				}
				cout << "? " << max_numbers[N-1] << " " << max_numbers[N] << endl;
				fflush(stdout);
				cin >> res;
				if(res == "=")
				{
					max_numbers.erase(find(max_numbers.begin(), max_numbers.end(), max_numbers[N-1]));
				}
				else if(res == ">")
				{
					max_numbers.erase(find(max_numbers.begin(), max_numbers.end(), max_numbers[N]));
				}
				else
				{
					max_numbers.erase(find(max_numbers.begin(), max_numbers.end(), max_numbers[N-1]));
				}
			}
			cout << "! " << min_numbers[min_numbers.size()-1] << " " << max_numbers[max_numbers.size()-1] << endl;
		}
		else
		{
			cout << "! 1 1" << endl;
			fflush(stdout);
		} 
		min_numbers.clear();
		max_numbers.clear();
	}
	return 0;
}