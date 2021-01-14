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

ll memo[200200][3];
ll q1,q2,q0;
ll n,l,r;

ll dp(int ind,int r){
	if(ind == n && r == 0) return 1;
	if(ind == n) return 0;

	ll& pdm = memo[ind][r];
	if(pdm != -1ll) return pdm;

	pdm = q0*dp(ind + 1,r);
	pdm %= MOD; 
	pdm += q1*dp(ind + 1,(r + 1)%3);
	pdm %= MOD; 
	pdm += q2*dp(ind + 1,(r + 2)%3);
	pdm %= MOD;

	return pdm; 
}

void calcq(){
	ll p,q;
	if (r == 1){
		q0 = 0;
		q1= 1;
		q2 = 0;
		return;
	}
	
	p = l;q = r;

	while(p%3 != 0) p++;
	while(q%3 != 0) q--;

	if(p > q) q0 = 0;
	else q0 = (q - p)/3 + 1;

	p = l;q = r;

	while(p%3 != 1) p++;
	while(q%3 != 1) q--;

	if(p > q) q1 = 0;
	else q1 = (q - p)/3 + 1;


	p = l;q = r;

	while(p%3 != 2) p++;
	while(q%3 != 2) q--;

	if(p > q) q2 = 0;
	else q2 = (q - p)/3 + 1;
}

int main(){

	fastio;
	
	cin >> n >> l >> r;
	calcq();
	//dbg(q0);
	//dbg(q1);
	//dbg(q2);

	ms(memo,-1ll);

	cout << dp (0ll,0ll) << endl;

}
