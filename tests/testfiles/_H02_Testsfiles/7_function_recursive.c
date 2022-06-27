int recursive(int a){
    if (a < 10){
        a = a + 1;
        recursive(a);
    }
    return a;
}

int main(){
    return recursive(1);
}
