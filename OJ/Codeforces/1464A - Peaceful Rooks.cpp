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

int coluna[100100];
int adj[100100];
pii v[100100];
bool correct[100100];
bool vis[100100];

int dfs(int v, int i){
	vis[v] = true;
	if(adj[v] == -1) return 1;
	if(adj[v] == i) return 2;
	if(vis[adj[v]]) return 1;
	return 1 + dfs(adj[v], i);
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		int n, m;
		cin >> n >> m;

		frr(i, n) coluna[i] = -1;
		frr(i, n) adj[i] = -1;
		frr(i, n) correct[i] = vis[i] = false;


		frr(i,m){
			int x, y;
			cin >> x >> y;
			v[i] = {x, y};
			coluna[y] = i;
			if(x == y) correct[i] = true;
		}

		frr(i, n){
			if(!correct[i]){
				adj[i] = coluna[v[i].fst];
			}
		}

		int ans = 0;
		//dbg(adj[1]);
		//dbg(adj[2]);
		frr(i, m){
			if(!correct[i] && !vis[i]) ans += dfs(i, i);
		}


		cout << ans << endl;

	}

}
