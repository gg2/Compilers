#include"queueL.h"

Queue::Queue()
{
    //  default constructor
}

Queue::Queue( const Queue& q ) : L(q.L)
{
    //  copy constructor
}

Queue::~Queue()
{
    //  destructor
}
//  \end{verbatim}  \lecpb  \begin{verbatim}
void Queue::Insert( QueueItemType newItem )
{
    L.AddNode( newItem );
}

QueueItemType Queue::Delete()
{
    QueueItemType iVal;

    iVal = L.FirstNode();
    L.DeleteNode();
    
    return iVal;
}


QueueItemType Queue::GetFront()
{
    return  L.FirstNode();
}

QueueItemType Queue::GetEnd()
{
    return  L.LastNode();
}

bool Queue::IsEmpty()
{
    int  length = L.Size();
    return bool( length == 0 );
}

void Queue::Print()
{
    L.PrintNodes();
}
