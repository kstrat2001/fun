#include "heap.h"
#include "block.h"
#include "sorter.h"
#include "defs.h"

#include "csortfunctions.h"
#include "linkedlistnode.h"
#include "hashmap.h"
#include "graphnode.h"
#include "graph.h"
#include "treenode.h"

#include <vector>
#include <iostream>
#include <iomanip>

using namespace gfx;
using namespace std;

void testHeap( size_t numBlocks );
void testSort( size_t arrSize );
void testList();
void testHash();
void testGraph();
void testTree( size_t size );

int main()
{
    //testHeap(10);

    testSort( 10 );

    //testHash();

    //testList();
    
    //testGraph();

    //testTree(10);

    return 0;
}

void testTree( size_t size )
{
    TreeNode root(50);

    for( size_t i = 0; i < size; ++i )
    {
        TreeNode* node = new TreeNode( rand() % 100 );
        root.Insert( node );
    }

    cout << "In Order Walk: " << endl;
    root.InOrderWalk();
    cout << "GetMin: " << root.GetMin() << endl;
    cout << "GetMax: " << root.GetMax() << endl;

    const TreeNode* searchNode = root.Search( 58 );
    cout << "Searched for 58: " << searchNode << endl;

    searchNode = root.Search( -20 );
    cout << "Searched for -20: " << searchNode << endl;

    searchNode = root.Search( 200 );
    cout << "Searched for 200: " << searchNode << endl;

    searchNode = root.Search( 59 );
    cout << "Searched for 59: " << searchNode << endl;
}

void testGraph()
{
    GraphNode* node1 = new GraphNode( 1 );
    GraphNode* node2 = new GraphNode( 2 );
    GraphNode* node3 = new GraphNode( 3 );
    GraphNode* node4 = new GraphNode( 4 );

    node1->Connect( node2 );
    node2->Connect( node3 );
    node1->Connect( node4 );

    Graph* graph = new Graph();
    graph->AddNode( node1 );
    graph->AddNode( node2 );
    graph->AddNode( node3 );
    graph->AddNode( node4 );

    cout << "Do BFS pass" << endl;
    graph->BFS( node1 );

    cout << "Distance from node1 to node2: " << node2->GetDistance() << endl;
    cout << "Distance from node1 to node3: " << node3->GetDistance() << endl;
    cout << "Distance from node1 to node4: " << node4->GetDistance() << endl;

    cout << "Print path to 4" << endl;
    graph->PrintPath( node4 );

    cout << "Print path to 3" << endl;
    graph->PrintPath( node3 );

}

void testHash()
{
    HashMap<int> map(97);

    int n1 = 10;
    int n2 = 13; 

    map.Insert( "n10", &n1 );
    map.Insert( "n13", &n2 );

    int* found = map.Find( "n13" );
    int* not_found = map.Find( "n13000" );

    cout << "Found = " << found << ", not_found = " << not_found << endl;
    cout << "Value of found = " << *found  << endl;

    cout << "LoadFactor = " << setprecision( 2 ) << map.GetLoadFactor() << endl;
}

void testList()
{
    cerr << "Testing list" << endl;
    LinkedListNode node1(1);
    LinkedListNode node2(2);
    LinkedListNode node3(3);

    node1.InsertNext( &node3 );
    node1.InsertNext( &node2 );
    node1.DumpList();

    cerr << "List count: " << node1.GetLength() << endl;

    LinkedListNode* pNode = node1.Find(2);
    cerr << "Find 3rd Node: " << pNode << ", value: " << pNode->GetValue() << endl;

    LinkedListNode* pNodeNil = node1.Find(3);
    cerr << "Find 4th Node: " << pNodeNil << endl;
}

void testSort( size_t arrSize )
{
    int* arr = new int[ arrSize ];

    cerr << "Initialize array for sort" << endl;
    for( size_t i = 0; i < arrSize; ++i )
    {
        arr[ i ] = rand() % 1000;
        cerr << "arr[ " << i << " ] = " << arr[ i ] << endl;
    }

    //mergeSort( arr, arrSize );
    quickSort( arr, arrSize );
    //heapSort( arr, arrSize );
    //bubbleSort( arr, arrSize );

    cerr << "Array after sort" << endl;
    for( size_t i = 0; i < arrSize; ++i )
    {
        cerr << "arr[ " << i << " ] = " << arr[ i ] << endl;
    }
}

void testHeap( size_t numBlocks )
{
    gfx::Heap testHeap;

    std::vector<IComparable*> blockVec;
    blockVec.resize(numBlocks);

    std::cout << "populating " << numBlocks << " blocks: " << std::endl;
    for( size_t i = 0; i < numBlocks; ++i )
    {
        size_t size = rand();
        std::cout << "Block[ " << i << " ] = " << size << std::endl;
        blockVec[ i ] = new Block(size);
    }

    gfx::Sorter sorter( eInsertionSort );
    sorter.Sort(blockVec);

    std::cout << "Dumping blockVec: " << std::endl;

    for( size_t i = 0; i < numBlocks; ++i )
    {
        std::cout << "blockVec[ " << i << " ] = " << blockVec[ i ]->GetValue() << std::endl;
    }

    char c;
    std::cin >> c;

    for( size_t i = 0; i < numBlocks; ++i )
    {
        delete blockVec[ i ];
    }
} 