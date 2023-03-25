#!/bin/bash
source /opt/intel/oneapi/setvars.sh > /dev/null 2>&1
/bin/echo "##" $(whoami) is compiling the Block Chain
icpx -fsycl src/*.cpp -o bin/TestChain -std=c++17
if [ $? -eq 0 ]; then bin/TestChain; fi
