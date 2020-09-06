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

vi pri[100100];
int check[100100];
int best[100100];


int s[100100];

void pr(){

	for(int i = 2;i<=100000;i++){
		for(int j = i; j <= 100000;j+=i){
			pri[j].pb(i);
	
		}
	}
	

}

int main(){

	fastio;

	int T;
	pr();
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		frr(i,n) cin >> s[i];

		frr(i,n){
			best[i] = 1;
			fr(j,pri[i].size()){
				int p = pri[i][j];
				if(s[i/p] < s[i]){
					best[i] = max(best[i],1 + best[i/p]);
				}

			}
			
		}

		int mx = 1;

		frr(i,n) mx = max(mx,best[i]);

		cout << mx << endl;



	}

}
