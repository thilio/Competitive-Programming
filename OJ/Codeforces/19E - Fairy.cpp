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
vii adj[10010];
pii edges[10010];
int color[10010];
pii acab[10010];
int h[10010];
int ans;

pii dfs(int v,int c,int p){
	//dbg(v);
	//dbg(adj[v].size());
	color[v] = c;

	pii aux;
	pii ret;
	aux = ret = mp(0,0);

	for(int j = 0; j < adj[v].size();j++){
	//	dbg(v);
	//	dbg(j);
		pii x = adj[v][j];
		
		int u = x.fst;
		
		if(u == p){
			continue;
		}
		if(color[u] != -1 && h[u] < h[v]){
			
			if(color[u] == c){
			
				ans++;
				edges[x.snd].snd++;
				acab[u].snd++;
				ret.snd++;
			}
			else{
				edges[x.snd].fst++;
				acab[u].fst++;
				ret.fst++;
			}
		}
		else if (color[u] == -1){
			//olar;
			h[u] = h[v] + 1;
			aux = dfs(u,1-c,v);

			ret.fst += aux.fst;
			ret.snd += aux.snd;

			edges[x.snd] = aux;
		}
	}

	ret.fst -= acab[v].fst;
	ret.snd -= acab[v].snd;

	return ret;
}

int main(){

	fastio;
	cin >> n >> m;
	ms(color,-1);

	frr(i,m){
		int a,b;
		cin >> a >> b;
	
		adj[a].pb(mp(b,i));
		adj[b].pb(mp(a,i));
	}

	frr(i,n){
		if(color[i] == -1){
			h[i] = 0;
			pii x = dfs(i,0,-1);
		}
	}

	if(ans == 0){
		cout << m << endl;
		frr(i,m){
			cout << i << ' ';
		}
		gnl;	
	}
	else{
		vi p;
		p.clear();
		frr(i,m){
			if(edges[i] == mp(0,ans)){
				p.pb(i);
			}
		}

		cout << p.size()<< endl;

		fr(i,p.size()) cout << p[i] << ' ';
		gnl;
	}



}
