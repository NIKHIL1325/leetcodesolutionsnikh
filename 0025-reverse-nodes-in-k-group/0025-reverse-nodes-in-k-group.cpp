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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        
        while (temp != nullptr) {
            // 1. Check if there are at least k nodes available ahead
            ListNode* check = temp;
            int count = 0;
            while (check != nullptr && count < k) {
                check = check->next;
                count++;
            }
            
            // If remaining nodes are less than k, leave them as they are
            if (count < k) {
                break;
            }
            
            // 2. Push the values of the k nodes onto the stack
            stack<int> q;
            ListNode* aux = temp;
            for (int i = 0; i < k; i++) {
                q.push(aux->val);
                aux = aux->next;
            }
            
            // 3. Pop from the stack to reverse the values in the nodes
            aux = temp;
            for (int i = 0; i < k; i++) {
                aux->val = q.top(); // Get the top value first
                q.pop();            // Then remove it from the stack
                aux = aux->next;
            }
            
            // 4. Move temp forward to the start of the next group
            temp = aux;
        }
        
        return head; // Return the modified list head
    }
};
