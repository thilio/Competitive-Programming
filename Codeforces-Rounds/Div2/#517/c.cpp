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

int main(){

	fastio;
	int a,b;
	cin >> a >> b;

	vi ans;

	if (b == 0){
		ll sum = 0;

		frr(j,112345){
			sum+=j;
			if (sum<=a)
				ans.pb(j);
			if (sum > a)
				break;
		}
		cout << ans.size() <<endl;
		fr(j,ans.size())
			cout <<ans[j] <<endl;
		cout << 0 <<endl;
		return(0);
	}

	if (a == 0){
		ll sum = 0;

		frr(j,112345){
			sum+=j;
			if (sum<=b)
				ans.pb(j);
			if (sum > b)
				break;
		}
		cout << 0 <<endl;
		cout << ans.size() <<endl;
		fr(j,ans.size())
			cout <<ans[j] <<endl;

		return(0);
	}



	ll i = 1;
	while((i*(i+1))/2 <= a + b) i++;
	i--;

	//olar;
	ll sum = 0;
	int aux;

	while(a>=i && i>0){
		ans.pb(i);
		a-=i;
		i--;
	}
	if(i == 0){
		cout << ans.size() <<endl;
		fr(j,ans.size())
			cout << ans[j] << endl;
		cout <<'0' << endl;
		return(0);
	}

	if(a == 0){
		cout << ans.size() << endl;
		fr(j,ans.size())
			cout << ans[j]<<endl;

		cout << i <<endl;
		frr(j,i)
			cout << j << endl;
	}
	else{
		aux = a;
		cout << ans.size() + 1<<endl;
		fr(j,ans.size())
			cout << ans[j]<<endl;
		cout << aux <<endl;

		cout<<max(i-1,0ll)<<endl;
		frr(j,i)
			if(j!=aux) cout << j <<endl;
	}


}
