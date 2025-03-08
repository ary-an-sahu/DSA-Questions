/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    // Node* helperOld(Node* head, unordered_map<Node* , Node*> &mp){
    //     if(head==0) return 0;

    //     Node* newHead =  new Node(head->val);
    //     mp[head] = newHead;
    //     newHead->next = helper(head->next,mp);

    //     if(head->random!=NULL){
    //         newHead-> random = mp[head->random];
    //     }
    //     return newHead;

    // }
    
   

    Node* copyRandomList(Node* head) {
        // unordered_map<Node*,Node*> mp;  //old node ---> new node : mapping 
        // return helperOld(head,mp);

        if(head==NULL)  return 0;

        // Step 1: Clone A -> A'
        Node * it = head;

        while(it!= NULL){
            Node* clonedNode =  new Node(it->val);
            clonedNode->next = it->next;
            it->next= clonedNode;
            it = it->next->next;
        }

        // Step 2 - assign random links of A' with the help of A
        it = head;

        while(it!=NULL){

            Node* clonedNode =  it->next;
            clonedNode->random = it->random? it->random->next: nullptr;
            it = it->next->next;
        }

        // Step 3 : detach A' from A-
        it = head;

        Node* clonedHead = it->next;
        while(it){
            Node* clonedNode = it->next;
            it->next = it->next -> next;
            if(clonedNode->next != NULL){
                clonedNode -> next = clonedNode -> next -> next;
            }
            it = it->next;
        }

        return clonedHead;

        // return helper(head);
    }
};