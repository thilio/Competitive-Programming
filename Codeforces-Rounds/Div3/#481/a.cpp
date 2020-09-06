#include<bits/stdc++.h>
using namespace std;

int v[1000],f[1001];

int main(){
	int i,n,ct=0;
	cin >> n;
	for (i=0;i<n;i++){
		cin >> v[i];
	}
	for (i=n-1;i>=0;i--){
		if (f[v[i]]!=0)
			v[i] = -1;
		else
			f[v[i]]++;
	}

	for (i=0;i<1001;i++){
		//cout << f[i] << 'a';
		if (f[i]>=1)
			ct++;
	}
	cout << ct << endl;
	for (i=0;i<n;i++)
		if (v[i]!=-1)
			cout << v[i]<<' ';
	cout << endl;

	return (0);
}