#ifndef TESTCHAIN_BLOCKCHAIN_H
#define TESTCHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include<CL/sycl.hpp>
#include "Block.h"

using namespace std;
using namespace sycl;

class Blockchain {
public:
    Blockchain(queue &q);

    void AddBlock(queue &q, Block bNew);

private:
    uint32_t _nDifficulty;
    vector<Block> _vChain;

    Block _GetLastBlock() const;
};

#endif //TESTCHAIN_BLOCKCHAIN_H
