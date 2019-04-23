#include <iostream>
#include <fstream>
#include <iterator>

int main(int argc, char **argv) {
    if (argc < 4) {
        std::cout << "No args provided!" << std::endl;
        return -1;
    }

    std::ifstream in(argv[1]);
    std::ofstream odd(argv[2]), even(argv[3]);

    std::istream_iterator<int> input_it(in), eof;
    std::ostream_iterator<int> odd_it(odd, " ");
    std::ostream_iterator<int> even_it(even, "\n");

    while (input_it != eof) {
        auto val = *input_it++;
        if (val & 0x1) {
            *even_it++ = val;
        } else {
            *odd_it++ = val;
        }
    }

    return 0;
}
