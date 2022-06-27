int compare(int a, int b){
    int soust = a - b;
    if (soust == 0){
        return 0;
    }
    else if (soust > 0){
        return a;
    }
    else{
        return b;
    }
}

int multiplication(int a, int b){
    return a*b;
}

int main(){
    int a = 23;
    int b = 42;
    int c = 3;
    int d = 12;
    return compare(multiplication(c, b), multiplication(a, d));
}