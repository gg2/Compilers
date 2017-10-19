/*  
 * testQueue.cpp
 * CS121
 * source: Bruce Bolden
 * 
 */

#include<iostream>

#include"queueL.h"

int main()
{
    Queue q1;
    int qVal;

      //  add some initial nodes
    q1.Insert( 3 );
    q1.Insert( 5 );

    std::cout << "Initial contents of q1:" << std::endl;
    q1.Print();

      //  add a few more nodes
    q1.Insert( 1 );

    std::cout << "Contents of q1 after adding:" << std::endl;
    q1.Print();

      //  delete a few items
    std::cout << "\nDeleting two items from queue:" << std::endl;
    
    qVal = q1.Delete();
    std::cout << "Contents of q1 after deleting one item:" << std::endl;
    q1.Print();
    
    qVal = q1.Delete();
    std::cout << "Contents of q1 after deleting one item:" << std::endl;
    q1.Print();
}
