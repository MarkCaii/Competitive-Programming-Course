#include<bits/stdc++.h>
using namespace std;
bool compare(const  pair<int, int> &x, const pair<int, int> &y){
	return x.second > y.second;
}
int main(){
	int n, min {0};
	vector<pair<int, int>>times;
	cin >> n;
	for(int i = 0; i < n; i++){
		pair<int, int> temp;
		int p, pv, d;
		cin >> p >> pv >> d;
		temp = {p, pv+d};
		times.push_back(temp);
	}
	sort(times.begin(), times.end(), compare);
	for(int i = 0; i < n; i++){
		min += times[i].first;
	}
	min += times[n-1].second;
	int count = times[n-1].first + times[n-1].second;
	for(int i = n-2; i >= 0; i--){
		if(times[i].second > count){
			min -= count;
			min += times[i].second;
		}
		count += times[i].second;
		count += times[i].first;

	}
	cout << min << endl;
	return 0;
}
