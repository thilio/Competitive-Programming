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

long double mx(long double a, long double b){
	if(a > b) return a;
	return b;
}

int main(){

	fastio;

	int n;
	long double a,d;
	scanf("%d %Lf %Lf",&n,&a,&d);

	long double prev = 0.0;

	fr(i,n){
		long double t,v;
		long double x = d;
		scanf("%Lf %Lf",&t,&v);
		long double temp;
		long double ans;
		temp = v/a;

		if(a*temp*temp/(2.0) >= x){
			ans = 2*x/a;
			ans = sqrt(ans);
		}
		else{
			x -= a*temp*temp/(2.0);
			ans = temp;
			ans += x/v;
		}

		ans += t;

		ans = mx(ans,prev);

		cout<< setprecision(10) << fixed;   
    	
		printf("%.10Lf\n",ans);

		prev = ans;
	
	}

	return 0;

}
