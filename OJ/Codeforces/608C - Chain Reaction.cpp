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

int acum[1000100];
int dp[1000100];

vii v;

int main(){

	fastio;
	cin >> n;

	fr(i,n){

		int a,b;
		cin >> a >> b;
		
		acum[a] = b;
	}

	fr(i,1000010){
		if(i == 0 && acum[0] != 0) dp[0] = 1;
		else if(i == 0) continue;
		else{
			if(acum[i] == 0) dp[i] = dp[i-1];
			if(acum[i] != 0){
				if(i - acum[i] > 0) dp[i] = 1 + dp[i - acum[i] - 1];
				else dp[i] = 1;
			}
		}
	}

	int mx = -1;
	fr(i,1000010){
		mx = max(mx,dp[i]);
	}

	cout << n - mx << endl;




}
