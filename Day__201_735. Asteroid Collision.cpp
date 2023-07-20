class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        int n = asteroids.size() ;
        for( int i = 0 ; i < n ; i++ ){
            bool flg = 1; // to mark at end set the current asteroid or it's destroyed  [ deafult to add if nothing changes ]

            // the destroy behaviour happens only in case having asteroids in order :: (+) (-) , else there is no effect 
            while( !res.empty() && res.back() > 0 && asteroids[i] < 0 ){
              
                // the right destroys the left one 
                if( abs(res.back()) < abs(asteroids[i]) ){
                    res.pop_back(); // remove it 
                    flg = 1; // we shall add this current if we end here 
                }
                  
                // they will destroy each other
                else if ( abs(res.back()) == abs(asteroids[i]) ){
                    res.pop_back();
                    flg = 0; // we shall not add it 
                    break; // no need to continue ( as it assumes the left side is a calculated one if the current destroyed )
                }
                  
                // the left one will destroy the current 
                else {
                    flg = 0; // we shall not add it 
                    break; // no need to continue ( as the prev assume left is done )  and ( there is no more on the right yet )
                }
              
            }
            if (flg) res.push_back(asteroids[i]); // just add it in this case
        }
        return res;
    }
};
