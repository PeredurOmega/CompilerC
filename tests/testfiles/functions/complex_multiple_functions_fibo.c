int fibonacci_naif(int n){
    if (n == 0){
        return 0;
    }
    else if (n == 1){
        return 1;
    }
    else{
        return (fibonacci_naif(n - 1) + fibonacci_naif(n - 2));
    }
}

int fibonacci_poly_recurs(int n, int a, int b){
    if (n == 0){
        return a;
    }
    else if (n == 1){
        return b;
    }
    else{
        return fibonacci_poly_recurs(n - 1, b, a+b);
    }
}

int main(){
    int n = 11;
    int a = 0;
    int b = 1;
    int res1 = fibonacci_naif(n);
    int res2 = fibonacci_poly_recurs(n, a, b);
    if (res1 == res2){
        return res2;
    }
    else{
        return 0;
    }
}