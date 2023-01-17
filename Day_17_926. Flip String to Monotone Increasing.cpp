/*
// #######################################
// explainig the idea main concept 
// #######################################


= greedy approach 

using prefix sum 

consider all possbile valid ways of constructing a "monotonic" string as mentioned 
only there is 3 possbile ways todo that 
= { all zeros , all ones , zeros followed by ones }
= 0....     [ 1 unique form ]
= 1....     [ 1 unique form ]
= 0....1... [ n-2 unique forms ]
= totally are n+1 unique solution  

for example of size 5 we have those unique ways 
abcde
11111
01111
00111
00011
00001
00000

all zeros = { 00000 }
all ones  = { 11111 } 
mix = { 01111 , 00111 , 00011 , 00001 }

we can imagine this way as a moving pointer from left to right in range [ -1 , n-1 ]
on each index all behind idx and idx itself [ are all covered with zeros ]
while what's after idx untill end           [ are all coverd with ones ]

at every idx [ -1 , n-1 ] we do :
( 0 , idx )       [ all must be zeros ]
( idx + 1 , n-1 ) [ all must be ones  ]

we introduce idea of using prefix 
to be able to access/know the number of zeros and ones in a given fixed range 

then the solution :

just start at index 0 and go until index n-1 
at each step of this loop we calclate the COST of this form to convert "based on the given criteria" [ flipping bits ]
the cost is the number of bits needed to be flipped either 0 -> 1 or 1 -> 0 according to current state 

cost = bits needed to be flipped to zero + bits needed to be flipped to one
we minimize on this cost and this is our answer 

bits needed to be flipped to zero ?
we calcuate the number of ones in the range [ 0 , idx ]
and this is actually our cost [ those ones needed to be converted to zeros ]
= directly calculated from one's prefix sum 


bits needed to be flipped to one ?
we calcuate the number of zeros in the range [ idx + 1 , n-1 ]
and this is actually our cost [ those zeros needed to be converted to ones ]
= (in)directly calculated from one's prefix sum
= if we have the sum of ones in this range 
= the sum of zeros is just it's complement 
=> complement defined as = size of the range - freq of item 


Just go and minimize on cost , and that's it 


N.B [ for calculating count in given ranges ]

we can make 2 prefixes one for zero and another of one 
but here we use only one prefix and conclude the other from it 
building on having only { 0 , 1 } values then 
using pigeonhole principle ::: 
size of ones in range is the complement of zeros size and vice versea 
range of size m ?
have x ones , then MUST have m-x zeros and that's it 



*/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int pre[n];
        for( int i = 0 ; i < n ; i++){
            int val = ( s[i] == '1' ? 1 : 0 ) ; 
            if (!i) pre[i] = val;
            else pre[i] = pre[i-1] + val; 
        }
        
        // init here with the case of idx -1 , of all are ones 111....
        int idx = -1 , mn = n - pre[n-1] ; 
        
        for ( int i = 0 ; i < n ; i++ ) {
            int preOnes , postOnes , convertToZeros , convertToOnes , cost ;
            
            // [ 0 , idx ] get all ones ( pre-ones before and in the index )
            preOnes = pre[i]; 
            
            // [ idx + 1 , n-1 ] get all ones ( post-ones after the index )
            postOnes = pre[n-1] - pre[i]; 
            
            // those must be converted to zeros [ all ones behind idx and idx must converted to zero ]
            convertToZeros = preOnes ;
            
            // those must be converted to ones [ all zeros after idx must converted to ones ]
            convertToOnes = (n-(i+1)) - postOnes ; // pigeonhole principle
            
            // convert to zero + convert to ones 
            cost = ( convertToZeros + convertToOnes );
            
            // just minimize
            if ( cost < mn ) idx = i , mn = cost ;
        }
        return mn; 
    }
};
