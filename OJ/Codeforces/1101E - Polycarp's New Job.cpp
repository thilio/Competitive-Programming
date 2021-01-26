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
	int n;
	cin >> n;

	int a,b;

	a = 0;
	b = 0;

	while(n--){
		char c;
		int u,v;

		cin >> c >> u >> v;
		if (u > v) swap(u,v);

		if(c == '+'){
			a = max(a,u);
			b = max(b,v);
		}
		else{
			if(u >= a && v >= b) cout << "YES" << endl;
			else cout << "NO" << endl;

		}



	}
		

}
