#pragma once

#include "isortstrategy.h"

namespace gfx
{
    class QuickSortStrategy : public ISortStrategy
    {
        virtual void Sort( std::vector<IComparable*>& sortVec ) const;

        void QuickSort( std::vector<IComparable*>& sortVec, size_t left, size_t right ) const;
    };
}
