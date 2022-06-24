int func_2(int a, int b){
    return a + b;
}

int main(){
    return func_2(func_2(10,20), func_2(10,20));
}