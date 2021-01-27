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
int n,k;
int v[300];

int f(int l,int r){
	vi t,aux;

	fr(i,n){
		if(i >= l && i <= r) t.pb(v[i]);
		else aux.pb(v[i]);
	}


	sort(all(t));
	sort(all(aux));



	fr(i,k){
		if(i >= aux.size() || i >= t.size()) break;
		t[i] = max(t[i],aux[aux.size() - 1 - i]);
	}

	int sum = 0;

	fr(i,t.size()) sum += t[i];

	return sum; 
}

int main(){

	fastio;
	cin >> n >> k;
	fr(i,n) cin >> v[i];

	int ans = -INF;

	fr(i,n){
		for(int j = i; j < n; j++){
			ans = max(ans,f(i,j));
		}
	}

	cout << ans << endl;

}
