#pragma once

#include <vector>

namespace gfx
{
    class IComparable;

    class ISortStrategy
    {
    public:
        virtual void Sort( std::vector<IComparable*>& sortVec ) const = 0;

        virtual ~ISortStrategy() {};
    };
}
