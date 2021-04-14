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

	queue<pii> par, impar;

	int n;
	cin >> n;

	frr(i, n){
		frr(j, n){
			if((i + j)%2) impar.push({i, j});
			else par.push({i, j});
		}
	}

	frr(k, n*n){
		int c;
		cin >> c;
		if(impar.empty()){
			int i, j;
			tie(i, j)=  par.front();
			par.pop();
			if(c == 2){
				cout << 3 << ' ' << i << ' ' << j << endl;
			}
			else{
				cout << 2 << ' ' << i << ' ' << j << endl;
			}
			continue;
		}
		if(par.empty()){
			int i, j;
			tie(i, j) = impar.front();
			impar.pop();
			if(c == 1){
				cout << 3 << ' ' << i << ' ' << j << endl;
			}
			else{
				cout << 1 << ' ' << i << ' ' << j << endl;
			}
			continue;
		}

		if(c == 1){
			int i, j;
			tie(i, j) = par.front();
			par.pop();
			cout << 2 << ' ' << i << ' ' << j << endl;
		}
		else{
			int i, j;
			tie(i, j) = impar.front();
			impar.pop();
			cout << 1 << ' ' << i << ' ' << j << endl;
		}
	}

}
