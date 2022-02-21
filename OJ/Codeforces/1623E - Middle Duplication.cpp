#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define endl '\n'
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

int n, k;
char s[200200];
int l[200200];
int r[200200];

bool good[200200];
bool dupli[200200];

vector<int> pre;

void dfsp(int v){
	if(v == 0) return;
	dfsp(l[v]);
	pre.pb(v);
	dfsp(r[v]);
}

void dfs(int v, int cost){
	if(v == 0) return;
	if(cost > k) return;

	dfs(l[v], cost + 1);
	if(dupli[l[v]]){
		dupli[v] = true;
		dfs(r[v], 1);
	}
	else{
		if(good[v]){
			dupli[v] = true;
			k -= cost;
			dfs(r[v], 1);
		}
	}
}

int main(){

	fastio;

	cin >> n >> k;

	frr(i, n) cin >> s[i];

	frr(i, n) cin >> l[i] >> r[i];

	dfsp(1);

	int p = n - 1;
	char at = '$';

	while(p >= 0){
		int q = p;

		while(q >= 0 && s[pre[q]] == s[pre[p]]){
			if(s[pre[q]] < at) good[pre[q]] = true;
			q--;
		}

		at = s[pre[p]];
		p = q;
	}

	//frr(i, n) dbg(good[i]);

	dfs(1, 1);

	fr(i, n){
		cout << s[pre[i]];
		if(dupli[pre[i]]) cout << s[pre[i]];
	}
	gnl;



}
