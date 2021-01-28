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

int v[300300];
int tim[300300];
vii event;

int main(){

	fastio;

	int n,q;
	cin >> n >> q;

	int ans = 0;
	int last = 0;
	event.pb(mp(-1,-1));

	ms(tim,-1);

	fr(i,q){
		int op,x;
		cin >> op >> x;
		if(op == 1){
			v[x]++;
			event.pb(mp(x,i));
			ans++;
		}

		if(op == 2){
			ans -= v[x];
			v[x] = 0;
			tim[x] = i;
		}

		if(op == 3){
			if(last < x){
				for(int i = last + 1; i<= x; i++){
					pii p = event[i];
					//dbg(p.fst);
					//dbg(p.snd);
					if(v[p.fst] > 0 && (p.snd > tim[p.fst])){
						v[p.fst]--;
						ans--;
					}
				}
				last = x;
			}
		}

		cout << ans << endl;
	}


}
