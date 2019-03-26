#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "lista.h"
#include "nr_mare.h"
#include "nr_rational.h"

using namespace std;
int main()
{
    ifstream f;
    f.open("numere.in");
    ofstream g;
    g.open("numere.out");
    nr_mare x,y,z;
    f>>x>>y;
    g<<x<<" + "<<y<<" = "<<x+y<<endl;
    g<<x<<" - "<<y<<" = "<<x-y<<endl;
    g<<x<<" * "<<y<<" = "<<x*y<<endl;
    g<<x<<" / "<<y<<" = "<<x/y<<endl;
    g<<x<<" % "<<y<<" = "<<x%y<<endl;
    g<<"gcd("<<x<<", "<<y<<") = "<<x.gcd(y)<<endl;
    nr_rational r,t;
    f>>r>>t;
    g<<r<<" "<<t<<endl;
    g<<r.ireductibil()<<" "<<t.ireductibil()<<endl;
    g<<r<<" + "<<t<<" = "<<r+t<<endl;
    g<<r<<" * "<<t<<" = "<<r*t<<endl;
    cin>>z;
    z.lista_div();
    return 0;
}
