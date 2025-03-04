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

    ListNode* getMiddle(ListNode* head,ListNode* &middleNodeKaPrev){
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!=NULL){
            fast = fast->next;
            //check kro null toh nhi hai fast?
            if(fast!=NULL){
                fast = fast->next;
                middleNodeKaPrev = slow;
                //abb slow ko bhi ek step badha do bhai mere
                slow = slow -> next;
            }
        }
        return slow;
    }

    ListNode* reverseList(ListNode* &prev, ListNode* &curr){

        while(curr!=NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            // LL is empty
            return true;
        }
        if(head->next == NULL){
            //single node present hai
            return true;
        }
        // travel till middle node and break the LL from middle
        ListNode* firstPartHead = head;
        ListNode* middleNodeKaPrev = NULL;
        ListNode* middleNode = getMiddle(head,middleNodeKaPrev);
        // break kr do linked list ko 
        middleNodeKaPrev->next = NULL;

        // reverse second half
        ListNode* prev = NULL;
        ListNode* curr = middleNode;

        ListNode* secondPartHead = reverseList(prev,curr);

        // compare both parts -> equal ->T , !equal -> F
        // Even length wale case me dono part ki length same hai 
        // Odd length me second part ki length badi hai 
        //iska matlab hum loop first part ki length ke equal hi chalayenge

        ListNode* tempHead1 = firstPartHead;
        ListNode* tempHead2 = secondPartHead;

        while(tempHead1!=NULL){
            if(tempHead1->val != tempHead2->val){
                //palindrome nhi hai
                return false;
            }
            else{
                // values equal hai toh
                // iska matalab dono pointer ko aage badhao
                tempHead1= tempHead1->next;
                tempHead2= tempHead2->next;

            }
        }
        //yha tak aaya hai toh sare value equal hai 
        //iska matlab palindrome hai 
        // iska matlab return true kro bhai
        return true;

        
    }

};