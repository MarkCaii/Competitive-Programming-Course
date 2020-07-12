#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans[1000000] = {0};
ll findMin(int x, int n, int p[]){
	if(x >= n){
		return 0;
	}else{
		if(ans[x] == 0){
			ans[x] = min(findMin(x+1, n, p) + p[x], findMin(x+2, n, p) + p[x]);
		}
		return ans[x];
	}
}
int main(){
	int n;
	cin >> n;
	int p[n];
	for(int i = 0; i < n; i++)
		cin >> p[i];
	if(n == 1){
		cout << p[0] << endl;
	}else{
		int m = min(findMin(0, n, p), findMin(1, n, p) + p[n-1]);
		cout << m << endl;
	}
	return 0;
}
