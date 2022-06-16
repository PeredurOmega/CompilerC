typedef struct complex {
    float real;
    float imag;
} complex;

complex add(complex n1, complex n2);

int main() {
    complex n1, n2, result;

    n1.real = 2.1;
    n1.imag = -2.3;

    n2.real = 5.6;
    n2.imag = 23.2;

    result = add(n1, n2);

    return result.real * result.imag;
}

complex add(complex n1, complex n2) {
    complex temp;
    temp.real = n1.real + n2.real;
    temp.imag = n1.imag + n2.imag;
    return (temp);
}
