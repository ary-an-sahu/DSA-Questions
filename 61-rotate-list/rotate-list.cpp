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
        int count =0;
        while(head){
            count++;
            head = head ->next;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL){
            return 0;
        }

        int len = getLength(head);
        int ActualrotateK = k% len;

        if(ActualrotateK == 0) return head;

        int newLastNodePos = len - ActualrotateK - 1;

        ListNode* newHead = nullptr;
        ListNode* newLastNode = head;

        for(int i=0;i<newLastNodePos ; i++){
            newLastNode = newLastNode ->next;
        }
        newHead = newLastNode ->next;
        newLastNode ->next = 0;

        ListNode* it = newHead;
        while(it->next ){
            it = it->next;
        }
        it->next = head;
        return newHead;

        
        
    }
};