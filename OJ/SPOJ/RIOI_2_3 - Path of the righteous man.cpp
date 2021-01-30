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

int memo[51][51][1100];
int vis[51][51][1100];
int m[51][51];
int sx,sy,ex,ey;
int n;
int dx[4] = {+1,-1,0,0},dy[4] = {0,0,+1,-1};

bool is(int x,int y){
	if(x>= 0 && x < n && y >=0 && y < n) return true;
	return false;
}

int pd(int x,int y,int mask){
	if(x == ex && y == ey) return 0;
	vis[x][y][mask] = 1;

	int& pdm = memo[x][y][mask];
	if(pdm != -1) return pdm;

	pdm = INF;
	int kx,ky;
	fr(i,4){
		kx = x + dx[i];
		ky = y + dy[i];
		if(!is(kx,ky)) continue;
		int bi = m[kx][ky];

		if((mask&(1<<bi)) != 0){
			
			pdm = min(pdm,pd(kx,ky,mask));
		}
		else{
			
			pdm = min(pdm,1 + pd(kx,ky,mask|(1<<bi)));
		}
	}

	return pdm;
}

void solve(){
	ms(memo,-1);
	ms(m,0);
	ms(vis,0);
	
	cin >> n;
	fr(i,n){
		fr(j,n){
			cin >> m[i][j];
		}
	}
	cin >> sx >>sy >>ex >>ey;

	int bi;

	bi = (1<<(m[sx][sy]));

	cout << 1 + pd(sx,sy,bi) << endl;
	//dbg(vis[1][4][1]);


}

int main(){

	fastio;

	int t;
	cin >> t;
	while(t--){
		solve();
	}

}
