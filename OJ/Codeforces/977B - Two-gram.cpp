#include<bits/stdc++.h>
using namespace std;

int main(){
	map<string,int> m;
	char s[100],t[2],r[2];
	int n,i,max=0;
	cin >> n;
	for (i=0;i<n;i++){
		cin >> s[i];
	}


	for (i=0;i<n-1;i++){
		t[0]=s[i];
		t[1]=s[i+1];
		m[t]++;
		if (m[t]>max){
			r[1]=t[1];
			r[0]=t[0];
			max=m[t];
		}
	}

	cout << r[0] <<r[1] << endl;

	return (0);
}