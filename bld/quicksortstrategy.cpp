#include "quicksortstrategy.h"
#include "icomparable.h"

#include <vector>
#include <iostream>

namespace gfx
{
    void QuickSortStrategy::Sort(
            std::vector<IComparable*>& sortVec ) const
    {
        QuickSort( sortVec, 0, sortVec.size() - 1 );
    }

    void Swap( std::vector<IComparable*>& vec, size_t index1, size_t index2 )
    {
        if( index1 != index2 )
        {
            IComparable* tmp = vec[index1];
            vec[index1] = vec[index2];
            vec[index2] = tmp;
        }
    }

    size_t Partition( std::vector<IComparable*>& vec, size_t pivotIndex, size_t left, size_t right )
    {
        int pivotVal = vec[pivotIndex]->GetValue();
        Swap( vec, right, pivotIndex );

        pivotIndex = left;

        for( size_t i = left; i < right; ++i )
        {
            if( vec[ i ]->GetValue() <= pivotVal )
            {
                Swap( vec, i, pivotIndex );
                ++pivotIndex;
            }
        }

        Swap( vec, pivotIndex, right );

        return pivotIndex;
    }

    void QuickSortStrategy::QuickSort( std::vector<IComparable*>& sortVec, size_t left, size_t right ) const
    {
        if( left < right )
        {
            size_t pivotIndex = left + ( ( right - left ) / 2 );

            pivotIndex = Partition( sortVec, pivotIndex, left, right );

            QuickSort( sortVec, left, pivotIndex );
            QuickSort( sortVec, pivotIndex + 1, right );
        }
    }
}
