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

int v[200200];
int w[200200];
int n;
int p[200200];

int mnpar[200200];
int mnimp[200200];

bool tent(){

	for(int i = 1; i <= n - 1; i++){
		w[i] -= w[i - 1];
		if(w[i] < 0) return false;
	}
	if(w[n - 1] == 0) return true;
	return false;

	
} 

void reset(){
	fr(i,n) w[i] = v[i];
}

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		
		cin >> n;
		fr(i,n){
			cin >> v[i];
		}
		reset();

		if(n == 1){
			cout << "NO" << endl;
			continue;
		}
		if(n == 2){
			if(v[0] == v[1]){
				cout << "YES" << endl;
			}
			else{
				cout << "NO" << endl;
 			}
 			continue;
		}

		reset();
		if(tent()){
			cout << "YES" << endl;
			continue;
		}
		reset();

		p[0] = v[0];
		for(int i = 1; i < n; i++){
			w[i] -= w[i - 1];
			p[i] = w[i];
		}
	//	fr(i,n) dbg(p[i]); 
		int delta = w[n - 1];


		if((n - 1)%2 == 0){
			mnpar[n - 1] = p[n-1];
			mnimp[n - 2] = p[n-2];
		}
		else{
			mnpar[n - 2] = p[n - 2];
			mnimp[n - 1] = p[n - 1]; 
		}

		for(int j = n - 3; j>= 0; j--){
			if(j%2 == 0) mnpar[j] = min(p[j],mnpar[j + 2]);
			if(j%2 == 1) mnimp[j] = min(p[j],mnimp[j + 2]);
		}

		bool ok = false;

		for(int i = 0; i < n - 1; i++){
			if(i > 0 && p[i - 1] < 0 && ok == false) break;
			if(i > 0 && v[i + 1] < p[i - 1]) continue;
			if(i > 0 && v[i] < v[i + 1] - p[i - 1]) continue;
			if(i == 0 && v[i] < v[i + 1]) continue;
			if(i%2 == 0){
				int par = 2*(-v[i] + v[i + 1]);
				int imp = -par;

				if((n - 1)%2 == 0 && delta + par != 0) continue;
				if((n - 1)%2 != 0 && delta + imp != 0) continue;

				if(i + 2 < n && mnpar[i + 2] + par < 0) continue;
				if(i + 3 < n && mnimp[i + 3] + imp < 0) continue;
				//olar;
				ok = true;
			}
			if(i%2 == 1){
				int imp = 2*(-v[i] + v[i + 1]);
				int par = -imp;
				if((n - 1)%2 == 0 && delta + par != 0) continue;
				if((n - 1)%2 != 0 && delta + imp != 0) continue;

				if(i + 2 < n && mnimp[i + 2] + imp < 0) continue;
				if(i + 3 < n && mnpar[i + 3] + par < 0) continue;

				ok = true;

			}
		}

		if(ok){
			cout << "YES" << endl;
		}	
		else{
			cout << "NO" << endl;
		}
	}

}
