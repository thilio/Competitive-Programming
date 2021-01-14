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

int grid[1010][1010];
int vis[1010][1010];

int di[4] = {-1,1,0,0};
int dj[4] = {0,0,1,-1};

int n,m,t;

bool is(int i,int j){
	if(i >= 0 && i < n && j >= 0 && j < m) return true;
	return false;

}

void bfs(){
	queue<pii> q;

	fr(i,n){
		fr(j,m){
			bool ok = false;
			fr(k,4){
				if(is(i + di[k],j + dj[k])){
					if(grid[i][j] == grid[i + di[k]][j + dj[k]])
						ok =true;
				}
			}
			if(ok){
				q.push(mp(i,j));
				vis[i][j] = 0;
			}
		}
	}

	while(!q.empty()){
		pii at = q.front();
		q.pop();
		int i = at.fst;
		int j = at.snd;
		fr(k,4){
			if(!is(i + di[k],j + dj[k])) continue;
			if(vis[i+di[k]][j + dj[k]] != -1) continue;
			vis[i+di[k]][j + dj[k]] = vis[i][j] + 1;
			q.push(mp(i+di[k],j+dj[k]));
		}
	}

}

int main(){

	fastio;

	cin >> n >> m >> t;

	fr(i,n){
		fr(j,m) vis[i][j] = -1;
	}

	string s;
	getline(cin,s);

	fr(i,n){
		getline(cin,s);
		fr(j,m){
			grid[i][j] = s[j] - '0';
		}
	}

	bfs();

	//dbg(vis[0][0]);

	fr(i,t){
		ll a,b,p;
		cin >> a >> b >> p;
		a--;b--;

		if(p <= vis[a][b] || vis[a][b] == -1) 
			cout << grid[a][b] << endl; 
		else{
			p-=vis[a][b];
			p = p%2;
			cout << (grid[a][b]^p) << endl;
		}
		
		
	}


}
