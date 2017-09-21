#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e5 + 10;

typedef long long ll;

ll arr[MAX_SIZE];
int capitals[MAX_SIZE] = {0};
int main(){
	ios_base::sync_with_stdio(false);
	ll n, k;
	cin>>n>>k;
	for(int i=0; i<n ; i++){
		cin>>arr[i];
	}
	ll precalc_ans = 0;
	ll presum = 0;
	for(int i=0; i<n; i++){
		presum += arr[i];
		precalc_ans += (arr[i]*arr[(i+1)%n]);
	}
	int index;
	for(int i=0; i<k; i++){
		cin>>index;
		index-=1;
		capitals[index] = 1;
		presum -= (arr[index]);
		if(capitals[(index + n - 1)%n] == 0)
			presum -= arr[(index+n-1)%n];
		if(capitals[(index+1)%n] == 0)
			presum -= arr[(index+1)%n];
		precalc_ans += (presum*arr[index]);
		if(capitals[(index + n - 1)%n] == 0)
			presum += arr[(index+n-1)%n];
		if(capitals[(index+1)%n] == 0)
			presum += arr[(index+1)%n];
	}
	cout<<precalc_ans<<endl;
	return 0;
}