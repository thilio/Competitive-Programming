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

string s;
ll v[100100];
ll c10, c01;

ll ones_back[100100], ones_front[100100], zero_back[100100], zero_front[100100];

vi pos;

int main(){

	fastio;
	cin >> s;
	int n = s.size();

	cin >> c01 >> c10;

	if(c10 > c01){
		reverse(all(s));
		swap(c10, c01);
	}

	v[0] = -1;
	v[n + 1] = -1;

	fr(i, s.size()){
		if(s[i] == '1'){
			v[i + 1] = 1;
		}
		else{
			v[i + 1] = 0;
		}
		if(s[i] == '?') pos.pb(i + 1);
	}

	frr(i,n){
		ones_back[i] = ones_back[i - 1];
		zero_back[i] = zero_back[i - 1];
		if(v[i - 1] == 0) zero_back[i]++;
		if(v[i - 1] == 1) ones_back[i]++;
	}

	int tot0 = zero_back[n] + (v[n] == 0);
	int tot1 = ones_back[n] + (v[n] == 1);

	frr(i, n){
		ones_front[i] = tot1 - ones_back[i] - (v[i] == 1);
		zero_front[i] = tot0 - zero_back[i] - (v[i] == 0);
	}

	ll cost = 0;

	frr(i,n){
		if(v[i] == 0) cost += ones_back[i]*c10;
		if(v[i] == 1) cost += zero_back[i]*c01;
	}

	ll ans = cost;

	frr(i,n){
		//dbg(ones_back[i]);
		//dbg(ones_front[i]);
		//dbg(zero_back[i]);
		//dbg(zero_front[i]);
	}

	fr(i, pos.size()){
		int at = pos[i];

		cost -= (ones_back[at] + i)*c10;
		cost += (zero_back[at] - i)*c01;
		cost -= ones_front[at]*c01;
		cost += zero_front[at]*c10;

		ans = min(ans, cost);
	}

	cout << ans << endl;


}
