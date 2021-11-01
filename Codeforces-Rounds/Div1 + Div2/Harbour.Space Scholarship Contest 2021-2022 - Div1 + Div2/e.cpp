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

int n, m;
vi ans;
int perm[300300];
int v[300300];
int shift[300300];
int invs[300300];
int vis[300300];

void clear(){
	ans.clear();
	fr(i, n) perm[i] = 0;
}

bool tent(int i){

	for(int j = 1; j <= n; j++){
		vis[j] = 0;
		shift[j] = (j - 1 - i + n)%n + 1;
		invs[shift[j]] = j;
	}

	int ans = 0;

	for(int j = 1; j <= n; j++){
		if(vis[v[j]] == 1) continue;

		int k = v[j];
		int ct = 0;
		do{
			ct++;
			vis[k] = 1;
			k = v[invs[k]];
		}while(k != v[j]	);

		ans += ct - 1;
	}

	if(ans <= m) return true;
	else return false;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;
		clear();

		frr(i, n){
			int k;
			cin >> k;
			v[i] = k;

			if(i == k) perm[0]++;
			if(i > k)  perm[i - k]++;
			if(i < k)  perm[n - k + i]++;
		}

		int c = n - 2*(n/3);

		fr(i, n){
			if(perm[i] >= c){
				if(tent(i)) ans.pb(i);
			}

		}

		cout << ans.size();
		for(auto x: ans) cout << ' ' << x;
		gnl;
	}

}
