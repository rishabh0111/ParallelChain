#ifndef TESTCHAIN_BLOCK_H
#define TESTCHAIN_BLOCK_H

#include <cstdint>
#include <iostream>
#include <sstream>
#include<CL/sycl.hpp>

using namespace std;
using namespace sycl;

class Block {
public:
    string sHash;
    string sPrevHash;

    Block(queue &q, uint32_t nIndexIn, const string &sDataIn);

    void MineBlock(queue &q, uint32_t nDifficulty);

private:
    uint32_t _nIndex;
    uint32_t _nNonce;
    string _sData;
    time_t _tTime;

    string _CalculateHash() const;
};

#endif //TESTCHAIN_BLOCK_H
