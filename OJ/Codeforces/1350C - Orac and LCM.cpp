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

int pri[200100];

vector<long long> decom[200100];
int n;

void pr(){

	pri[1] = 1;
	for(int i =2; i <= 200000; i++){
		if(pri[i] == 0){
			pri[i] = i;
			for(int j = i; j <= 200000; j+=i){
				if(pri[j] == 0) pri[j] = i;
			}
		}
	}

}

int main(){

	fastio;

	
	cin >> n;
	pr();



	fr(i,n){
		int x;
		cin >> x;
		while(x != 1){
			int k = pri[x];
			int ct = 0;
			while(x%k == 0){
				x/=k;
				ct++;
			}

			decom[k].pb(ct);
		}
	}

	ll ans = 1;

	frr(k,200000){
		if(decom[k].size() <= n - 2) continue;

		sort(all(decom[k]));

		if(decom[k].size() == n-1){
			int x = decom[k][0];
			//dbg(x);
			while(x--){
				//olar;
				ans *= k;
			}
		}
		else{
			int x = decom[k][1];
			while(x--){
				ans *= k;
			}

		}
	}

	cout << ans << endl;



}
