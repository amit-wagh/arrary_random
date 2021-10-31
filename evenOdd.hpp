auto evenOdd( std::vector<unsigned int>& input ) -> void {
    std::size_t nextEven = 0;
    std::size_t nextOdd  = input.size() - 1;

    auto isEven = []( const auto & value ) { return value % 2 == 0; };

    while( nextEven < nextOdd ) {
        if( isEven(input[nextEven]) ) {
            ++nextEven;
        }
        else {
            std::swap( input[nextEven], input[nextOdd]);
            --nextOdd;
        }
    }
}
