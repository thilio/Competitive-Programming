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

const int N = 100100;
string S;
int n;
int cn,cd;
int en = 1;

struct node{
	int l,r;
	int p;
	map<char,int> f;
	node(): l(0), r(-1) {}
	node(int L, int R, int P): l(L), r(R), p(P) {}
	inline int len() {return r -l + 1;}
	inline char operator[](int i){return S[i + l];}
}t[N];

inline int new_node(int L, int R, int P){
	t[en] = node(L, R, P);
	return en++;
}

void build(){
	S.push_back('$');
	n = S.size();
	for(int i = 0; i < S.size(); i++){
		cn = cd = 0;
		for(int j = i; j < S.size(); j++){
			if(cd == t[cn].len() && !t[cn].f.count(S[j]) ){
				t[cn].f[S[j]] = new_node(j, n - 1, cn);
				break;
			}
			if(cd < t[cn].len() && t[cn][cd] != S[j]){
				int mid = new_node(t[cn].l, t[cn].l + cd - 1, t[cn].p);
				t[mid].f[S[j]] = new_node(j, n - 1, mid);
				t[mid].f[t[cn][cd]] = cn;
				t[cn].l += cd;
				t[cn].p = mid;
				t[t[mid].p].f[t[mid][0]] = mid;
				break;
			}
			if(cd == t[cn].len()){
				cn = t[cn].f[S[j]];
				cd = 0;
			}
			cd++;
		}
	}
}

int dfs(int v){
	int ans = 0;
	for(auto &x : t[v].f) ans += dfs(x.snd);

	return ans + t[v].len();
}

int main(){

	fastio;
	cin >> S;
	build();
	cout << dfs(0) - n << endl;

}
