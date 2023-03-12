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
    static const int N = 1e4 ;
    int n = 0 ;
    int arr[N+5] = {0};
    Solution(ListNode* head) {
        while (head != NULL) {
            arr[n++] = head->val ;
            head = head->next;
        }
    }
    int getRandom() {
        int rnd = rand()%n;
        return arr[rnd] ; 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
