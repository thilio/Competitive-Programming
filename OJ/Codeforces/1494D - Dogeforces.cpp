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

int n, k, c[30000], sal[5000][5000], pai[5000];
vi son[30000];

int solve(vi v){

	int mx = 0;
		//if(v.size() == 2) olar;
	if(v.size() == 1) return v[0];
		//if(v.size() == 2) olar;

	for(int i = 1; i < v.size(); i++){
		mx = max(sal[v[0]][v[i]], mx);
	}

	vector<vi> g;
	g.resize(v.size());
	fr(i,v.size()) g[i].clear();

	fr(i,v.size()){
		bool ok = false;
		fr(j,v.size()){
			if(g[j].size() == 0) continue;
			if(sal[v[i]][g[j][0]] < mx && !ok){
				g[j].pb(v[i]);
				ok = true;
			}
		}
		if(!ok) g[i].pb(v[i]);
	}

//	if(v.size() == 2) olar;

	int raiz = k++;
	c[raiz] = mx;

	fr(i,v.size()){
		if(g[i].size()) son[raiz].pb(solve(g[i]));
	}
	return raiz;
}

int main(){

	fastio;
	cin >> n;

	frr(i,n){
		frr(j,n){
			cin >> sal[i][j];
		}
	}
	k = n + 1;

	vi v;
	frr(i,n) v.pb(i);
	frr(i,n) c[i] = sal[i][i];

	int root = solve(v);

	k--;

	cout << k << endl;
	frr(i,k) cout << c[i]<<' ';
	gnl;
	cout << root << endl;
	frr(i,k){
		for(auto x: son[i]) pai[x] = i;
	}
	frr(i,k){
		if(pai[i] != 0) cout << i << ' ' << pai[i] << endl;
	}

}
