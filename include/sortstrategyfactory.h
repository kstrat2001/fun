#pragma once

#include "defs.h"

namespace gfx
{
    class ISortStrategy;

    class SortStrategyFactory
    {
    public:
        static ISortStrategy* CreateSortStrategy( ESortMethod method );

    private:
        SortStrategyFactory();
        ~SortStrategyFactory();
        SortStrategyFactory( const SortStrategyFactory& rhs );
        SortStrategyFactory& operator=( const SortStrategyFactory& rhs );
    };
}
