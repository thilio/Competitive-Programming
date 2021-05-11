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

ll v[100100];

void corner(){
	cout << 1 << ' ' << 1 << endl;
	cout << 1 << endl;
	cout << 1 << ' ' << 1 << endl;
	cout << 1 << endl;
	cout << 1 << ' ' << 1 << endl;
	cout << -(v[1] + 2) << endl;
}

int main(){

	fastio;
	ll n;
	cin >> n;
	frr(i, n) cin >> v[i];

	if(n == 1){
		corner();
		return 0;
	}

	cout << 2 << ' ' << n << endl;

	for(int i = 2; i <= n; i++){
		if(v[i] >= 0){
			cout << (v[i]%n)*(n - 1) << ' ';
			v[i] += (v[i]%n)*(n - 1);
		}
		else{
			v[i] = -v[i];
			cout << -(v[i]%n)*(n - 1) << ' ';
			v[i] += (v[i]%n)*(n - 1);
			v[i] = -v[i];	
		}
	}
	gnl;

	cout << 1 << ' ' << n << endl;
	for(int i = 1; i<= n; i++){
		if(i == 1) cout << n << ' ';
		else cout << -v[i] << ' ';
	}
	gnl;

	cout << 1 << ' ' << 1 << endl;
	cout << -(v[1] + n) << endl;
}
