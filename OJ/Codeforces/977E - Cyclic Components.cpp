#include<bits/stdc++.h>
using namespace std;
vector<int> V[1123456],chk[1123456];
int f[1123456];
void DFS (int i,int t){
	int j;
	f[i]=t;
	chk[t].push_back(i);
	for (j=0;j<V[i].size();j++){
		if (f[V[i][j]]==0)
			DFS(V[i][j],t);
	}

}

int main(){
	int j,a,b,i,m,n,t=1,ct,ans=0,sum,ok;
	cin >> n;
	cin >> m;
	for (i=0;i<m;i++){
		cin >> a;
		cin >> b;
		V[a].push_back(b);
		V[b].push_back (a);
	}
//	cout << 'a' <<endl;
	for (i=1;i<=n;i++){
//		cout << i <<endl;
		if (f[i]==0){
			DFS(i,t);
			t++;
		}
	}
//	cout << 'a' <<endl;


	for (i=1;i<t;i++){
		ok=1;
		for (j=0;j<chk[i].size() && ok;j++){
			if (V[chk[i][j]].size()!=2)
				ok=0;
		}
	
		if (ok) ans++;
		
	}

	cout << ans <<endl;	
	return (0);
}