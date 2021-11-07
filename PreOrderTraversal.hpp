//Definition for a binary tree node. 
struct TreeNode {
    int val {};
    TreeNode *left  = nullptr;
    TreeNode *right = nullptr;
    TreeNode() : val( 0 ), left( nullptr ), right( nullptr ) noexcept( true ) {
    }
    explicit TreeNode( int x ) noexcept( true ) 
        : val( x ), left( nullptr ), right( nullptr ) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) noexcept( true )
        : val( x ), left( left ), right( right ) {
    }
};
class Solution {
private:
    void preorderRecursive(TreeNode* root, vector<int>& result) const {
        if ( root == nullptr ) {
            return;
        }
        result.push_back( root->val );
        preorder( root->left,  result );
        preorder( root->right, result );
    }
public:
    //Recursive : O(n) time and O(n) space (function call stack);
    auto preorderTraversal1(TreeNode* root) const -> vector<int> {
        vector<int> result {};
        if( root == nullptr )
            return result;

        preorderRecursive( root, result );
        return result;
    }
    //Iterative : O(n) time and O(n) space;
    auto preorderTraversal2(TreeNode* root) const -> vector<int> {
        vector<int> result;
        if( root == nullptr )
            return result;

        stack<TreeNode*> rights;

        while( root != nullptr ) {
            result.push_back( root->val  );

            if( root->right != nullptr )
                rights.push( root->right );

            root = root->left;
            if( root == nullptr && !rights.empty() ) {
                root = rights.top();
                rights.pop();
            }
        }
        return result;
    }
    //Optimized : O(n) time and O(n) space;
    auto preorderTraversal3(TreeNode* root) const -> vector<int> {
        vector<int> result;
        if( root == nullptr )
            return result;

        stack<TreeNode*> rights;

        while( root != nullptr ) {
            result.push_back( root->val  );

            if( root->right != nullptr )
                rights.push( root->right );

            root = root->left;
            if( root == nullptr && !rights.empty() ) {
                root = rights.top();
                rights.pop();
            }
        }
        return result;
    }
    //Morris Traversal : O(n) time and O(1) space.
    auto preorderTraversal4(TreeNode* root) const -> vector<int> {
        vector<int> result;
        if ( !root )
            return result;

        while ( root != nullptr ) {
            if( root->left == nullptr ) {
                result.push_back( cur->val );
                root = root->right;
            }
            else {
                auto pre = root->left;
                while( pre->right != nullptr && pre->right != cur )
                    pre = pre->right;

                if( pre->right == nullptr ) {
                    result.push_back( cur->val );
                    pre->right = cur;
                    cur=cur->left;
                }
                else {
                    pre->right = NULL;
                    cur=cur->right;
                }
            }
        }
        return result;
    }
};
