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
	int s[6];

	fr(i,6) cin >> s[i];

	if(s[1] == s[5]){
		int x = s[0] + s[1];
		int ans = (x*x - s[0]*s[0]);
		ans += x*x - s[3]*s[3]; 

		cout << ans << endl;

		return 0;
	}

	int ans;

	if(s[1] < s[5]){
		int x = s[1] + s[0];
		ans = (x*x - s[0]*s[0]);
		ans += 2*(x*(s[5] - s[1]));
		ans += x*x - s[3]*s[3];
	}

	if(s[1] > s[5]){
		int x = s[0] + s[5];
		ans = (x*x - s[0]*s[0]);
		ans+= 2*(x*(s[1] - s[5]));
		ans += x*x - s[3]*s[3];
	}

	cout << ans << endl;
}
