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
	int b,k;
	cin >> b >> k;
	int v[100100];
	fr(i,k) cin >> v[i];
	if(b%2 == 0){
		if(v[k-1]%2 == 0) cout << "even" << endl;
		else cout << "odd" << endl;
		return 0; 
	}
	ll sum = 0;
	fr(i,k) sum += v[i];

	if(sum%2 == 0) cout << "even" << endl;
	else cout << "odd" << endl;


	



}
