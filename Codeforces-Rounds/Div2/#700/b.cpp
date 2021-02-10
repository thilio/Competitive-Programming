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

vector<pll> v;
ll A,B,n;

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> A >> B >> n;
		v.clear();
		v.resize(n);
		
		fr(i,n) cin >> v[i].fst;
		fr(i,n) cin >> v[i].snd;

		sort(all(v));

		bool ok = true;

		fr(i,n){
			if(i != n - 1){
				ll many = (v[i].snd + A - 1)/A;
				B-= many*v[i].fst;
				if(B <= 0) ok = false;
			}
			else{
				ll many = (v[i].snd + A - 1)/A;
				many--;
				B -= many*v[i].fst;
				if(B <= 0) ok = false;

			}
		}

		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}
