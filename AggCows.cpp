#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, c;
bool check(int x, ll pos[]){
	int count = 1;
	ll current_dist = pos[0];
	for(int i = 1; i < n; i++){
		if((pos[i]-current_dist) >= x){
			if(++count == c){
				return true;
			}
			current_dist = pos[i];
		}
	}
	return false;
}
void getMinDist(){
	cin >> n >> c;
	ll pos[n];
	ll low = 0, high = 1000000000, p = 0;
	for(int i = 0; i < n; i++){
		cin >> pos[i];
	}
	sort(pos, pos+n);
	while(high >= low){
		cout << low << " " << high << endl;
		ll mid = (high+low)/2;
		if(check(mid, pos)){
			low = mid+1;
			p = mid;
		}else{
			high  = mid-1;
		}
	}
	cout << p << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		getMinDist();
	}
	return 0;
}
