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

int pai[100100];
ll val[100100];
vi filhos[100100];
int vis[100100];
ll ans;

bool dfs (int v,int valo){
	vis[v] = 1;
	if(v==1){
		bool ok = true;
		for(int i = 0;i<filhos[v].size();i++){
			if(!vis[filhos[v][i]]){
				ok = (ok && dfs(filhos[v][i],val[1]));
			}
		}
		return ok;
	}
	if(val[v] == -1){
		bool ok = true;
		for(int i = 0;i<filhos[v].size();i++){
			if(!vis[filhos[v][i]]){
				ok = (ok && dfs(filhos[v][i],valo));
			}
		}
		return ok;
	}

	if(val[v] < valo){
		return false;
	}

	bool ok = true;
	for(int i = 0;i<filhos[v].size();i++){
		if(!vis[filhos[v][i]]){
			ok = (ok && dfs(filhos[v][i],val[v]));
		}
	}
	return ok;
}

void dffs(int v,ll valo){
	vis[v] = 1;
	if(val[v]!=-1){
		ans += val[v] - valo;
	}

	if(val[v] == -1){
		if(filhos[v].size() == 0) return;
		ll mn = llINF;
		for(int i = 0;i<filhos[v].size();i++){
			if(mn > val[filhos[v][i]])
				mn = val[filhos[v][i]];
		}
		ans += mn - valo;
		for(int i = 0;i<filhos[v].size();i++){
			if(!vis[filhos[v][i]]){
				dffs(filhos[v][i],mn);
			}
		}
		return;
	}

	for(int i = 0;i<filhos[v].size();i++){
		if(!vis[filhos[v][i]]){
			dffs(filhos[v][i],val[v]);
		}
	}


	

}

int main(){

	fastio;
	int n;
	cin >> n;
	for(int i = 2;i<=n;i++){
		cin >> pai[i];
	}

	frr(i,n) cin >> val[i];

	for(int i = 2;i<=n;i++){
		filhos[pai[i]].pb(i);
	}


	bool ok = dfs(1,1);
	if(!ok){
		cout << -1 << endl;
		return 0;
	}

	ms(vis,0);

	dffs(1,0ll);
	cout << ans << endl;

}
