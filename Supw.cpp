#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll answer[200000][3];
int findMin(int n, int a[], int x, int t){
	if(t == 3){
		return INT_MAX;
	}else if(x == n){
		return 0;
	}else{
		if(answer[x][t] == 0){
			int ans = min(findMin(n, a, x+1, t+1), findMin(n, a, x+1, 0) + a[x]);
			answer[x][t] = ans;
			return answer[x][t];
		}else{
			return answer[x][t];
		}
	}
}
int main(){
	int n, m;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++)
			answer[i][j] = 0;
	}
	cout << findMin(n, a, 0, 0) << endl;
	return 0;
}
