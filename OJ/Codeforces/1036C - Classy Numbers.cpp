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

ll memo_x[20][2][4];
ll memo_y[20][2][4];

long long x,y;

int dig(ll x, int pos){
	fr(i,pos) x = x/10;

	ll y = x%10;
	return y;
}

ll dp_x(int ind,int menor,int non_zero){
	if(ind == -1) return 1;

	ll &pdm = memo_x[ind][menor][non_zero];
	int p = dig(x,ind);

	if(pdm != -1) return pdm;

	if(non_zero == 0){
		if(p > 0)
			pdm = dp_x(ind-1,1,0);
		else
			pdm = dp_x(ind -1,menor,0);

		return pdm;
	}

	if(p > 0)
		pdm = dp_x(ind -1,1,non_zero);
	else{
		pdm = dp_x(ind-1,menor,non_zero);
	}

	if(menor == 0){
		if(p != 0){
			pdm += (p-1)*dp_x(ind-1,1,non_zero - 1);
			pdm += dp_x(ind - 1,menor,non_zero - 1);
		}
	}

	if(menor == 1){
		pdm += 9*dp_x(ind-1,1,non_zero -1);
	}

	return pdm;

}

ll dp_y(int ind,int menor,int non_zero){
	if(ind == -1) return 1;

	ll &pdm = memo_y[ind][menor][non_zero];
	int p = dig(y,ind);

	if(pdm != -1) return pdm;

	if(non_zero == 0){
		if(p > 0)
			pdm = dp_y(ind-1,1,0);
		else
			pdm = dp_y(ind -1,menor,0);

		return pdm;
	}

	if(p > 0)
		pdm = dp_y(ind -1,1,non_zero);
	else{
		pdm = dp_y(ind-1,menor,non_zero);
	}

	if(menor == 0){
		if(p != 0){
			pdm += (p-1)*dp_y(ind-1,1,non_zero - 1);
			pdm += dp_y(ind - 1,menor,non_zero - 1);
		}
	}

	if(menor == 1){
		pdm += 9*dp_y(ind-1,1,non_zero -1);
	}
	
	return pdm;

}

ll solve_x(){
	if(x == 0) return 0;
	if(x == 1) return 1;

	return dp_x(18, 0, 3) - 1;
}

ll solve_y(){
	if(y == 0) return 0;
	if(y == 1) return 1;

	return dp_y(18, 0, 3) -1;
}

int main(){

	fastio;

	int T;
	cin >> T;

	while(T--){
		

		ms(memo_y,-1);
		ms(memo_x,-1);



		cin >> x >> y;
		x--;
		//dbg(solve_y());
		cout << solve_y() - solve_x() << endl;
	}

}
	