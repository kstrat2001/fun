#pragma once

#include <string>
#include <cassert>
#include <iostream>

template <class T>
class HashMap
{
public:
    HashMap( size_t size )
    :  m_pBucketArr( NULL ),
      mSize( size ),
      mNumEntries(0)
    {
        assert( size != 0 && "Hash initial size must be greater than 0!!" );

        std::cout << "Initializing hash map with " << size << " buckets" << std::endl;
        m_pBucketArr = new T*[ size ];

        // Initialize all buckets to null 
        for( size_t i = 0; i < size; ++i )
        {
            m_pBucketArr[ i ] = NULL;
        }
    }

    ~HashMap()
    {
        delete [ ] m_pBucketArr;
    }


    void Insert( const std::string& key, T* pValue )
    {
        assert( pValue != NULL && "Must insert a non-null value" );

        unsigned long hash = Hash( key );

        if( m_pBucketArr[ hash ] != NULL )
        {
            assert( false && "collision!" );
        }
        else
        {
            std::cout << "Inserting < " << key << ", " << *pValue << " > : hash = " << hash << std::endl;
            m_pBucketArr[ hash ] = pValue;
            ++mNumEntries;
        }
    }

    void Remove( const std::string& key )
    {
        unsigned long hash = Hash( key );

        m_pBucketArr[ hash ] = NULL;
        --mNumEntries;
    }

    T* Find( const std::string& key ) const
    {
        std::cout << "Locating \"" << key << "\"" << std::endl;
        unsigned long hash = Hash( key );
        return m_pBucketArr[ hash ];
    }

    float GetLoadFactor() const
    {
        return (float)mNumEntries / (float)mSize;
    }

private:

    unsigned long Hash( const std::string& key ) const
    {
        assert( key.empty() == false && "Must use a key with at least 1 character" );
        std::cout << "Hashing key \"" << key << "\" = "; 
        // use djb2 hash method
        unsigned long hash = 5381;
        const char* str = key.c_str();
        int c = *str;
        
        while( c )
        {
            c = *str++;
            hash = (( hash << 5 ) + hash ) + c;
        }

        std::cout << hash << ", % mSize ( " << mSize << " ) = " << ( hash % mSize ) << std::endl;

       return hash % mSize; 
    }

private:
    T** m_pBucketArr;
    size_t mSize;
    size_t mNumEntries;
};
