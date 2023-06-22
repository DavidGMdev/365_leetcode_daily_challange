class Solution {
public:
    // Transaction here is not clear in statement 
    // Transactions means complete cycle of both buy and sell , buy + sell = 1 transaction 
    // the fees is taken either during buy or during selling ( one time only not during both ) <= take care 
    int rec( int i , int state , vector<int>& prices , int fees , vector<vector<int>>& memo ){
        if( i >= prices.size() ) return 0;
        if( memo[i][state] != -1 ){
            return memo[i][state];
        }
        int ret = 0 ; 
        if(!state){ // don't have a stock 
            ret = max( rec(i+1,state,prices,fees,memo) , (rec(i+1,state^1,prices,fees,memo) - prices[i]) ); // stay neutral or buy a stock
        }
        else { // already have a stock 
            ret = max( rec(i+1,state,prices,fees,memo) , (rec(i+1,state^1,prices,fees,memo) + prices[i]) - fees); // stay having stock or sell it 
        }
        return memo[i][state] = ret ;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>memo( prices.size() , vector<int>(2,-1)); // Nx2 memo [ as states are binary either have stock or not ]
        return rec(0,0,prices,fee,memo);
    }
};
