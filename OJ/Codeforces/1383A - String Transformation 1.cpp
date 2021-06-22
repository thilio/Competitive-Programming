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

int n; string a, b;
bool m[30][30];

void solve(){
	ms(m, false);

	fr(i, n){
		if(a[i] > b[i]){
			cout << -1 << endl;
			return;
		}
		if(a[i] < b[i]){
			m[a[i] - 'a'][b[i] - 'a'] = true;
		}
	}

	int ans= 0;

	fr(i, 20){
		int smal = 21;
		fr(j, 20) if(m[i][j]) smal = min(smal, j);

		if(smal > 20) continue;
		else{
			ans++;

			for(int j = smal + 1; j < 20; j++){
				if(m[i][j]) m[smal][j] = true;
			}
		}
	}

	cout << ans << endl;


}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n;
		cin >> a >> b;
		solve();
	}

}
