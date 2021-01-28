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
int memo[100100][3][2];
string s;

int dp(int ind,int turn,int last){
	if(ind == n) return 0;

	int& pdm = memo[ind][turn][last];

	if(pdm != -1) return pdm;

	pdm = dp(ind+1,turn,last);

	if(turn < 2)
		pdm = max(pdm,dp(ind,turn+1,last));

	int atual = s[ind] - '0';

	if(turn == 1) atual = (atual + 1)%2;

	if(atual != last) pdm = max(pdm, 1 + dp(ind+1,turn,atual));

	return pdm;
}

int main(){

	fastio;
	cin >> n;
	ms(memo,-1);
	getline(cin,s);
	getline(cin,s);

	cout<<max(dp(0,0,0),dp(0,0,1))<<endl;

}
