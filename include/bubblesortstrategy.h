#pragma once

#include "isortstrategy.h"

namespace gfx
{
    class BubbleSortStrategy : public ISortStrategy
    {
        virtual void Sort( std::vector<IComparable*>& sortVec ) const;

        bool CheckPair( const IComparable& left, 
                        const IComparable& right ) const;
    };
}
