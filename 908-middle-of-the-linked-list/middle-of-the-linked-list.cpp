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
    // ListNode* middleNode(ListNode* head) {
    //     ListNode* fast = head;
    //     ListNode* slow = head;

    //     // condition -
    //     while(fast!=NULL){
    //         // fast ko ek step aage badhao -
    //         fast = fast->next;
    //         // check kro ki fast null toh nhi hai?
    //         if(fast!=NULL){
    //             // fast ko ek aur step aage badha do - 
    //             fast = fast->next;
    //             // agar null nhi hai toh slow ko bhi aage badha do 
    //             slow = slow->next;
    //         }
    //     }
    //     return slow;
    // }

    ListNode* middleNode(ListNode* head){
        ListNode * fast = head;
        ListNode* slow = head;

        while(fast!= NULL){
            fast = fast -> next ;

            if(fast!= NULL){
                fast = fast -> next ;
                slow = slow -> next ;
            }
        }
        return slow;
    }



};