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

map<string,int> m;
map<int,string> mr;

vi adj[1000];
int dist[1000];
int vis[1000];

void bfs(int v){
	queue<int> q;
	q.push(v);
	dist[v] = 0;
	vis[v] = 1;
	while(!q.empty()){
		int s = q.front();
		q.pop();

		fr(i,adj[s].size()){
			if(vis[adj[s][i]] == 0){
				vis[adj[s][i]] = 1;
				dist[adj[s][i]] = dist[s] + 1;
				q.push(adj[s][i]);
			}
		}

	}
}


int main(){

	fastio;
	int n;
	cin >> n;
	string s;
	string t;
	string r;
	getline(cin,s);
	vector<string> v;

	int ct = 1;
	int root = -1;

	//dbg(n);

	fr(i,n){
		cin >> s >> r >> t;
		if(m[s] == 0){
			m[s] = ct;
			v.pb(s);
			if(s == "Isenbaev") root = ct;
			ct++;
		}
		if(m[r] == 0){
			m[r] = ct;
			v.pb(r);
			if(r == "Isenbaev") root = ct;
			ct++;
		}
		if(m[t] == 0){
			m[t] = ct;
			v.pb(t);
			if(t == "Isenbaev") root = ct;
			ct++;
		}

		adj[m[t]].pb(m[r]);
		adj[m[t]].pb(m[s]);
		adj[m[r]].pb(m[s]);
		adj[m[r]].pb(m[t]);
		adj[m[s]].pb(m[t]);
		adj[m[s]].pb(m[r]);

	}


	fr(i,1000) dist[i] = 1000;

	sort(all(v));

	if(root == -1){
		fr(i,v.size()){
			cout << v[i] << " undefined\n";
		}
		return 0;
	}

	bfs(root);

	fr(i,v.size()){
		cout << v[i] << ' ';
		if(dist[m[v[i]]] == 1000) cout << "undefined\n";
		else cout << dist[m[v[i]]] << endl;
	}



}
