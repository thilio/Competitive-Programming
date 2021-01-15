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


char grid[1010][1010];

bool vis[1010][1010];

int n,m;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool is(int x,int y){
	if(x >= 0 && x < n && y >= 0 && y < m) return true;

	return false;
}

void dfs(int i,int j){

	vis[i][j] = true;

	fr(k,4){
		int il = i + dx[k];
		int jl = j + dy[k];
		if(is(il,jl)){
			if(vis[il][jl] == false){
				if(grid[il][jl] == '#')
					dfs(il,jl);
			}

		}
	}


}


int main(){

	fastio;

	
	cin >> n >> m;

	string s;
	getline(cin,s);

	fr(i,n){
		getline(cin,s);
		fr(j,m){
			grid[i][j] = s[j];
		}
	}

	bool pos = true;

	int lin[1010];
	int col[1010];

	bool ok = true;

	bool cz,lz;
	cz=lz = false;

	fr(j,m){
		int comp = 0;
		if(grid[0][j] == '#') comp = 1;
		frr(i,n - 1){
			if(grid[i][j] == '#' && grid[i-1][j] == '.') comp++;
		}

		if(comp > 1) ok = false;
		col[j] = comp;
		if(comp == 0) cz = true;
		
	}

	fr(i,n){
		int comp = 0;
		if(grid[i][0] == '#') comp = 1;
		frr(j,m - 1){
			if(grid[i][j] == '#' && grid[i][j-1] == '.') comp++;
		}

		if(comp > 1) ok = false;
		lin[i] = comp;
		if(comp == 0) lz = true;
	}

	if(cz && !lz) ok = false;
	if(!cz && lz) ok = false;

	if(ok == false){
		cout << -1 << endl;
		return 0;
	}

	int c = 0;

	fr(i,n){
		fr(j,m){
			if(vis[i][j] == false && grid[i][j] == '#'){
				dfs(i,j);
				c++;
			}

		}
	}

	cout << c << endl;



}
