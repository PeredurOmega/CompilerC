int factorial(int n);

int main() {
    return factorial(7);
}

int factorial(int n) {
    int i = 1;
    int res = 1;
    while(i < n) {
        res = res * i;
        i = i + 1;
    }
    return res;
}