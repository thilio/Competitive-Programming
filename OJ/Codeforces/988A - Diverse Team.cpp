#include <bits/stdc++.h>
using namespace std;
int v[1000];

int main(){
	int n,k,sum = 0;
	cin >> n;
	cin>> k;
	for (int i=0;i<n && sum < k;i++){
		int at;
		cin >> at;
		if (v[at]==0){
			v[at] =i+1;
			sum ++;
		}
	}
	if (sum==k){
		cout <<"YES" << endl;
		for (int i=0;i<101;i++){
			if (v[i]!=0)
				cout << v[i]<<' ';

		}
		cout << endl;
	}
	else
		cout << "NO" << endl;

	return (0);

}