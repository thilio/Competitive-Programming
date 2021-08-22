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

set<int> S[200200];
bool bom[200200];
int ans;

void add_edge(){
	int u, v;
	cin >> u >> v;

	if(bom[u] && (v > u)){
		bom[u] = false;
		ans--;
	}
	if(bom[v] && (u > v)){
		bom[v] = false;
		ans--;
	}

	S[u].insert(v);
	S[v].insert(u);
}

void rem_edge(){
	int u, v;
	cin >> u >> v;

	S[u].erase(v);
	S[v].erase(u);

	auto it = S[u].end();
	it--;

	if(!bom[u] && (S[u].empty()|| *(it) < u)){
		bom[u] = true;
		ans++;
	}


	it = S[v].end();
	it--;

	if(!bom[v] && (S[v].empty() || *(it) < v)){
		bom[v] = true;
		ans++;
	}
}

int main(){

	fastio;

	int n, m;
	cin >> n >> m;

	frr(i, n) bom[i] = true;
	ans = n;

	fr(i, m){
		add_edge();
	}

	int q;
	cin >> q;

	fr(i, q){
		int op;
		cin >> op;
		if(op == 1){
			add_edge();
		}
		if(op == 2){
			rem_edge();
		}
		if(op == 3){
			cout << ans << '\n';
		}
	}

}
