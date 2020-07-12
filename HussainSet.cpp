#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	int n, m;
	cin >> n >> m;
	ll set[n];
	queue<ll> q1;	
	for(int i = 0; i < n; i++){
		cin >> set[i];
	}
	sort(set, set+n);
	int count = 0, temp, endp = n-1;
	for(int i = 0; i < m; i++){
		ll ans;
		cin >> temp;
		for(;count < temp; count++){
			if(endp >= 0 && (q1.empty() || (q1.front()<=set[endp]))){
				ans = set[endp];
				endp--;
			}else{
				ans = q1.front();
				q1.pop();
			}
			q1.push(ans/2);
		}
		cout << ans << endl;
	}
	return 0;
}
