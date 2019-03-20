#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#pragma once

#include<iostream>

struct nod
{
    int key;
    struct nod *next;
    struct nod *prec;
};

class nr_mare;

class lista
{
    struct nod *start;
    struct nod *stop;

    public:
    lista();
    void adauga_in(int );
    void adauga_sf(int );
    void copiaza_lista(lista );
    void sterge_lista();
    friend std::istream & operator >> (std::istream &, nr_mare &);
    friend std::ostream & operator << (std::ostream &, const nr_mare &);
    friend class nr_mare;
};


#endif // LISTA_H_INCLUDED
