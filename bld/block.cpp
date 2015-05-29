#include "block.h"

#include <iostream>

namespace gfx
{
    Block::Block( unsigned int size )
     :mSize(size)
    {
    }

    Block::~Block()
    {
    }

    int Block::GetValue() const
    {
        return static_cast<int>(mSize);
    }
}
