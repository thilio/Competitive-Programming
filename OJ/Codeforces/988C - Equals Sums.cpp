#include <bits/stdc++.h>
using namespace std;
int main(){ 
	int k,n,i,ct,a,sum,ok=0,I,J,X,Y;
	vector <int> v;
	map <int,pair<int,int> > m;
	cin >> k;
	for (ct=0;ct<k && !ok;ct++){
		cin >> n;
		v.clear();
		sum =0;
		for (i=0;i<n;i++){
			cin >> a;
			sum+= a;
			v.push_back(a);
		}
		int t = v.size();
		for (i=0;i<t && !ok;i++){
			//cout <<m[9].first << endl;
			if (m[sum - v[i]].first == 0){
				//cout << "a "<<m[sum - v[i]].first<< endl;
				m[sum-v[i]].first = ct + 1;
				m[sum - v[i]].second = i + 1;
			}
			else{
				if(m[sum-v[i]].first != ct + 1){
					ok = 1;
					I = ct + 1;
					X = i + 1;
					J = m[sum-v[i]].first;
					Y = m[sum-v[i]].second;
				}
			}
		}
	}
	if (ok){
		cout << "YES" << endl;
		cout << I << ' ' << X << endl;
		cout << J << ' ' << Y << endl;
	}
	else
		cout <<"NO" << endl;
	return (0);
}