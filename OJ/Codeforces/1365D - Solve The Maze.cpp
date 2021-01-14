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

int n,m;
string s;
char maze[101][101];

int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};

bool is(int i,int j){
	if(i >= 0 && i < n & j >= 0 && j <m) return true;
	return false;
}

bool all_B(){
	fr(i,n){
		fr(j,m){
			if(maze[i][j] == 'G') return false;
		}
	}

	return true;
}
bool BG(){
	fr(i,n){
		fr(j,m){
			if(maze[i][j] == 'B'){
				fr(k,4){
					if(is(i+ di[k],j + dj[k]) && maze[i+di[k]][j+dj[k]] == 'G') return true;
				}

			}
		}
	}

	return false;
}

void lock_B(){
	fr(i,n){
		fr(j,m){
			if(maze[i][j] == 'B'){
				fr(k,4){
					if(is(i+ di[k],j + dj[k]) && maze[i+di[k]][j+dj[k]] != 'B') maze[i+di[k]][j+dj[k]] = '#';
				}

			}
		}
	}

}

int vis[100][100];

int dfs(int i,int j){
	vis[i][j] = 1;
	int ans = 0;
	if(maze[i][j] == 'G') ans++;

	fr(k,4){
		int il = i + di[k];
		int jl = j + dj[k];
		if(is(il,jl)){
			if(vis[il][jl] == 0 && maze[il][jl] !='#') ans += dfs(il,jl);
		}
	}

	return ans;

}

int all_G(){
	int ans = 0;
	fr(i,n){
		fr(j,m){
			if(maze[i][j] == 'G') ans++;
		}
	}

	return ans;
}

bool connected(){
	if(maze[n-1][m-1] != '.') return false;
	if(dfs(n-1,m-1) == all_G()) return true;
	return false;

}
int main(){

	fastio;

	int T;
	cin >> T;
	if(0) return 0;
	while(T--){
		ms(vis,0);
		cin >> n >> m;
		getline(cin,s);	

		fr(i,n){
			getline(cin,s);
			fr(j,m){
				maze[i][j] = s[j];
			}
			
		}

		if(all_B()){
			cout << "Yes" << endl;
			continue;
		}
		if(BG()){
			cout << "No" << endl;
			continue;
		}

		lock_B();
		if(connected()){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}

}
