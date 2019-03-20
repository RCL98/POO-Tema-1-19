
#include "nr_rational.h"

nr_rational::nr_rational()
{
    semnf = false;
    a = 0;
    b = 1;
}

nr_rational::nr_rational(const nr_rational &copiat)
{
    semnf = copiat.semnf;
    a = copiat.a;
    b = copiat.b;
}

nr_rational nr_rational::operator=(const nr_rational &copiat)
{
    semnf = copiat.semnf;
    a = copiat.a;
    b = copiat.b;
    return (*this);
}

bool nr_rational::operator== (const nr_rational &y)
{
    if(semnf != y.semnf)
        return false;
    else if(!(a==y.a)||!(b==y.b))
        return false;
    return true;
}

std::istream & operator >> (std::istream &in, nr_rational &num)
{
    char k;
    num.b.nr.sterge_lista();
    in>>num.a>>k>>num.b;
    num.semnf = (num.a.semn || num.b.semn);
    return in;
}

std::ostream & operator << (std::ostream &out, const nr_rational &nr)
{
    out<<nr.a<<"/"<<nr.b<<" ";
    return out;
}

nr_rational nr_rational::ireductibil()
{
   nr_mare c = a.gcd(b), it;
   c.semn = false; it = 1;
   if(!(c == it))
   {
       a = a / c;
       b = b / c;
   }
   return (*this);
}

nr_rational nr_rational::operator+ (nr_rational y)
{
    nr_rational sum, x = (*this);
    x.ireductibil();
    y.ireductibil();
    nr_mare cmmmc = (x.b*y.b)/x.b.gcd(y.b);
    sum.a = x.a*(cmmmc/x.b) + y.a*(cmmmc/y.b);
    sum.b = cmmmc;
    return sum;
}

nr_rational nr_rational::operator* (nr_rational y)
{
    nr_rational prod, x = (*this);
    x.ireductibil();
    y.ireductibil();
    prod.a = x.a*y.a;
    prod.b = x.b*y.b;
    return prod;
}
