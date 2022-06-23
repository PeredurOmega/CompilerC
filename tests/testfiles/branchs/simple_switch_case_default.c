int main(){
    int a = 42;
    int n = 0;
    switch (a) {
        case 1:
            n = 1;
            break;
        case 2:
            n = 2;
            break;
        case 3:
            n = 3;
            break;
        default:
            n++;
            break;
    }
    return n;
}