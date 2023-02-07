
/*

------------------------
solution intuition :::::
------------------------


bkt[] : represent the basket we have of size two , distinct elements [ fruits ]
cnt[] : represent the frequancy of elements [ fruits ] which currently exist in basket
lst[] : represent the lst index from which this element visited [ collected ] 

on traversing the array of fruits we do the following : 
- pick the element and continue 
- don't pick the element and stop 

when to pick ?
= as long as no obstacle to pick 
= obstacle to pick is the backet is fully used [ has two distinct elements ]
= on having basket full we will sacrify one of the elements [ fruits we have currently ]

= greedly :
    - we sacrify the element of lRU [ least recently updated ] 
        = we keep track this using lst[] array , lst[x] < lst[y] then, x is the LRU and we will delete it and use it's backet space to set the new element type 
        
    - on doing this we update the frequancy of the unsacrified element 
        = to avoid the fake frequancy which overlapped with the scarified elements positions 
        = we set the new freuancy of unsacrified element to ( prev_idx - lst[ sacrified element ] )
        = since previous element gurannted that it's an unsacrified element 
        = since gurannted that this window  [ lst[ sacrified element ] + 1 , prev_idx ] , inclusive has unsacrified elments [ peigonhole principle ]
        
    - set the new element in place of sacrified element and continue iterate 
    

and that's it 

*/

//#############################################
// solution 1 version 3 
//#############################################

class Solution {
public:
    int bkt[2] = {-1,-1} , cnt[2] = {0,0} , lst[2] = {-1,-1};
    int ans = 0 ;
    void update( int &val , int slot ,int &idx ){
        bkt[slot] = val , cnt[slot]++ , lst[slot] = idx;
        return;
    }
    void set( int &val , int &i ){
        if ( bkt[0] == val )         update(val,0,i) ;
        else if ( bkt[1] == val )    update(val,1,i) ;
        else if ( bkt[0] == -1 )     update(val,0,i) ;
        else if ( bkt[1] == -1 )     update(val,1,i) ;
        else {
            ans = max( ans , cnt[0]+cnt[1] ) ;
            if ( lst[0] < lst[1] ){
                cnt[1] = i - lst[0] - 1;
                cnt[0] = 0 ;  
                update(val,0,i) ;
            }
            else {
                cnt[0] = i - lst[1] - 1 ; 
                cnt[1] = 0 ; 
                update(val,1,i) ;
            }
        }
    }
    int totalFruit(vector<int>& arr) {
       int n = arr.size(); 
       for( int i = 0 ; i < n; i++ ) set(arr[i],i);
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


