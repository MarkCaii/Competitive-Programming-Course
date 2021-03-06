#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll dp[10000][10000];
bool isPal(string str, ll len){
	ll mid = len/2;
	ll j = len-1;
	if(len%2 == 0){
		for(ll i = 0; i <= mid; i++){
			if(str[i] != str[j--])
				return false;
		}
		return true;
	}else if(len%2 != 0){
		for(ll i = 0; i < mid; i++){
			if(str[i] != str[j--])
				return false;
		}
		return true;
	}	
}

int findMin(ll start, ll end){
	if(isPal(s.substr(start, (end-start+1)), (end-start+1))){
		return 0;
	}
	if(start == end){
		return 0;
	}else{
		if(dp[start][end] == -1){
			dp[start][end] = 1 + min(findMin(start, end-1), findMin(start+1, end));
		}
		return dp[start][end];
	}
}
int main(){
	ll t;
	cin >> t;
	for(ll i =0; i < t; i++){
		s = "";
		cin >> s;
		for(ll j = 0; j < s.length(); j++){
			for(ll h = 0; h < s.length(); h++){
				dp[j][h] = -1;
			}	
		}
		cout <<	findMin(0, s.length()-1) << endl;			
	}
	return 0;
}
