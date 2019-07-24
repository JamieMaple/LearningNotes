#include <iostream>
#include <fstream>
#include "text_query.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "No input file!" << std::endl;
        return -1;
    }
    
    std::ifstream infile(argv[1]);

    runQuery(infile);
}
