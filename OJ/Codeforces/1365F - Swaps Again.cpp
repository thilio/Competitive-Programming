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
int s[505],t[505];
vii sl,tl;

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		tl.clear();
		sl.clear();

		cin >>n;
		fr(i,n){
			int a;
			cin >> a;
			s[i] = a;
		}

		fr(i,n){
			int a;
			cin >> a;
			t[i] = a;
		}

		bool ok = true;

		if(n%2){
			if(s[n/2] != t[n/2]) ok = false;
		} 

		fr(i,n/2){
			int a = min(s[i],s[n-1-i]);
			int b = max(s[i],s[n-1-i]);
			sl.pb(mp(a,b));

			a = min(t[i],t[n-1-i]);
			b = max(t[i],t[n-1-i]);
			tl.pb(mp(a,b));
		}

		sort(all(sl));
		sort(all(tl));

		fr(i,n/2){
			if(sl[i] != tl[i]) ok = false;
		}

		if(!ok){
			cout << "No" << endl;
			continue;
		}

		cout << "Yes" << endl;

		

	}

}
