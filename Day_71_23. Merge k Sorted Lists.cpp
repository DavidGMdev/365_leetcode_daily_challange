/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        for( auto &ls : lists ){
            while(ls != NULL){
                v.push_back(ls->val);
                ls = ls->next;
            }
        }
        sort(v.begin(),v.end());
        ListNode *ans = NULL , *curr = ans;
        for( int i = 0 ; i < v.size() ; i++ ){
            ListNode *nxt =  new ListNode(v[i]);
            if(!i){
                ans = nxt  ;
                curr = ans ;
            }
            else {
                curr->next = nxt;
                curr = curr->next;
            }
        }
        return ans;
    }
};
