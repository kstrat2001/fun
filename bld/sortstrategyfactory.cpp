#include "sortstrategyfactory.h"

#include "bubblesortstrategy.h"
#include "mergesortstrategy.h"
#include "quicksortstrategy.h"
#include "insertionsortstrategy.h"

namespace gfx
{
    class ISortStrategy;

    ISortStrategy* SortStrategyFactory::CreateSortStrategy( ESortMethod method )
    {
        ISortStrategy* pStrategy = NULL;

        switch( method )
        {
        case eBubbleSort:
            pStrategy = new BubbleSortStrategy();
            break;
        case eMergeSort:
            pStrategy = new MergeSortStrategy();
            break;
        case eQuickSort:
            pStrategy = new QuickSortStrategy();
            break;
        case eInsertionSort:
            pStrategy = new InsertionSortStrategy();
            break;
        default:
            break;
        }

        return pStrategy;
    }
}
