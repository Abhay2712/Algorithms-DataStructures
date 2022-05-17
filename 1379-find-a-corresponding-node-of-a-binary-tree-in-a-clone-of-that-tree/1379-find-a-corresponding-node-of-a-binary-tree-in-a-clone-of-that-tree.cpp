class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr) return nullptr;
		//Don't compare value. Compare the pointer
        if (original == target) return cloned;
        TreeNode* left = getTargetCopy(original->left, cloned->left, target);
		// early return if we already find it
        if (left != nullptr) return left;
        return getTargetCopy(original->right, cloned->right, target);
        
    }
};