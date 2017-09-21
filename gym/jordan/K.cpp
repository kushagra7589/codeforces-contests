#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int nom = n*(n-1)/2;
	if(nom%n){
		printf("No\n");
		return 0;
	}
	int d = (n-1)/2;
	printf("Yes\n");
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(j <= i+d){
				printf("1 ");
			}else printf("0 ");
		}
		printf("\n");
	}
	return 0;
}