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

int main(){
    int a = 23;
    int b = 42;
    int res = compare(a, b);
    return res;
}