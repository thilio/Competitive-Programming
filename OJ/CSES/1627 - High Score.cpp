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
vector<pair<ll,pair<int,int>>> edge;
int v;
vi adj[100100];
int vis[100100];

void dfs(int v){
	vis[v] = 1;
	for(auto y : adj[v]){
		if(!vis[y]) dfs(y);
	}
}

void Bellman(){
    vector<ll> d (n + 1, -llINF);
    d[v] = 0;
    for (int i = 0; i< n-1; i++){
        for (int j = 0; j < m; j++)
            if (d[edge[j].second.first] > -llINF)
                d[edge[j].second.second] = max(d[edge[j].second.second], d[edge[j].second.first] + edge[j].first);
    }

    vi pos;
    for(int j = 0; j < m; j++){
    	
    	if(d[edge[j].snd.snd] != -llINF && d[edge[j].snd.snd] < d[edge[j].snd.fst] + edge[j].fst) pos.pb(edge[j].snd.snd);
    }

   

    for(auto x: pos) dfs(x);

    if(vis[n]) d[n] = -1;

	cout << d[n] << endl;
    
}

int main(){

	fastio;

	cin >> n >> m;
	edge.resize(m);
	fr(i,m){
		cin >> edge[i].snd.fst >> edge[i].snd.snd >> edge[i].fst;
		adj[edge[i].snd.fst].pb(edge[i].snd.snd);
	}
	v = 1;
	Bellman();

}
