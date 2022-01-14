#include <iostream>
#include <vector>

using std::pair;
using std::vector;
using Points = pair<int, int>;

//sort a vector based on second element
auto sort( vector<Points>& point ) {
    std::sort(begin(point), end(point), [](auto const p1, auto const p2) {
        return p1.second < p2.second;
    });
}

template<typename T>
void print_vec(T const& container) {
    for(auto const [_, second]:container) {
        std::cout << second << " | ";
    }
    std::cout << std::endl;
}



[[nodiscard]]
auto main() -> int {
    auto points = vector<Points> {{3,6}, {1,4}, {4,8}};
    sort(points);

    auto arrows = 1;
    auto xStart = 0, xEnd = 0, firstEnd = points[0].second;
    for( auto const [start, end] : points ) {
        xStart = start;
        xEnd = end;

        if( firstEnd < xStart ) {
            arrows++;
            firstEnd = xEnd;
        }
    }
    std::cout << "No of arrows " << arrows << std::endl;
    return EXIT_SUCCESS;
}
