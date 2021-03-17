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
char mat[550][550];

void color(int mod){
	frr(i,n){
		if(i%3 == mod){
			frr(j,m) mat[i][j] = 'X';
		}
	}

	frr(i,n){
		if(i%3 == mod && i + 3 <= n){
			if(mat[i + 1][2] == 'X' || mat[i + 2][2] == 'X'){
				mat[i + 1][2] = mat[i + 2][2] = 'X';
			}
			else{
				mat[i + 1][1] = mat[i + 2][1] = 'X';
			}
		}
	}
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;

		frr(i,n){
			frr(j,m) cin >> mat[i][j];
		}
		if(m == 1){
			frr(i,n){
				cout << 'X' << endl;
			}
			continue;
		}

		if(n%3 == 1) color(1);
		else color(2);

		frr(i,n){
			frr(j,m){
				cout << mat[i][j];
			}
			gnl;
		}
	}

}
