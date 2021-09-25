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

int n, m;

vi bolsa[110];

void print(vi v){
	cout << "Vector = ";
	for(auto x: v) cout << x + 1<< ' ';
	gnl;
}

int main(){

	fastio;
	cin >> n;

	fr(i, n){
		int k;
		cin >> k;
		fr(j, k){
			int x; cin >> x; bolsa[i].pb(x);
		}
	}

	map<vector<int>, bool> M;

	cin >> m;

	fr(i, m){
		vector<int> v; v.resize(n);
		fr(i, n){
			cin >> v[i];
			v[i]--;
		}
		M[v] = true;
		//print(v);
		//olar;
	}

	priority_queue<pair<int, vi>> pq;

	vector<int> raiz;
	fr(i, n) raiz.pb(bolsa[i].size() - 1);
	int sum = 0;
	fr(i, n) sum += bolsa[i][raiz[i]];

	pq.push(mp(sum, raiz));

	int mx = -1;

	map<vector<int>, bool> vis;
	vi ans;

	while(!pq.empty()){
		vi at;
		int val;

		tie(val, at) = pq.top();
		pq.pop();

//		print(at);

		if(val < mx) continue;

		if(!M.count(at)){
			if(val > mx){
				mx = val;
				ans = at;
			}
		}
		else{
			fr(i, n){
				if(at[i] > 0){
					val -= bolsa[i][at[i]];
					val += bolsa[i][at[i] - 1];
					at[i]--;
					if(!vis[at]){
						pq.push(mp(val, at));
						vis[at] = true;
					}
					at[i]++;
					val += bolsa[i][at[i]];
					val -= bolsa[i][at[i] - 1];
				}
			}
			
		}
	}

	for(auto x: ans) cout << x + 1 << ' ';
	gnl;


}
