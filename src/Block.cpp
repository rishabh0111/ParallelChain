#include "Block.h"
#include "sha256.h"
#include<CL/sycl.hpp>
using namespace sycl;

Block::Block(queue &q, uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{
    _nNonce = 0;
    _tTime = time(nullptr);

    sHash = _CalculateHash();
}

void Block::MineBlock(queue &q, uint32_t nDifficulty)
{
//     std::cout << "Device from MineBlock: " << q.get_device().get_info<info::device::name>() << std::endl;
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i)
    {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    string str(cstr);
//     auto e = q.parallel_for(range(1), [=](id<1> index) {
      
//     });

//     // Wait for the asynchronous computation on device to complete.
//     e.wait();
    
    do
    {
        _nNonce++;
        sHash = _CalculateHash();
    }
    while (sHash.substr(0, nDifficulty) != str);

    std::cout << "Block mined: " << sHash << std::endl;
}

inline string Block::_CalculateHash() const
{
    stringstream ss;
    ss << _nIndex << sPrevHash << _tTime << _sData << _nNonce;

    return sha256(ss.str());
}
