
#include <string>
#include <cmath>
#include "nr_mare.h"

nr_mare::nr_mare()
{
    semn = false;
}

nr_mare::nr_mare(const nr_mare &copiat)
{
    semn = copiat.semn;
    nr.copiaza_lista(copiat.nr);
}

nr_mare nr_mare::operator= (const nr_mare &b)
{
    semn = b.semn;
    nr.copiaza_lista(b.nr);
    return (*this);
}

nr_mare nr_mare::operator= (const int &b)
{
    int c = b;
    nr.sterge_lista();
    if(b<0)
    {
        semn = true;
        c = std::abs(b);
    }
    if(c==0)nr.adauga_sf(0);
    while(c!=0)
    {
        nr.adauga_sf(c%10);
        c /= 10;
    }
    return (*this);
}

bool nr_mare::operator== (const nr_mare &b)
{
    if(semn != b.semn)
        return false;
    else
    {
        struct nod *p = this->nr.start;
        struct nod *q = b.nr.start;
        while(p!=NULL && q!=NULL)
        {
            if(p->key != q->key)
                return false;
            p = p->next;
            q = q->next;
        }
        if(p!=q)
            return false;
    }
    return true;
}

bool nr_mare::operator<(const nr_mare &b)
{
    if(b.semn && !semn)
        return false;
    else if(semn && !b.semn )
        return true;
    else
    {
            if((*this).max_abs(b)==b && (*this).max_abs(b)==(*this))
                return false;
            if((*this).max_abs(b)==b)
            {
                if(!b.semn)
                    return true;
                else return false;
            }
            else
            {
                if(b.semn)
                    return true;
                return false;
            }
    }
}

bool nr_mare::operator<=(const nr_mare &b)
{
    if(b.semn && !semn)
        return false;
    else if(semn && !b.semn )
        return true;
    else
    {
            if((*this).max_abs(b)==b && (*this).max_abs(b)==(*this))
                return true;
            if((*this).max_abs(b)==b)
            {
                if(!b.semn)
                    return true;
                else return false;
            }
            else
            {
                if(b.semn)
                    return true;
                return false;
            }
    }
}

std::istream & operator >> (std::istream &in, nr_mare &n)
{
    std::string sir; int i = 0,c;
    in >> sir;
    if(sir[0] == '-')
    {
        n.semn = true;
        i++;
    }
    c = sir.length();
    for(i=i;i<c;i++)
    {
        if(sir[i]-'0'<= 9 && sir[i]-'0' >=0)
             n.nr.adauga_in(sir[i]-'0');
        else
        {
            n.nr.sterge_lista();
            return in >> n;
        }
    }
    struct nod *p = n.nr.stop, *q;
    while(p->prec != NULL && p->key==0)
    {
        q = p;
        p = p->prec;
        delete q;
        p->next = NULL;
        q = p;
    }
    n.nr.stop = p;
    return in;
}

std::ostream & operator << (std::ostream &out, const nr_mare &n)
{
    if(n.semn)
        out<<'-';
    struct nod *p = n.nr.stop;
    while( p!= NULL)
    {
        out<<p->key;
        p = p->prec;
    }
    return out;
}

nr_mare nr_mare::operator+ (nr_mare b)
{
    if(semn != b.semn)
    {
        b.semn = semn;
        return (*this)-b;
    }
    int r = 0;
    struct nod *p = this->nr.start;
    struct nod *q = b.nr.start;
    nr_mare c;
    c.semn = semn;
    while( p!=NULL && q!=NULL )
    {
        c.nr.adauga_sf((p->key + q->key +r )%10);
        r = (p->key + q->key)/10;
        p = p->next;
        q = q->next;
    }
    if( p==q )
    {
         if(r) c.nr.adauga_sf(r);
    }
    else
    {
        if( p==NULL )
            p = q;
        while( p!=NULL )
        {
            c.nr.adauga_sf((p->key+r)%10);
            r = (p->key +r)/10;
            p = p->next;
        }
        if(r)
            c.nr.adauga_sf(r);
    }
    return c;
}

nr_mare nr_mare::max_abs(nr_mare b)
{
    struct nod *p = this->nr.stop;
    struct nod *q = b.nr.stop;
    bool ok = true, done = false;
    while(p!=NULL && q!=NULL)
    {
        if(p->key < q->key && !done)
            ok =false;
        else if (p->key!=q->key) done = true;
        p = p->prec;
        q = q->prec;
    }
    if(p==NULL && q!=NULL )
        return b;
    else
    {
        if(q==NULL && p!=NULL)
            return *this;
        else
        {
            if(ok)
                return *this;
            else return b;
        }
    }
}

