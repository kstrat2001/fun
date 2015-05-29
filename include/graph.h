#include <vector>

class GraphNode;

class Graph
{
    public:
        Graph();
        ~Graph();

        void AddNode( GraphNode* node );

        void BFS( GraphNode* node );
        void PrintPath( GraphNode* node ) const;

    private:

        std::vector<GraphNode*> mNodes;
};
