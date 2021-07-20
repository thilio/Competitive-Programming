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

int ans[100100];

int main(){

	fastio;

	int T;
	cin >> T;
	vii v;

	while(T--){
		int n, m, x;
		cin >> n >> m >> x;
		v.clear();
		fr(i,n){
			int x;
			cin >> x;
			v.pb({x, i + 1});
		}
		sort(all(v));
		reverse(all(v));

		priority_queue<pii, vii, greater<pii>> pq;
		fr(i, m) pq.push({0, i + 1});

		for(auto x: v){
			pii y = pq.top();
			pq.pop();
			y.fst += x.fst;
			ans[x.snd] = y.snd;
			pq.push(y);
		}
		int mn = INF;
		int mx = 0;
		while(!pq.empty()){
			pii y = pq.top();
			pq.pop();
			mn = min(mn, y.fst);
			mx = max(mx, y.fst);
		}

		if(mx - mn > x) cout << "NO" << endl;
		else{
			cout << "YES" << endl;
			frr(i, n) cout << ans[i] << ' ';
			gnl;
		}
	}

}
