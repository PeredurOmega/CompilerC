int function1(int a, int b, int c) {
    if (a < 10) {
        return b + c;
    } else {
        return b - c;
    }
}

int function2(int a, int b, int c, int d) {
    return (a + b) / c * d;
}

int main() {
    int a = function1(10, 50, 30);
    int b = function2(10,20,5,4);
    return  a*b/10;
}
