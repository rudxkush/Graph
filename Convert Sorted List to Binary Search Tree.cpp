class Solution {
public:
    TreeNode* recBuild(ListNode* head, ListNode* end) {
        if(head == end) return nullptr;

        // Find middle node (slow will be mid)
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* root = new TreeNode(slow->val);
        root->left = recBuild(head, slow);   // left half
        root->right = recBuild(slow->next, end); // right half
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return recBuild(head, nullptr);
    }
};
