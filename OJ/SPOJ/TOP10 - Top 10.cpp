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

const int N = 800400;
int en = 1;
int ns;
vector<ll> S[200200];
vector<int> top[400400];
ll ans;

int lex[100100];
int sz[100100];

struct node{
	int l,r, si;
	int p, suf;
	map<ll,int> f;
	node(): l(0), r(-1) {}
	node(int L, int R, int P, int Si): l(L), r(R), p(P), si(Si) {}
	inline int len() {return r - l + 1;}
	inline ll operator[](int i){return S[si][i + l];}
}t[N];

inline int new_node(int L, int R, int P, int S){
	t[en] = node(L, R, P, S);
	t[en].f.clear();
	return en++;
}

void build(vector<ll> &s, int k){
	s.push_back(26 + k);
	S[k] = s;
	int n = s.size();
	int i,cn,cd;
	i = cn = cd = 0;
	for(int j = 0; j < n; j++){
		for(; i<= j; i++){
			if(cd == t[cn].len() && t[cn].f.count(s[j])){
				cn = t[cn].f[s[j]];
				cd = 0;
			}
			if(cd < t[cn].len() && t[cn][cd] == s[j]){
				cd++;
				break;
			}

			if(cd == t[cn].len()){
				t[cn].f[s[j]] = new_node(j, n - 1, cn, k);
				if(cn){
					cn = t[cn].suf;
					cd = t[cn].len();
				}
			}
			else{
				int mid = new_node(t[cn].l, t[cn].l + cd - 1, t[cn].p, t[cn].si);
				t[t[mid].p].f[t[mid][0]] = mid;
				t[mid].f[s[j]] = new_node(j, n -1, mid, k);
				t[mid].f[t[cn][cd]] = cn;
				t[cn].p = mid;
				t[cn].l += cd;

				if(ns) t[ns].suf = mid;

				cn = t[mid].p;
				int g;
				if(cn){
					cn = t[cn].suf;
					g = j - cd;
				}
				else{
					g = i + 1;
				}
				while(g < j && g + t[t[cn].f[s[g]]].len() <= j){
					cn = t[cn].f[s[g]];
					g += t[cn].len();  
				}

				if(g == j){
					t[mid].suf = cn;
					cd = t[cn].len();
					ns = 0; 
				}
				else{
					ns = mid;
					cn = t[cn].f[s[g]];
					cd = j - g;
				}
			}
		}
	}
}

int ct = 1;
bool comp(int i, int j){
	if(sz[i] == sz[j]) return lex[i] < lex[j];
	return sz[i] < sz[j];
}

void dfs_lex(int cn, int p){
	bool any = false;
	for(auto x: t[cn].f){
		any = true;
		dfs_lex(x.snd, p + t[cn].len());
	}

	if(!any){
		int cd = t[cn].len() - 1;
		int tipo = t[cn][cd] - 26;
		if(p + t[cn].len() == sz[tipo]) lex[tipo] = ct++;
	}
}

void merge(int a, int b){
	vi v;
	int i = 0;
	int j = 0;
	while(i < top[a].size() && j < top[b].size()){
		if(top[a][i] == top[b][j]){
			v.pb(top[a][i]);
			i++;
			j++;
		}
		else if(comp(top[a][i], top[b][j])){
			v.pb(top[a][i]);
			i++;
		}
		else{
			v.pb(top[b][j]);
			j++;
		}
	}

	while(i < top[a].size()){
		v.pb(top[a][i]);
		i++;
	}

	while(j < top[b].size()){
		v.pb(top[b][j]);
		j++;
	}

	int szz = v.size();

	while(szz > 10){
		szz--;
		v.pop_back();
	}
	top[a] = v;
}

void dfs_10(int cn){

	bool any = false;
	for(auto x: t[cn].f){
		dfs_10(x.snd);
		merge(cn, x.snd);
		any = true;
	}

	if(!any){
		int cd = t[cn].len() - 1;
		int tipo = t[cn][cd] - 26;
		top[cn].pb(tipo);
	}
}

void print(int a){
	if(top[a].size() == 0){
		cout << -1 << endl;
	}
	else{
		fr(i, top[a].size()){
			cout << top[a][i];
			if(i != top[a].size() - 1) cout << ' ';
		}
		gnl;
	}
}

void find(int cn, vector<ll>& v, int p){
	int cd = 0;

	while(cd < t[cn].len() && p < v.size() && t[cn][cd] == v[p]){
		cd++;
		p++;
	}

	if(p == v.size()){
		print(cn);
	}
	else if(cd == t[cn].len()){
		if(t[cn].f.count(v[p]))
			find(t[cn].f[v[p]], v, p);
		else{
			cout << -1 << endl;
			return;
		}
	}
	else{
		cout << -1 << endl;
		return;
	}

}

int main(){

	fastio;

	int n;
	cin >> n;
	
	frr(i,n){
		string t;
		cin >> t;
		vector<ll> v;
		v.clear();

		for(auto x: t) v.pb(x - 'a');
		build(v, i); 
		sz[i] = v.size();

		//dbg((v.size() > 1000));
	}

	dfs_lex(0, 0);
	dfs_10(0);

	int q;
	cin >> q;
	vector<ll> v;

	fr(i, q){
		string t;
		cin >> t;
		v.clear();

		for(auto x: t) v.pb(x - 'a');
		find(0, v, 0);
	}

}
