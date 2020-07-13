#include<bits/stdc++.h>
using namespace std;
int m, n, maximum = 0;
string s, t;
int dp[10000][10000];
int LCSW(int x, int y){
	if(x == m-1){
		for(int i = x; i < n; i++){
			if(s[x] == t[i])
				return 1;
		}
		return 0;
	}else if(y == n-1){
		for(int i = y; i < m; i++){
			if(t[y] == s[i])
				return 1;
		}
		return 0;
	}else{
		if(s[x] == t[y]){
			if(dp[x][y] == 0){
				dp[x][y] = 1 + LCSW(x+1, y+1);
				if(dp[x][y] > maximum)
					maximum = dp[x][y];
			}
			return dp[x][y];
		}else{
			dp[x][y] = 0;
			return max(LCSW(x+1, y), LCSW(x, y+1));
		}
	}
}
int main(){
	int temp;
	cin >> s >> t;
	m = s.length();
	n = t.length();
	LCSW(0,0);
	cout << maximum << endl;
	return 0;
}
