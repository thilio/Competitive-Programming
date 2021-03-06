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

bool valid[200][200];
int h, m;

bool is(int i, int j){
	int k[2] = {i/10, i%10};
	int l[2] = {j/10, j%10};

	fr(ct,2){
		if(k[ct] == 3 || k[ct] == 4 || k[ct] == 6 || k[ct] == 7 || k[ct] == 9) return false;
		else if(k[ct] == 2) k[ct] = 5;
		else if(k[ct] == 5) k[ct] = 2;
	}

	fr(ct,2){
		if(l[ct] == 3 || l[ct] == 4 || l[ct] == 6 || l[ct] == 7 || l[ct] == 9) return false;
		else if(l[ct] == 2) l[ct] = 5;
		else if(l[ct] == 5) l[ct] = 2;
	}

	swap(k[0], k[1]); swap(l[0], l[1]);

	if(k[0]*10 + k[1] < m && l[0]*10 + l[1] < h) return true;
	return false;


}
int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		
		cin >> h >> m;
		fr(i,h){
			fr(j,m) valid[i][j] = false;
		}

		fr(i, h){
			fr(j , m){
				if(is(i,j)) valid[i][j] = true;
			}
		}

		//dbg(valid[12][21]);

		int ath, atm;
		char c;
		cin >> ath >> c >> atm;
		
		while(true){
			if(valid[ath][atm]){
				if(ath < 10) cout << 0;
				cout << ath << ':';
				if(atm < 10) cout << 0;
				cout << atm << endl; 
				//cout << ath << ':' << atm << endl;
				break;
			}
			atm++;
			if(atm >= m){
				ath++;
				atm = 0;
			}
			if(ath >= h) ath = 0;	
		}
	}



}
