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
    while(n!=1){
        facto = facto * n;
        n = n-1;
    }
    return facto;
}

int main(){
    int a = 5;
    int b = 6;
    int test = 0;
    if(nested_factorial(5)== non_nested_factorial(5)){
        test++;
    }
    if(nested_factorial(6)== non_nested_factorial(6)){
        test++;
    }
    return test;
}