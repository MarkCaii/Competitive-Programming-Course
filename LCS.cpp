#include<bits/stdc++.h>
using namespace std;
int m, n;
int dp[10000][10000];
int LCSW(int x, int y, string s, string t){
	if(x == m){
		if(s[x] == t[y]){
			return 1;
		}else{
			return 0;
		}
	}
	if(y == n){
		if(t[y] == s[x]){
			return 1;
		}else{
			return 0;
		}
	}
	if(s[x] == t[y]){
		if(dp[x][y] == 0){
			dp[x][y] = 1 + LCSW(x+1, y+1, s, t);
		}
		return dp[x][y];
	}else{
		return 0;
	}
}
int main(){
	int i, j, max;
	string s, t;
	cin >> m >> n;
	cin >> s >> t;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			int temp = LCSW(j, i, s, t);
			if(temp > max){
				max = temp;	
			}
		}
	}
	cout << max << endl;	
	return 0;
}
