#include"bstree.h"

void BinarySearchTree::~BinarySearchTree() {
	DeleteBST( rootPtr );
}

// Delete an entire BST. All memory is released using a "PostOrder" traversal method.
void BinarySearchTree::DeleteBST( TreePtr& treePtr ) {
	if( treePtr != NULL )
	{
		DeleteBST( treePtr->leftPtr );
		DeleteBST( treePtr->rightPtr );
		
		delete  treePtr;
		treePtr = NULL;
	}
}

// Test if a node is a leaf
bool  BinarySearchTree::IsLeaf( TreePtr treePtr) {
	return ( (treePtr->leftPtr == NULL) && (treePtr->rightPtr == NULL) );
}

void BinarySearchTree::ProcessLeftMost( TreePtr& treePtr, tree_data& theItem ) {
   if( treePtr->leftPtr != NULL )
      ProcessLeftMost( treePtr->leftPtr, theItem );
   else {
      theItem = treePtr->data;
      TreePtr delPtr = treePtr;
      treePtr = treePtr->rightPtr;
      delPtr->rightPtr = NULL;
      delete  delPtr;  
   }  
}

//   Add (insert) new item into the BST, whose root node is pointed to by "rootPtr". 
//   If the data already exists, it is ignored.
void BinarySearchTree::AddNode( tree_data title, tree_data genre, int released, int ended, linkedlist actors, tree_data source ) {
	TreePtr newNode;
	newNode = new BSTreeNode;
	
	// Add new data to the new node's data field
	newNode->title = title;
	newNode->genre = genre;
	newNode->released = released;
	newNode->ended = ended;
	newNode->source = source;
	newNode->title = title;
	// Copy list of actors to node
	linkedlist* tmp = new linkedlist;
	while(actors.size() > 0) {
		tmp->add(actors.last());
		actors.remove(actors.last());
	}
	while(tmp->size() > 0) {
		newNode->actors.add(tmp->last());
		tmp->remove(tmp->last());
	}
	delete tmp;
	
	newNode->leftPtr  = NULL;
	newNode->rightPtr = NULL;
	
	// If the BST is empty, new node becomes the root
	if( rootPtr == NULL ) {
	  rootPtr = newNode;
	} else {  // Look for the insertion location
	  TreePtr treePtr = rootPtr;
	  TreePtr targetNodePtr;
	  
	  while( treePtr != NULL ) {
	    targetNodePtr = treePtr;
	    if( title == treePtr->title ) 
	       // Found same data; ignore it. 
	       return;
	    else if( title < treePtr->title ) 
	       // Search left subtree for insertion location
	       treePtr = treePtr->leftPtr; 
	    else   //  title > treePtr->title 
	       // Search right subtree for insertion location
	       treePtr = treePtr->rightPtr; 
	  }
	
	  //  "targetNodePtr" is the pointer to the parent of the new node; decide which branch gets the new node
	  if( title < targetNodePtr->title )
	     targetNodePtr->leftPtr = newNode;
	  else
	     targetNodePtr->rightPtr = newNode;
	}
}

//   Find a given node by "key" in BST. 
//   If successful, it returns the pointer that points to the node with "key"; 
//   otherwise, it returns NULL. 
//   Uses preorder traversal.
BinarySearchTree::TreePtr BinarySearchTree::SearchNodeInBST( TreePtr treePtr, tree_data key ) {
   if( treePtr != NULL ) {
      if( key == treePtr->data )
         return  treePtr;
      else if( key < treePtr->data ) 
         // Search for "key" in left subtree
         return SearchNodeInBST( treePtr->leftPtr, key );
      else   // (key > tree_ptr->data) 
         // Search for "key" in right subtree
         return SearchNodeInBST( treePtr->rightPtr, key );
   } 
   else {
      return NULL;
   } 
} 

void BinarySearchTree::SearchNode( tree_data searchKey ) {
   TreePtr srchPtr = NULL;

   srchPtr = SearchNodeInBST( rootPtr, searchKey );
   if( srchPtr != NULL ) {
      std::cout << "\n Node: " << srchPtr->data << " was found in the BST" << std::endl;
   } else {
      std::cout << "\n Node: " << searchKey << " was not found" << std::endl;
   }
}

//   Print a BST tree uses InOrder traversal by default.
void BinarySearchTree::PrintTree() { 
    PrintBST_InOrder( rootPtr );
}

//   Print BST using InOrder traversal
void BinarySearchTree::PrintInOrder() {
   PrintBST_InOrder( rootPtr );
}

void BinarySearchTree::PrintBST_InOrder( TreePtr treePtr ) {
   if( treePtr != NULL) {
     PrintBST_InOrder( treePtr->leftPtr );
     std::cout << treePtr->data << std::endl;
     PrintBST_InOrder( treePtr->rightPtr );
   }
} 

//   Print BST using PreOrder traversal
void BinarySearchTree::PrintPreOrder() {
   PrintBST_PreOrder( rootPtr );
}

void BinarySearchTree::PrintBST_PreOrder( TreePtr treePtr ) {
   if( treePtr != NULL ) {
     std::cout << treePtr->data << std::endl;
     PrintBST_PreOrder( treePtr->leftPtr );
     PrintBST_PreOrder( treePtr->rightPtr );
   }
}

//   Print BST using PostOrder traversal
void BinarySearchTree::PrintPostOrder() {
   PrintBST_PostOrder( rootPtr );
}

void BinarySearchTree::PrintBST_PostOrder( TreePtr treePtr ) {
   if( treePtr != NULL ) {
     PrintBST_PostOrder( treePtr->leftPtr );
     PrintBST_PostOrder( treePtr->rightPtr );
     std::cout << treePtr->data << std::endl;
   }
}

}