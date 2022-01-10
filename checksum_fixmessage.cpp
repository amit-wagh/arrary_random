#include <iostream>
#include <string>
#include <numeric>

[[nodiscard]][[maybe_unused]]
auto calculate_checksum( std::string const& fix_message ) noexcept(true) -> uint16_t {
    std::cout << "Message : " << fix_message << std::endl;
    auto const sum = std::accumulate(std::cbegin(fix_message), std::cend(fix_message), 0);
    auto const checksum = sum % 256;
    return checksum;     
}

 [[nodiscard]]
 auto main() noexcept(true) -> int {
    auto const message {"8=FIX.4.2\0019=49\00135=5\00134=1\00149=ARCA\00152=20150916-04:14:05.306\00156=TW\001"};
    auto const cksum = calculate_checksum(message);
    std::cout << "CheckSum " << cksum << std::endl;
    return EXIT_SUCCESS;
}
