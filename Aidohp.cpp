#include<bits/stdc++.h>
using namespace std;
string s;
int dp[10000][10000];
bool isPal(string str, int len){
	if(len%2 == 0){
		int mid = (len-1)/2;
		int j = len-1;
		for(int i = 0; i <= mid; i++){
			if(str[i] != str[j--])
				return false;
		}
		return true;
	}else if(len%2 != 0){
		int mid = (len-1)/2;
		int j = len-1;
		for(int i = 0; i < mid; i++){
			if(str[i] != str[j--])
				return false;
		}
		return true;
	}	
}

int findMin(int start, int end){
	if(isPal(s.substr(start, (end-start)), (end-start))){
		return 0;
	}
	if(start == end){
		return 0;
	}
	if(end - start == 1){
		if(s[0] == s[1]){
			return 0;
		}else{
			return 1;
		}
	}else{
		if(dp[start][end] == 0){
			dp[start][end] = 1 + min(findMin(start, end-1), findMin(start+1, end));
		}
		return dp[start][end];
	}
}
int main(){
	int t;
	cin >> t;
	for(int i =0; i < t; i++){
		s = "";
		cin >> s;
		cout <<	findMin(0, s.length()) << endl;			
	}
	return 0;
}
