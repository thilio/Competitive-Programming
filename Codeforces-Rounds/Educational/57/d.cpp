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

ll n;
string s;
ll v[112345];
ll memo[112345][4];

ll mn(ll a,ll b){
	if(a<b) return a;
	return b;

}

ll pd(int ind,int c){
	if(ind == n) return 0;

	ll &pdm = memo[ind][c];
	if(pdm != -1) return pdm;
	if(c == 3 && s[ind] == 'd'){
		pdm = v[ind] + pd(ind + 1,c);
		return pdm; 
	}

	pdm = v[ind] + pd(ind+1,c);

	if(c==0){
		if(s[ind] != 'h'){
			pdm = pd(ind + 1,c);
			return pdm;
		}

		pdm = mn(pdm,pd(ind+1,c+1));
		return pdm;
	}
	if(c==1){
		if(s[ind] != 'a'){
			pdm = pd(ind + 1,c);
			return pdm;
		}

		pdm = mn(pdm,pd(ind+1,c+1));
		return pdm;
	}
	if(c==2){
		if(s[ind] != 'r'){
			pdm = pd(ind + 1,c);
			return pdm;
		}

		pdm = mn(pdm,pd(ind+1,c+1));
		return pdm;
	}

	pdm = pd(ind+1,c);
	return pdm;
}

int main(){

	fastio;
	cin >> n;
	getline(cin,s);
	getline(cin,s);

	fr(i,n){
		cin >> v[i];
	}

	fr(i,n+2){
		fr(j,4){
			memo[i][j] = -1ll;
		}
	}

	cout<< pd(0,0)<<endl;
	


}
