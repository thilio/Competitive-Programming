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

double modu(double a){
	if(a<0) return -a;
	return a;
}

double calc (double d){
	if (modu(d) < 1e-6) return 0.0;
	if (modu(d-4)< 1e-6) return 2.0;

	if (d < 4) return -1;

	double r;
	r = d*(d-4);

	r = pow (r,0.5);

	double ans1;

	ans1 = (d + r)*0.5;

	return (ans1);


}

int main(){

	fastio;
	cout.precision(15);

	double d;
	int T;
	cin >> T;


	while(T--){
		cin >> d;
		double b = calc(d);

		if(b < -0.5)
			cout << "N\n";
		else{
			cout << "Y " << d - b <<' '<< b<<endl;
		}
	}

}
