int func_3(int a, int b){
    return a + b;
}

int func_2(int a, int b){
    return a * b * func_3(a + b, a - b);
}


int func_1(int a, int b){
    return a - b + func_2(a,b) - func_2(func_3(a,b), func_2(a,b));
}

int main(){
    return func_1(10, 20);
}