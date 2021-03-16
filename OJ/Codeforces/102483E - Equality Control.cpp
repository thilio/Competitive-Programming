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

string s;
vi v[1000100][2];
int ind = 0;
ll var;
int type;

bool is_number(char c){
	return c >= '0' && c <= '9';
}

int get_number(int j){
	var = 0;
	while(is_number(s[j])){
		var *= 10;
		var += s[j] - '0';
		j++;
	}
	return j;
}

int go_shuffle(int i){
	int open = 1;
	vi aux;

	while(open > 0){
		if(s[i] == '('){ 
			i++;
			open++;
		}
		else if(s[i] == ')'){
			open--;
			i++;
		}
		else if(is_number(s[i])){
			i = get_number(i);
			aux.pb(var);
		}
		else{
			i++;
		}
	}
	sort(all(aux));

	if(aux[0] != aux[aux.size() - 1]){ // corner case: Shuffle a list with no distinct elements
		v[ind][type] = aux;
		ind++;
	}
	else{
		for(auto x: aux){
			v[ind][type].pb(x);
			ind++;
		}
	}
	return i;
}

int go_sort(int i){
	int open = 1;
	vi aux;

	while(open > 0){
		if(s[i] == '('){ 
			i++;
			open++;
		}
		else if(s[i] == ')'){
			open--;
			i++;
		}
		else if(is_number(s[i])){
			i = get_number(i);
			aux.pb(var);
		}
		else{
			i++;
		}
	}

	sort(all(aux));
	
	for(auto x: aux){
		v[ind][type].pb(x);
		ind++;
	}
	
	return i;
}

void go(int i){
	if(i == s.size()) return;

	if(s[i] == 'c'){
		go(i + 6);
	}
	else if(s[i] == 's' && s[i + 1] == 'o'){
		go(go_sort(i + 7));
	}
	else if(s[i] == 's' && s[i + 1] == 'h'){
		go(go_shuffle(i + 8));
	}
	else if(is_number(s[i])){
		int r = get_number(i);
		v[ind][type].pb(var);
		ind++;
		go(r);
	}
	else{
		go(i + 1);
	}
}

bool comp(){
	fr(i, 1000100){
		if(v[i][0].size() != v[i][1].size()) return false;
		fr(j, v[i][0].size()){
			if(v[i][0][j] != v[i][1][j]) return false;
		}
	}
	return true;
}

int main(){

	fastio;
	getline(cin,s);
	type = 0;
	ind = 0;
	go(0);

	type = 1;
	ind = 0;
	getline(cin,s);
	go(0);

	if(comp()){
		cout << "equal" << endl;
	}
	else{
		cout << "not equal" << endl;
	}
}
