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

int freq[1123456];
int n,k;
bool boo (int a){
	ll sum = 0;
	fr(i,1000000){
		sum += freq[i]/a;
	}
	if(sum >=k) return true;
	return false;
}

int main(){

	fastio;

	
	cin >> n >> k;

	fr(i,n){
		int a;
		cin >> a;
		freq[a]++;
	}

	int ini = 1;
	int fim= n;

	int best;

	while(ini <= fim){
		int mid = (ini + fim)/2;
		if(boo(mid)){
			ini = mid + 1;
			best = mid;
		}
		else{
			fim=mid-1;
		}
	}
	int ct = 0;

	fr(i,1000000){

		int r = freq[i]/best;

		for(int j = 0;j<r && ct != k;j++){
			///olar;
			cout << i << ' ';
			ct++;
		}
	}

	gnl;

}
