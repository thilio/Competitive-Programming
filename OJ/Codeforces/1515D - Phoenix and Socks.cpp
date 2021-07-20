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

int lef[200200];
int rig[200200];
int n, l, r;
int ans;

void clear(){
	ans = 0;
	frr(i, n) rig[i] = lef[i] = 0;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n >> l >> r;
		clear();
		fr(i, l){
			int x;
			cin >> x;
			lef[x]++;
		}
		fr(i, r){
			int x;
			cin >> x;
			rig[x]++;
		}

		frr(i, n){
			int mn = min(lef[i], rig[i]);
			lef[i] -= mn;
			rig[i] -= mn;
			l -= mn;
			r -= mn;
			
		}

		if(l > r){
			frr(i, n) swap(lef[i], rig[i]);
			swap(l, r);
		}

		frr(i, n){
			if(rig[i]%2 && l > 0){
				rig[i]--;
				l--;
				ans++;
			}
		}

		frr(i, n){
			while(rig[i] > 1 && l > 1){
				l -= 2;
				rig[i] -= 2;
				ans += 2;
			}
		}

		frr(i, n){
			ans += rig[i]/2;
			ans += rig[i]%2;
		}
		cout << ans << endl;
		
		

	}

}
