/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* hasCycle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast= head;

        while(fast!=NULL){
            // fast ko ek badha do 
            fast = fast->next;

            // check again if it is null or not?
            if(fast!=NULL){
                fast = fast->next;

                slow = slow ->next;
                if(fast == slow){
                    return slow;
                }
            }
        }

        return nullptr;
    }

    ListNode *detectCycle(ListNode *head) {
        // step 1 - find kro ki loop hai bhi ki nhi

        ListNode* fast = hasCycle(head);

        if(fast == NULL) return nullptr;

        // step 2 - find kro starting point of loop by - 
        // setting fast as it and slow as head
        // and increase the fast and slow at 1x speed.
        ListNode* slow = head;
        while(slow!= fast){

            slow = slow -> next;
            fast = fast-> next;
        }
        return slow;// starting point yhi hai mere bhai 


        
    }
};