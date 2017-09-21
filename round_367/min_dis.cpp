#include <bits/stdc++.h>

using namespace std;

const double INF = 1e9;

double distance(double x1, double y1, double x2, double y2)
{
	double dis = sqrt((((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2))));
	return dis;
}

double tim(double dis, double speed)
{
	return dis/speed;
}

int main()
{
	// ios_base::sync_with_stdio(false);
	double x1, y1;
	scanf("%lf %lf", &x1, &y1);
	int n;
	scanf("%d", &n);
	double x, y, v;
	double min_time = INF;
	for(int i=0; i<n; i++)
	{
		scanf("%lf %lf %lf", &x, &y, &v);
		double dis = distance(x1, y1, x, y);
		double tim1 = tim(dis, v);
		if(tim1 < min_time)
			min_time = tim1;
	}
	printf("%.12lf\n", min_time);
	return 0;
}