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

    // ListNode* swapNodes(ListNode* head, int k) {
        
        // // easiest approach to solve the problem 
        // ListNode* temp = head;
        // vector<int> arr(0);

        // while(temp){
        //     arr.push_back(temp->val);
        //     temp = temp->next;
        // }
        // swap(arr[k-1], arr[arr.size()-k]);

        // int i=0;
        // ListNode* temp2 =  head;
        // while(temp2){
        //     temp2->val = arr[i];
        //     i++;
        //     temp2 = temp2->next;
        // }

        // return head;

    // }

    int getLength(ListNode* head){
        ListNode* temp = head;
        int c=0;

        while(temp){
            temp = temp->next;
            c++;
        }
        return c;
    }
    
    ListNode* swapNodes(ListNode* head, int k){
        //case 1: 
        if(!head || head -> next == NULL) return head;

        //case 2:
        int l = getLength(head);
        int lpos = k;
        int rpos = l - k+1;

        if(rpos< lpos) swap(lpos,rpos);// taki iska nomenclature naa kharab ho solving me

        if(lpos == rpos) return head;

        //case 3:
        if(l == 2){
            ListNode* nextNode = head->next;
            nextNode->next = head;
            head->next = NULL;
            head = nextNode;
            return head;
        }

        //case 4:
        if(lpos == 1){
            ListNode* lp = 0;
            ListNode* ln = head;
            ListNode* rp = head;

            for(int i=0; i<l-2;i++) rp = rp->next;

            ListNode* rn = rp->next;
            ListNode* rsave = 0; //iss case me NULL hoga

            //swapping 
            rn ->next = ln->next;
            rp->next = ln;
            ln->next = rsave;
            head = rn;
            return head;
        }

        //case 5 
        int noOfNodesBetweenSwapNodes = rpos - lpos -1;
        if(noOfNodesBetweenSwapNodes == 0){
            // ln and rn are adjacents
            ListNode* lp = head;
            for(int i=0; i<lpos-2;i++){
                lp = lp->next;
            }
            ListNode* ln = lp->next;

            ListNode *rp = head;
            for(int i=0; i<rpos-2;i++){
                rp = rp ->next;
            }
            ListNode * rn = rp->next;
            ListNode* rsave = rn ->next;

            //swapping -
            lp->next = rp->next;
            rn ->next = rp;
            rp->next = rsave;
            return head;

        }
        else{
            // noOfNodesBetweenSwapNodes >=1
             ListNode* lp = head;
            for(int i=0; i<lpos-2;i++){
                lp = lp->next;
            }
            ListNode* ln = lp->next;

            ListNode *rp = head;
            for(int i=0; i<rpos-2;i++){
                rp = rp ->next;
            }
            ListNode * rn = rp->next;
            ListNode* rsave = rn ->next;

            //swapping 
            lp ->next = rn ;
            rn->next = ln->next;
            rp->next = ln;
            ln->next = rsave;
            return head;
        }

    }
};