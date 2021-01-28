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
	int a,b;
	int n;
	cin >> a >> b;
	cin >> n;

	int g = __gcd(a,b);

	vi div;

	for(int i = 1;i*i<=g;i++){
		if(g%i == 0){
			div.pb(i);

			if(g/i != i) div.pb(g/i);
		}
	}

	sort(all(div));

	fr(i,n){
		int l,h;
		cin >> l >> h;

		auto it = upper_bound(all(div),h);

		if(it == div.begin()){
			cout << -1 << endl;
		}

		else{
			int p = it - div.begin();
			p--;
			if(div[p]< l || div[p] > h){
				cout << -1 << endl;
				continue;
			}
			cout << div[p] << endl;
		}

	}

}
