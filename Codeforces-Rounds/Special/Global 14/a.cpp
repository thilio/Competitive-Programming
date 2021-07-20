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

vector<pii> v;
int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		int n, x;
		int sum = 0;
		cin >> n >> x;
		v.clear();
		fr(i, n){
			int y;
			cin >> y;
			sum += y;
			v.pb(mp(y, i + 1));
		}
		if(sum == x){
			cout << "NO" << endl;
			continue;
		}
		sum = 0;
		sort(all(v));
		fr(i, n - 1){
			sum += v[i].fst;
			if(sum == x){
				swap(v[i], v[n - 1]);
				break;
			}
		}
		cout << "YES" << endl;
		for(auto x: v) cout << x.fst << ' ';
		gnl;
	}
}
