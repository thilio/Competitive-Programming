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
	pair<pii,int> v[100100];
	int ans[100100];
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		
		fr(i,n){
			cin >> v[i].fst.fst >> v[i].fst.snd;
			v[i].snd = i;
		}

		sort(v,v+n);

		int l,r;
		int j = -1;
		fr(i,n){
			if(i == 0){
				l = v[i].fst.fst;
				r = v[i].fst.snd;
				continue;
			}

			if(v[i].fst.fst > r){
				j = i;
				break;
			}
			else
				r = max(r,v[i].fst.snd);
		}

		if(j == -1){
			cout << -1 << endl;
			continue;
		}



		fr(i,n){
			if(i < j) ans[v[i].snd] = 1;
			else ans[v[i].snd] = 2;
		}

		fr(i,n) cout << ans[i] << ' ';
		gnl;


	}

}
