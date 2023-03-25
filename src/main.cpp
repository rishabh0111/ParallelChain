
#include <chrono>
#include <iostream>

#include <CL/sycl.hpp>

#include "Blockchain.h"

int main() {
    auto start_time = std::chrono::high_resolution_clock::now();

    // Select device to perform operations with. We select the default
    // device using a lambda function as a device selector.
    cl::sycl::queue q([](cl::sycl::device dev) {
        return dev.is_gpu() && dev.get_info<cl::sycl::info::device::name>().find("Intel") != std::string::npos;
    });

    std::cout << "Device: "
              << q.get_device().get_info<cl::sycl::info::device::name>()
              << std::endl;

    {
        using namespace std;
        using namespace cl::sycl;

        Blockchain bChain{q};

        std::cout << "Mining block 1..." << std::endl;
        bChain.AddBlock(q, Block{q, 1, "Block 1 Data"});

        std::cout << "Mining block 2..." << std::endl;
        bChain.AddBlock(q, Block{q, 2, "Block 2 Data"});

        std::cout << "Mining block 3..." << std::endl;
        bChain.AddBlock(q, Block{q, 3, "Block 3 Data"});
    }

    return 0;
}

