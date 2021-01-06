//Only works for 1 test set

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

int dist(int x,int y){
	return abs(x) + abs(y);
}
int main(){

	fastio;

	int T;
	cin >> T;
	int g = 1;
	while(T--){
		ll n,d;
		cin >> n >> d;
		vector<ll> v;
		v.clear();
		set<ll> s;
		s.clear();
		fr(i,n){
			ll x;
			cin >> x;
			v.pb(x);
			s.insert(x);
		}

		sort(all(v));
		int ans = -1;
		if(d == 2){

			ans = 1;

			fr(i,v.size() - 1){
				if(v[i] == v[i+1])
					ans = 0;
			}

		}
		if(d == 3){

			ans = 2;
			for(int i = 2; i < v.size();i++){
				if(v[i] == v[i-1] && v[i-1] == v[i-2])
					ans = 0;
			}

			fr(i,v.size()){
				if(s.find(2*v[i]) != s.end())
					ans = min(ans,1);
			}

			for(int i = 1; i < v.size();i++){
				if(v[i] == v[i-1] && v[i] < v[v.size() - 1])
					ans = min(ans,1);
			}


		}

		cout << "Case #" << g++ << ": ";

		if(ans == -1) cout << "IMPOSSIBLE";
		else cout << ans;

		gnl;



		
	}

}
