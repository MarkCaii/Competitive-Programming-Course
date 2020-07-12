#include<bits/stdc++.h>
using namespace std;
int lowerBound(int a[], int val, int s, int e){
	if(s >= e){
		if(a[s] > val)
			return -1;
		else		
			return a[s];
	}
	int mid = (s+e)/2;
	if(val == a[mid]){
		return a[mid];	
	}else if(val > a[mid] && val < a[mid+1]){
		return a[mid];
	}else if(val >a[mid]){
		return lowerBound(a, val, mid+1, e);
	}else if(val < a[mid]){
		return lowerBound(a, val, s, mid);
	}
}
int upperBound(int a[], int val, int s, int e){
	if(s >= e){
		if(a[s] > val)
			return -1;
		else		
			return a[s];
	}
	int mid = (s+e)/2;
	if(val == a[mid]){
		return a[mid];	
	}else if(val < a[mid] && val > a[mid-1]){
		return a[mid];
	}else if(val > a[mid]){
		return upperBound(a, val, mid+1, e);
	}else if(val < a[mid]){
		return upperBound(a, val, s, mid);
	}
}

int main(){
	int n, x, y, min = 1000001;
	pair<int, int> temp;
	cin >> n >> x >> y;
	int v[x], w[y];
	vector<pair<int, int>>cont;
	for(int i = 0; i < n; i++){
		int s, f;
		cin >> s >> f;
		temp = {s, f};
		cont.push_back(temp);
	}
	for(int i = 0; i < x; i++)
		cin >> v[i];
	for(int i = 0; i < y; i++)
		cin >> w[i];
	sort(v, v+x);
	sort(w, w+y);
	for(int i = 0; i < n; i++){
		int lower = lowerBound(v, cont[i].first, 0, x-1); 
		int upper = upperBound(w, cont[i].second, 0, y-1);
		if(upper != -1 && lower != -1 && upper > lower){
			if((upper-lower+1) < min){
				min = upper-lower+1;
			}
		}
	}
	cout << min << endl;
	return 0;
}
