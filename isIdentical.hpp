struct [[maybe_unused]] Node {
    int data;
    Node* left  = nullptr;
    Node* right = nullptr;

    explicit Node( int value ) noexcept( true ) : data( value ){}
};

[[maybe_unused]]
[[nodiscard]]
auto isIdenticalRecursive( Node* root1, Node* root2 ) noexcept( true ) -> bool {
    if( root1 == nullptr && root2 == nullptr )
        return true;

    return ( root1 && root2 )
        && ( root1->data == root2->data )
        && isIdenticalRecursive( root1->left, root2->left )
        && isIdenticalRecursive( root1->right, root2->right );
}

[[maybe_unused]]
[[nodiscard]]
auto isIdenticalIterative( Node* root1, Node* root2 ) noexcept( true ) -> bool {

    if( root1 == nullptr && root2 == nullptr )
        return true;

    if( root1 == nullptr )
        return false;

    if( root2 == nullptr )
        return false;

    stack<pair<const Node*, const Node*>> stk;
    stk.push({root1, root2});

    while( !stk.empty() ) {
        const auto [ left, right ] = stk.top(); stk.pop();

        if( left->data != right->data )
            return false;

        if( left->left && right->left )
            stk.push( { left->left, right->left } );
        else if( left->left || right->left )
            return false;

        if( left->right && right->right )
            stk.push( { left->right, right->right } );
        else if( left->right || right->right )
            return false;

    }

    return true;
}


auto main( [[ maybe_unused ]] int   argc,
           [[ maybe_unused ]] char* argv[]
         ) -> int {

    auto root1 = new Node(5);
    root1->left = new Node(7);
    root1->right = new Node(6);

    root1->left->left = new Node(1);
    root1->left->right = new Node(2);

    root1->right->left = new Node(3);
    root1->right->right = new Node(4);

    auto root2 = new Node(5);
    root2->left = new Node(7);
    root2->right = new Node(6);

    root2->left->left = new Node(1);
    root2->left->right = new Node(2);

    root2->right->left = new Node(3);
    root2->right->right = new Node(4);

    cout << boolalpha << isIdenticalRecursive( root1, root2 ) << '\n';
    cout << boolalpha << isIdenticalIterative( root1, root2 ) << '\n';
    
    
    return EXIT_SUCCESS;
}
