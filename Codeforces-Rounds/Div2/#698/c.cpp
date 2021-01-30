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
vector<ll> v;
map<ll,int> freq;
ll a[200200];

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;

		v.clear();
		freq.clear();
		frr(i,n) a[i] = 0;

		fr(i,2*n){
			ll x;
			cin >> x;
			if(freq[x] == 0){
				freq[x] = 1;
			}
			else if(freq[x] == 1){
				freq[x] = 0;
				v.pb(x);
			}
		}

		if(v.size() != n){
			cout << "NO" << endl;
			continue;
		}

		v.pb(-llINF);

		sort(all(v));

		ll sum = 0;

		bool ok = true;
	
		for(int j = n ;j > 0; j--){
			if(v[j] <= 2*sum) ok = false;
			else{
				ll k = v[j] - 2*sum;
				if(k%(2*j) != 0) ok = false;
				else{ 
					a[j] = k/(2*j);
					sum += a[j];
				}
			}
		}

		freq.clear();

		frr(i,n){
			if(freq[a[i]] > 0) ok = false;
			else freq[a[i]]++; 
		}

		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;


	}

}
