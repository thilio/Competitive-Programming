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

int main(){

	fastio;

	int n;
	double r;
	cout.precision(2);
	cout << fixed;
	cin >> n >> r;

	double dist = 2*(3.1415926)*r;

	double oldx,oldy;
	cin >> oldx >> oldy;

	double fx,fy;
	fx = oldx;
	fy = oldy;

	double x,y;
	fr(i,n-1){
		
		cin >> x >> y;
		//dbg(dist);
		dist += sqrt((x - oldx)*(x - oldx) + (y-oldy)*(y - oldy));
		//dbg(dist);
		oldx = x;oldy = y;
	}

	if(n != 1){

		dist += sqrt((x - fx)*(x - fx) + (y-fy)*(y - fy));

	}

	cout << dist << endl;

}
