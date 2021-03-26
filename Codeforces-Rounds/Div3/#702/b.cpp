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

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;

		int c[3];
		fr(i, 3) c[i] = 0;

		frr(i, n){
			int x;
			cin >> x;
			c[x%3]++;
		}

		int lim = n/3;
		int ans = 0;

		fr(j ,2){
			fr(i, 3){
				if(c[i] > lim){
					ans += c[i] - lim;
					c[(i + 1)%3] += c[i] - lim;
					c[i] = lim;
				}
			}
		}

		cout << ans << endl;


	}

}
