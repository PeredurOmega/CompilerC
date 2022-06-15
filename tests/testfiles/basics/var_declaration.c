int main(){
    int b, c;
    int a = b = c = 5;
    int d = b;
    d = 6;
    c = b;
    return 42;
}