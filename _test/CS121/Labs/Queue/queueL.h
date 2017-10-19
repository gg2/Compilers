/* QueueL.h
 *
 * Interface file for the ADT queue.
 * Implementation uses a Linked List.
 * source: Bruce Bolden, CS121
 * 
 */

#include"listQ.h"

typedef int QueueItemType;

class Queue
{
private:
    LinkedList L;   //  list of queue items

public:
    Queue();
    Queue( const Queue& q );
    ~Queue();
    
    void Insert( QueueItemType newItem );
    QueueItemType  Delete();
    
    QueueItemType GetFront();
    QueueItemType GetEnd();
    
    bool IsEmpty();
    
    void Print();
};
