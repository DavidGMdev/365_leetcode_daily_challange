class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> freq;
        int n = tasks.size() , ans = 0 ; 
        for( int i = 0 ; i < n ; i++ ) freq[ tasks[i] ]++;
        for( auto & i : freq ){
            int val = i.second ; 
            if ( val < 2 ) return -1 ;
            else ans += ((val+2)/3);
        }
        return ans ; 
    }
};

/*
#############################
Proof :
#############################


okay , first of all if we have number x 
x can be formed of by this formula a*2 + b*3 where x >= 2 in +ve numbers
regardless it's minimized operation 
if x is even it can be formed of x/2 2's 
if x is odd  it can be formed of (x/2 - 1) 2's and a 3    
so we conclude the -1 case only in case x < 2 else there is a solution 
how to minimize ?
3 is the greatest so let's make it prior and try to divide on it 
using modular arithmatic 
divison by zero have 3 possilbe reminders x%3 = { a , b , c } = { 0 , 1 , 2 }
= where possible reminders of divison by x are [ 0 , x-1 ]
in case reminder 0
= we are good and greedy conquer the number with set of 3's 

in case reminder 1 
= we conquer most of number with 3's but we have a "1" ( we can only take 2 or 3 )
= here we can release one of 3's we take ( -1 operation ) 
= 3 + 1 = 4 that can be done in form of 2 2's ( +2 oepration ) and we have no reminder 
= -1 operation + 2 operation = 1 
[ we need extra one operation to handle ]

in case reminder 2 
= we conquer most of number with 3's but we have a "2" ( we can only take 2 or 3 )
= here we can directly do on opertion by selecting 2 tasks ( +1 operation )
[ we need extra one operation to handle ]

then in case 
basicly we have atleast x/3 oepration to do 
reminders 
0 => we +0 operation 
1 or 2 => we +1 operation

we can sum it up that we get the ceil of divison by three 
ans += ceil(x/3)

*/
