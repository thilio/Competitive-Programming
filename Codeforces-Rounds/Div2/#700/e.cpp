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

vector<pll> adj[50];
ll mn[50];
ll mx[50];
ll sz[50];

int main(){

	fastio;

	int l,r;
	cin >> l >> r;
	int delta = r - l;

	if(delta == 0){
		cout << "YES" << endl;
		cout << 2 << ' ' << 1<< endl;
		cout << 1 << ' ' << 2 << ' ' << l << endl;
		return 0;
	}

	ll mxat = 0;
	ll vtx = 31;
	frr(i,32){
		mx[i] = -1;
		mn[i] = llINF;
	}
	sz[32] = 1;
	mn[32] = 0;
	mx[32] = 0;
	while(mxat < delta){
		for(int i = 1; vtx + i <= 32; i++){
			if(sz[vtx + i] <= delta - mxat){
				adj[vtx].pb(mp(vtx + i, mxat + 1 - mn[vtx + i]));
				mn[vtx] = min(mn[vtx], mxat + 1);
				mxat += sz[vtx + i];
				mx[vtx] = max(mx[vtx], mxat);
			}
		}
		sz[vtx] = mx[vtx] - mn[vtx] + 1;
		vtx--;
	}

	int grau = 0;
	for(int i = 2; i <= 32; i++) adj[1].pb(mp(i,l));

	frr(i,32) grau += adj[i].size();

	cout << "YES" << endl;
	cout << 32 << ' ' << grau << endl;

	frr(i,32){
		for(auto x: adj[i]){
			cout << i << ' ' << x.fst << ' ' << x.snd << endl;
		}
	}


}
