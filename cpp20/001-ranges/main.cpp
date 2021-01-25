#include <iostream>
#include <array>
#include <algorithm>

void print(auto const& seq) {
    for (auto const& elem : seq) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}
 
int main(void) {
	std::array foo = {50, 40, 42, 6, 0, 3, 4, 4, 6, 7, 13,5};

    std::vector<char> v;

	namespace ranges = std::ranges;
  	ranges::sort(foo);
	print(foo);

	ranges::sort(foo, ranges::greater());
        print(foo);

	return 0;
}
