// Create an inordered threaded binary tree and perform inorder and preorder traversals.Analyze time and space complexity of the algorithm.

#include <iostream>
using namespace std;

class TreeNode
{
private:
    int data;
    bool rFlag;
    bool lFlag;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode()
    {
        data = 0;
        rFlag = 0;
        lFlag = 0;
        left = NULL;
        right = NULL;
    }
    friend class ThreadedBinaryTree;
};

class ThreadedBinaryTree
{
private:
    TreeNode *root;

public:
    ThreadedBinaryTree()
    {
        root = NULL;
    }

    void insertNode(int val)
    {
        TreeNode *newn = new TreeNode();
        newn->data = val;

        if (root == NULL)
        {
            root = newn;
            root->left = newn;
            root->right = newn;
            root->rFlag = 1;
            root->lFlag = 1;
            cout<<"Root Inserted\n";
        }
        else
        {

            TreeNode *current = root;
            while (true)
            {
                if(current->data > val)
                {
                    if(current->lFlag == 1)
                    {
                        newn->left = current->left;
                        newn->right = current;
                        current->left = newn;
                        newn->lFlag = 1;
                        newn->rFlag = 1;
                        current->lFlag = 0;
                        cout<<"Left Inserted\n";
                        break;
                    }
                    else
                    {
                        current = current->left;
                    }
                }
                else
                {
                    if(current->rFlag == 1)
                    {
                        newn->right = current->right;
                        newn->left = current;
                        current->right = newn;
                        newn->lFlag = 1;
                        newn->rFlag = 1;
                        current->rFlag = 0;
                        cout<<"Right Inserted\n";
                        break;
                    }
                    else
                    {
                        current = current->right;
                    }
                }
            }
        }
    }

    TreeNode *findSuccessor(TreeNode *current)
    {
        if(current->rFlag == 1)
        {
            return current->right;
        }
        else
        {
            TreeNode *temp = current->right;
            while (temp->lFlag == 0)
            {
                temp = temp->left;
            }
            return temp;
        }
    }

    void inOrderTraversal()
    {
        TreeNode *current = root;

        while(current->lFlag == 0)
        {
        	current = current->left;
        }
        cout<<current->data<<" ";
        while(current->right != root || current->data < root->data)
        {
        	current = findSuccessor(current);
        	cout<<current->data<<" ";
        }
        cout<<endl;
    }

    void preOrderTraversal(int n)
    {
    	TreeNode *current = root;
    	bool flag = 0;
    	cout<<current->data<<" ";
        int cnt = 0;
    	while(current->right != root || current->data <= root->data || cnt != n-1)
    	{
    		while((current->lFlag == 0) && (flag == 0))
    		{
    			current = current->left;
                cnt++;
    			cout<<current->data<<" ";
    		}
    		if(current->rFlag == 0)
    		{
                cnt++;
    			current = current->right;
    			cout<<current->data<<" ";
    			flag = 0;
    		}
    		else
    		{
    			current = current->right;
    			flag = 1;
    		}
    	}

    }
};

int main()
{
    ThreadedBinaryTree tobj;
    int no,ele;
    cout<<"Enter number of elements\n";
    cin>>no;

    for(int i = 0; i < no; i++)
    {
        cout<<"Enter ele \n";
        cin>>ele;
        tobj.insertNode(ele);
    }
    cout<<"Inorder Traversal \n";
    tobj.inOrderTraversal();
    cout<<"Preorder Traversal \n";
    tobj.preOrderTraversal(no);
    return 0;
}
