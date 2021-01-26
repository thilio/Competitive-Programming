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
ll xi,yi,xf,yf;
ll n;
string s;
pair<ll,ll> acum[100100];
bool boo (ll k){
	ll xt,yt;
	xt = xi;
	yt = yi;
	ll r = k/n;
	ll q = k%n;
	xt += r*acum[n-1].fst;
	if(q > 0)
		xt += acum[q-1].fst;
	yt += r*acum[n-1].snd;
	if(q > 0)
		yt += acum[q-1].snd;

	ll dist = abs(xt - xf) + abs(yt - yf);
	if(dist <= k) return true;
	return false;

}

ll bb(){

	ll ini = 1;
	ll fim = 1e18;

	ll best = -1;

	while(ini <= fim){
		ll mid= (ini + fim)/2;
		
		
		if(boo(mid)){
			fim = mid - 1;
			best =mid;
		}
		else
			ini = mid + 1;
	}

	return best;
}

int main(){

	fastio;
	
	cin >> xi >> yi >> xf >> yf;
	cin >> n;

	getline(cin,s);
	getline(cin,s);
	ll xh,yh;
	fr(i,n){
		xh = 0;yh = 0;
		if(s[i] == 'U') yh++;
		if(s[i] == 'D') yh--;
		if(s[i] == 'R') xh++;
		if(s[i] == 'L') xh--;
		if ( i == 0){
			acum[i].fst = xh;
			acum[i].snd = yh;
		}
		else{
			acum[i].fst = acum[i-1].fst + xh;
			acum[i].snd = acum[i-1].snd + yh;
		}

	}

	cout << bb() << endl;

}
