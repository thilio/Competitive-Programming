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

const int N = 2000200;
int en = 1;
int ns;
vector<ll> S[100100];

ll ans[100100];
map<int, ll> m[400100];
int k;

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

void dfs(int cn){
	int folha = 0;
	for(auto x: t[cn].f){
		dfs(x.snd);
		if(m[x.snd].size() > m[cn].size()) m[x.snd].swap(m[cn]);
		for(auto x: m[x.snd]) m[cn][x.fst] += x.snd;
		m[x.snd].clear();
	}
	if(t[cn].f.empty()){
		folha = 1;
		int cd = t[cn].len() - 1;
		int tipo = t[cn][cd] - 26;
		m[cn][tipo]++;
	}
	if(m[cn].size() >= k){
		for(auto x: m[cn]){
			ans[x.fst] += x.snd*(t[cn].len()- folha);
		}

	}

}

int main(){

	fastio;

	int n;
	cin >> n >> k;	
	
	fr(i,n){
		string t;
		cin >> t;
		vector<ll> v;
		v.clear();

		for(auto x: t) v.pb(x - 'a');

		build(v, i); 
	}			

	dfs(0);
	
	fr(i,n) cout << ans[i] << ' ';
	gnl;

}
