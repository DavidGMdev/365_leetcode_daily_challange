class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0 ; 
        for( int i = 0 ; i < 32 ; i++ ){
            int ai = (a >> i) & 1 , bi = (b >> i) & 1 , ci = (c >> i) & 1; // bits extraction
            if( (ai || bi) == ci ) continue; // best case , no need to fix 
            else if(ci) ans++; // if the target is just 1 , and not satsfied this implies that both ai and bi are zeros since their or is zero , so just flip one of them 
            else if(ai == bi) ans+=2; // if the target is not 1 , then it's zero , and if both ai , bi are equal then they are ones and we need to flip both of them 
            else ans++; // if not equal then we have one and zero , and we need to just flip this one 
        }
        return ans;
    }
};
