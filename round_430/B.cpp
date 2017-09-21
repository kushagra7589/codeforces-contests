C

int main()
{
	ll r, d;
	cin >> r >> d;
	r -= d;
	int n; 
	cin >> n;
	ll x, y, R;
	ll cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> x >> y >> R;
		if((x*x + y*y >= (r + R)*(r + R)) && (x*x + y*y <= (r + d - R) * (r + d - R)))
			cnt += 1;
	}
	cout << cnt << endl;
	return 0;
}