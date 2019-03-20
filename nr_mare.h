#ifndef NR_MARE_H_INCLUDED
#define NR_MARE_H_INCLUDED
#pragma once

#include <iostream>
#include "lista.h"

class nr_rational;

class nr_mare
{
    bool semn;
    lista nr;

    public:
        nr_mare();
        nr_mare(const nr_mare &);
        nr_mare operator= (const nr_mare &);
        nr_mare operator= (const int &);
        bool operator== (const nr_mare &);
        bool operator< (const nr_mare &);
        nr_mare operator+ (nr_mare );
        nr_mare operator- (nr_mare );
        nr_mare operator* (nr_mare );
        nr_mare operator/ (nr_mare );
        nr_mare operator% (nr_mare );
        nr_mare gcd (nr_mare );
        nr_mare max_abs (nr_mare );
        friend std::istream & operator >> (std::istream &, nr_mare &);
        friend std::ostream & operator << (std::ostream &, const nr_mare &);

        friend class nr_rational;
        friend std::istream & operator >> (std::istream &, nr_rational &);
        friend std::ostream & operator << (std::ostream &, const nr_rational &);
};

#endif // NR_MARE_H_INCLUDED
