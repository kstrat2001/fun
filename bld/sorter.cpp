#include "sorter.h"
#include "sortstrategyfactory.h"
#include "isortstrategy.h"

#include <cassert>

namespace gfx
{
    Sorter::Sorter( ESortMethod method )
    {
        mSortStrategy = SortStrategyFactory::CreateSortStrategy( method );
    }

    Sorter::~Sorter()
    {
        if( mSortStrategy != NULL )
        {
            delete mSortStrategy;
        }
    }

    void Sorter::SetSortStrategy( ESortMethod method )
    {
        if( mSortStrategy != NULL )
            delete mSortStrategy;

        mSortStrategy = SortStrategyFactory::CreateSortStrategy( method );
    }

    void Sorter::Sort( std::vector<IComparable*>& sortVec ) const
    {
        assert( mSortStrategy != NULL );

        mSortStrategy->Sort( sortVec);
    }
}
