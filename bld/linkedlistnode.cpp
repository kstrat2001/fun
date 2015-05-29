#include "linkedlistnode.h"

#include <cassert>
#include <iostream>

using namespace std;

LinkedListNode::LinkedListNode( int val )
    :m_pNext(NULL), mVal( val )
{

}

LinkedListNode::~LinkedListNode()
{
}

bool LinkedListNode::HasNext() const
{
    return ( m_pNext != NULL );
}

size_t LinkedListNode::GetLength() const
{
    size_t count = 0;

    const LinkedListNode* current = this;

    while( current != NULL )
    {
        ++count;
        current = current->m_pNext;
    }

    return count;
}

LinkedListNode* LinkedListNode::Find( size_t index ) 
{
    LinkedListNode* retval = this;

    while( index > 0 && retval != NULL )
    {
        retval = retval->m_pNext;
        --index;
    }

    return retval;
}

void LinkedListNode::InsertNext( LinkedListNode* node )
{
    assert( node != NULL && "Expecting a non-NULL node to be set for next" );
    assert( node->HasNext() == false && "Expecting to insert a single node" );

    // If this node has a next already then push it to the front of
    // the new next node
    if( m_pNext )
    {
        node->m_pNext = m_pNext;
    }

    m_pNext = node;
}

void LinkedListNode::DumpList() const
{
    cerr << GetValue() << ", ";

    if(m_pNext != NULL)
        m_pNext->DumpList();
    else
        cerr << " NIL" << endl;
}
