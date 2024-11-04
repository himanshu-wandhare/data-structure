#include <iostream>
#include <math.h>
using namespace std;

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    Term *terms;
};

void create(Poly *p)
{
    cout << "Enter the no. of terms in polynomial: ";
    cin >> p->n;

    p->terms = new Term[p->n];

    for (int i = 0; i < p->n; i++)
    {
        cout << "Enter term no. " << i + 1 << ": ";
        cin >> p->terms[i].coeff >> p->terms[i].exp;
    }
}

int evaluate(Poly p, int x)
{
    int sum = 0;
    for (int i = 0; i < p.n; i++)
    {
        sum += p.terms[i].coeff * pow(x, p.terms[i].exp);
    }
    return sum;
}

void display(Poly p)
{
    for (int i = 0; i < p.n; i++)
    {
        if (i == 0 && p.terms[i].coeff > 0)
        {
            cout << p.terms[i].coeff << "X^" << p.terms[i].exp;
            continue;
        }
        cout
            << (p.terms[i].coeff < 0 ? " - " : " + ")
            << p.terms[i].coeff;

        if (p.terms[i].exp != 0)
            cout << "X^" << p.terms[i].exp;
    }
}

Poly add(Poly p, Poly q)
{
    int i, j, k;
    i = j = k = 0;

    Poly result;
    result.terms = new Term[p.n + q.n];

    while (i < p.n && j < q.n)
    {
        if (p.terms[i].exp > q.terms[j].exp)
            result.terms[k++] = p.terms[i++];
        else if (q.terms[j].exp > p.terms[i].exp)
            result.terms[k++] = q.terms[j++];
        else
        {
            result.terms[k] = p.terms[i++];
            result.terms[k++].coeff += q.terms[j++].coeff;
        }
    }
    while (i < p.n)
        result.terms[k++] = p.terms[i++];
    while (j < q.n)
        result.terms[k++] = q.terms[j++];
    result.n = k;

    return result;
}

int main()
{
    Poly p, q, sum;
    create(&p);
    create(&q);

    cout << "\nPolynomial 1: ";
    display(p);

    cout << "\nPolynomial 2: ";
    display(q);

    sum = add(p, q);
    cout << "\nSum: ";
    display(sum);
}