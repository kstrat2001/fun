#include "heap.h"

#include <stdlib.h>
#include <iostream>

namespace gfx
{

Heap::Heap()
{
    std::cout << "Heap Created" << std::endl;
}

Heap::~Heap()
{
    std::cout << "Heap Destroyed" << std::endl;
}

void* Heap::AllocateBlock(unsigned int size)
{
    return malloc(size);
}

}
