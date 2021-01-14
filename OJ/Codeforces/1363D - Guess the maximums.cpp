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
int n;
int k;
vi adj[1010];

bool maxx[1010];
bool lastq[1010];

void query(int a, int b){
	cout << "? ";
	cout << b - a + 1 << ' ';
	for(int i=a ; i <= b ; i++){
		cout << i << ' ';
	}
	gnl;
}

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		ms(lastq,false);
		ms(maxx,false);

		cin >> n >> k;

		fr(i,k) adj[i].clear();

		fr(i,k){
			int c;
			cin >> c;
			while(c--){
				int a;
				cin >> a;
				adj[i].pb(a);
			}
		}


		query(1,n);
		
		int mx;
		cin >> mx;

		int l = 1;
		int r = n;

		int tent;

		while(l < r){
			int m = (l + r)/2;
			query(l,m);
			cin >> tent;

			if(tent == mx){
				r = m;
			}
			else
				l = m + 1;
		}


		fr(i,k){
			maxx[i] = false;
			fr(j,adj[i].size()){
				if(adj[i][j] == l) maxx[i] = true;
			}
			if(maxx[i] == true){
				fr(j,adj[i].size())
					lastq[adj[i][j]] = true;
			}
		}

		cout << "? ";

		vi aux;
		aux.clear();

		frr(i,n){
			if(lastq[i] == false) aux.pb(i);
		}
		cout << aux.size() << ' ';
		fr(i,aux.size())cout << aux[i] << ' ';
		gnl;

		int bom;
		cin >> bom;

		cout << '!' << ' ';

		fr(i,k){
			if(maxx[i] == false) cout << mx << ' ';
			else cout << bom << ' ';
		}

		gnl;
		string s;
		cin >> s;


	}

}
