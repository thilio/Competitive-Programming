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

ll dp[1000100];

int main(){

	fastio;

	int k;
	string s;
	cin >> k >> s;

	reverse(all(s));
	ll tam = ((1 << k) - 1);

	for(int i = tam - 1; i >= 0; i--){
		if(2*i + 1  > tam - 1){
			if(s[i] == '?') dp[i] = 2;
			else dp[i] = 1;
		}
		else{
			if(s[i] == '?') dp[i] = dp[2*i + 1] + dp[2*i + 2];
			if(s[i] == '1') dp[i] = dp[2*i + 1];
			if(s[i] == '0') dp[i] = dp[2*i + 2];
		}
	}

//	fr(i, tam) dbg(dp[i]);
//	gnl;

	int q;
	cin >> q;

	while(q--){
		int p; char c;

		cin >> p >> c;
		p--;
		p = tam - p - 1;
		s[p] = c;

		for(int i = p; i >= 0; i = (i - 1)>> 1){
			if(2*i + 1  > tam - 1){
				if(s[i] == '?') dp[i] = 2;
				else dp[i] = 1;
			}
			else{
				if(s[i] == '?') dp[i] = dp[2*i + 1] + dp[2*i + 2];
				if(s[i] == '1') dp[i] = dp[2*i + 1];
				if(s[i] == '0') dp[i] = dp[2*i + 2];
			}
		}

		cout << dp[0] << endl;

	//	fr(i, tam) dbg(dp[i]);
	//	gnl;
	}

}
