#include <bits/stdc++.h>
using namespace std;
int comp(string s,int t,string l,int r){
	int i;
	for (i=0;i<r;i++){
		if (s[0]==l[i]){
			int k;
			k=1;
			while (s[k] == l[i+k] && (i + k) < r && k<t){
				k++;
			}
			if (k==t)
				return (1);
		}
	}

	return (0);




}

int main(){
	vector<pair <int,string> > v;
	int n,ok=1;
	

	cin >> n;
	v.resize(n);
	getchar();
	for (int i=0;i<n;i++){
		getline (cin,v[i].second);
		v[i].first = v[i].second.size();
	}
	sort (v.begin(),v.end());
	for (int i =0; i<n-1;i++){
		if (!comp(v[i].second,v[i].first,v[i+1].second,v[i+1].first))
			ok=0;

	}



	if (ok){
		cout << "YES" << endl;
		for (int i=0;i<n;i++){
			cout << v[i].second <<endl;
		}
	}
	else{
		cout << "NO" << endl;
	}
	return (0);

}