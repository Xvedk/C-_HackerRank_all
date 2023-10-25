Complex operator+(const Complex& x, const Complex& y)
{
    Complex z;
    z.a = x.a + y.a;
    z.b = x.b + y.b;
    return z;
}

ostream& operator<<(ostream& o, const Complex& x)
{
    o << x.a << "+i"  << x.b;
    return o;
}
