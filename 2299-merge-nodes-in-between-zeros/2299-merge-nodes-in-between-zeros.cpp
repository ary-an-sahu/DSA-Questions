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
    // ListNode* mergeNodes(ListNode* head) {
    //     ListNode* modify = head->next; // Start from the node after the initial 0
    //     ListNode* nextSum = modify;

    //     while (nextSum != nullptr) {
    //         int sum = 0;
    //         // Find the sum of all nodes until you encounter a 0.
    //         while (nextSum->val != 0) {
    //             sum += nextSum->val;
    //             nextSum = nextSum->next;
    //         }

    //         // Assign the sum to the current node's value.
    //         modify->val = sum;
    //         // Move nextSum to the first non-zero value of the next block.
    //         nextSum = nextSum->next;
    //         // Move modify also to this node.
    //         modify->next = nextSum;
    //         modify = modify->next;
    //     }
    //     return head->next; // Skip the initial 0 node.
    // }


    //another approach - 
    // ListNode* mergeNodes(ListNode* head){

    //     ListNode* temp  = head->next;
    //     int sum = 0;

    //     if(temp == NULL){
    //         return NULL;
    //     }

    //     while(temp->val != 0){
    //         sum = sum+ temp->val;
    //         temp = temp->next;
    //     }
    //     ListNode* newNode = new ListNode(sum);

    //     newNode->next = mergeNodes(temp);
    //     return newNode;
    // }


    //another approach -

     ListNode* mergeNodes(ListNode* head){
        
        if(head == NULL)
        {
            return 0;
        }

        ListNode* slow = head, *fast = head->next, *lastNode = 0;
        int sum = 0;

        while(fast){

            if(fast->val != 0){
                sum += fast ->val ;
            }
            else{
                //fast->val == 0;
                slow->val = sum;
                lastNode = slow;
                slow = slow->next;
                sum =0;
            }
            fast = fast->next;
        }

        ListNode* temp = lastNode->next;
        lastNode->next = NULL;

        //deleting remaining nodes to avoid memory leak
        while(temp){
            ListNode* nxt = temp->next;
            delete temp;
            temp = nxt;
        }

        return head;
    }

    
};