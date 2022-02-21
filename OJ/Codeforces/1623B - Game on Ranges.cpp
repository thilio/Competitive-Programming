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

vector<int> com[1010], fim[1010];
int n;
vector<array<int, 3>> ans;

void reset(){
	frr(i, n){
		com[i].clear();
		fim[i].clear();
	}
	ans.clear();
}

void solve(int l, int r){
	if(l > r) return;
	int mx = -1;
	int mn = n + 1; 

	for(auto x: com[l]){
		if(x < r) mx = max(mx, x);
	}
	for(auto x: fim[r]){
		if(x > l) mn = min(mn, x);
	}

	//dbg(mx); dbg(mn);

	if(mx == -1){
		ans.pb({l, r, l});
		solve(l + 1, r);
	}
	else if(mn == n + 1){
		ans.pb({l, r, r});
		solve(l, r - 1);
	}
	else{
		assert(mx + 2 == mn);
		ans.pb({l, r, mx + 1});
		solve(l, mx); solve(mn, r);
	}
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n;
		reset();

		frr(i, n){
			int l, r;
			cin >> l >> r;
			com[l].pb(r);
			fim[r].pb(l);
		}

	

		solve(1, n);

		for(auto x: ans){
			cout << x[0] << ' ' << x[1] << ' ' << x[2] << endl;
		}
	}

}
