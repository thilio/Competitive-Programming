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
vector<vector<char>> grid;

int col[1000100];

void pre(){
	for(int j = 0; j < m - 1; j++){
		for(int i = 1; i < n; i++){
			if(grid[i][j] == 'X' && grid[i - 1][j + 1] == 'X'){
				col[j] = 1;
			}
		}
	}

	for(int j = 1; j < m; j++) col[j] += col[j - 1];
}


int main(){

	fastio;

	cin >> n >> m;

	grid.resize(n);
	fr(i, n) grid[i].resize(m);

	string s;
	getline(cin, s);
	fr(i, n){
		getline(cin, s);
		fr(j, m) grid[i][j] = s[j];
	}

	pre();

	//fr(j, m) dbg(col[j]);

	int q;
	cin >> q;

	fr(i, q){
		int a, b;
		cin >> a >> b;
		a--;
		b--;

		if(a == b || (a == 0 && col[b - 1] == 0) || (a != 0 && col[b - 1] == col[a - 1])){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}

}
