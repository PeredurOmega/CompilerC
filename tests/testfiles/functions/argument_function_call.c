int basic_return(int n) {
    return n + 2;
}

int main() {
    return basic_return(basic_return(10));
}
