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

ll n,m,k;
ll v[200200];

int main(){

	fastio;

	cin >> n >> m >> k;
	frr(i,n) cin >> v[i];
	ll t[200200];

	frr(i,n) t[i] = v[i];

	sort(t+1,t+n+1);
	map<ll,ll> best;
	int aux = m*k;

	ll sum = 0;
	//dbg(aux);
	//dbg(t[1]);
	fr(i,aux){
		best[t[n-i]]++;
		sum += t[n-i];
	}

	vi ans;

	cout << sum << endl; 

	frr(i,n){
		int a= 0;
		while(a < m && i <= n){
			if(best[v[i]] > 0){
				best[v[i]]--;
				a++;
			}
			i++;
		}
		i--;
		ans.pb(i);
		 
	}

	fr(i,k-1) cout << ans[i]<<' ';
	gnl;

}
