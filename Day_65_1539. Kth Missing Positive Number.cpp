// ##########################################
// direct for loop 
// ##########################################

class Solution {
public:
    
    int findKthPositive(vector<int>& arr, int k) {
        int prev = 0 ; 
        for( int i = 0 ; i < arr.size() ; i++ ) {
            while ( k && arr[i] != prev+1 ) prev++ , k--;
            if (!k) return prev;
            prev = arr[i];
        }
        while(k--) prev++;
        return prev;
    }
};

// ##########################################
// using unordered map & visited 
// ##########################################

class Solution {
public:
    
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,bool> mp;
        for( int i = 0 ; i < arr.size() ; i++ ) mp[arr[i]] = 1 ;
        // make use of small range of numbers and k
        for( int i = 1 ; i <= 2e3 ; i++ ){
            if (!mp[i]){
                k--;
                if (!k) return i ;
            }
        }
        return -1 ; // dummy return
    }
};

