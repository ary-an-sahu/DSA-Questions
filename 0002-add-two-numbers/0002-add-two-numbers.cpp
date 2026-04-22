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

    // ListNode* reverseLL(ListNode* head){

    //     if(head == NULL && head->next == NULL) return head;

    //     ListNode* prev = NULL;

    //     ListNode* curr = head;

    //     while(curr!= NULL){

    //         ListNode* forward = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = forward;
    //     }

    //     return prev;
    // }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp1= l1;
        ListNode* temp2 = l2;
        ListNode* prev = NULL;

        int carry = 0;

        while(temp1!= NULL && temp2!= NULL){

            int d1 = temp1->val;
            int d2 = temp2 ->val;

            int sum = d1+ d2 + carry;
            int csum = sum;

            sum = sum%10;
            carry = csum /10;

            temp1->val = sum;
            prev = temp1;
            temp1= temp1->next;
            temp2 = temp2 -> next;
        }

        if(temp1!= NULL){
            prev ->next = temp1;
            while(temp1 != NULL){

                int sum = temp1->val + carry;
                int csum = sum;

                sum = sum% 10;
                carry = csum/10;

                temp1->val = sum;
                prev = temp1;
                temp1 = temp1 -> next;
            }
        }

        if(temp2!= NULL){
            prev ->next = temp2;
            while(temp2 != NULL){

                int sum = temp2->val + carry;
                int csum = sum;

                sum = sum% 10;
                carry = csum/10;
                temp2->val = sum;
                prev = temp2;
                temp2 = temp2->next;
            }
            
        }

        if(carry){
            ListNode* newNode = new ListNode(carry);
            prev->next = newNode;
        }

        // ListNode* ans = reverseLL(l1);

        return l1;
    }
};