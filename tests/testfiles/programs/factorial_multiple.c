int nested_factorial(int n){
    if(n >= 1){
        return nested_factorial(n-1)*n;
    }
    else{
        return 1;
    }
}

int non_nested_factorial(int n){
    int facto = 1;
    while(n>1){
        facto = facto * n;
        n = n-1;
    }
    return facto;
}

int main(){
    int i = 0, nb = 15;
    while(i<nb){
        if(non_nested_factorial(i)!=nested_factorial(i)){
            return 0;
        }
        ++i;
    }
    return 1;
}