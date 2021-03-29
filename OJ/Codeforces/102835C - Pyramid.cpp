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

int mat[100010];
int v[100100];

int go(int n, int k){
	if(n == 0) return 0;
	
	mat[0] = k;
	int bola = 0;

	if(k%2) bola = 1;

	for(int soma = 1; soma < n; soma++){
		for(int j = 0; j <= soma; j++){
			if(j != soma) v[j] += (mat[j] + 1)/2;
			if(j != 0) v[j] += mat[j - 1]/2;
		}
		if(v[bola]%2) bola++;
		for(int j = 0; j <= soma; j++){
			mat[j] = v[j];
			v[j] = 0;
		} 
	}

	return bola;
	
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		int n, k;
		cin >> n >> k;
		n--; k--;

		cout << go(n, k) << endl;
	}

}
