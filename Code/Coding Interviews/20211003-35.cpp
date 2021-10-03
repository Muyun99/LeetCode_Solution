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
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;

        for (Node *node = head; node != NULL; node = node->next->next)
        {
            Node *newNode = new Node(node->val);
            newNode->next = node->next;
            node->next = newNode;
        }

        for (Node *node = head; node != NULL; node = node->next->next)
        {
            Node *copyNode = node->next;
            if (node->random)
                copyNode->random = node->random->next;
            else
                copyNode->random = NULL;
        }

        Node *newhead = head->next;
        for (Node *node = head; node != NULL; node = node->next)
        {
            Node *copyNode = node->next;
            node->next = node->next->next;

            if (copyNode->next != NULL)
                copyNode->next = copyNode->next->next;
            else
                copyNode->next = NULL;
        }

        return newhead;
    }
};