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

int a[200];

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int mx = -1;
		int sum = 0;
		frr(i, n){
			cin >> a[i];
			sum += a[i];
			mx = max(mx, a[i]);
		}

		sum -= mx;

		if(mx > sum){
			cout << 'T' << endl;
		}
		else{
			if((sum - mx)%2) cout << 'T' << endl;
			else cout << "HL" << endl;
		}
	}

}
