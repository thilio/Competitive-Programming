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
int v[5050];

int main(){

	fastio;

	cin >> n >> m;

	int tot = 0;
	int j = 0;

	frr(i, n){
		j = i;
		tot += (i - 1)/2;
		if(tot > m) break;
		v[i] = i; 
	}

	if(tot < m){
		cout << -1 << endl;
		return 0;
	}

	tot -= (j - 1)/2;

	v[j] = 2*(j - 1) + 1 - 2*(m - tot);

	for(int i = j + 1; i <= n; i++){
		v[i] = 10000000 + i*10000 + 1;
	}

	frr(i, n) cout << v[i] << ' ';
	gnl;

}
