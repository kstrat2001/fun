#pragma once

#include "isortstrategy.h"

namespace gfx
{
    class MergeSortStrategy : public ISortStrategy
    {
        virtual void Sort( std::vector<IComparable*>& sortVec ) const;

        void MergeArrays( const std::vector<IComparable*>& vec1, 
                          const std::vector<IComparable*>& vec2,
                          std::vector<IComparable*>& result ) const;
    };
}
