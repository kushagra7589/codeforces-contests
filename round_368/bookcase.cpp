#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e3+10;
const int MAX_Q = 1e5+10;

int total_books[MAX_Q] = {0};

int book_is_kept[MAX_SIZE][MAX_SIZE];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	vector < vector < int> > V(n);
	for(int i=1; i<=n ; i++) {
		book_is_kept[i][0] = 1;
		for(int j=1; j <= m; j++) {
			book_is_kept[i][j] = -1;
		}
	}
	for(int i=0; i<M; i++) {
		V[0].push_back(0);
	}
	int choice, x, y;
	for(int i=1; i<=q; i++) {
		V[i] = V[i-1];
		cin >> choice ; 
		if(choice == 1) {
			cin >> x >> y;
			if(book_is_kept[x][0]*book_is_kept[x][y] == -1) {
				book_is_kept
			}
		}
	}
	return 0;
}