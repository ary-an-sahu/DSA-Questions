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

    int getLength(ListNode* head){
        ListNode* temp = head;
        int l = 0;
        while(temp!= NULL){
            l++;
            temp= temp->next;
        }
        return l;

    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        // k length ke liye hume reverse karna hai 
        
        int len = getLength(head);

        // condition check to avoid nullpointer error-
        // check for Linked list length
        if(len<k){
            // reverse krne ki jarurat nhi hai 
            // aise hi return kr sakte hai
            return head;
        }

        // 1case hum solve krenge aur bakki recursion sambhal leha mere bhai
        // 1 case -> k length ko reverse krna hai bhai. 
        ListNode* prev =NULL;
        ListNode* curr =  head;
        int position = 0;

        while(position<k){
            ListNode* forward = curr->next;

            curr->next = prev;
            prev = curr;
            curr = forward;
            position++;
        }
        
        // baaki recursion sambhal lega 
        if(curr!=NULL){
            ListNode* recursionKaHead =  reverseKGroup(curr,k);
            head->next = recursionKaHead;
        }
        return prev;
    }
};