
//#############################################
// solution 1 version 3 
//#############################################

class Solution {
public:
    int bkt[2] = {-1,-1} , cnt[2] = {0,0} , lst[2] = {-1,-1};
    int ans = 0 ;
    void set( int &val , int slot ,int &idx ){
        bkt[slot] = val , cnt[slot]++ , lst[slot] = idx;
        return;
    }
    void update( int &val , int &i ){
        if ( bkt[0] == val )         set(val,0,i) ;
        else if ( bkt[1] == val )    set(val,1,i) ;
        else if ( bkt[0] == -1 )     set(val,0,i) ;
        else if ( bkt[1] == -1 )     set(val,1,i) ;
        else {
            ans = max( ans , cnt[0]+cnt[1] ) ;
            if ( lst[0] < lst[1] ){
                cnt[1] = i - lst[0] - 1;
                cnt[0] = 0 ;  
                set(val,0,i) ;
            }
            else {
                cnt[0] = i - lst[1] - 1 ; 
                cnt[1] = 0 ; 
                set(val,1,i) ;
            }
        }
    }
    int totalFruit(vector<int>& arr) {
       int n = arr.size(); 
       for( int i = 0 ; i < n; i++ ) update(arr[i],i);
       return max( ans , cnt[0]+cnt[1] ) ;
    }
};

//#############################################
// solution 1 version 2 
//#############################################

class Solution {
public:
    int bkt[2] = {-1,-1} , cnt[2] = {0,0} , lst[2] = {-1,-1};
    void update( int val , int slot ,int idx ){
        bkt[slot] = val , cnt[slot]++ , lst[slot] = idx;
        return;
    }
    int totalFruit(vector<int>& arr) {
       int n = arr.size() , ans = 0; 
       for( int i = 0 ; i < n; i++ ){
           if ( bkt[0] == arr[i] )      update(arr[i],0,i) ;
           else if ( bkt[1] == arr[i] ) update(arr[i],1,i) ;
           else if ( bkt[0] == -1 )     update(arr[i],0,i) ;
           else if ( bkt[1] == -1 )     update(arr[i],1,i) ;
           else {
               ans = max( ans , cnt[0]+cnt[1] ) ;
               if ( lst[0] < lst[1] ){
                   cnt[1] = i - lst[0] - 1;
                   cnt[0] = 0 ;  
                   update(arr[i],0,i) ;
               }
               else {
                   cnt[0] = i - lst[1] - 1 ; 
                   cnt[1] = 0 ; 
                   update(arr[i],1,i) ;
               }
           }
       }
       return max( ans , cnt[0]+cnt[1] ) ;
    }
};

//#############################################
// solution 1 version 1 
//#############################################

class Solution {
public:
    int totalFruit(vector<int>& arr) {
       int n = arr.size() , ans = 0; 
       int bkt[2] = {-1,-1} , cnt[2] = {0,0} , lst[2] = {-1,-1};
       for( int i = 0 ; i < n; i++ ){
           if( bkt[0] == arr[i] ) {
               cnt[0]++;
               lst[0] = i; 
           }
           else if( bkt[1] == arr[i] ) {
               cnt[1]++;
               lst[1] = i; 
           }
           else if ( bkt[0] == -1 ) {
               bkt[0] = arr[i];
               cnt[0] = 1;
               lst[0] = i;
           }
           else if ( bkt[1] == -1 ) {
               bkt[1] = arr[i];
               cnt[1] = 1;
               lst[1] = i;
           }
           else {
               ans = max( ans , cnt[0]+cnt[1] ) ;
               if ( lst[0] < lst[1] ){
                   cnt[1] = i - lst[0] - 1 ; 
                   bkt[0] = arr[i];
                   cnt[0] = 1;
                   lst[0] = i;
               }
               else {
                   cnt[0] = i - lst[1] - 1 ; 
                   bkt[1] = arr[i];
                   cnt[1] = 1;
                   lst[1] = i;
               }
           }
       }
       return max( ans , cnt[0]+cnt[1] ) ;
    }
};


