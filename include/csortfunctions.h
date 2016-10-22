#pragma once

#include <cstdlib>
#include <iostream>
#include <cassert>

template <class T>
void swap( T& a, T& b )
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
size_t partition( T arr[ ], size_t start, size_t end, size_t pivot )
{
    size_t index = start;
    T pivotVal = arr[ pivot ];

    swap( arr[ end ], arr[ pivot ] );

    for( size_t i = start; i < end; ++i )
    {
        if( arr[ i ] <= pivotVal )
        {
            swap( arr[ i ], arr[ index ] );
            ++index;
        }
    }

    swap( arr[ index ], arr[ end ] );

    return index;
}

template <class T>
void quickSortPartition( T arr[ ], size_t start, size_t end )
{
    if( end > start )
    {
        size_t pivot = start + (( end - start ) / 2 );

        pivot = partition( arr, start, end, pivot );

        quickSortPartition( arr, start, pivot );
        quickSortPartition( arr, pivot + 1, end );
    }
}

template <class T>
void quickSort( T arr[ ], size_t size )
{
    quickSortPartition( arr, 0, size - 1 );
}

template <class T>
void merge( T arr1[ ], T arr2[ ], size_t size1, size_t size2, T arrOut[ ] )
{
    size_t index1 = 0;
    size_t index2 = 0;

    while( index1 < size1 && index2 < size2 )
    {
        if( arr1[ index1 ] < arr2[ index2 ] )
        {
            arrOut[ index1 + index2 ] = arr1[ index1 ];
            ++index1;
        }
        else
        {
            arrOut[ index1 + index2 ] = arr2[ index2 ];
            ++index2;
        }
    }

    if( index1 == size1 )
    {
        memcpy( arrOut + index1 + index2, arr2 + index2, ( size2 - index2 ) * sizeof(T) );
    }
    else
    {
        memcpy( arrOut + index1 + index2, arr1 + index1, ( size1 - index1 ) * sizeof(T) );
    }
}

template <class T>
void mergeSort( T arr[ ], size_t size )
{
    if( size > 1 )
    {
        size_t size1 = size / 2;
        size_t size2 = size - size1;

        T* arr1 = new T[ size1 ];
        T* arr2 = new T[ size2 ];

        memcpy( arr1, arr, size1 * sizeof(T) );
        memcpy( arr2, arr + size1, size2 * sizeof(T) );

        mergeSort( arr1, size1 );
        mergeSort( arr2, size2 );

        merge( arr1, arr2, size1, size2, arr );

        delete [ ] arr1;
        delete [ ] arr2;
    }
}

size_t leftChild( size_t index )
{
    return ( 2 * index ) + 1;
}

size_t rightChild( size_t index )
{
    return ( 2 * index ) + 2;
}

template <class T>
void maxHeapify( T arr[ ], size_t size, size_t index )
{
    size_t left = leftChild( index );
    size_t right = rightChild( index );

    size_t largest = index;

    if( left < size && arr[ left ] > arr[ index ] )
        largest = left;

    if( right < size && arr[ right ] > arr[ largest ] )
        largest = right; 

    if( largest != index )
    {
        swap( arr[ index ], arr[ largest ] );
        maxHeapify( arr, size, largest );
    }
}

template <class T>
void buildMaxHeap( T arr[ ], size_t size )
{
    // get the last parent in the array
    for( int i = (size - 2) / 2; i >= 0; --i )
    {
        maxHeapify( arr, size, i );
    }
}

template <class T>
void heapSort( T arr[ ], size_t size )
{
    if( size > 1 )
    {
        buildMaxHeap( arr, size );

        for( size_t newSize = size - 1; newSize > 1; --newSize )
        {
            swap( arr[ 0 ], arr[ newSize] );
            maxHeapify( arr, newSize, 0 );
        }

        swap( arr[ 0 ], arr[ 1 ] );
    }
}

template <class T>
void bubbleSort( T arr[ ], size_t size )
{
    bool swapped = false;

    do
    {
        swapped = false;

        for( size_t i = 0; i < size - 1; ++i )
        {
            if( arr[ i ] > arr[ i + 1 ] )
            {
                swap( arr[ i ], arr[ i + 1 ] );
                swapped = true;
            }                
        }
    }
    while( swapped == true );
}
