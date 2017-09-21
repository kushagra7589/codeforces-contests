#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define F first
#define S second
#define mp make_pair
vector< pair<vector< int >, double >  > times;

// bool compareTime(vector<int> const &t1, vector<int> const &t2)
// {
// 	if(t1[0] != t2[0])
// 		return t1[0] > t2[0];
// 	else if(t1[1] != t2[1])
// 		return t1[1] > t2[1];
// 	else
// 		return t1[2] > t2[2];
// }

double subtractTime(vector<int> const &a, vector<int> const &b)
{
	double ans = (a[0] - b[0])*3600.0;
	ans += (a[1] - b[1])*60.0;
	ans += (a[2] - b[2]);
	return ans;
}

vector<int> makeTime(string a)
{
	stringstream ss;
	ss.str(a);
	string item;
	vector<int> res;
	while(getline(ss, item, ':'))
	{
		res.pb(stoi(item));
	}
	return res;
}

double query(vector<int> const &x)
{

	double dist = 0;
	dist += (subtractTime(x, times[times.size()-1].F) * 5.0 * times[times.size()-1].S )/(18.0 * 1000.0);
	for(int i= times.size()-2; i >= 0; i--)
	{
		dist += (subtractTime(times[i+1].F, times[i].F) * 5.0 * times[i].S)/(18.0 * 1000.0) ; 
	}
	return dist;
}

void displayTime(vector<int> const &a)
{
	for(auto i : a)
	{
		cout << i << ":";
	}
	cout << endl;
}

int main()
{
	string input;
	ll speed;
	vector<int> A;
	A.pb(0); A.pb(0); A.pb(0);
	times.pb(mp(A, 0.0));
	while(getline(cin, input))
	{
		stringstream ss;
		ss.str(input);
		string item;
		pair<vector<int>, double > inter;
		vector<string> temp;
		while(getline(ss, item, ' '))
		{
			temp.pb(item);
		}
		if(temp.size() == 1)
		{
			double ans = query(makeTime(temp[0]));
			// cout << "Query" << endl;
			cout << temp[0] << " " <<setprecision(2)<<fixed<< ans << " km\n";
		}
		else if(temp.size() == 2)
		{
			inter.F = makeTime(temp[0]);
			// displayTime(inter.F);
			inter.S = stod(temp[1]);
			times.pb(inter);
			// cout << "Update" << endl;
		}
	}
}