#include "bits/stdc++.h"
using namespace std;

const int N = 100100;
const int LOGN = 20;

int lg[N];
int st[N][LOGN];
int v[N];
int n;

void build_st(){
	lg[1] = 0;
	for(int i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;

	for(int i = 0; i < n; i++) st[i][0] = v[i];

	for(int j = 1; j <= lg[n]; j++){
		for(int i = 0; i + (1 << j) <= n; i++){
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query_st(int l, int r){ // minimum element in v[l, ..., r] 
	int j = lg[r - l + 1];
	return min(st[l][j], st[r - (1 << j) + 1][j]);
}

int main(){
	cin >> n;

	for(int i = 0; i < n; i++) cin >> v[i];
	build_st();

}
