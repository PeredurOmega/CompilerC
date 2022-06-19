int convert(int);

int main() {
    return convert(965);;
}

int convert(int n) {
    int bin = 0;
    int rem, i = 1;

    while( n != 0) {
        rem = n % 2;
        n = n / 2;
        bin = bin + (rem * i);
        i = i * 10;
    }

    return bin;
}