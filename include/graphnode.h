#pragma once

#include <vector>

class GraphNode
{
public:
    enum Color
    {
        WHITE = 0,
        GREY,
        BLACK
    };

public:
    GraphNode( int value );
    ~GraphNode();

    size_t GetAdjacentListSize() const;
    GraphNode* GetAdjacent( size_t index ) const;

    Color GetColor() const { return mColor; }
    int   GetDistance() const { return mDistance; }
    GraphNode* GetParent() const { return mParent; }
    int GetValue() const { return mValue; }

    void Connect( GraphNode* node );

    void SetParent( GraphNode* node );
    void SetColor( Color color );
    void SetDistance( int distance );

private:

    std::vector<GraphNode*> mAdjList;

    int mValue;
    Color mColor;    // used for BFS/DFS
    GraphNode* mParent; // parent in BFS/DFS tree
    int mDistance; // Distance from search node

};
