#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m, x = 0, y = 0;
	cin >> n >> m;
	string line;
	int dp[n][m];
	dp[n-1][0] = 1;
	dp[n-2][0] = 1;
	dp[n-1][1] = 1;
	for(int i = 0; i < n; i++){
		cin >> line;
		for(int j = 0; j < m; j++){
			if(line[m] == '*'){
				dp[i][j] = -1;
			}else if(dp[i][j] != 1){
				dp[i][j] = 0;
			}
		}
	}
	
	for(int i = n-2; i >= 0; i--){
		for(int j = 1; j < m; j++){
			if(j-1 == 0)
				x = 1;
			else
				x = dp[i][j-1];
			if(i+1 == n-1)
				y = 1;
			else
				y = dp[i+1][j];
			if(x != -1)
				dp[i][j] += x;
			if(y != -1)
				dp[i][j] += y;
		}
	}
	cout << dp[0][m-1] << endl;
	return 0;
}
