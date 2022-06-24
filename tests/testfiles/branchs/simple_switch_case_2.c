int test(int a){
    int b = 0;
    switch(a) {
        case 1:
            b = 1;
            break;
        case 2 :
            b = 2;
            break;
        case 42 :
            b = 3;
            break;
    }
    return b;
}

int main(){
    int a = 42;
    return test(a);
}