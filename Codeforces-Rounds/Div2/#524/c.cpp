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

ll black(ll n,ll m,ll i){
	if(n%2 ==0 || m%2== 0){
		return (n*m/2);
	}

	ll aux = 0;

	if(i == 1) aux++;


	return (n*m + aux)/2;
}

ll white(ll n,ll m,ll i){
	if(n%2 ==0 || m%2== 0){
		return (n*m/2);
	}

	ll aux = 0;

	if(i == 0) aux++;
	return (n*m + aux)/2;
}

int main(){

	fastio;
	int t;
	cin >> t;
	while(t--){
		ll b,w;
		ll n,m;
		cin >> n >> m;
		b = black(n,m,0);
		w = white(n,m,0);
		
		
		ll x1,x2,x3,x4,y1,y2,y3,y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >>x4 >> y4;

		w-= white(x2-x1 + 1,y2-y1+1,(x1 + y1)%2);
		b -= black(x2-x1 + 1,y2-y1+1,(x1 + y1)%2);

		w += (x2 - x1 + 1)*(y2 - y1 + 1);

		ll xinter = -max(x1,x3) + min(x2,x4) + 1;
		ll yinter = -max(y1,y3) + min(y2,y4) + 1;

		if(xinter <= 0 || yinter <= 0){
			w-= white(x4-x3 + 1,y4-y3+1,(x3 + y3)%2);
			b -= black(x4-x3 + 1,y4-y3+1,(x3 + y3)%2);

			b += (x4 - x3 + 1)*(y4 - y3 + 1);
		} 

		else{
			w -= black(xinter,yinter,(max(x1,x3) + max(y1,y3))%2);
			b += black(xinter,yinter,(max(x1,x3) + max(y1,y3))%2);

			w-= white(x4-x3 + 1,y4-y3+1,(x3 + y3)%2);
			b -= black(x4-x3 + 1,y4-y3+1,(x3 + y3)%2);

			b += (x4 - x3 + 1)*(y4 - y3 + 1);

		}

		

		cout << w << ' ' << b << endl;


	}

}
