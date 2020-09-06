#include <bits/stdc++.h>
using namespace std;


int main(){
	int v[2000];
	int n;
	cin >> n;
	int i;
	int at;
	for (i=0;i<n;i++){
		cin >> at;
		if (at%2==0)
			at--;
		v[i] = at;
	}

	for (i=0;i<n;i++){
		cout << v[i] << ' ';
	}
	cout << endl;
	return (0);

}