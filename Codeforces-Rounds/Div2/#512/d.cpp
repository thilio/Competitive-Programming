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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m,k;
	ll mm,nn;
	cin >> n >> m >> k;
	mm = m;
	nn = n;

	ll aux = __gcd(k,m);

	m = m/aux;
	k = k/aux;

	aux = __gcd(k,n);
	n = n/aux;
	k = k/aux; 

	if (k>2){
		cout << "NO" << endl;
		return(0);
	}

	if (k == 2){
		cout << "YES" << endl;
		cout << "0 0" << endl;
		cout << "0 "<< m << endl;
		cout << n<< " 0"<< endl;
		return(0);
	}
	if (2*m <= mm){
		cout << "YES" << endl;
		cout << "0 0" << endl;
		cout << "0 "<< 2*m << endl;
		cout << n<< " 0"<< endl;
		return(0);
	}
	cout << "YES" << endl;
	cout << "0 0" << endl;
	cout << "0 "<< m << endl;
	cout << 2*n<< " 0"<< endl;
	return(0);

}