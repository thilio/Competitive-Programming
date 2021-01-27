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

int memo[100100][35];
string s;
int n;
int m[30][30];

bool f(int a,int b){
	if (a==30 || b == 30) return false;

	if(m[a][b] >= 1) return true;
	return false;
}

int dp(int ind,int last){
	if(ind == n) return 0;

	int& pdm = memo[ind][last];
	if(pdm != -1) return pdm;

	pdm = INF;

	bool hc = f(s[ind] - 'a',last);

	if(hc){
		pdm = 1 + dp(ind+1,last);
	}
	else{
		pdm = 1 + dp(ind+1,last);
		pdm = min(pdm,dp(ind+1,s[ind]-'a'));
	}

	return pdm;
}

int main(){

	fastio;
	ms(memo,-1);

	getline(cin,s);
	n=s.size();
	int k;
	cin >> k;
	string t;
	getline(cin,t);

	fr(i,k){
		getline(cin,t);
		m[t[0] - 'a'][t[1] - 'a']++;
		m[t[1] - 'a'][t[0] - 'a']++;
	}

	cout << dp(0,30) << endl;



}
