#pragma once

#include "defs.h"

#include <vector>

namespace gfx
{
    class IComparable;
    class ISortStrategy;

    class Sorter
    {
    public:
        Sorter( ESortMethod method );
        ~Sorter();

        void SetSortStrategy( ESortMethod method );
        void Sort( std::vector<IComparable*>& sortVec ) const;

    private:
        ISortStrategy* mSortStrategy;
    };
}
