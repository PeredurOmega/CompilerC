// Not Implemented

void test(int *x){
    if (*x == 0){
        *x = 5;
    }
}

int main(){
    int x = 0;
    test(&x);
    return x;
}