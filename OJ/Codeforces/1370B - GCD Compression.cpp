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


vi par;
vi impar;

int v[100100];

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){

		int n;
		cin >> n;
		par.clear();
		impar.clear();

		frr(i,2*n){
			cin >> v[i];
			if(v[i]%2){
				impar.pb(i);
			}
			else par.pb(i);
		}

		int p = par.size();
		int ip = impar.size();

		int k = 0;

		for(int i = 1; i < p;i += 2){
			if(k == n-1) break;
			cout << par[i] << ' ' << par[i-1] << endl;
			k++;
		}

		for(int i = 1; i < ip; i+= 2){
			if(k == n -1) break;
			cout << impar[i] << ' ' << impar[i-1] << endl;
			k++;
		}





	}

}
