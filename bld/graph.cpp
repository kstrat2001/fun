#include "graph.h"
#include "graphnode.h"

#include <queue>

#include <cassert>
#include <iostream>

Graph::Graph()
{
}

Graph::~Graph()
{
}

void Graph::AddNode( GraphNode* node )
{
    if( node != NULL )
    {
        mNodes.push_back( node );
    }
}

void Graph::BFS( GraphNode* node )
{
    assert( node != NULL );

    for( size_t i = 0; i < mNodes.size(); ++i )
    {
        mNodes[ i ]->SetParent( NULL );
        mNodes[ i ]->SetDistance( INT_MAX );
        mNodes[ i ]->SetColor( GraphNode::WHITE );
    }

    node->SetColor( GraphNode::GREY );
    node->SetDistance( 0 );

    std::queue<GraphNode*> nodeQueue;

    nodeQueue.push( node );

    while( !nodeQueue.empty() )
    {
        GraphNode* u = nodeQueue.front();
        nodeQueue.pop();

        for( size_t i = 0; i < u->GetAdjacentListSize(); ++i )
        {
            GraphNode* v = u->GetAdjacent( i );
            if( v->GetColor() == GraphNode::WHITE )
            {
                v->SetColor( GraphNode::GREY );
                v->SetParent( u );
                v->SetDistance( u->GetDistance() + 1 );
                nodeQueue.push( v );
            } 
        }

        u->SetColor( GraphNode::BLACK );
    }        
}

void Graph::PrintPath( GraphNode* dest ) const
{
    if( dest != NULL )
    {
        PrintPath( dest->GetParent() );
        std::cout << "Node value: " << dest->GetValue() << std::endl;
    }
}
