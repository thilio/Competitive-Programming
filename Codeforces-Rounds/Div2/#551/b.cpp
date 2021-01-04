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
int n,m,h;
int ans[110][110];
int v1[110] , v2[110];

int main(){

	fastio;
	cin >> n >> m >> h;

	fr(i,m){
		cin >> v1[i];
	}

	fr(j,n) cin >> v2[j];

	fr(i,n){
		fr(j,m){
			cin >> ans[i][j];
		}
	}


	fr(i,n){
		fr(j,m){
			if(ans[i][j] == 0) continue;
			ans[i][j] = min(v1[j],v2[i]);
		}
	}

	fr(i,n){
		fr(j,m){
			cout << ans[i][j] << ' ';
		}
		gnl;
	}



}
