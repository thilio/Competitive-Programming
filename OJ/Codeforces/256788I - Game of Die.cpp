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
int a[7];
ll S;
int s0;

bool dp[20000000][7];
int m[20000000];

int exp(int base,int esp){
	if(esp == 0) return 1;
	return base*exp(base,esp - 1);
}

int main(){

	fastio;

	ms(m, -1);

	frr(i,6) cin >> a[i];
	cin >> S >> s0;

	S -= a[s0];

	ll ite = min<ll>(S, 15000000);

	int K = exp(5,9);

	int i = 1;

	int base = 0;
	ll mask = 0;

	while(i <= ite){
		int wins = 0;
		frr(face,6){
			frr(vou, 6){
				if(vou + face == 7 || vou == face) continue;
				if(a[vou] >= i) dp[i][face] = true;
				else if (!dp[i - a[vou]][vou]) dp[i][face] = true; 
			}
			if(dp[i][face]) wins++;
		}

		int bit = -1;
		
		if(wins == 0) bit = 0;
		if(wins == 6) bit = 4;
		if(wins == 4){
			if(dp[i][1] == false) bit = 1;
			if(dp[i][2] == false) bit = 2;
			if(dp[i][3] == false) bit = 3;
		}

		mask /= 5;
		mask += bit*K;

		if(m[mask] != -1){				
			base = m[mask];
			break;
		}
		else{
			m[mask] = i;
		}
		i++;
	}

	frr(i,10){
		frr(j,6){
			//cout << dp[i][j];
		}
		//gnl;
	}
	if(S < ite){
		if(dp[S][s0]) cout << "ADA" << endl;
		else cout << "BOB" << endl;
		return 0;
	}

	int sz = i - base;
	S -= base;
	S %= sz;
	S += base;

	if(dp[S][s0]) cout << "ADA" << endl;
	else cout << "BOB" << endl;
	return 0;





}
