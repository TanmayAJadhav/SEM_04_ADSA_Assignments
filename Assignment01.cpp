// Beginning with an empty binary tree, construct binary tree by inserting the values in the order given. After constructing a binary tree perform following operations onit-
// • Perform inorder, preorder and post order traversal (Implement both recursive and non-recursive methods)
// • Change a tree so that the roles of the left and right pointers are swapped at every node 
// • Find the height of tree
// • Copy this tree to another [operator=] 
// • Count number of leaves, number of internal nodes. 
// • Erase all nodes in a binary tree.

#include <iostream>
using namespace std;

class TreeNode
{
private:
    int data;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode()
    {
        left = NULL;
        right = NULL;
    }
    friend class BinaryTree;
};

#define MAX 50
template <typename T>
class Stack
{
private:
    T data[MAX];
    int Top;

public:
    Stack()
    {
        Top = -1;
    }

    bool isEmpty()
    {
        if (Top == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (Top == MAX - 1)
        {
            return true;
        }
        return false;
    }

    void push(T element)
    {
        if (isFull())
        {
            cout << "Stack is Full !" << endl;
            return;
        }
        data[++Top] = element;
    }

    T pop()
    {
        if (isEmpty())
        {
            return 0;
        }
        else
        {
            int index = Top;
            Top--;
            return data[index];
        }
    }

    T top()
    {
        if (isEmpty())
        {
            return 0;
        }
        return data[Top];
    }
};

class BinaryTree
{
    TreeNode *root;

public:
    BinaryTree()
    {
        root = NULL;
    }

    void create()
    {
        char choice1, choice2;
        do
        {
            TreeNode *newn = new TreeNode();
            cout << "Enter the element to add" << endl;
            cin >> newn->data;

            if (root == NULL)
            {
                root = newn;
                cout << newn->data << " is set as current" << endl;
            }
            else
            {
                TreeNode *temp = root;
                bool flag = false;

                do
                {
                    cout << "Where do you want to add the add " << newn->data << ", to [L/R] of " << temp->data << endl;
                    cin >> choice2;
                    if (choice2 == 'L' || choice2 == 'l')
                    {
                        if (temp->left == NULL)
                        {
                            temp->left = newn;
                            cout << "Element added to left of " << temp->data << endl;
                            flag = true;
                        }
                        else
                        {
                            temp = temp->left;
                        }
                    }
                    else
                    {
                        if (temp->right == NULL)
                        {
                            temp->right = newn;
                            cout << "Element added to right of " << temp->data << endl;
                            flag = true;
                        }
                        else
                        {
                            temp = temp->right;
                        }
                    }
                } while (flag == false);
            }
            cout << "\nDo you want to add more TreeNode [y/n]" << endl;
            cin >> choice1; cout<<endl;
            
        } while (choice1 == 'y' || choice1 == 'Y');
    }

    void inorder_rec(TreeNode *current)
    {
        if (current == NULL)
        {
            return;
        }
        else
        {
            inorder_rec(current->left);
            cout << current->data << " ";
            inorder_rec(current->right);
        }
    }

    void inorder_rec()
    {
        inorder_rec(root);
    }

    void inorder_itr()
    {
        TreeNode *temp = root;
        bool flag = false;
        Stack<TreeNode *> st;
        if (temp == NULL)
        {
            return;
        }
        do
        {
            while (temp != NULL)
            {
                st.push(temp);
                temp = temp->left;
            }
            if (st.isEmpty() == false)
            {
                temp = st.pop();
                cout << temp->data << " ";
                temp = temp->right;
            }
            else
            {
                flag = true;
            }
        } while (flag == false);
    }

    void preorder_rec(TreeNode *current)
    {
        if (current == NULL)
        {
            return;
        }
        else
        {
            cout << current->data << " ";
            preorder_rec(current->left);
            preorder_rec(current->right);
        }
    }

    void preorder_rec()
    {
        preorder_rec(root);
    }

    void preorder_itr()
    {
        TreeNode *current = root;
        Stack<TreeNode *> st;
        if (current == NULL)
        {
            return;
        }
        else
        {
            st.push(current);
            while (st.isEmpty() == false)
            {
                current = st.pop();
                cout << current->data << " ";
                if (current->right != NULL)
                {
                    st.push(current->right);
                }
                if (current->left != NULL)
                {
                    st.push(current->left);
                }
            }
        }
    }

    void postorder_rec(TreeNode *current)
    {
        if (current == NULL)
        {
            return;
        }
        else
        {
            postorder_rec(current->left);
            postorder_rec(current->right);
            cout << current->data << " ";
        }
    }

    void postorder_rec()
    {
        postorder_rec(root);
    }

    void postorder_itr()
    {
        Stack<TreeNode*> st1;
        Stack<TreeNode*> st2;
        TreeNode* current = root;
        st1.push(current);
        while (st1.isEmpty() == false)
        {
            current = st1.pop();
            st2.push(current);
            if(current->left != NULL)
            {
                st1.push(current->left);
            }
            if(current->right != NULL)
            {
                st1.push(current->right);
            }
        }
        while (st2.isEmpty() == false)
        {
            cout<<st2.pop()->data<<" ";
        }    
    }

