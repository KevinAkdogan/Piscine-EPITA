#include "complex_operations.h"

struct complex neg_complex(struct complex a)
{
    struct complex neg;
    neg.real = -a.real;
    neg.img = -a.img;
    return neg;
}

struct complex add_complex(struct complex a, struct complex b)
{
    struct complex add;
    add.real = a.real + b.real;
    add.img = a.img + b.img;
    return add;
}

struct complex sub_complex(struct complex a, struct complex b)
{
    struct complex sub;
    sub.real = a.real - b.real;
    sub.img = a.img - b.img;
    return sub;
}

struct complex mul_complex(struct complex a, struct complex b)
{
    struct complex mul;
    mul.real = a.real * b.real - b.img * a.img;
    mul.img = a.real * b.img + a.img * b.real;
    return mul;
}

struct complex div_complex(struct complex a, struct complex b)
{
    struct complex div;
    div.real =
        (a.real * b.real + b.img * a.img) / (b.real * b.real + b.img * b.img);
    div.img =
        (a.img * b.real - a.real * b.img) / (b.real * b.real + b.img * b.img);
    return div;
}
