class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end(),greater<>());
        int i = 0 , j = n-1 , ans = 0 ;
        for(; i < n && i <= j ; i++){
            ans++;
            if( people[i] + people[j] <= limit ) j-- ;
        }
        return ans;
    }
};
/*
  N.B : ( why current max always paired / aim to be paired with min possible not the largest possible fit ? )
  it can be proved mathimatically that it's valid to take max possible with min possible.
  by intuation , if mx + x <= limit , then it's observable that any y <= mx can use this x too
  and if mx + mn > limit , then max cannot be used at all and no possible fit with it 
 
*/
