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

ll c[6];

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		int x,y;
		cin >> y >> x;
		fr(i,6) cin >> c[i];

		fr(j,2){
			fr(i,6){
				if(c[i] > c[(i + 1)%6] + c[(i + 5)%6]) c[i] = c[(i + 1)%6] + c[(i + 5)%6];
			}
		}

		//fr(i,6) dbg(c[i]);

		ll cost = 0;

		if(x >= 0 && y >= 0){
			if(x >= y){ 
				cost += y*c[0];
				cost += (x - y)*c[1]; 
			}
			if(y > x){
				cost += x*c[0];
				cost += (y - x)*c[5];
			}
		}
		else if(x <= 0 && y <= 0){
			if(x >= y){
				cost += -x*c[3];
				cost += (x - y)*c[2];
			}
			if(y > x){
				cost += -y*c[3];
				cost += (y - x)*c[4];
			}
		}
		else if(x >= 0 && y < 0){
			cost += x*c[1] - y*c[2];
		}
		else if(x < 0 && y >= 0){
			cost += -x*c[4] + y*c[5];
		}

		cout << cost << endl;
	}

}
