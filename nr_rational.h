#ifndef NR_RATIONAL_H_INCLUDED
#define NR_RATIONAL_H_INCLUDED
#pragma once

#include <iostream>
#include "nr_mare.h"
#include "lista.h"


class nr_rational
{
    bool semnf;
    nr_mare a;
    nr_mare b;

    public:
        nr_rational();
        nr_rational(const nr_rational &);
        nr_rational operator= (const nr_rational &);
        bool operator== (const nr_rational &);
        bool operator< (const nr_rational &);
        nr_rational operator+ (nr_rational );
        nr_rational operator* (nr_rational );
        nr_rational ireductibil ();
        friend std::istream & operator >> (std::istream &, nr_rational &);
        friend std::ostream & operator << (std::ostream &, const nr_rational &);
};

#endif // NR_RATIONAL_H_INCLUDED
