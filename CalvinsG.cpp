#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k, idx;
	cin >> n >> k;
	int a[n+1];
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int dp1[n+1], dp2[n+1];
	dp1[1] = a[1];
	dp1[2] = a[1]+a[2];
	for(int i = 3; i <= n; i++){
		dp1[i] = a[i] + max(dp1[i-1], dp1[i-2]);
	}
	dp2[k] = 0;
	dp2[k-1] = 0;
	for(int i = k+1; i < n; i++){
		dp2[i] = a[i] + max(dp2[i-1], dp2[i-2]);
	}
	int ans = dp1[k]+dp2[k]-a[k];
	for(int i = k; i <= n; i++)
		ans = max(ans, dp1[i]+dp2[i]-a[i]);
	cout << ans << endl;
	return 0;
}
