auto isUnique( const std::string& input ) noexcept( true ) -> bool {
    std::array<bool, 128> charset{};
    const char zero { '0' };
    for( auto const &c : input ) {
        if(charset[c - zero])
            return false;
        charset[c - zero] = true;
    }
    return true;
}

//const auto MIN_INT = std::numeric_limits<int>::min();

auto difference(std::vector<int> const & input) -> int {
    const auto [ min, max ] = std::minmax_element( std::cbegin( input ), std::cend( input ) );
    return ( *max - *min);
}
