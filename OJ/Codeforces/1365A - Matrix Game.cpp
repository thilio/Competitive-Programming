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
int grid[110][110];

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		int n,m;
		cin >> n >> m;

		fr(i,n){
			fr(j,m){
				cin >> grid[i][j];
			}
		}

		int lin = 0;
		int col = 0;

		fr(i,n){
			bool ok = false;
			fr(j,m) if(grid[i][j]) ok =true;
			if(ok == false) lin++;
		}

		fr(j,m){
			bool ok = false;
			fr(i,n) if(grid[i][j]) ok = true;
			if(ok == false) col++;
		}

		int mn = min(lin,col);

		if(mn%2) cout << "Ashish" << endl;
		else cout << "Vivek" << endl;


	}

}
