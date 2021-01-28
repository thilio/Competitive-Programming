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

int mark[1000020];
vi primo;
int main(){

	fastio;
	int T;
	cin >> T;

	int lim = 1000000;

	for(int i = 2; i <= lim; i++){
		if(mark[i] == 0){
			primo.pb(i);
			for(int j = i; j <= lim; j+= i){
				mark[j] = 1;
			}
		}
	}

	while(T--){
		int d;
		cin >> d;
		auto it = lower_bound(all(primo), d + 1);
		int k = *it;

		it = lower_bound(all(primo), k + d);
		int s = *it;

		cout << k*s << endl;
	}

}
