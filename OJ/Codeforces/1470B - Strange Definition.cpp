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

ll ans;
int prime[1000100];
int rep[1001000];

int v[1000100];

void pre(){
	for(int i = 2; i <= 1000000; i++){
		if(prime[i] == 0){
			ans++;
			for(int j = i; j <= 1000000; j+= i) if(prime[j] == 0) prime[j] = i;
		}
	}
}

int main(){

	fastio;

	pre();
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;

		frr(i,n){
			int x;
			cin >> x;

			int aa = 1;

			while(x != 1){
				int k = prime[x];
				int ct = 0;
				while(x%k == 0){
					x /= k;
					ct++;
				}
				if(ct % 2) aa *= k;
			} 

			rep[i] = aa;
			//dbg(aa);
		}

		frr(i,n){
			v[rep[i]] = 0;
		}
		v[1] = 0;
		frr(i,n){
			v[rep[i]]++;
		}

		int ans0 = 0;

		frr(i,n){
			ans0 = max(ans0, v[rep[i]]);
		}

		frr(i,n){
			if(v[rep[i]]%2 == 0 && rep[i] != 1){
				v[1] += v[rep[i]];
				v[rep[i]] = 0;
			}
			
		}
//		dbg(v[1].size());

		int ans1 = v[1];
//		dbg(ans1);
		frr(i,n){
			ans1 = max(ans1, v[rep[i]]);
		}

		int q;
		cin >> q;
		fr(i,q){
			ll w;
			cin >> w;
			if(w == 0) cout << ans0 << endl;
			else cout << ans1 << endl;
		}
	}

	

}
