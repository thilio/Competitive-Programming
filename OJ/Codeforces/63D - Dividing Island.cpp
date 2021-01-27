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


int a,b,c,d,n;
int v[100];
char m[100][100];

void start(int y,int x,int up){
	cout << "YES" << endl;

	int col = a + c;
	int lin = max(b,d);
	//dbg(col);
	//dbg(lin);
	int j = 0;


	if(x == 1){
		while(x <= col){
			if(up){
				for(int k = lin;k >= 1;k--){
					if(x <= a && k > b)
						m[k][x] = '.';
					else{
						if(v[j] == 0) j++;
						m[k][x] = j + 'a';
						v[j]--;
					}
				}
				up = 0;

			}
			else{
				for(int k = 1;k <= lin;k++){
					if(x <= a && k > b)
						m[k][x] = '.';
					else{
						if(v[j] == 0) j++;
						m[k][x] = j + 'a';
						v[j]--;
					}
				}
				up = 1;
			}
			x++;
		}
	}

	else{
		while(x >= 1){
			if(up){
				for(int k = lin;k >= 1;k--){
					if(x > a && k > d)
						m[k][x] = '.';
					else{
						if(v[j] == 0) j++;
						m[k][x] = j + 'a';
						v[j]--;
					}
				}
				up = 0;

			}
			else{
				for(int k = 1;k <= lin;k++){
					if(x > a && k > d)
						m[k][x] = '.';
					else{
						if(v[j] == 0) j++;
						m[k][x] = j + 'a';
						v[j]--;
					}
				}
				up = 1;
			}
			x--;
		}

	}

	
	frr(i,lin){
		frr(l,col){
			cout << m[i][l];
		}
		gnl;
	}
}

int main(){

	fastio;

	cin >> a >> b >> c >>d >> n;
	fr(i,n) cin >> v[i];

	

	if(b >= d){
		if(c%2){
			start(max(b,d),a+c,1);
		}
		else start(1,a+c,0);
	}

	else{
		if(a%2) start(max(d,b),1,1);
		else start(1,1,0);
	}



}
