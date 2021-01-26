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
	vector<int> bes;
	vector<int> v;
	int t;
	cin >> t;
	fr(i,t){
		int n;
		cin >> n;
		
		v.clear();
		v.resize(n+1);
		frr(i,n)
			v[i] = -1;

	
		bes.clear();
		bes.resize(n+1);
		frr(i,n){
			bes[i] = INF;
		}

		frr(i,n){
			int a;
			cin >> a;
			if(v[a] == -1) v[a] = i;
			else{
				bes[a] = min(bes[a], i - v[a] + 1);
				v[a] = i;
			}
		}

		int ans = INF;

		frr(i,n){
			ans = min(ans,bes[i]);
		}

		if(ans == INF) ans = -1;

		cout << ans << endl;

	}

}
