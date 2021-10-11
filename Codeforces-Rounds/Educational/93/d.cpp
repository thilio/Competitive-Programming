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

int nr, ng, nb;
vector<ll> vr, vg, vb;

ll memo[300][300][300];

ll dp(int ir, int ib, int ig){

	ll&pdm = memo[ir][ib][ig];
	if(pdm != -1) return pdm;

	pdm = 0;
	int lr = nr - ir;
	int lb = nb - ib;
	int lg = ng - ig;

	if(lr > 0 && lb > 0){
		pdm = max(pdm, vr[ir]*vb[ib] + dp(ir + 1, ib + 1, ig));
	}
	if(lr > 0 && lg > 0){
		pdm = max(pdm, vr[ir]*vg[ig] + dp(ir + 1, ib, ig + 1));
	}
	if(lb > 0 && lg > 0){
		pdm = max(pdm, vb[ib]*vg[ig] + dp(ir, ib + 1, ig + 1));
	}
	return pdm;

}

int main(){

	fastio;
	ms(memo, -1);
	cin >> nr >> nb >> ng;

	vr.resize(nr);
	vb.resize(nb);
	vg.resize(ng);

	fr(i, nr) cin >> vr[i];
	fr(i, nb) cin >> vb[i];
	fr(i, ng) cin >> vg[i];

	sort(all(vr)); reverse(all(vr));
	sort(all(vb)); reverse(all(vb));
	sort(all(vg)); reverse(all(vg));

	cout << dp(0, 0, 0) << endl; 



}
