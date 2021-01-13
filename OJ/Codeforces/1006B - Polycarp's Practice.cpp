#include <bits/stdc++.h>
using namespace std;

pair <int,int> v[10000];
int pos[10000];

int main(){
	int n,i,k;
	
	cin >> n;
	cin >> k;
	for (i=0;i<n;i++){
		cin >> v[i].first;
		v[i].second = i;
	}

	sort (v,v+n);

	int sum=0;
	for (i=n-k;i<n;i++){
	 	sum+=v[i].first;
	}

	cout << sum << endl;

	for (i=n-k;i<n;i++){
		pos[i-(n-k)] = v[i].second;
	}

	sort (pos,pos + k);

	if (k==1)
		cout << n <<endl;
	else{
		int ja=0;
		cout << pos[0] + 1 << ' ';
		ja+=pos[0] + 1;
		for (i=1;i<k-1;i++){
			cout << pos[i] - pos[i-1] << ' ';
			ja+=pos[i]-pos[i-1];
		}
		cout << n-ja << endl;

	}
	return(0);


}