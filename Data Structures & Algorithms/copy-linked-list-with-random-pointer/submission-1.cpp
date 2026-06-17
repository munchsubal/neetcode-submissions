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
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        
        // insert copied nodes in between
        while (temp != nullptr) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;

            temp = temp->next->next;
        }

        // connect random pointers
        temp = head;
        while (temp != nullptr) {
            if (temp->random == nullptr) {
                temp->next->random = nullptr;
            }
            else {
                temp->next->random = temp->random->next;
            }
            
            temp = temp->next->next;
        }

        Node* dummyNode = new Node(-1);
        Node* curr = dummyNode;
        temp = head;
        while (temp != nullptr) {
            curr->next = temp->next;
            temp->next = temp->next->next;

            curr = curr->next;
            temp = temp->next;
        }

        return dummyNode->next;
    }
};