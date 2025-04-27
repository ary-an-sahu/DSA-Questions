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

    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* temp = head;
        vector<int> arr(0);

        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        swap(arr[k-1], arr[arr.size()-k]);

        int i=0;
        ListNode* temp2 =  head;
        while(temp2){
            temp2->val = arr[i];
            i++;
            temp2 = temp2->next;
        }

        return head;

    }
};