int nested_factorial(int n) {
    if(n >= 1) return n * nested_factorial(n - 1);
    else return 1;
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

int main(){
    int i = 1, nb = 21;

    while(i<nb){
        if(factorial(i) != nested_factorial(i)){
            return 0;
        }
        ++i;
    }
    return 1;
}