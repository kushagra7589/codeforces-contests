#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e5 + 10;

typedef long long ll;

ll a[MAX_SIZE], b[MAX_SIZE];

bool p(ll x, int n, int k){
	ll req = 0;
	for(int i=0; i<n; i++){
		req += max((ll)0, a[i]*x - b[i]);
		if(req > k)
			return 0;
	}
	return 1;
}

int maximise_cookies(int n, int k){
	int maxim = 0;
	for(int i = 0; i<n; i++){
		maxim  = max((ll)maxim, (b[i]+k)/a[i]);
	}
	int l = 0;
	int u = maxim+1;
	while(l < u){
		int mid = l + (u-l)/2;
		if(p(mid, n, k)){
			l = mid+1;
		}
		else{
			u = mid;
		}
	}
	return l-1;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin>>n>>k;
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++)
		cin>>b[i];
	int ans = maximise_cookies(n, k);
	cout<<ans<<endl;
	return 0;
}
