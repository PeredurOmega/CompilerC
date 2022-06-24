int main(){
    int a = 0;
    int b;
    while(a!=12){
        if(a<10){
            b = 0;
            while(b!=10){
                b++;
            }
        }
        ++a;
    }
    return a;
}