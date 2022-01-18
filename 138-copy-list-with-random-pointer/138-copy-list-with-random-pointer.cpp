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
    Node* copyRandomList(Node* head) 
    {
        Node *iter=head;
        Node* front=head;
        
        // 1.Make copy and link them together
        
        while(iter!=NULL)
        {
            front=iter->next;
            
            Node* copy=new Node(iter->val);
            copy->next=iter->next;
            iter->next=copy;
            iter=iter->next->next;
        }
        
        //2.Assign random pointer for the copy nodes
        
        iter=head;
        while(iter!=NULL)
        {
            if(iter->random!=NULL)
                iter->next->random = iter->random->next;
            
            iter=iter->next->next;
        }
        
        //3.Diferentiate the original and copy linked list
        
          iter = head;
          Node *pseudoHead = new Node(0);
          Node *copy = pseudoHead;

          while (iter != NULL)
          {
            

            // extract the copy
            copy->next = iter->next;

            // restore the original list
            iter->next = iter->next->next;
              
            copy = copy -> next; 
             iter=iter->next;
            
          }

          return pseudoHead->next;
    }
};