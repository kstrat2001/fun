#include "insertionsortstrategy.h"
#include "icomparable.h"

#include <vector>
#include <iostream>

namespace gfx
{
    void InsertionSortStrategy::Sort(
            std::vector<IComparable*>& sortVec ) const
    {
        for( size_t i = 1; i < sortVec.size(); ++i )
        {
            size_t numShift = 0;

            int j = i - 1;

            while( j >= 0 && sortVec[i]->Compare( *sortVec[j] ) < 0 )
            {
                ++numShift;
                --j;
            }

            if( numShift > 0 )
            {
                IComparable* tmp = sortVec[ i ];

                // Shift the values greater than temp
                for( size_t k = 0; k < numShift; ++k )
                {
                    sortVec[i - k] = sortVec[ i - k - 1];
                }

                // Insert the temp value
                sortVec[ i - numShift ] = tmp;
            }
        }
    }
}
