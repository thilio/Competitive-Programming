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

ll h,n;

ll f(ll h,ll start,ll end,ll w){
	if(start == end) return 0ll;

	if(w == 0){
		if(n <= (start + end)/2)
			return 1 + f(h-1,start,(start+end)/2,1);
		else
			return (1ll << h) + f(h-1,((start + end)/2) + 1,end,0);
	}
	else{
		if(n > (start + end)/2)
			return 1 + f(h-1,((start + end)/2) + 1,end,0);
		else
			return (1ll << h) + f(h-1,start,(start+end)/2,1);
	}

}

int main(){

	fastio;
	
	cin >> h >> n;

	cout << f(h,1ll,(1ll << h),0)<<endl;

}
