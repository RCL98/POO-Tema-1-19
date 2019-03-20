
#include "lista.h"

lista::lista()
{
    start = new nod;
    stop = new nod;
    start = stop = NULL;
}

void lista::sterge_lista()
{
    struct nod *p = start;
    while( p != NULL )
    {
        start = p->next;
        delete p;
        p = start;
    }
    start = stop = NULL;
}

void lista::adauga_in(int x)
{
    struct nod *p = new struct nod;
    p->key = x;
    p->prec = NULL;
    p->next = NULL;
    if(start == NULL)
        start = stop = p;
    else
    {
        start->prec = p;
        p->next = start;
        start = p;
    }
}

void lista::adauga_sf(int x)
{
    struct nod *p = new struct nod;
    p->key = x;
    p->prec = NULL;
    p->next = NULL;
    if(start == NULL)
        start = stop = p;
    else
    {
        stop->next = p;
        p->prec = stop;
        stop = p;
    }
}

void lista::copiaza_lista(lista lis)
{
    (*this).sterge_lista();
    struct nod *p = lis.stop;
    while(p != NULL)
    {
        (*this).adauga_in(p->key);
        p = p->prec;
    }
}

