#include <iostream>
#include <vector>
#include <utility>

int main()
{
    std::vector<std::pair<int,int>> my_vector;
    my_vector.push_back(std::make_pair(1,2));
    my_vector.push_back(std::make_pair(3,4));

    for (auto const& p : my_vector) {
        std::cout << p.first << " " << p.second << std::endl;
    }

    for (auto& p : my_vector) {
        std::swap(p.first, p.second);
    }

    for (auto const& p : my_vector) {
        std::cout << p.first << " " << p.second << std::endl;
    }
}