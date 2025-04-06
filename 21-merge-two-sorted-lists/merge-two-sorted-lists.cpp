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
//   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//     if (!list1 || !list2)
//       return list1 ? list1 : list2;
//     if (list1->val > list2->val)
//       swap(list1, list2);
//     list1->next = mergeTwoLists(list1->next, list2);
//     return list1;
//   }


ListNode* mergeTwoLists(ListNode* left, ListNode* right){

    ListNode* ans = new ListNode(-1);
    ListNode* mptr = ans;

    if(left== 0) return right;
    if(right == 0) return left;

    while(left && right){

        if(left->val <= right->val){
            mptr->next = left;
            mptr = left;    
            left = left-> next;

        }
        else{

            mptr->next = right;
            mptr = right;
            right = right->next; 
        }

    }

    if(left){
        mptr->next = left;
        
    }

    if(right){
        mptr->next = right;
        
    }

    return ans->next;
}

};