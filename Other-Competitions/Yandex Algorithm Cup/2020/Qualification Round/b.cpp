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

int memo[100100][2];
int n;
string s;

int maiu(char c){
	if('A' <= c && c <= 'Z') return 1;
	return 0;
}

int dp(int ind,int cur){
	if(ind == n) return 0;

	int& pdm = memo[ind][cur];

	if(pdm != -1) return pdm;

	if(cur == maiu(s[ind])){
		pdm = 1 + dp(ind + 1,cur);
	}
	else{
		pdm = 2 + dp(ind + 1,cur);
		pdm = min(pdm, 3 + dp(ind + 1, 1^cur));
	}

	return pdm;
}

int main(){

	fastio;

	ms(memo,-1);
	string t;
	int ans = 0;
	getline(cin,t);
	fr(i,t.size()){
		if(t[i] == ' ') ans++;
		else s.pb(t[i]);
	}
	n = s.size();
	ans += dp(0,0);

	cout << ans << endl;


}
