#include "graphnode.h"

#include <climits>

GraphNode::GraphNode( int value )
    : mValue( value ),
      mColor( WHITE ),
      mParent( NULL ),
      mDistance( INT_MAX )
{
}

GraphNode::~GraphNode()
{
}

size_t GraphNode::GetAdjacentListSize() const
{
    return mAdjList.size();
}

GraphNode* GraphNode::GetAdjacent( size_t index ) const
{
    GraphNode* retval = NULL;

    if( index < mAdjList.size() )
    {
        retval = mAdjList[ index ];
    }

    return retval;
}

void GraphNode::Connect( GraphNode* node )
{
    if( node != NULL )
    {
        mAdjList.push_back( node );
    }
}

void GraphNode::SetParent( GraphNode* node )
{
    mParent = node;
}

void GraphNode::SetColor( Color color )
{
    mColor = color;
}

void GraphNode::SetDistance( int distance )
{
    mDistance = distance;
}
