int tab[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int fibonacci_memoisation(int n){
    if (tab[n] == 0){
        if (n == 0){
            return 0;
        }
        else if (n == 1 || n == 2){
            return 1;
        }
        else{
            tab[n] = fibonacci_memoisation(n - 1) + fibonacci_memoisation(n - 2);
        }
    }
    return tab[n];
}

int main(){
    return fibonacci_memoisation(8);
}