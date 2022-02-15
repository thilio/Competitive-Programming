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
int grid[1010][1010];
bool vis[1010][1010];
vector<array<int, 3>> ans;
queue<pii> q;

bool equal(int i, int j){ // true if every nonspecial has same olor
	int mn = INF;
	int mx = 0;
	for(int dx = 0; dx < 2; dx++){
		for(int dy = 0; dy < 2; dy++){
			if(grid[i + dx][j + dy] == -1) continue;
			mn = min(mn, grid[i + dx][j + dy]);
			mx = max(mx, grid[i + dx][j + dy]);
		}
	}

	return mn == mx;
}

bool valid(int i, int j){
	if(i >= 0 && i < n - 1 && j >= 0 && j < m - 1) return true;
	return false;
}

int main(){

	fastio;

	cin >> n >> m;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cin >> grid[i][j];
	}

	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < m - 1; j++){
			if(equal(i, j)){
				q.push({i, j});
				vis[i][j] = true;
			}
		}
	}

	while(!q.empty()){
		int i, j;
		tie(i, j) = q.front();
		q.pop();
		int color = -1;
		for(int dx = 0; dx < 2; dx++){
			for(int dy = 0; dy < 2; dy++){
				if(grid[i + dx][j + dy] != -1){
					color = grid[i + dx][j + dy];
					grid[i + dx][j + dy] = -1;
					for(int di = -1; di <= 0; di++){
						for(int dj = -1; dj <= 0; dj++){
							if(valid(i + dx + di, j + dy + dj) && equal(i + dx + di, j + dy + dj) && !vis[i + dx+ di][j + dj + dy]){
								q.push({i + dx + di, j + dy + dj});
								vis[i + dx + di][j + dy + dj] = true;
							}
						}
					}

				}
			}
		}
		if(color != -1) ans.pb({i, j, color});
	}

	reverse(all(ans));

	bool ok = true;

	fr(i, n) fr(j, m){
		if(grid[i][j] != -1) ok = false;
	}

	if(ok){
		cout << ans.size() << endl;
		for(auto x: ans){
			cout << x[0] + 1<< ' ' << x[1] + 1 << ' ' << x[2] << endl;
		}
	}
	else
		cout << -1 << endl;
}
