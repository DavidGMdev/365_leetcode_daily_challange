// ####################################### 
// way 3 : using lazy pointer 
// ####################################### 

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        // using lazy pointer 
        ListNode *kth , *curr , *lazy ;
        curr = kth = lazy = head;
        while(curr->next&&--k) curr = curr->next ; 
        kth = curr;
        while(curr->next){ 
            // this loops moves n-k step , 
            // so the lazy one ends where we need to 1+(n-k) = n-k+1 postion
            curr = curr->next ;
            lazy = lazy->next ;
        }
        swap(kth->val,lazy->val);
        return head;
    }
};

// ####################################### 
// way 2 : using extra memory 
// ####################################### 


class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        const int N = 1e5 ; 
        ListNode* memo[N+5]; 
        int n = 0;
        ListNode* curr = head;
        while(curr){
            memo[++n] = curr;
            curr = curr->next ;
        }
        swap(memo[k]->val,memo[n-k+1]->val);
        return head;
    }
};

// ####################################### 
// way 1 : using extra loop 
// ####################################### 

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode* curr = head;
        while(curr){
            n++;
            curr = curr->next ;
        }
        ListNode* a = NULL , *b = NULL ;
        curr = head;
        int i = 1 ; 
        while(curr&&( a == NULL || b == NULL)) {
            if( i == k ) a = curr;
            if( i == n-k+1 ) b = curr;
            curr = curr->next;
            i++;
        }
        if(a&&b) swap(a->val,b->val);
        return head;
    }
};
