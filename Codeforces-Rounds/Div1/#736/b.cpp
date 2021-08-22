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

ll v[400200];
ll lg[400200];

ll st[400200][20];
int n;

void build(){
	for(int i = 0; i < n; i++) st[i][0] = v[i];

	for(int j = 1; j <= 20; j++){
		for(int i = 0; i + (1ll << j) <= n; i++){
			st[i][j] = __gcd(st[i][j - 1], st[i + (1ll << (j - 1))][j - 1]);
		}
	}
}

bool query(int a, int b){
	int j = lg[b - a + 1];
	ll g = __gcd(st[a][j], st[b - (1 << j) + 1][j]);
	if(g > 1 || g == 0) return true;
	else return false;
}

int tent(int j){
	int l = j;
	int r = n - 1;
	int best = -1;

	while(l <= r){
		int m = (l + r)/2;
		if(query(j, m)){
			best = m;
			l = m + 1;
		}
		else{
			r = m - 1;
		}
	}

	if(best == -1) return -1;

	return best - j + 1;

}

int bb(){
	int mx = 1;
	for(int i = 0; i < n; i++){
		mx = max(tent(i) + 1, mx);
	}
	return mx;
}


int main(){

	fastio;

	int T;
	cin >> T;

	lg[1] = 0;
	for(int i = 2; i <= 200000; i++){
		lg[i] = lg[i/2] + 1;
	}

	while(T--){
		
		cin >> n;
		fr(i, n) cin >> v[i];

		if(n == 1){
			cout << 1 << '\n';
			continue;
		}

		n--;

		fr(i, n){
			v[i] = abs(v[i + 1] - v[i]);
		}

		build();

		cout << bb() << '\n';
	}

}
