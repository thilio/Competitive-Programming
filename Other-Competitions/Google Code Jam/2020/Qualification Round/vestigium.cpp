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

int m[110][110];
int g =1;
int n;
int freq[101];

int trace(){
	int sum = 0;
	fr(i,n) sum += m[i][i];
	return sum;
}

int rows(){
	int x = 0;

	frr(i,n) freq[i] = 0;

	fr(i,n){

		fr(j,n){
			freq[m[i][j]]++;
		}

		bool ok = false;

		frr(i,n) if(freq[i] != 1) ok = true;
		if(ok) x++;
		frr(i,n) freq[i] = 0;

	}

	return x;
}

int columns(){
	int x = 0;

	frr(i,n) freq[i] = 0;

	fr(j,n){

		fr(i,n){
			freq[m[i][j]]++;
		}

		bool ok = false;

		frr(i,n) if(freq[i] != 1) ok = true;
		if(ok) x++;
		frr(i,n) freq[i] = 0;

	}
	return x;
}


int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n;
		fr(i,n){
			fr(j,n){
				cin >> m[i][j];
			}
		}

		cout << "Case #" << g++ <<": ";
		cout << trace() << ' ';
		cout << rows() << ' ';
		cout << columns() << endl;


	}

}
