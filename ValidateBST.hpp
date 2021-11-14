
// 98. Validate Binary Search Tree
// using std::optional/lambda functions
class Solution {
  auto validator( TreeNode* root ) const noexcept( true ) -> std::optional<bool> {
    
    auto constexpr predecessor = [](auto const current) { 
        auto p = current->left;
        while( p->right != nullptr && p->right != current ) 
          p = p->right;
        return p; 
    };
    
    auto constexpr validate = []( auto const prev, auto const current ) -> std::optional<bool> {
      if( prev != nullptr && prev->val >= current->val )
          return false;
      return nullopt;
    };
    
    auto constexpr move_right = []( auto& prev, auto& current ) {
       prev = current;
       current = current->right; 
    };
    
    auto current { root };
    decltype(root) prev { nullptr };
    auto result = std::optional<bool>{ true };
    
    while( current != nullptr ) {
      if( current->left == nullptr ) {
        result = validate( prev, current ).value_or(result.value());
        move_right( prev, current );
      } else {
        auto pred = predecessor(current);
        if( pred->right == nullptr ) {
          pred->right = current;
          current = current->left;
        } else {
          pred->right = nullptr;
          result = validate( prev, current ).value_or(result.value());
          move_right( prev, current );
        }      
      }
    }  
    return result;
  }
  
public:
    bool isValidBST(TreeNode* root) {
        return validator(root).value_or("false");
    }
};
