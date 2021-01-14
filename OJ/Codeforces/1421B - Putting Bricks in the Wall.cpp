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

char grid[220][220];

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		string s;
		getline(cin,s);
		
		frr(i,n){
			getline(cin,s);
			fr(j,n){
				grid[i][j + 1] = s[j];
			}
		}

		vii ans;
		ans.clear();

		if(grid[1][2] == grid[2][1]){
			if(grid[n][n-1] == grid[1][2]) ans.pb({n,n-1});
			if(grid[n-1][n] == grid[1][2]) ans.pb({n-1,n});
		}
		else if(grid[n][n-1] == grid[n-1][n]){
			if(grid[1][2] == grid[n][n-1]) ans.pb({1,2});
			if(grid[2][1] == grid[n][n-1]) ans.pb({2,1});
		}
		else{
			if(grid[1][2] == '1') ans.pb({1,2});
			if(grid[2][1] == '1') ans.pb({2,1});
			if(grid[n][n-1] == '0') ans.pb({n,n-1});
			if(grid[n-1][n] == '0') ans.pb({n-1,n});
		}

		cout << ans.size() << endl;

		for(auto x: ans){
			cout << x.fst << ' ' << x.snd << endl;
		}


	}	

}
