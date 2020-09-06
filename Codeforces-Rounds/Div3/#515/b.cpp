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

int n,r;
int freq[1123];


bool isvalid(int k){
	if (k >= 0 && k< n)
		return (true);
	return false;

}

void acend(int k){

	int i;
	for (i = k -r;i<=k+r;i++){
		if (isvalid(i))
			freq[i] = 1;
	}
}

int main(){

	fastio;

	cin >> n >> r;
	int v[1123];
	r--;
	
	fr(i,n)
		cin >> v[i];

	bool pos = 0;
	
	fr(i,n){
		pos = 0;
		for (int j = i - r;j<= i + r;j++){
			if (isvalid(j) && v[j] == 1){
				pos = 1;
			}
		}
		if (pos == 0){
			cout << "-1" << endl;
			return (0);
		}
	}

	
	int ct = 0;
	fr(i,n){
		if (freq[i] == 1) continue;
		bool lig = 0;
		for(int j = i+r; j>i;j--){
			if (isvalid(j) && v[j] == 1){
				lig = 1;
				acend(j);
				ct++;
				break;
			}
		}
		if (lig) continue;

		for (int j = i;j>= i - r;j--){
			if (isvalid(j) && v[j] == 1){
				acend(j);
				ct++;
				break;
			}
		}



	}

	cout << ct << endl;





}
