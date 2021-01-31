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

struct edge{
	int u;
	int w;
	int ct;
};

typedef struct edge edge;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int t = 1;
vector<edge> ed;
int d[1010];

int main(){

	fastio;
	int n,r;
	cin >> n >> r;
	while(n != 0 && r != 0){
		cout << "Scenario #" << t++ << endl;
		ms(d,-1);
		ed.clear();
		fr(i,r){
			int a,b,c;
			cin >> a >> b >> c;
			edge e;
			e.u = a;
			e.w = b;
			e.ct = c;
			ed.pb(e);
			e.w = a;
			e.u = b;
			ed.pb(e);
		}

		int s,de,p;
		cin >> s >> de >> p;
		d[s] = INF;

		fr(i,n-1){
			fr(j,ed.size()){
				if(d[ed[j].u] == -1) continue;
				//dbg(ed[j].u);
				//dbg(ed[j].w);
				if(d[ed[j].w] < min(d[ed[j].u],ed[j].ct))
					d[ed[j].w] = min(d[ed[j].u],ed[j].ct);
			}
		}

		int k = d[de];
		//dbg(k);
		k--;
		if(s == de){
			p = 0;
			k = 1;	
		}
		cout << "Minimum Number of Trips = " << (p+k-1)/k<< endl;
		gnl;
		cin >> n >> r;
	}

}
