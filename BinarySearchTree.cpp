#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string info;
    Node* leftchild;
    Node* rightchild;

    //constructor for the node class
    Node(string i, Node* l, Node* r)
    {
        info = i;
        leftchild = l;
        rightchild = r;
    }  
};

class BinaryTree
{
public:
    Node* ROOT;

    BinaryTree()
    {
        ROOT = nullptr; //Initializing ROOT to null
    }

    void insert(string element) // insert a node in the binary search tree
    {
       Node* newNode = new Node(element, nullptr, nullptr); // alocate memory for the new node
       newNode->info = element; //Assign value to the data field of the new node
       newNode->leftchild = nullptr; //Make the  left child of the new node point to null
       newNode->rightchild = nullptr; //Make the  left child of the new node point to null

       Node* parent = nullptr;
       Node* currentNode = nullptr;
       search(element,parent,currentNode); //Locate the node which wiil be teh parent of the new node to be insert

       if (parent == nullptr) //if the parent is NULL (Tree is empty)
       {
            ROOT = newNode; //Mark the new node as ROOT
            return; // exit
       }

       if (element < parent->info)      // info the value in the data field of the new nodeis less than that of the
       {
        parent->leftchild = newNode;   // make the left child of the parent point to the new node
       }

       else if(element > parent->info) //if the value in the data field of the new node is greater than that
       {
        parent->rightchild = newNode;  // make the left child of the parent point to the new node
       }
        
    }

    void search(string element, Node*& parent, Node*& currentNode)
    {
        //This function seacrhes the currentNode of the specified Node as well as the current node of its parent
        currentNode = ROOT;
        parent = NULL;

        while((currentNode != NULL) && (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->rightchild;
        }
    }

    void inorder(Node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr !=NULL)
        {
            inorder(ptr->leftchild);
            cout << ptr->info << "  ";
            inorder(ptr->rightchild);
        }
    }

    void preorder(Node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr !=NULL)
        {
            cout << ptr->info << "  ";
            preorder(ptr->leftchild);
            preorder(ptr->rightchild);
        }
    }

    void postorder(Node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr !=NULL)
        {
            postorder(ptr->leftchild);
            postorder(ptr->rightchild);
            cout << ptr->info << "  ";
        }
    }
};

int main()
{
    BinaryTree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1.Implement insert Operation" << endl;
        cout << "2.Perform inorder traversal" << endl;
        cout << "3.Perform preorder traversal" << endl;
        cout << "4.Perform postorder traversal" << endl;
        cout << "5.Exit" << endl;
        cout << "\nEnter your Choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            cout << "Enter a word: ";
            string word;
            cin >> word;
            x.insert(word);
            break;
        }
        }
    }
}