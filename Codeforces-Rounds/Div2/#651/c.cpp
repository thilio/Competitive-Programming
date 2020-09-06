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

void FF(){
	cout << "FastestFinger" << endl;
}

void A(){
	cout << "Ashishgup" << endl;
}

bool isp(int n){
	int k = n;
	while(k%2 == 0){
		k/=2;
	}

	if(k == 1) return true;
	return false;
}

bool prime(int k){
	if(k == 1) return false;
	if(k < 4) return true;

	for(int i = 2 ; i*i <= k; i++){
		if(k%i == 0) return false;
	}

	return true;

}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		if(n==1){
			FF();
			continue;
		}
		if(n==2){
			A();
			continue;
		}

		if(n%2){
			A();
			continue;
		}

		if(isp(n)){
			FF();
			continue;
		}

		int i = 0;

		while(n%2 == 0){
			n/=2;
			i++;
		}

		if(i>=2){
			A();
			continue;
		}
		
		if(prime(n)){
			FF();
		}
		else{
			A();
		}
	}

}
