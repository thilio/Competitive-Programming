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

int sum[200][200];

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;

		frr(i, n){
			string s;
			cin >> s;
			frr(j, m){
				grid[i][j] = s[j - 1] - '0';
			}
		}

		bool ok = true;

		frr(i, n){
			frr(j, m){
				int sum = 0;
				sum = grid[i][j] + grid[i - 1][j] + grid[i][j - 1]+ grid[i - 1][j - 1];
				if(sum == 3){
					ok = false;
				}
			}
		}

		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}
