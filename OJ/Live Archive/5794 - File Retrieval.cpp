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

const int N = 2000000;
int en = 1;
int ns;
string S[60];
map<string, bool> ja;
map<ll, bool> mask_f;

struct node{
	int l,r, si;
	int p, suf;
	map<char,int> f;
	node(): l(0), r(-1) {}
	node(int L, int R, int P, int S): l(L), r(R), p(P), si(S) {}
	inline int len() {return r -l + 1;}
	inline char operator[](int i){return S[si][i + l];}
}t[N];

inline int new_node(int L, int R, int P, int S){
	t[en] = node(L, R, P, S);
	t[en].f.clear();
	return en++;
}

void build(string &s, int k){
	s.push_back('!' + k);
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

ll ans;

void clear(){
	en = 1;
	t[0].f.clear();
	ja.clear();
	mask_f.clear();
}

ll dfs(int cn){
	ll mask = 0;
	for(auto x: t[cn].f){
		mask |= dfs(x.snd);
	}
	if(mask == 0){
		ll tipo = (int)(t[cn][t[cn].len() - 1] - '!');
		mask = (1ll << tipo);
	}

	if(cn != 0) mask_f[mask] = true;
	return mask;
}

int dfs_f(int cn, string &s, int p){
	if(p + t[cn].len() == s.size()){
		if(t[cn].len() > 1) return 1;
		return 0;
	}

	return dfs_f(t[cn].f[s[p + t[cn].len()]], s, p + t[cn].len());
}

int main(){

	fastio;
	int n;
	cin >> n;
	while(n != 0){
		clear();
		int ct = 0;
		fr(i,n){
			string s;
			cin >> s;
			if(!ja[s]){
				ja[s] = true;
				build(s,ct);
				ct++;
			}
		}
		
		n = ct;
		ans = 0;
		ll x = dfs(0);
		//dbg(t[23].len());
		//for(auto x: t[6].f) dbg(x.snd);

		fr(i,n){
			ans += dfs_f(0, S[i], 0);
			//if(dfs_f(0, S[i], 0)) dbg(i);
		}

		//dbg(ans);
		
		for(auto x: mask_f) if( __builtin_popcountll(x.fst) > 1) ans++;

		cout << ans << endl;
		cin >> n;
	}


}
