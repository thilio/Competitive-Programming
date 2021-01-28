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

int v[1001];

int mn(int i,int j){
	int ans = INF;
	for(int k = i; k <= j; k++){
		ans = min(ans,v[k]);
	}

	return ans;
}

int main(){

	fastio;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	

	frr(i,n) cin >> v[i];

	int r1,c1,r2,c2;

	cin >> r1 >> c1 >> r2 >> c2;

	int dist = INF;

	frr(i,n){
		int tent = abs(i - r1) + abs(i - r2);

		int col,col1,col2;

		int aux = min(i,r1);
		int mmn = min(aux,r2);
		aux = max(i,r1);
		int mmx = max(aux,r2);

		col1 = mn(mmn,mmx) + 1;
		col2 = c1;

		col = min(col1,col2);

		tent += abs(col - c2);

		dist = min(dist,tent);

	}

	cout << dist << endl;

}
