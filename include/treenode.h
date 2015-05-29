
class TreeNode
{
public:
    TreeNode( int key );
    ~TreeNode();

    int GetKey() const { return mKey; }

    void Insert( TreeNode* node );
    int GetMin() const;
    int GetMax() const;

    const TreeNode* Search( int key ) const;

    void InOrderWalk() const;

private:

    int mKey;

    TreeNode* mParent;
    TreeNode* mLeft;
    TreeNode* mRight;
};
