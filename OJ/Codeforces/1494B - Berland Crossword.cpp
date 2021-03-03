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


bool tent(int mask, int n,int u,int r , int d, int l){
	if(mask&1){
		u--;
		l--;
	}
	if(mask&2){
		u--;
		r--;
	}
	if(mask&4){
		r--;
		d--;
	}
	if(mask&8){
		d--;
		l--;
	}

	if(u < 0 || r < 0 || d < 0 || l < 0) return false;
	if(u <= n -2 && r <= n -2 && d <= n -2 && l <= n - 2) return true;
	return false;
}


int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		int n,u,r,d,l;
		cin >> n >> u >> r >> d >> l;
		bool ok = false;
		fr(i,16){
			ok |= tent(i, n , u ,r ,d, l);
		}

		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}		

}
