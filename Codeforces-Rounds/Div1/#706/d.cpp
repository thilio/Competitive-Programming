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
const int MOD =  998244353;

int n, m;

vi adj[500];
int dist[500][500];
ll p[500];
int level[500];

void pre_dist(int v){
	dist[v][v] = 0;
	queue<int> q;

	q.push(v);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto x: adj[u]){
			if(dist[v][x] == -1){
				dist[v][x] = dist[v][u] + 1;
				q.push(x);
			}
		}
	} 
}

ll bfs(int x, int y){
	//gnl;
	//dbg(dist[1][2]);
	//dbg(x);
	//dbg(y);

	ms(p, 0);
	ms(level, -1);
	queue<int> q;
	int v = y;
	
	while(v != x){
		q.push(v);
		p[v] = 1;
		level[v] = 0;
		for(auto k: adj[v]){
			if(dist[x][k] == dist[x][v] - 1){
				v = k;
				break;
			}
		}
	}
	
	q.push(x);
	p[x] = 1;
	level[x] = 0;
	

	while(!q.empty()){
		int at = q.front();
		q.pop();

		for(auto w: adj[at]){
			if(dist[x][w] == dist[x][at] + 1 && dist[y][w] == dist[y][at] + 1){
				p[w]++;
				if(level[w] == -1){
					level[w] = level[at] + 1;
					q.push(w);
				}
			}
		}
	}

	ll ans = 1;

	frr(i,n){
		ans = (ans*p[i])%MOD;
	}
	return ans;
}

int main(){

	fastio;

	cin >> n >> m;

	fr(i,m){
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	ms(dist, -1);
	frr(i,n){
		pre_dist(i);
	}



	frr(i,n){
		frr(j,n){
			cout << bfs(i, j) << ' ';
		}
		gnl;
	}


}
