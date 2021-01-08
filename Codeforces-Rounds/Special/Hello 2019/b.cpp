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

int v[20];
int main(){

	fastio;
	int n;
	cin >> n;
	fr(i,n)
		cin >> v[i];

	int mask;

	bool ok = false;

	for(mask = 0;mask<pow(2,n);mask++){
		int ans = 0;
		fr(i,n){
			//dbg((1<<i));
			if((mask & 1<<i) != 0){
				ans += v[i];
			}
			else
				ans-= v[i];
		}

		ans = max(ans,-ans);
		ans%= 360;

		if(ans == 0)
			ok = true;
	}

	if(ok) cout << "YES"<<endl;
	else cout << "NO" << endl;


}
