class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        
        if (head == nullptr) return nullptr;

        Node* current = head;  // Start with the head of the list

        while (current != nullptr) {
            // Skip m nodes
            for (int i = 1; i < m && current != nullptr; i++) {
                current = current->next;
            }

            // If we've reached the end of the list, break
            if (current == nullptr) return head;

            Node* temp = current->next;  // The first node to delete

            // Delete n nodes
            for (int i = 0; i < n && temp != nullptr; i++) {
                Node* nodeToDelete = temp;
                temp = temp->next;
                delete nodeToDelete;  // Deleting the node
            }

            // Link the current node to the node after the deleted nodes
            current->next = temp;
            current = temp;  // Move the current pointer to the next node
        }

        return head;
    }
};
