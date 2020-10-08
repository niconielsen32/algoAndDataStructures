/*
* Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
*       Example:-   $ g++ -std=c++11 c++Template.cpp
*/
 
/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip> 
#include <unordered_map>
using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(n) for (int i=0 ; i<n ; i++)
#define FOR2(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
#define ar array
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef unordered_map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

/****** Template of some basic operations *****/
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
/**********************************************/

/****** Template of Fast I/O Methods *********/
template <typename T> inline void write(T x)
{
	int i = 20;
	char buf[21];
	// buf[10] = 0;
	buf[20] = '\n';

	do
	{
		buf[--i] = x % 10 + '0';
		x/= 10;
	}while(x);
	do
	{
		putchar(buf[i]);
	} while (buf[i++] != '\n');
}

template <typename T> inline T readInt()
{
	T n=0,s=1;
	char p=getchar();
	if(p=='-')
		s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-')
		p=getchar();
	if(p=='-')
		s=-1,p=getchar();
	while(p>='0'&&p<='9') {
		n = (n<< 3) + (n<< 1) + (p - '0');
		p=getchar();
	}

	return n*s;
}


/**************************************/

/******** User-defined Function *******/


bool areAnagrams(string first, string second){

	sort(first.begin(), first.end());
	sort(second.begin(), second.end());

	if(first == second){
		return true;
	}

	return false;
}

// quadratic time complexity
VI twoSumNumbers(VI nums, int targetSum){
	FOR2(i, 0, nums.size(), 1){
		FOR2(j, i+1, nums.size(), 1){
			if(nums[j] == targetSum - nums[i]) return {nums[i], nums[j]};
		}
	}
	return {0,0};
}

//Linear time complexity
VI twoSumNumLinear(VI nums, int target){

	unordered_map<int,int> map;

	FOR(nums.size()){
		int temp = target - nums[i];
		if(map.find(temp) != map.end() && map.find(temp)->second != i){

			int tempIndex = map.find(temp)->second;

            return {nums[tempIndex], nums[i]};
		}

		map.insert(pair<int,int>(nums[i],i));
	}
	return {0,0};
}


void solve(){

	int n,k;
	cin >> n;
	vector<int> arr;
	FOR(n){
		int temp;
		cin >> temp;
		arr.PB(temp);
	}

	double pos = 0, neg = 0, zero = 0;
	FOR(n){
		if(arr[i] == 0) zero += 1;
		else if(arr[i] > 0) pos += 1;
		else neg += 1;
	}

	cout << setprecision(6);

	cout << fixed << pos/n << endl;
	cout << fixed << neg/n << endl;
	cout << fixed << zero/n << endl;
	
}

/**************************************/


/********** Main()  function **********/
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); 

   
   	#ifndef ONLINE_JUDGE 
   	freopen("input.txt", "r", stdin); 
   	freopen("error.txt", "w", stderr); 
   	freopen("output.txt", "w", stdout); 
   	#endif 
   
   	int n,k;
	cin >> n;
	vector<int> arr;
	FOR(n){
		int temp;
		cin >> temp;
		arr.PB(temp);
	}

	VI twoSum = twoSumNumLinear(arr, n);
	FOR(2){
		cout << twoSum[i] << " ";
	}

	/*VI twoSum = twoSumNumbers(arr, n);
	FOR(2){
		cout << twoSum[i] << " ";
	}*/

   	//cout << areAnagrams("shaaale", "leaaash") << endl;

   	/*int t;
   	cin >> t; 

   	FOR(t){
      cout<<"Case #" << i << ": ";
      solve(); 
      cout << endl;
   	} */
   

   	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0;
}
/********  Main() Ends Here *************/