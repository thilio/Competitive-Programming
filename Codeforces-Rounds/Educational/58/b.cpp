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
ll memo[500500][7];
string s;
int n;

ll dp(int ind,int si){
	if(ind == n && si == 5) return 0;
	if(ind == n) return -llINF;

	ll& pdm = memo[ind][si];
	if(pdm != -1) return pdm;

	pdm = dp(ind +1,si);
	if(si == 0){
		if(s[ind] == '[')
			pdm = max(pdm,1 + dp(ind+1,si+1));
	}

	else if(si == 1){
		if(s[ind] == ':') pdm = max(1 + dp(ind+1,si+2),max(pdm,1 + dp(ind+1,si+1)));
	}

	else if(si == 2){
		if(s[ind] == '|') pdm = max(max(pdm,1 + dp(ind+1,si + 1)),1 + dp(ind+1,si));
	}

	else if(si == 3){
		if(s[ind] == ':') pdm = max(pdm,1 + dp(ind + 1,si + 1));
	}

	else if (si == 4){
		if(s[ind] == ']') pdm = max(pdm,1 + dp(ind +1,si+1));
	}

	return pdm;
}

int main(){

	fastio;
	

	getline(cin,s);
	n = s.size();

	ms(memo,-1);

	ll ans = dp(0,0);
	if(ans <= 0) ans =  -1;

	cout << ans << endl;

}
