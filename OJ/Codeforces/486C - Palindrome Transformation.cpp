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

int n,p;
string s;

bool wrong[100100];

int dist_letter(char a,char b){
	if(b < a) swap(a,b);

	int ans1 = b - a;
	int ans2 = ('z' - b) + (a -'a') + 1;

	return min(ans1,ans2);
}
int main(){

	fastio;
	cin >> n >> p;
	getline(cin,s);
	getline(cin,s);

	string t;
	t.pb('0');
	frr(i,n) t.pb(s[i-1]);

	int ans = 0;

	frr(i,n/2){
		if(t[i] != t[n - i + 1]){
			wrong[i] = true;
			wrong[n+1 - i] = true;
			ans += dist_letter(t[i],t[n+1-i]);
		}
	}

	if(p == (n+1)/2){
		int j = -1;
		frr(i,n){
			if(wrong[i] == true){
				j = i;
				break;
			}
		}
		if(j == -1){
			cout << ans << endl;
		}
		else{
			cout << ans + (p - j) << endl;
		}
	}

	else if(p < (n+1)/2){
		int j = -1;
		frr(i,n){
			if(wrong[i] == true){
				j = i;
				break;
			}
		}
		int k = -1;
		for(int i = (n+1)/2; i > 0; i--){
			if(wrong[i] == true){
				k = i;
				break;
			}
		}


		if(j == -1) cout << ans << endl;
		else{
			if(p <= j){
				ans += k - p;
			}
			else if(p >= k){
				ans += p - j;
			}
			else{
				ans += k - j;
				ans += min(k-p,p-j);
			}

			cout << ans << endl;
		}

	}

	else if(p > (n+1)/2){
		int j = -1;
		for(int i = (n/2) + 1; i <= n;i++){
			if(wrong[i] == true){
				j = i;
				break;
			}
		}
		int k = -1;
		for(int i = n; i > (n+1)/2; i--){
			if(wrong[i] == true){
				k = i;
				break;
			}
		}

		if(j == -1) cout << ans << endl;
		else{
			if(p <= j){
				ans += k - p;
			}
			else if(p >= k){
				ans += p - j;
			}
			else{
				ans += k - j;
				ans += min(k-p,p-j);
			}

			cout << ans << endl;
		}

	}





}
