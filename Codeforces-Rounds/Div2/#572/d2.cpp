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
vi adj[100100];
tuple<int,int,int> edges[1010];
vector<tuple<int,int,int>> ans;

int find_leave(int pai,int eu){
	if(adj[eu].size() == 1) return (eu);
	if(adj[eu][0] == pai) return find_leave(eu,adj[eu][1]);
	return find_leave(eu,adj[eu][0]);
}

bool dfs(int pai,int v,int p){
	if(v == p) return true;
	bool ok = false;
	fr(i,adj[v].size()){
		if(adj[v][i] == pai) continue;
		ok = ok | dfs(v,adj[v][i],p);
	}

	return ok;
}

void add_to_leave(int v,int leave,int val){
	int l1 = -1,l2 = -1;
	fr(i,adj[v].size()){
		if(dfs(v,adj[v][i],leave) == false){
			if(l1 == -1){
				l1 = find_leave(v,adj[v][i]);
			}
			else{
				l2 = find_leave(v,adj[v][i]);
				break;
			}
		}
	}

	ans.pb(make_tuple(leave,l1,val/2));
	ans.pb(make_tuple(leave,l2,val/2));
	ans.pb(make_tuple(l2,l1,-val/2));
}

bool is_leave(int v){
	return(adj[v].size() == 1);
}

int main(){

	fastio;

	int n;
	cin >> n;
	fr(i,n-1){
		int u,v,val;
		cin >> u >> v>> val;
		adj[u].pb(v);
		adj[v].pb(u);
		edges[i] = make_tuple(u,v,val);
	}

	bool ok = true;

	frr(i,n){
		if(adj[i].size()== 2){
			ok = false;
		}
	}

	if (ok) cout << "YES\n";

	else{
		cout << "NO\n";
		return 0;
	}

	if(n == 2){
		cout << "1\n";
		cout << "1 2 " << get<2>(edges[0])<< endl;
		return 0;
	}

	fr(i,n-1){
		tuple<int,int,int> aux = edges[i];
		int u = get<0>(aux);
		int v = get<1>(aux);
		int val = get<2>(aux);

		if (is_leave(u)){
			add_to_leave(v,u,val);
			continue;
		}

		if(is_leave(v)){
			add_to_leave(u,v,val);
			continue;
		}

		int s = find_leave(u,v);
		add_to_leave(u,s,val);
		add_to_leave(v,s,-val);
	}

	cout << ans.size() << endl;
	fr(i,ans.size()){
		cout << get<0>(ans[i]) << ' ' << get<1>(ans[i]) << ' ' << get<2>(ans[i]) << endl; 
	}

}
