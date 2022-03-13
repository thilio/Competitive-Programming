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

int grid[200][200];
vector<array<int, 4>> ans;

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		ans.clear();
		cin >> n >> m;

		frr(i, n){
			string s;
			cin >> s;
			frr(j, m){
				grid[i][j] = s[j - 1] - '0';
			}
		}

		if(grid[1][1] == 1){
			cout << -1 << endl;
			continue;
		}

		for(int j = m; j > 0; j--){
			for(int i = n; i > 0; i--){
				if(grid[i][j]){
					if(i > 1){
						ans.pb({i - 1, j, i, j});
					}
					else{
						ans.pb({i, j - 1, i, j});
					}
				}
			}
		}

		cout << ans.size() << endl;

		for(auto x: ans){
			cout << x[0] << ' ' << x[1] << ' ' << x[2] << ' ' << x[3] << endl;
		}
	}

}
