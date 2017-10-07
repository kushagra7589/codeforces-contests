#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int w[2*n];

	for(int i=0; i<2*n; i++)
		scanf("%d",&w[i]);

	sort(w,w+2*n);

	long long int tot=1000000000;

	for(int i=0; i<2*n-1; i++){
		for(int j=i+1; j<2*n; j++){

			int ctot=0;
			for(int z=0; z<2*n; z+=2){
				//printf("z=%d ", z);

				if(z==i)
					z++;
				int s=z+1;
				if(s==i)
					s+=1;
				if(s==j)
					s+=1;
				if(z<2*n && s<2*n)
					ctot+=abs(w[z]-w[s]);
				// printf("%d %d\n", z,s);
			}
			// printf("%d %d %d\n\n",i,j,ctot);

			if(ctot<tot)
				tot=ctot;

		}
	}

	printf("%lld", tot);
	return 0;
}
