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

int n,m,k,s;
char mat[520][510];

int vis[520][520];
int ct = 0;

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

bool is(int i,int j){
	if(i < 0 || i >= n || j <0 || j>= m) return false;
	return true; 
}

bool dfs(int i,int j){
	vis[i][j] = 1;
	ct++;
	if(ct == s - k){
		return true;
	}

	bool ok = false;

	fr(k,4){
		if(is(i + dx[k],j + dy[k])){
			if(mat[i + dx[k]][j + dy[k]] == '.' && vis[i + dx[k]][j + dy[k]] == 0){
				ok = dfs(i + dx[k],j + dy[k]);
				if(ok) return true;
			}
		}
	}

	return false;
}

int main(){

	fastio;

	cin >> n >> m >> k;
	string t;
	getline(cin,t);

	fr(i,n){
		getline(cin,t);
		fr(j,m){
			mat[i][j] = t[j];
		}
		
	}

	fr(i,n){
		fr(j,m){
			if(mat[i][j] == '.') s++;
		}
	}

	bool ok;

	fr(i,n){
		fr(j,m){
			if(mat[i][j] == '.'){
				ok = dfs(i,j);
				i = 700;
				j = 700;
			}
		}
	}

	fr(i,n){
		fr(j,m){
			if(mat[i][j] == '#') cout << mat[i][j];
			else if(vis[i][j]) cout << mat[i][j];
			else cout << 'X';
		}
		gnl;
	}
}
