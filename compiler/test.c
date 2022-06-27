int check(int a, int b, int c, int d){
    if (a < b){
        if (a < c){
            if (a < d){
                return a;
            }
        }
    }
    return 0;
}

int update(int a, int b, int c, int d){
    while (check(a, b, c, d) != a){
        a = a - 1;
    }
    return a;
}

int result(int a, int b, int c, int d){
    return update(a, b, c, d);
}

int main(){
    int a = 10;
    int b = 7;
    int c = 6;
    int d = 5;
    return result(a, b, c, d);
}