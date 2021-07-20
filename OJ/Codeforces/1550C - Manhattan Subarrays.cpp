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

int v[200200];
int n;

bool good(int i, int j, int k){
	if(v[j] >= v[i] && v[j] <= v[k]) return false;
	if(v[j] <= v[i] && v[j] >= v[k]) return false;

	return true;
}

int brute_3(){
	int a = 0; 
	for(int i = 1; i <= n - 2; i++){
		if(good(i, i + 1, i + 2)) a++;
	}
	return a;
}

int brute_4(){
	int a = 0;

	for(int i = 1; i <= n - 3; i++){
		if(good(i, i + 1, i + 2) && good(i, i + 1, i + 3) && good(i, i + 2, i + 3) && good(i + 1, i + 2, i + 3)) a++;
	}

	return a;

}


int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n;
		frr(i, n) cin >> v[i];

		int ans = 2*n - 1;

		ans += brute_3();
		//dbg(ans);
		ans += brute_4();

		cout << ans << endl;
	}

}
