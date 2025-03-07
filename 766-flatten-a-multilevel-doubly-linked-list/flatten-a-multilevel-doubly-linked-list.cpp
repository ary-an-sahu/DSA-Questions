/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

Node* solve(Node* head){
    
    auto it= head;
    auto tail = it;

    while(it!=NULL){
        if(it->child){
            auto childTail = solve(it->child);
            Node* temp= it->next;
            it->next = it->child;
            it->next->prev = it;

            childTail->next = temp;
            if(temp!=NULL){
                temp->prev = childTail;
            }
            it->child = nullptr;
        }
        tail = it; // taki child node milne ke baad aage ke nodes ka gum naa ho jaye.
        it = it->next;
    }
    return tail;
}
        
class Solution {
public:
    Node* flatten(Node* head) {

        if(head==NULL) return nullptr;
        solve(head);
        return head;

    }
};