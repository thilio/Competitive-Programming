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

int n,x;
vi adj[1010];

void clear(){
	frr(i,n) adj[i].clear();
}

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		cin >> n >> x;
		clear();
		fr(i,n-1){
			int a,b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}

		if(adj[x].size()<=1){
			cout << "Ayush" << endl;
			continue;
		}

		if(n%2){
			cout << "Ashish" << endl;
		}
		else{
			cout << "Ayush" << endl;
		}
	}

}
