#include<bits/stdc++.h>
using namespace std;

int main(){
	int i,n,k;
	cin >> n;
	cin >> k;
	for (i=0;i<k;i++){
		if (n%10==0)
			n=n/10;
		else
			n--;
	}

	cout << n <<endl;
	return (0);
}