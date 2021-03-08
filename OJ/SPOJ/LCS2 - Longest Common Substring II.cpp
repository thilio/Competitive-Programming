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
char S[11][100100];

struct node{
	int l,r, si;
	int p, suf;
	int f[40];
	node(): l(0), r(-1) {}
	//node(int L, int R, int P, int S): l(L), r(R), p(P), si(S) {}
	inline int len() {return r -l + 1;}
	inline char operator[](int i){return S[si][i + l];}
};

vector<node> t;
inline int new_node(int L, int R, int P, int S){
	t[en].l = L; t[en].r = R;
	t[en].si = S; t[en].p = P;
	return en++;	
}

void build(int k, int n){
	//dbg(n);
	char* s = S[k]; 
	int i,cn,cd;
	i = cn = cd = 0;
	for(int j = 0; j < n; j++){
		for(; i<= j; i++){
			//cout << 0 << endl;
			if(cd == t[cn].len() && t[cn].f[s[j] - 'W'] != 0){
				cn = t[cn].f[s[j] - 'W'];
				cd = 0;
			}
			//cout << 1 << endl;
			if(cd < t[cn].len() && t[cn][cd] == s[j]){
				cd++;
				break;
			}
			//cout << 2 << endl;
			if(cd == t[cn].len()){
				t[cn].f[s[j] - 'W'] = new_node(j, n - 1, cn, k);
				if(cn){
					cn = t[cn].suf;
					cd = t[cn].len();
				}
			}
			else{
				
				int mid = new_node(t[cn].l, t[cn].l + cd - 1, t[cn].p, t[cn].si);
				t[t[mid].p].f[t[mid][0] - 'W'] = mid;
				t[mid].f[s[j] - 'W'] = new_node(j, n -1, mid, k);
				t[mid].f[t[cn][cd] - 'W'] = cn;
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
				while(g < j && g + t[t[cn].f[s[g] - 'W']].len() <= j){
					cn = t[cn].f[s[g] - 'W'];
					g += t[cn].len();  
				}


				if(g == j){
					t[mid].suf = cn;
					cd = t[cn].len();
					ns = 0; 
				}
				else{
					ns = mid;
					cn = t[cn].f[s[g] - 'W'];
					cd = j - g;
				}

			}
		}
	}
}

ll ans = 0;
int ct = 0;
int full;

ll dfs(int cn, int d){

	ll mask = 0;

	fr(i, 40){
		if(t[cn].f[i] != 0){
			mask |= dfs(t[cn].f[i], d + t[cn].len());
		}
	}

	if(mask == 0){
		int cd = t[cn].len() - 1;
		int tipo = t[cn][cd] - 'W';
		mask = (1ll << tipo);
	}

	if(mask == full){
		ans = max(ans, (ll)d + t[cn].len());
	}

	return mask;
}

int main(){
	
	ct = 0;
	int j;
	t.resize(2000200);
	while(scanf("%s", S[ct]) != EOF){
		
		for(j = 0; S[ct][j]; j++);
		//for(int k = 0; k < j; k++) cout << S[ct][k];
		//	gnl;

		S[ct][j] = 'W' + ct;
		build(ct, j + 1);
		ct++;
	}

	full = (1 << ct) - 1;

	if(ct == 1){
		int sz = j;
		printf("%d \n",sz);
		return 0;
	}

	ll x = dfs(0, 0);

	printf("%lld\n", ans);




}
