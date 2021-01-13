#include <bits/stdc++.h>
using namespace std;

int main(){
	string s,t;

	getline(cin,s);
	getline (cin,t);

	int st,ss;
	st = t.size();
	ss=s.size();
	int i;

	for (i=0;i<min(ss,st);i++){
		if (s[ss - i - 1] != t[st - i -1]) break;
	}

	cout << ss + st - 2*i << endl;
	return (0);
}