#include <bits/stdc++.h>

using namespace std;

class CompareDist
{
public:
    bool operator()(pair<int,int> const &n1,pair<int,int> const &n2) {
        return n1.second>n2.second;
    }
};

priority_queue<pair<double, double>,  vector<pair<double, double> >, CompareDist > P;
vector<double> max_y;
int main(){
	ios_base::sync_with_stdio(false);
	int n, w;
	double v, u;
	cin>>n>>w>>v>>u;
	pair<double, double> c;
	double max_yy = 0;
	double min_time = 1e9+1;
	for(int i=0; i<n; i++){
		cin>>c.first>>c.second;
		if(c.first < 0)
			c.first  = 0;
		if(c.second > max_yy)
			max_yy = c.second;
		if(c.first/v < min_time){
			max_y.clear();
			min_time = c.first/v;
			max_y.push_back(c.second);
		}
		else if(c.first/v == min_time){
			max_y.push_back(c.second);
		}
		P.push(c);
	}
	double time = 0;
	double my_pos = 0;
	// cout<<"----------------------------"<<endl;
	// cout<<"MAX X : "<<max_x<<" MAX Y : "<<max_y<<endl;
	cout<<"MINTIME: "<<min_time<<" MAX_Y: "<<*max_element(max_y.begin(), max_y.end())<<endl;
	double yy = *max_element(max_y.begin(), max_y.end());
	if(min_time >= yy/u){
		// cout<<"Yo"<<endl;
		time = w/u;
	}
	else{
		while(!P.empty()){
			c = P.top();
			// cout<<c.first<<" "<<c.second<<endl;
			if(time <= c.first/v){
				time += max((c.second - my_pos)/u, (c.first-time)/v);
				my_pos = c.second;
			}
			// cout<<"T = "<<time<<" "<<" POS = "<<my_pos<<endl;
			P.pop();
		}
		time += (w - my_pos)/u;
	}
	printf("%.8lf\n", time);
	return 0;
}