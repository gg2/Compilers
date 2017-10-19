#include"listQ.h"

void LinkedList::AddNode(int x)
{
    nodeptr n, nTmp;

    n = new node;
    n->info = x;
    n->next = NULL;
    count++;

    if( start == NULL )
    {
        start = n;
        end   = start;
    }
    else
    {
        end->next = n;
        nTmp = end;
        end  = nTmp->next;
    }
}

void LinkedList::DeleteNode()
{
    nodeptr curr;

    if( start != NULL )
    {
        curr = start;
        start = start->next;
        delete curr;
        
        count--;
    }
}

int LinkedList::FirstNode()
{
    int  iVal;
    
    if( start != NULL )
        iVal = start->info;
        
    return iVal;
}

int LinkedList::LastNode()
{
    if( end != NULL )
        return end->info;
}

void LinkedList::PrintNodes()
{
    nodeptr p = start;

    while( p != NULL )
    {
        std::cout << p->info << std::endl;
        p = p->next;
    }

}

bool LinkedList::IsInList(int x)
{
    nodeptr p = start;

    while (p != NULL && x > p->info)
        p = p->next;

    return (x == p->info);
}


int LinkedList::Size()
{
    return count;
}
 
