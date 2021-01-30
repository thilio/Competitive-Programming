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

int memo[100][10];

bool y(int x,int d){
	if(x == 0) return true;
	if(x < d) return false;
	int &pdm = memo[x][d];
	if(pdm != -1) return pdm;

	int k = 10;
	int i = 0;
	pdm = 0;
	while(i*k + d <= x){
		if(y(x - i*k - d,d)) pdm = 1;
		i++;
	}
	return pdm;
}

int main(){

	fastio;

	int T;
	cin >> T;
	ms(memo, -1);
	while(T--){
		int q,d;
		cin >> q >> d;

		fr(i,q){
			int x;
			cin >> x;

			if(x >= 10*d) cout << "YES" << endl;
			else{
				if(y(x,d)) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
		}
	}

}
