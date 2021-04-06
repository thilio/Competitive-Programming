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

const int MAXN = 100100; 

int en;
ll pre[MAXN];
vector<int> topo;
string T;

int p[MAXN], o[MAXN], lf[MAXN], lo[MAXN];

struct trie{
	int cnt, wrd; 
	char c;
	map<char, int> m;
	trie(){
		cnt = wrd = 0;
		m.clear();
	}
	
}t[MAXN];

int new_node(int P, char C){
	t[en] = trie();
	t[en].c = C;

	p[en] = P;
	o[en] = lf[en] = lo[en] = 0;

	return en++;
}

void init(){
	topo.clear();
	en = 0;
	new_node(0, 0);
}

void add(int node, string &s, int i){ // add string to trie
	t[node].cnt++;
	if(i == s.size()){
		t[node].wrd++;
		return;
	}
	if(!t[node].m.count(s[i])){
		t[node].m[s[i]] = new_node(node, s[i]);
	}
	add(t[node].m[s[i]], s, i + 1);
}

void auxlink(int v){
	lf[v] = lf[p[v]];
	while(lf[v] != 0 && !t[lf[v]].m.count(t[v].c)){
		lf[v] = lf[lf[v]];
	}
	if(t[lf[v]].m.count(t[v].c)){
		lf[v] = t[lf[v]].m[t[v].c];
	}
	if(t[lf[v]].wrd > 0) lo[v] = lf[v];
	else lo[v] = lo[lf[v]]; 
}

void build(){
	queue<int> q;

	for(auto x: t[0].m){
		q.push(x.second);
		lf[x.second] = 0;
		lo[x.second] = 0;
	}

	while(!q.empty()){
		int u = q.front();
		topo.push_back(u);
		q.pop();
		for(auto x: t[u].m){
			auxlink(x.second);
			q.push(x.second);
		}
	}
}

ll dp[1010][1010];

ll cont_oc(int u, int i){
	if(i == T.size()){
		return 0;
	}

	ll &pdm = dp[u][i];
	if(pdm != -1) return pdm;

	if(T[i] != '?'){
		while(u != 0 && !t[u].m.count(T[i])){
			u = lf[u];
		}
		if(t[u].m.count(T[i])) u = t[u].m[T[i]];
		pdm = pre[u] + cont_oc(u, i + 1);
	}
	else{
		pdm = 0;
		fr(j, 26){
			int x = u;
			while(x != 0 && !t[x].m.count('a' + j)){
				x = lf[x];
			}
			if(t[x].m.count('a' + j)) x = t[x].m['a' + j];
			pdm = max(pdm, pre[x] + cont_oc(x, i + 1));
			
		}
	}
	return pdm;
}

void recop(int u, int i){
	if(i == T.size()) return;

	if(T[i] != '?'){
		while(u != 0 && !t[u].m.count(T[i])){
			u = lf[u];
		}
		if(t[u].m.count(T[i])) u = t[u].m[T[i]];
		recop(u, i + 1);	
	}
	else{
		fr(j, 26){
			int x = u;
			while(x != 0 && !t[x].m.count('a' + j)){
				x = lf[x];
			}
			if(t[x].m.count('a' + j)) x = t[x].m['a' + j];
			if(T[i] == '?' && pre[x] + cont_oc(x, i + 1) == cont_oc(u, i)){
				T[i] = 'a' + j;
				recop(x, i + 1);
			}
		}
	}
}

int main(){

	fastio;
	int tt;
	cin >> tt;

	while(tt--){
		init();
		int n, m;
		cin >> n >> m;
		cin >> T;

		fr(i, m){
			string s;
			cin >> s;
			add(0, s, 0);
		}
		
		build();
	//	dbg(en);
		fr(i, en){
			pre[i] = 0;
			if(t[i].wrd > 0) pre[i]+= t[i].wrd;

			int x = lo[i];
			while(x != 0){
				pre[i] += t[x].wrd;
				x = lo[x];
			}
		}


		fr(i, 1010) fr(j, 1010) dp[i][j] = -1;


		ll x = cont_oc(0, 0);
		recop(0, 0);
		cout << x << endl;
		cout << T << endl;
	}

}
