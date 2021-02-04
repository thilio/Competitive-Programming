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

int sz[600600];
int id[600600];

int find(int i){
	if(i == id[i]) return i;
	return id[i] = find(id[i]);
}

void merge(int u,int v){
	
	u = find(u);
	v = find(v);
	if(u == v) return;
	if(sz[u] > sz[v]) swap(u,v);
	id[u] = v;
	sz[v] += sz[u];
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		n++;

		frr(i,2*n){
			id[i] = i;
			sz[i] = 1; 
		}

		string s;
		getline(cin,s);
		getline(cin,s);

		for(int i = 1; i <= n - 1; i++){
			if(s[i - 1] == 'R') merge(i , i + n + 1);
			if(s[i - 1] == 'L') merge(i + 1, i + n);
		}

		frr(i,n) cout << sz[find(i)] << ' ';
		gnl;
	}

}
