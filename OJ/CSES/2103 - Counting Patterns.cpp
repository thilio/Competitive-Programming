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
const int MAXN = 500100;

string s[MAXN];

int en;
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

void cont_oc(){
	int u = 0;
	for(int i = 0; i < T.size(); i++){
		while(u != 0 && !t[u].m.count(T[i])){
			u = lf[u];
		}
		if(t[u].m.count(T[i])) u = t[u].m[T[i]];
		o[u]++;
	}

	for(int i = topo.size() - 1; i >= 0; i--){
		o[lf[topo[i]]] += o[topo[i]];
	}
}

int find(int node, string &s, int i){
	if(i == s.size()){
		return o[node];
	}
	if(!t[node].m.count(s[i])) return false;
	return find(t[node].m[s[i]], s, i + 1);
}

int main(){

	fastio;

	init();

	cin >> T;
	int n;
	cin >> n;
	

	fr(i,n){
		cin >> s[i];
		add(0, s[i] , 0);
	}

	build();
	cont_oc();

	fr(i,n){
		cout << find(0, s[i], 0) << endl;
	}


}