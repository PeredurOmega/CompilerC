int factorial(int n);

int main() {
    return factorial(7);
}

int factorial(int n) {
    if(n >= 1) return n * factorial(n - 1);
    else return 1;
}