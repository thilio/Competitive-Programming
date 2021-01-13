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

int m[10][10];

int main(){

	fastio;
	int T;
	cin >> T;
	string s;
	getline(cin,s);
	while(T--){

		frr(i,9){
			getline(cin,s);
				frr(j,9){
					m[i][j] = s[j-1] - '0';
				}
			
		}

		m[1][1] = m[2][1];
		m[4][2] = m[5][2];
		m[7][3] = m[8][3];
		m[2][4] = m[3][4];
		m[5][5] = m[6][5];
		m[8][6] = m[9][6];
		m[3][7] = m[4][7];
		m[6][8] = m[7][8];
		m[9][9] = m[1][9];

		frr(i,9){
			frr(j,9){
				cout << m[i][j];
			}
			gnl;
		}


		



	}

}
