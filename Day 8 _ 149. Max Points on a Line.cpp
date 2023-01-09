// ########################################################################
// Solution 1 : using numerator and denomurator instead of double solpes
// ########################################################################

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
       const int OO = 0x3f3f3f3f ;
       int n = points.size() , ans = 0 ;
       for( int i = 0 ; i < n ; i++ ) {

           // at each point asumme this is our source
           // count all other points you can reach in linear form and it's slope 
           // same slopes means same line 
           // describe slope as num and deno to avoid diffrent percesions on mapping doubles ( incase :) )
           map<pair<int,int>,int>mp;
           for( int j = i+1 ; j < n ; j++ ){
               int nemo , deno ;
               nemo = points[i][1] - points[j][1] ; // y2 - y1 
               deno = points[i][0] - points[j][0] ; // x2 - x1 
               if (!deno) nemo = deno = OO ; // same x-axis

               // simplify numerator and denominator 
               else {
                    
                    int g = __gcd(nemo,deno) ; 
                    nemo /= g , deno/= g ; 
               }

               // in case negativity , keep it all for numerator 
               if ( deno < 0 ) { 
                   nemo = -nemo ; 
                   deno = -deno ; 
               }
               
               // count this used slope 
               // accessing n points using same slopes means this form a line of n+1 points ( n reached , 1 is the source setted )
               mp[{nemo,deno}]++;     


               ans = max ( ans , mp[{nemo,deno}] ) ; 
           }
       }
       return ans+1 ; 
    }
};


// ##################################################################################################################
// Solution 2 : same solution but with clean code way ( Point , Slope ) classes useful for more complex problems
// ##################################################################################################################

class Solution {
public:
    static const int OO = 0x3f3f3f3f ;
    class Point {
        public :
            int x , y ; 
            Point(){
                x = y = OO ; 
            }
            Point( int a , int b ) {
                x = a ; 
                y = b ; 
            }
    };
  
    class Slope{
        private : 
        void generalize() {
            if (!denominator) {
                numerator = denominator = OO ;
            }
            else {
                int g = __gcd(numerator,denominator) ; 
                numerator /= g , denominator/= g ; 
            }
            if ( denominator < 0 ) { 
                numerator = -numerator ; 
                denominator = -denominator ; 
            }
        }
        public:
            int numerator , denominator ;
            Slope(){ 
                numerator = denominator = OO ;
            }
            Slope( Point a , Point b ){
               numerator   = a.y - b.y ;
               denominator = a.x - b.x ;
               generalize() ;
            }
            // as sorting of pairs in order to be able to map this class to value [ use as a key ]
            bool operator == ( const Slope & slope ) const {
                return ( this->numerator == slope.numerator && this->denominator == slope.denominator ); 
            }
            bool operator < ( const Slope & slope ) const {
                return (  this->numerator < slope.numerator || ( this->numerator == slope.numerator && this->denominator < slope.denominator )); 
            }
    };

    int maxPoints(vector<vector<int>>& points) {
       int n = points.size() , ans = 0 ;
       for( int i = 0 ; i < n ; i++ ) {
           map<Slope,int>mp;
           for( int j = i+1 ; j < n ; j++ ){
               Slope slope( Point(points[i][0],points[i][1]) , Point(points[j][0],points[j][1]) ) ;
               mp[slope]++;     
               ans = max ( ans , mp[slope] ) ; 
           }
       }
       return ans+1 ; 
    }
  
};

// ####################################################################################################################################################
// Solution 3 : just use map of doubles and no way of diffrent percesions , cuz ( int - int ) / ( int - int ) = int/int = same division evey time 
// #####################################################################################################################################################

// and that's it <3
