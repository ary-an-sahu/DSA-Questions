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


    bool hasCycle(ListNode *head) {
        
        unordered_map<ListNode*,bool>m;
        ListNode* temp = head;

        while(temp!=NULL){
            if(m[temp]==true){
                // phle se hi true hai
                // cycle present hai
                return true;
            }
            else{
                //phle se true nhi hai ,
                // toh isko true banao aur aage badhao
                m[temp]= true;
                temp= temp->next;
            }
        }
        // agar yha aa gya iska matlab travesal complete ho gya hai
        //aur cycle present nhi hai 
        // iska matlb false return karna hoga
        return false;
    }
};