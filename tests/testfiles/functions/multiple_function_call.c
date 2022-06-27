int function1(int a, int b, int c) {
    putchar(a);
    putchar(32);
    putchar(b);
    putchar(32);
    putchar(c);
    putchar(32);
    int z;
    if (a < 10) {
//        return b + c;
        z = b + c;
    } else {
//        return b - c;
        z = b - c;
    }
    putchar(z);
    putchar(32);
    return z;
}

int function2(int a, int b, int c, int d) {
    putchar(a);
    putchar(32);
    putchar(b);
    putchar(32);
    putchar(c);
    putchar(32);
    putchar(d);
    putchar(32);
    return (a + b) / c * d;
}

int main() {
    int a = function1(10, 50, 30);
    putchar(a);
    int b = function2(10,20,5,4);
    putchar(b);
    return  a*b/10;
}
