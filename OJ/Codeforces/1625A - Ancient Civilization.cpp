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

int bit[32][2];

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		for(int i = 0; i < 30; i++) bit[i][0] = bit[i][1] = 0; 
		int n, l;
		cin >> n >> l;

		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;

			for(int i = 0; i < l; i++){
				if(x&(1 << i)) bit[i][1]++;
				else bit[i][0]++;
			}
		}
		int ans = 0;
		for(int i = 0; i < l; i++){
			if(bit[i][1] > bit[i][0]) ans += (1 << i);
		}

		cout << ans << endl;


	}

}
