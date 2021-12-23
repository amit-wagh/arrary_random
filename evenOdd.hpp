#include <cstdlib>
#include <iostream>
#include <vector>

#include <iterator>
namespace {
    using std::cout;
    using std::vector;
    auto constexpr nl {'\n'};

    auto evenOdd( std::vector<std::int32_t>& input ) noexcept -> void {
        auto nextOdd  = input.size() - 1;
        decltype(nextOdd) nextEven = 0;
        
        auto constexpr isEven = []( const auto value ) { return value % 2 == 0; };

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
}


[[nodiscard]]
auto main() noexcept -> int {
    auto input = vector<std::int32_t>{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    evenOdd(input);
    std::copy(cbegin(input), cend(input), std::ostream_iterator<std::int32_t>(cout, " "));
    return EXIT_SUCCESS;
}
