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


int vx[3];
int vy[3];
int vz[3];
int oo[3];

int a[1010][1010];
int b[1010][1010];

int n;
int m;

void reset(){
	ms(vx, 0);
	ms(vy, 0);
	ms(vz, 0);
	ms(oo, 0);
	vx[0] = 1;
	vy[1] = 1;
	vz[2] = 1;
}


int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		reset();

		cin >> n >> m;
		fr(i, n){
			fr(j, n){
				cin >> a[i][j];
				a[i][j]--;
			}
		}

		string s;
		cin >> s;

		fr(i, m){
			if(s[i] == 'R'){
				oo[1]++;
			}
			if(s[i] == 'L'){
				oo[1]--;
			}
			if(s[i] == 'D'){
				oo[0]++;
			}
			if(s[i] == 'U'){
				oo[0]--;
			}
			if(s[i] == 'I'){
				swap(vx[1], vx[2]);
				swap(vy[1], vy[2]);
				swap(vz[1], vz[2]);
				swap(oo[1], oo[2]);
			}
			if(s[i] == 'C'){
				swap(vx[0], vx[2]);
				swap(vy[0], vy[2]);
				swap(vz[0], vz[2]);
				swap(oo[0], oo[2]);
			}
		}

		fr(i, n){
			fr(j, n){
				int vetor[3] = {0, 0, 0};
				fr(k, 3){
					vetor[k] += oo[k];
				}
				fr(k, 3){
					vetor[k] += i*vx[k];
				}
				fr(k, 3){
					vetor[k] += j*vy[k];
				}
				fr(k, 3){
					vetor[k] += a[i][j]*vz[k];
				}
				b[(vetor[0] + m*n + n)%n][(vetor[1] + m*n + n)%n] = (vetor[2] + m*n + n)%n;
			}
		}

		fr(i, n){
			fr(j,n){
				cout << b[i][j] + 1<< ' ';
			}
			gnl;
		}

	}

}
