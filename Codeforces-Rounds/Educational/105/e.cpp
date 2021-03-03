#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int n,m;
map<pii, char> tem;
int main(){

	fastio;
	cin >> n >> m;

	int ig = 0;
	int dif = 0; 

	fr(i,m){
		char op, c;
		int u, v;

		cin >> op;
		if(op == '+'){
			cin >> u >> v;
			cin >> c;
			tem[mp(u,v)] = c;
			if(tem.count(mp(v,u))){
				if(tem[{v,u}] == c) ig++;
				else dif++;
			}
		}
		if(op == '-'){
			cin >> u >> v;
			c = tem[{u,v}];
			tem.erase({u,v});
			if(tem.count({v,u})){
				if(tem[{v,u}] == c) ig--;
				else dif--;
			}
		}
		if(op == '?'){
			cin >> u;
			if(u%2 == 1){
				if(dif > 0 || ig > 0) cout<< "YES" << endl;
				else cout << "NO" << endl;
			}
			else{
				if(ig > 0) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
		}

	}

}
