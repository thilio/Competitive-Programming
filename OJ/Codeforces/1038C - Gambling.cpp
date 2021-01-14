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
#define LAU cout << "LAW" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
int A[112345],B[112345];
int main(){
	int n;
	cin >> n;
	fr(i,n){
		cin >> A[i];
	}
	fr(i,n){
		cin >> B[i];
	}
	sort (A,A+n);
	sort (B,B+n);

	int na,nb;
	na = nb = n;
	long long sum = 0;
	int vez = 0;
	while (na != 0 || nb != 0){
		if (!vez){
			if (nb == 0){
				sum += A[na - 1];
				na--;
				
			}
			else if (na == 0){
				nb--;
				
			}
			else if (B[nb - 1] > A[na - 1]){
				nb--;
				
			}
			else if (A[na - 1] >= B[nb - 1]){
				sum+= A[na - 1];
				na--;
				
			}

		}
		else{
			if (nb == 0){
				na--;
				
			}
			else if (na == 0){
				sum -= B[nb - 1];
				nb--;
				
			}
			else if (B[nb - 1] > A[na - 1]){
				sum -= B[nb - 1]; 
				nb--;
				
			}
			else if (A[na - 1] >= B[nb - 1]){
				na--;
				
			}

		}
		vez++;
		vez = vez%2;

	}

	cout << sum << endl;

	return (0);
}