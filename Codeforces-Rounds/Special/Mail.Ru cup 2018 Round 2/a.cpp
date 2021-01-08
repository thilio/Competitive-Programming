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
	cin >> n;
	int s;
	cin >> s;

	int v[10000],t[10000];

	frr(i,n)
		cin >> v[i];

	frr(i,n)
		cin >> t[i];

	bool ok = true;

	if(v[1] == 0){
		cout << "NO" << endl;
		return (0);
	}

	if(v[s] == 0 && t[s] == 0){
		cout << "NO" << endl;
		return (0);
	}

	if(v[s] == 1){
		cout << "YES" << endl;
		return (0);
	}

	for(int i = s;i<=n;i++){
		if (v[i] == 1 && t[i] == 1 ){
			cout << "YES" << endl;
			return (0);
		}
	}

	cout << "NO" << endl;


}
