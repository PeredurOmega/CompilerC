int main() {
    int a = 0, b = 10;
    int d = a + b - a - b + a;
    while (a < b) {
        a = a + 1;
        /*while (a < b) {
            b = b - 1;
        }*/
    }
    return d;
}