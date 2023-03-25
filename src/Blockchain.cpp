#include "Blockchain.h"
#include<CL/sycl.hpp>
using namespace sycl;

Blockchain::Blockchain(queue &q)
{
    _vChain.emplace_back(Block(q, 0, "Genesis Block"));
    _nDifficulty = 6;
}

void Blockchain::AddBlock(queue &q, Block bNew)
{
    bNew.sPrevHash = _GetLastBlock().sHash;
    bNew.MineBlock(q, _nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const
{
    return _vChain.back();
}
