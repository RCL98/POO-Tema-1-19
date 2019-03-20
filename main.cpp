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
    nr_mare x,y,z;
    f>>x>>y;
    cout<<x<<" + "<<y<<" = "<<x+y<<endl;
    cout<<x<<" - "<<y<<" = "<<x-y<<endl;
    cout<<x<<" * "<<y<<" = "<<x*y<<endl;
    cout<<x<<" / "<<y<<" = "<<x/y<<endl;
    cout<<x<<" % "<<y<<" = "<<x%y<<endl;
    cout<<"gcd("<<x<<", "<<y<<") = "<<x.gcd(y)<<endl;
    nr_rational r,t;
    f>>r>>t;
    cout<<r<<" "<<t<<endl;
    cout<<r.ireductibil()<<" "<<t.ireductibil()<<endl;
    cout<<r<<" + "<<t<<" = "<<r+t<<endl;
    cout<<r<<" * "<<t<<" = "<<r*t;
    return 0;
}
