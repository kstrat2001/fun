#include "bubblesortstrategy.h"
#include "icomparable.h"

#include <vector>
#include <iostream>

namespace gfx
{
    void BubbleSortStrategy::Sort(
            std::vector<IComparable*>& sortVec ) const
    {
        std::cout << "Performing bubble sort on " << sortVec.size() << " objects" << std::endl;

        bool swappedPair = false;

        do
        {
            swappedPair = false;

            for( size_t i = 0; i < sortVec.size() - 1; ++i )
            {
                if( CheckPair( *sortVec[i], *sortVec[ i + 1 ] ) )
                {
                    IComparable* tmp = sortVec[ i ];
                    sortVec[ i ] = sortVec[ i + 1 ];
                    sortVec[ i + 1 ] = tmp;

                    swappedPair = true;
                }
            }
        }
        while( swappedPair );
    }

    bool BubbleSortStrategy::CheckPair( const IComparable& left, 
                                        const IComparable& right ) const
    {
        return (left.Compare(right) > 0);
    }
}
