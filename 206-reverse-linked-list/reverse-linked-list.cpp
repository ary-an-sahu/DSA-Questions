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

    ListNode* reverseList(ListNode* &prev, ListNode* &curr){
        // base case-
        if(curr==NULL){
            // reverse of LL ho chuka hai
            // reversed LL ke starting node pr prev wala pointer hai 
            return prev;
        }

        ListNode* forward = curr->next;
        // ek case hum solve krenge 
        // curr node ko piche ke disha me ghuma do
        curr->next = prev;
        // baki pointers ko bada do 
        prev = curr;
        curr = forward;
        // baki kaam recursion sambhal lega mere bhai
        return reverseList(prev,curr);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        ListNode* newNode = reverseList(prev,curr);
        return newNode;
        
    }
}; 