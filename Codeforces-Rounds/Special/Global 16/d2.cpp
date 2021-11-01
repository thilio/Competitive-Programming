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

int v[100100];
vector<int> vv;
map<int, int> lim;
int mat[400][400];
int n, m;
int ans;

void clear(){
	ans = 0;
	vv.clear();
	lim.clear();
	ms(mat, 0);
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		clear();
		cin >> n >> m;

		fr(i, n*m){
			cin >> v[i];
			vv.pb(v[i]);
		}

		sort(all(vv));

		fr(i, n*m){
			if(!lim.count(vv[i])) lim[vv[i]] = i + 1;
		}

		fr(i, n*m){
			int pos = lim[v[i]];
			int r = ((pos - 1)/m) + 1;

			fr(j, m){
				if(mat[r][j] == 0){
					mat[r][j] = v[i];
					lim[v[i]] = lim[v[i]] + 1;
					break;
				}
				else if(mat[r][j] < v[i]) ans++;
			}
		}

		cout << ans << endl;
	}

}