    int heightOfTree(TreeNode *current)
    {
        int lheight, rheight;
        if (current == NULL)
        {
            return -1;
        }
        else
        {
            lheight = heightOfTree(current->left);
            rheight = heightOfTree(current->right);

            if (lheight > rheight)
            {
                return (lheight + 1);
            }
            else
            {
                return (rheight + 1);
            }
        }
    }

    int heightOfTree()
    {
        return heightOfTree(root);
    }

    int numberOfLeaves(TreeNode *current)
    {
        if (current == NULL)
        {
            return 0;
        }
        if (current->left == NULL && current->right == NULL)
        {
            return 1;
        }
        else
        {
            int leftLeaves = numberOfLeaves(current->left);
            int rightLeaves = numberOfLeaves(current->right);
            int totalLeaves = leftLeaves + rightLeaves;
            return totalLeaves;
        }
    }

    int numberOfLeaves()
    {
        return numberOfLeaves(root);
    }

    int numberOfInternalNodes(TreeNode *current)
    {
        if ((current == NULL) || ((current->left == NULL) && (current->right == NULL)))
        {
            return 0;
        }
        else
        {
            return (numberOfInternalNodes(current->left) + numberOfInternalNodes(current->right) + 1);
        }
    }

    int numberOfInternalNodes()
    {
        TreeNode *temp = root;
        return numberOfInternalNodes(temp);
    }

    void swapTree(TreeNode *current)
    {
        if (current == NULL)
        {
            return;
        }

        TreeNode *temp = current->left;
        current->left = current->right;
        current->right = temp;

        swapTree(current->left);
        swapTree(current->right);
    }

    void swapTree()
    {
        TreeNode *temp = root;
        swapTree(temp);
    }

    BinaryTree operator=(BinaryTree tree)
    {
        if (tree.root == NULL)
        {
            return tree;
        }

        root = tree.root;
        Copy(tree.root->left, root->left);
        Copy(tree.root->right, root->right);
    }

    void Copy(TreeNode *temp, TreeNode *ctemp)
    {
        if (temp == NULL)
        {
            return;
        }

        ctemp = new TreeNode();
        ctemp->data = temp->data;
        Copy(temp->left, ctemp->left);
        Copy(temp->right, ctemp->right);
    }


    void deleteTree(TreeNode *current)
    {
        if (current == NULL)
        {
            return;
        }
        else
        {
            deleteTree(current->left);
            deleteTree(current->right);
            cout << "Deleted node: " << current->data << endl;
            delete current;
        }
    }

    void deleteTree()
    {
        deleteTree(root);
    }
};

int main()
{
    BinaryTree obj,Copy;
    int val;
    TreeNode *current = NULL;
    int choice = 0;

    do
    {
        cout << "\n------------Menu------------\n";
        cout << " 1) Create Binary Tree \n";
        cout << " 2) Display Binary Tree in InOrder \n";
        cout << " 3) Display Binary Tree in PreOrder \n";
        cout << " 4) Display Binary Tree in PostOrder \n";
        cout << " 5) Swap of Binary Tree \n";
        cout << " 6) Height of Binary Tree \n";
        cout << " 7) Number of Lead Nodes of Binary Tree \n";
        cout << " 8) Number of Internal Nodes of Binary Tree \n";
        cout << " 9) Deleting the Binary Tree \n";
        cout<<"   10) Copy Tree\n";
        cout << "\nEnter your choice\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.create();
            break;
        case 2:
            cout << "Display Binary Tree in InOrder:" << endl;
            cout << "In Recursive way : " << endl;
            obj.inorder_rec();
            cout << "\nIn Iterative way : " << endl;
            obj.inorder_itr();
            cout << endl;
            break;
        case 3:
            cout << "Display Binary Tree in PreOrder:" << endl;
            cout << "In Recursive way : " << endl;
            obj.preorder_rec();
            cout << "\nIn Iterative way : " << endl;
            obj.preorder_itr();
            cout << endl;
            break;
        case 4:
            cout << "Display Binary Tree in PostOrder: " << endl;
            cout << "In Recursive way : " << endl;
            obj.postorder_rec();
            cout << endl;
            cout << "\nIn Iterative way : " << endl;
            obj.postorder_itr();
            cout << endl;
            break;
        case 5:
            cout << "Before Swapping (Inorder): " << endl;
            obj.inorder_rec();
            obj.swapTree();
            cout<<" After Swapping (Inorder): "<<endl;
            obj.inorder_rec();
            cout << endl;
            break;
        case 6:
            cout << "Height of Binary Tree is : " << obj.heightOfTree() << endl;
            cout << endl;
            break;
        case 7:
            cout << "Number of Leaf Nodes of Binary Tree is :- " << obj.numberOfLeaves() << endl;
            cout << endl;
            break;
        case 8:
            cout << "Number of Internal Nodes of Binary Tree is :- " << obj.numberOfInternalNodes()<< endl;
            cout << endl;
            break;
        case 9:
            obj.deleteTree();
            cout << "Binary Tree Deleted Successfully !" << endl;
            cout << endl;
            break;

        case 10:
            Copy = obj;
            cout << "Successfully copied!\n";
            Copy.inorder_rec();
            break;
        default:
            cout<<"Enter another choice.\n";
            break;
        }
    } while (choice != 10);


    return 0;
}
