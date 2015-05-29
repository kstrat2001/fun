#pragma once

#include <cstdlib>

class LinkedListNode
{
public:
    LinkedListNode( int val );
    virtual ~LinkedListNode();

    void InsertNext( LinkedListNode* node );
    bool HasNext() const;
    size_t GetLength() const;
    LinkedListNode* Find( size_t index );

    int GetValue() const { return mVal; }
    void DumpList() const;

private:
    LinkedListNode* m_pNext;
    int mVal;
};
