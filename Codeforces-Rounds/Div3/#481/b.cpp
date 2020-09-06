#include<bits/stdc++.h>
using namespace std;

int main(){
	char s[1000];
	int n,i,ct=0;
	cin >> n;
	for (i=0;i<n;i++){
		cin >> s[i];
	}
	for (i=2;i<n;i++){
		if (s[i-2]== 'x' && s[i-1]== 'x' && s[i]== 'x')
			ct++;
	}
	cout << ct <<endl;
	return (0);
}