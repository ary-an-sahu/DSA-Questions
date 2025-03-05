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
    ListNode* deleteDuplicates(ListNode* head) {
        // case 1 - LL is empty
        if(head== NULL){
            return head;

        }
        // case 2 - only one node is present in LL
        if(head->next == NULL){
            return head;
        }

        // case 3 - more than 1 nodes present
        ListNode* prev = head;
        ListNode* temp = head->next;
        
        while(temp != NULL){
            
            if(temp->val == prev->val){
                //duplicate found
                prev->next = temp->next;
                temp->next = NULL;
                delete temp;
            }

            else{
                // duplicate not found
                prev= prev->next;
                temp = temp->next;
                
            }
            //temp ko set krdo
            temp= prev->next;
        }
        return head;
    }
};