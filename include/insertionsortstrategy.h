#pragma once

#include "isortstrategy.h"

namespace gfx
{
    class InsertionSortStrategy : public ISortStrategy
    {
        virtual void Sort( std::vector<IComparable*>& sortVec ) const;
    };
}
