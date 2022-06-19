int main() {
    int a = 10;
    if (a - 4 == 6) {
        if (a + 4 == 10) return 100;
        else if (a + 2 == 10) {
            return 200;
        } else if (a + 6 == 10) return 250;
    } else return -100;
}