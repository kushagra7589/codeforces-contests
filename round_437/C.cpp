#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define F first
// #define S second
#define fast_cin() ios_base::sync_with_stdio(false)

const int MAX_SIZE = 1e5 + 10;

ll slices[MAX_SIZE], A[MAX_SIZE], B[MAX_SIZE];

ll solve(ll X, ll Y, ll SUM, ll S, vector< pair<ll, ll> > diff)
{
	// cout << X << " " << Y << endl;
	ll xmin = max((ll)0, SUM - Y*S), xmax = S*X;
	// cout << xmin << " " << xmax << endl;
	int n = diff.size();
	ll pos = 0;
	int i = 0;
	ll sum = 0;
	ll tot = 0;
	while(i < n && sum + diff[i].second < xmin)
	{
		sum += diff[i].second;
		tot += diff[i].first * diff[i].second;
		diff[i].second = 0;
		i++;
	}
	if(i == n)
		return 0;
	tot += (xmin - sum) * diff[i].first;
	diff[i].second -= (xmin - sum);
	sum = xmin;
	while(i < n && diff[i].first > 0 && sum + diff[i].second < xmax)
	{
		tot += diff[i].first * diff[i].second;
		sum += diff[i].second;
		diff[i].second = 0;
		i++;
	}
	if(i == n)
		return tot;
	if(diff[i].first > 0)
	{
		tot += (xmax - sum) * diff[i].first;
	}
	return tot;
}

int main()
{
	ll N, S;
	cin >> N >> S;
	ll s, a, b, X, Y, totX, totY = 0, total;
	ll sum = 0;
	ll pos = 0;
	vector< pair<ll, ll > > diff1, diff2;
	for(int i = 1; i <= N; i++)
	{
		cin >> slices[i] >> A[i] >> B[i];
		sum += slices[i];
		diff1.pb({A[i] - B[i], slices[i]});
		diff2.pb({A[i] - B[i], slices[i]});
		totY += B[i] * slices[i];
		if(A[i] > B[i])
			pos += slices[i];
	}
	ll pizzas = (sum + S - 1) / S;
	ll Xmin = pos / S, Xmax = (pos + S - 1) / S;
	sort(diff1.begin(), diff1.end(), greater<pair<ll, ll> >());
	sort(diff2.begin(), diff2.end(), greater<pair<ll, ll> >());
	ll one = solve(Xmin, pizzas - Xmin, sum, S, diff1);
	ll two = solve(Xmax, pizzas - Xmax, sum, S, diff2);
	// cout << Xmin << " " << Xmax << endl;
	// cout << one << " " << two << " " << totY << endl;
	cout << totY + max(one, two) << endl;
	return 0;
}