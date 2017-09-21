#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define S second
#define F first

const int MAX_SIZE = 752;

vector< pair<ll, int > > sumI;
vector< vll > input(MAX_SIZE, vll());
vector< ll > ans;


int main()
{
	ios_base::sync_with_stdio(false);
	int k;
	while(cin >> k)
	{
		sumI.resize(k);
		for(int i=0; i<k; i++)
		{
			input[i].resize(k);
			for(int j=0; j<k; j++)
			{
				cin >> input[i][j];
			}
			sort(input[i].begin(), input[i].end());
		}
		queue< ll > q1;
		ll sum = 0;
		for(int i=0; i<k; i++)
		{
			sum += input[i][0];
		}
		q1.push(sum);
		for(int i=0; i<k; i++)
		{
			sumI[i].F = sum - input[i][0];
			int j = 1;
			int count  = 1;
			while(input[i][j] == input[i][0])
			{
				count += 1;
				j+=1;
			}
			sumI[i].S = count;
			// cout <<  sumI[i].F << " " << sumI[i].S << endl;
		}
		for(int i=0; i<k; i++)
		{
			for(int j=1; j<k; j++)
			{
				for(int x=0; x<sumI[i].S; x++)
					ans.pb(sumI[i].F + input[i][j]);
			}
		}
		sort(ans.begin(), ans.end());
		// for(auto i : ans)
		// {
		// 	cout << i << " ";
		// }
		// cout << endl;
		for(int i=0; i<k-1; i++)
		{
			q1.push(ans[i]);
		}
		while(!q1.empty())
		{
			cout << q1.front() << " ";
			q1.pop();
		}
		ans.clear();
		cout << endl;
	}
}