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

int ans[110];
int par[110];
int feq;
int fdif;
int B;


int main(){

	fastio;

	int T;
	cin >>T>>B;
	while(T--){
		feq=fdif=-1;

		for(int j = 1; j <= B/2 ;){
			int k = 0;
			if(j != 1){
				if(feq != -1){
					k++;
					int a;
					cout << feq << endl;
					cin >> a;
					if(a != ans[feq]){
						for(int r = 1;r <= B/2;r++){
							if(par[r] == 1){
								ans[r] = 1 - ans[r];
								ans[B + 1 - r] = 1 - ans[B + 1 -r];	
							} 
						}
					}
				}
				if(fdif != -1){
					k++;
					int a;
					cout << fdif << endl;
					cin >> a;
					if(a != ans[fdif]){
						for(int r = 1;r <= B/2;r++){
							if(par[r] == 0){
								ans[r] = 1 - ans[r];
								ans[B + 1 - r] = 1 - ans[B + 1 -r];	
							}
						}
					}

				}
				if (k == 1){
					cout << '1' << endl;
					int bb;
					cin >> bb;
					k++;
				}

			}
			int l = 0;
			for(int i = 0; k < 10; i++){
				cout << i + j << endl;
				cin >> ans[i+j];
				cout << B + 1 - i -j << endl;
				cin >> ans[B + 1 - i - j];

				if(ans[i+j] == ans[B + 1 - i - j]){
					par[i+j] = 1;
					if(feq == -1) feq = i + j;
				}

				if(ans[i+j] != ans[B + 1 - i - j]){
					par[i+j] = 0;
					if(fdif == -1) fdif = i + j;
				}

				k+=2;
				l++;
			}
			j+=l;
		}

		string s;
		frr(i,B){
			if(ans[i]) s.pb('1');
			else s.pb('0');
		}

		cout << s << endl;

		char x;
		cin >> x;


	}

}