nr_mare nr_mare::operator-(nr_mare b)
{
    if(semn != b.semn)
    {
        b.semn = semn;
        return (*this)+b;
    }
    b.semn = !b.semn;
    int r = 0;
    struct nod *p, *q;
    nr_mare c;
    if((*this).max_abs(b) == b)
    {
         c.semn = b.semn;
         p = b.nr.start;
         q = this->nr.start;
    }
    else
    {
         c.semn = semn;
         q = b.nr.start;
         p = this->nr.start;
    }
    while( p!=NULL && q!=NULL )
    {
        c.nr.adauga_sf((p->key + 10 - q->key - r )%10);
        r = (p->key - r < q->key);
        p = p->next;
        q = q->next;
    }
    if( p!=NULL )
    {
        while( p!=NULL )
        {
            c.nr.adauga_sf((p->key + 10 - r)%10);
            r = (p->key - r < 0);
            p = p->next;
        }

    }
    p = c.nr.stop;
    while(p->prec != NULL && p->key==0)
    {
        q = p;
        p = p->prec;
        delete q;
        p->next = NULL;
        q = p;
    }
    c.nr.stop = p;
    if(c.nr.stop->key==0)c.semn=false;
    return c;
}

nr_mare nr_mare::operator*(nr_mare b)
{
    nr_mare prod, sum;
    prod.nr.adauga_in(0);
    int r = 0, i = 0, j;
    struct nod *p = nr.start, *q = b.nr.start;
    while(p != NULL)
    {
        while(q != NULL)
        {
            sum.nr.adauga_sf((p->key*q->key + r)%10);
            r = (p->key*q->key + r)/10;
            q = q->next;
        }
        if(r)sum.nr.adauga_sf(r);
        for(j = 0; j < i; j++)
            sum.nr.adauga_in(0);
        prod = prod + sum;
        i++;
        sum.nr.sterge_lista();
        p = p->next;
        q = b.nr.start;
        r = 0;
    }
    p = prod.nr.stop;
    while(p->prec != NULL && p->key==0)
    {
        q = p;
        p = p->prec;
        delete q;
        p->next = NULL;
        q = p;
    }
    prod.nr.stop = p;
    if(semn == b.semn)
        prod.semn = false;
    else
        prod.semn = true;
    if(prod.nr.stop->key==0)prod.semn=false;
    return prod;
}

nr_mare nr_mare::operator/(nr_mare b)
{
    nr_mare cat;
    cat = 0;
    if(b.nr.stop->key==0)
    {
        std::cout<<("Imapritrea la 0 nu este permisa!");
        return cat;
    }
    if((*this).max_abs(b)==b)
        return cat;
    bool ok = b.semn;

    cat.nr.sterge_lista();
    struct nod *p = this->nr.stop;
    nr_mare in, inm, it, ad, c;
    ad = 1;
    b.semn = false;
    while(p != NULL)
    {
        inm = 1;
        it = 1;
        in.nr.adauga_in(p->key);
        p = p->prec;
        c = in.max_abs(b);
        while(c==b && !(c==in) && p!=NULL)
        {
            in.nr.adauga_in(p->key);
            cat.nr.adauga_in(0);
            p = p->prec;
            c = in.max_abs(b);
        }
        if(cat.nr.stop != NULL && cat.nr.stop->key==0)
            cat.nr.sterge_lista();
        if(p==NULL && c==b && !(c==in))
        {
            cat.nr.adauga_in(0);
            break;
        }

        while(inm<in)
        {
            it = it + ad;
            inm = b * it;
        }
        if(!(in==inm))
        {
            it = it - ad;
            inm = inm - b;
            in = in - inm;
            if(in.nr.stop->key==0)
                in.nr.sterge_lista();
        }
        else
        {
            in.nr.sterge_lista();
        }
        cat.nr.adauga_in(it.nr.stop->key);
        in.semn = false;
    }
    if(semn == ok)
        cat.semn = false;
    else
        cat.semn = true;
    if(cat.nr.stop->key==0)cat.semn=false;
    return cat;
}

nr_mare nr_mare::operator%(nr_mare b)
{
    nr_mare c;
    c = (*this)/b;
    c.semn = b.semn = false;
    if(semn)
        c = (*this) + c * b;
    else
        c = (*this) - c * b;
    c.semn = false;
    return c;
}

nr_mare nr_mare::gcd(nr_mare b)
{
    if(nr.stop != NULL && nr.stop->key==0)
        return b;
    else return (b%(*this)).gcd((*this));
}

void nr_mare::lista_div( )
{
    nr_mare a = (*this), div, it, r;
    it = 1;
    r = 0;

    for( div = 1; div * div <= a ; div = div + it)
    {
        if ( a % div == r)
        {
            std::cout << " (" << div << ", " << a/div << ") ";
        }
    }
}
