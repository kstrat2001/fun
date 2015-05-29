#include "mergesortstrategy.h"
#include "icomparable.h"

#include <vector>
#include <iostream>

namespace gfx
{
    void MergeSortStrategy::Sort(
            std::vector<IComparable*>& sortVec ) const
    {
        std::vector<IComparable*>::iterator middle = sortVec.begin() + ( sortVec.size() / 2 );
        std::vector<IComparable*> leftVec( sortVec.begin(), middle );
        std::vector<IComparable*> rightVec( middle, sortVec.end() );

        if( leftVec.size() > 1 )
        {
            Sort( leftVec );
        }
        if( rightVec.size() > 1 )
        {
            Sort( rightVec );
        }

        MergeArrays( leftVec, rightVec, sortVec );
    }

    void MergeSortStrategy::MergeArrays( const std::vector<IComparable*>& vec1, 
                                         const std::vector<IComparable*>& vec2,
                                         std::vector<IComparable*>& result ) const
    {
        result.clear();

        size_t index1 = 0;
        size_t index2 = 0;

        while( index1 < vec1.size() && index2 < vec2.size() )
        {
            if( vec1[index1]->Compare( *vec2[index2] ) < 0 )
            {
                result.push_back( vec1[index1] );
                ++index1;
            }
            else
            {
                result.push_back( vec2[index2] );
                ++index2;
            }
        }
        while( index1 < vec1.size() )
        {
            result.push_back( vec1[index1] );
            ++index1;
        }
        while( index2 < vec2.size() )
        {
            result.push_back( vec2[index2] );
            ++index2;
        }
    }
}
