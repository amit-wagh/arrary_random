#include <iostream>
#include <vector>
#include <deque>


namespace {
    constexpr auto newline = '\n';
    using std::vector;
    using std::cout;
    using std::max;
    using std::boolalpha;

    template < typename T, typename Container = vector<T> >
    class [[ maybe_unused ]] Solution final {
        Container elems;
    public:
        explicit Solution( Container _elems ) noexcept( true ) :
            elems( std::move( _elems ) ) {}

        [[ maybe_unused ]]
        [[ nodiscard ]]
        constexpr auto kadane( ) const noexcept( true ) -> T {
            if( elems.empty() ) return -1;
            auto currentMax = elems[0];
            auto globalMax  = currentMax;

            for( size_t i = 1; i < elems.size(); ++i ) {
                currentMax = std::max( elems[i], elems[i] + currentMax );
                globalMax  = std::max( currentMax, globalMax );
            }
            return globalMax;
        }

    };
}

auto main() -> int {

    Solution<int> test1(vector<int>{ -2, 2, 3, -1 });
    cout << boolalpha << ( test1.kadane() == 5 ) << newline;

    Solution<int> test2(vector<int>{ -2, 2, 3, -1, 7 });
    cout << boolalpha << ( test2.kadane() == 11 ) << newline;

    Solution<int> test3(vector<int>{ -2, 2, 3, -1, 0, 7, 8 });
    cout << boolalpha << ( test3.kadane() == 19 ) << newline;

    Solution<int> test4(vector<int>{});
    cout << boolalpha << ( test4.kadane() == -1 ) << newline;

    using std::deque;
    Solution<int, deque<int>> test5(deque<int>{ 1, 2, 3, 4});
    cout << boolalpha << ( test5.kadane() == 10 ) << newline;
    
    return EXIT_SUCCESS;
}
