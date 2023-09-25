
#include <iostream>
#include <cstdlib>
#include <getopt.h>

void printUsage() {
    std::cout << "Usage: calculator [OPTIONS] OPERANDS..." << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -o, --operation=OPERATION   Specify the operation to perform" << std::endl;
    std::cout << "  -h, --help                  Display this help message" << std::endl;
}

int main(int argc, char* argv[]) {
    int option;
    std::string operation;
    
    // Parse command line options
    while ((option = getopt(argc, argv, "o:h")) != -1) {
        switch (option) {
            case 'o':
                operation = std::string(optarg);
                break;
            case 'h':
                printUsage();
                return 0;
            default:
                printUsage();
                return 1;
        }
        std::cout<< operation <<std::endl;
    }
    
    // Check if operation is specified
    if (operation.empty()) {
        std::cerr << "Error: Operation not specified" << std::endl;
        printUsage();
        return 1;
    }
    
    // Check if there are enough operands
    if (optind >= argc) {
        std::cerr << "Error: No operands specified" << std::endl;
        printUsage();
        return 1;
    }
    
    // Perform the specified operation
    if (operation == "summa") {
        int sum = 0;
        for (int i = optind; i < argc; i++) {
            sum += std::atoi(argv[i]);
        }
        std::cout << "Sum: " << sum << std::endl;
    } else if (operation == "subtraction") {
        int result = std::atoi(argv[optind]);
        for (int i = optind + 1; i < argc; i++) {
            result -= std::atoi(argv[i]);
        }
        std::cout << "Result: " << result << std::endl;
    } else {
        std::cerr << "Error: Unknown operation" << std::endl;
        printUsage();
        return 1;
    }
    
    return 0;
}
