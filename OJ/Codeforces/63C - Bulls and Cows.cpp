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

int num[10000][4];

bool pos[10000];
int bull,cow;


int dig(int x, int pos){
	fr(i,pos) x = x/10;

	int y = x%10;
	return y;
}

bool check(int x,int j){

	vi aa;
	fr(k,4){
		aa.pb(num[j][k]);
	}

	sort(all(aa));

	if(aa[0] == aa[1] || aa[1] == aa[2] || aa[2] == aa[3]) return false;

	int match = 0;

	fr(k,4){
		int p = dig(x,k);
		if(p == aa[0] || p == aa[1] ||p == aa[2] || p == aa[3]) match++;
	}

	int b = 0;

	fr(k,4){
		if(dig(x,k) == num[j][k]) b++;
	}

	if(b == bull && (bull + cow == match)) return true;

	return false;


}


int main(){

	fastio;

	fr(i,10000){
		int j = i;
		fr(k,4){
			num[i][k] =j%10;
			j/=10; 
		}
	}
	int n;
	cin >> n;

	ms(pos,true);

	fr(i,n){
		int x;
		cin >> x;
		cin >> bull >> cow;
		fr(j,10000){
			if(!check(x,j)){
				pos[j] = false;
			}
		}
	}

	int ans = 0;
	int k;

	fr(i,10000){
		if(pos[i]){
			ans++;
			k = i;
		}
	}

	if(ans >=  2){
		cout << "Need more data" << endl;
	}
	if(ans == 0){
		cout << "Incorrect data" << endl;
	}

	if(ans == 1){
		vi ab;
		fr(l,4) ab.pb(dig(k,l));
		reverse(all(ab));
		fr(l,4) cout << ab[l];
		gnl;
	}



}
