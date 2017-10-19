/* 
 * Binary Search Tree
 * Dependencies: <cstdlib> (NULL), <iostream>
 *  
 */

#ifndef BSTREE_H
#define BSTREE_H

#include<iostream>
#include"linkedlist.h"

class BinarySearchTree {
	private:
		typedef std::string tree_data;

		typedef struct  BSTreeNode {
			tree_data title;
			tree_data genre;
			int released;
			int ended;
			linkedlist actors;
			tree_data source;
			BSTreeNode* leftPtr;
			BSTreeNode* rightPtr;
		} *TreePtr;
		
		TreePtr rootPtr;
		
    void InitBSTree() { rootPtr = NULL; }

    bool IsLeaf( TreePtr );
    void ProcessLeftMost( TreePtr&, tree_data& );                     
    TreePtr SearchNodeInBST( TreePtr, tree_data );
    
    void PrintBST_InOrder( TreePtr );
    void PrintBST_PreOrder( TreePtr );
    void PrintBST_PostOrder( TreePtr );
 
  public:
    BinarySearchTree() { InitBSTree(); }
    ~BinarySearchTree();
    
		void DeleteBST( TreePtr& );
    bool IsEmpty() { return (rootPtr == NULL); }
    
    void AddNode( tree_data title, tree_data genre, int released, int ended, linkedlist actors, tree_data source );
    // Create expanded SearchNode ( or --> PrintNode ) -- for each search type desired
    void SearchNode( tree_data );
    
    void PrintTree();
    void PrintInOrder();
    void PrintPreOrder();
    void PrintPostOrder();
};

#endif