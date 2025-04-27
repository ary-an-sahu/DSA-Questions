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
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next ->next;
        }
        return slow; 
    }

    ListNode* merge(ListNode* left, ListNode* right){

        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans;

        if(left== 0) return right;
        if(right == 0) return left;

        while(left && right){

            if(left->val <= right->val){
                mptr->next = left;
                mptr = left;    
                left = left-> next;

            }
            else{

                mptr->next = right;
                mptr = right;
                right = right->next; 
            }

        }

        if(left){
            mptr->next = left;
            
        }

        if(right){
            mptr->next = right;
            
        }

        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        //Break ll into two halves from mid
        ListNode*left = head;
        ListNode* mid = findMid(head);
        ListNode* right = mid->next;
        mid->next = 0;

        left = sortList(left);
        right = sortList(right);
        

        //merge right and left at end -
        ListNode* mergedLL = merge(left, right);
        return mergedLL;
    }
};