#include "treenode.h"

#include <iostream>

TreeNode::TreeNode( int key )
 : mKey( key ),
   mParent( NULL ),
   mLeft( NULL ),
   mRight( NULL )
{
}

TreeNode::~TreeNode()
{
}

void TreeNode::Insert( TreeNode* node )
{
    if( node != NULL && node->GetKey() != mKey )
    {
        if( mKey > node->GetKey() )
        {
            if( mLeft != NULL )
                mLeft->Insert( node );
            else
            {
                mLeft = node;
                node->mParent = this;
            }
        }
        else
        {
            if( mRight != NULL )
                mRight->Insert( node );
            else
            {
                mRight = node;
                node->mParent = this;
            }
        }
    }
}

int TreeNode::GetMin() const
{
    int retval = GetKey();

    if( mLeft != NULL )
    {
        retval = mLeft->GetMin();
    }

    return retval;
}

int TreeNode::GetMax() const
{
    int retval = GetKey();

    if( mRight != NULL )
    {
        retval = mRight->GetMax();
    }

    return retval;
}

void TreeNode::InOrderWalk() const
{
    if( mLeft != NULL )
    {
        mLeft->InOrderWalk();
    }

    std::cout << mKey << std::endl;

    if( mRight != NULL )
    {
        mRight->InOrderWalk();
    }
}

const TreeNode* TreeNode::Search( int key ) const
{
    const TreeNode* retval = this;

    while( retval != NULL && retval->GetKey() != key )
    {
        if( key > retval->GetKey() )
            retval = retval->mRight;
        else
            retval = retval->mLeft;
    }

    return retval;
}
