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
#define endl '\n'

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
int n, m;
int lim;
vi v[100100];
int freq[100100];
int ans[100100];

void clean(){
	frr(i, n) freq[i] = 0;
	frr(i, m) v[i].clear();
	frr(i, m) ans[i] = 0;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;
		lim = (m + 1)/2;
		clean();

		frr(i,m){
			int k;
			cin >> k;
			fr(j, k){
				int x;
				cin >> x;
				v[i].pb(x);
			}
			if(k == 1) freq[v[i][0]]++;
		}
		bool ruim = false;

		frr(i, n){
			if(freq[i] > lim){
				ruim = true;
			}
		}

		if(ruim){
			cout << "NO" << endl;
			continue;
		}

		frr(i,m){
			int resp = -1;
			int fresp = INF;
			if(v[i].size() == 1){
				ans[i] = v[i][0];
				continue;
			}
			for(auto x : v[i]){
				if(freq[x] < fresp){
					resp = x;
					fresp = freq[x];
				}
			}
			freq[resp]++;
			ans[i] = resp;
		}

		cout << "YES" << endl; 

		frr(i,m){
			cout << ans[i] << ' ';
		}
		cout << endl;

	}

}
