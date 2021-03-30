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

ll freq[26];

ll num(char c){
	return 1ll << (c - 'a');
}

int main(){

	fastio;

	int n;
	ll x;
	cin >> n >> x;
	string s;
	cin >> s;

	x -= num(s[n - 1]);
	x += num(s[n - 2]);

	fr(i, n - 2) freq[s[i] - 'a']++;

	ll cur = 0;

	fr(i, 26) cur += freq[i]*(1ll << i);

	if(x < 0) x = -x;

	for(int i = 25; i >= 0; i--){
		ll dif = cur - x;
		while(dif >= 2ll*(1ll << i) && freq[i] > 0){
			cur -= 2ll*(1ll << i);
			dif = cur - x;
			freq[i]--;
		}
		if(dif == 0){
			cout << "Yes" << endl;
			return 0;
		}
		//if(dif < 0) olar;
	}

	cout << "No" << endl;
	return 0;
	





}
