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

int s[200200];
int t[200200];
int f[200200];
int n;

int main(){

	fastio;

	cin >> n;

	fr(i, n) cin >> s[i];
	fr(i, n) cin >> t[i];

	int index = 0;
	fr(i, n) if(t[i] < t[index]) index = i;

	int j = index;
	f[j] = t[j];
	j = (j + 1)%n;

	for(; j != index; j = (j + 1)%n){
		int p = (j - 1 + n)%n;
		f[j] = min(t[j], f[p] + s[p]);
	}

	fr(i, n) cout << f[i] << endl;

}
