#include<iostream>
using namespace std;
#define ll long long
int main(){
	int n;
	cin >> n;
	ll a[n], diff1[n], diff2[n], sumArray[n], sum = 0, num;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> num;
		sum += num;
		sumArray[i] = sum;
	}
	diff1[0] = a[0] - sumArray[0];
	for(int i = 1; i < n; i++){
		diff1[i] = max(diff1[i-1], a[i] - sumArray[i]);
		cout << diff1[i] << " ";
	}
	cout << endl;
	diff2[0] = a[0];
	for(int i = 1; i < n; i++){
		diff2[i] = max(diff2[i-1], sumArray[i-1] + a[i]);
		cout << diff2[i] << " ";
	}
	cout << endl;
	return 0;
}
