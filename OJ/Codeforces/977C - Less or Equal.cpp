#include<bits/stdc++.h>
using namespace std;

int main(){
	int i,n,k,v[1123456];
	cin >> n;
	cin >>k;
	for (i=0;i<n;i++){
		cin >> v[i];
	}
	sort (v,v + n);
	if (k==n){
		cout << v[n-1] << endl;
	}
	else if (k==0)
		if (v[k]==1)
			cout << -1 <<endl;
		else
			cout << v[k]-1<<endl;
	else{
		if (v[k-1]==v[k])
			cout << -1 << endl;
		else
			cout << v[k-1] << endl;
	}
	return (0);
}