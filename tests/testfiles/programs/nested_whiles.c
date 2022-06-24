int main(){
    int a = 12, b = 14, c = 15;
    int i=0;
    int sum = 0;
    while(i<4){
        while(a>0) {
            while(b>0){
                while(c>0) {
                    sum = sum + 1;
                    c = c - 1;
                }
                b = b - 1;
            }
            a = a - 1;
        }
        i++;
    }
    return sum;
}