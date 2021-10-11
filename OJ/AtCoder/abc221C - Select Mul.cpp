#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define endl '\n'
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

ll tent(vi &v){
	int n = v.size();

	ll ans = 0; 
	for(int i = 0; i < n - 1; i++){
		if(v[0] == 0 || v[i + 1] == 0) continue;
		ll num1, num2;
		num1 = num2 = 0;
		for(int j = 0; j <= i; j++){
			num1 *= 10;
			num1 += v[j];
		}
		for(int j = i + 1; j < n; j++){
			num2 *= 10;
			num2 += v[j];
		}

		ans = max(ans, num1*num2);
	}

	return ans;
}

int main(){

	fastio;

	vector<int> v;
	string s;

	cin >> s;

	for(auto x: s) v.pb(x - '0');
	sort(all(v));

	ll ans = 0;

	do{
		ans = max(ans, tent(v));
	}while(next_permutation(all(v)));

	cout << ans << endl;
}
