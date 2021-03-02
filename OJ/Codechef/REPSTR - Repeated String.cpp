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

const int N = 200200;
string s;
int n;
int en = 1;
int ns;

int l,r;
int ans, sz;

struct node{
	int l,r;
	int p, suf;
	map<char,int> f;
	node(): l(0), r(-1) {}
	node(int L, int R, int P): l(L), r(R), p(P) {}
	inline int len() {return r -l + 1;}
	inline char operator[](int i){return s[i + l];}
}t[N];

inline int new_node(int L, int R, int P){
	t[en] = node(L, R, P);
	t[en].f.clear();
	return en++;
}

void build(){
	s.push_back('$');
	n = s.size();
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
				t[cn].f[s[j]] = new_node(j, n - 1, cn);
				if(cn){
					cn = t[cn].suf;
					cd = t[cn].len();
				}
			}
			else{
				int mid = new_node(t[cn].l, t[cn].l + cd - 1, t[cn].p);
				t[t[mid].p].f[t[mid][0]] = mid;
				t[mid].f[s[j]] = new_node(j, n -1, mid);
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

int dfs(int cn, int d){
	ll son = 0;
	for(auto x: t[cn].f){
		son += dfs(x.snd, d + t[cn].len());
	}

	if(t[cn].r == n - 1) son++;

	if(d + t[cn].len() >= l){
		if(son > ans){
			ans = son;
			sz = min(r, d + t[cn].len());
		}
		else if(son == ans){
			if(sz < min(r, d + t[cn].len())) sz = min(r,d + t[cn].len());
		}
	}
	return son;
}


int main(){

	fastio;

	cin >> l >> r;
	while(l != 0 || r != 0){
		cin >> s;
		en = 1;
		t[0].f.clear();
		build();
		ans = 0;
		sz = 0;

		int x = dfs(0,0);
		//dbg(x);

		cout << ans << ' ' << sz << endl;
		cin >> l >> r;
	}	


}
