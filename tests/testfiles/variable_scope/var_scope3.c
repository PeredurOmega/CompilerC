int a = 10;

int main(){
    int b = 2;
    {
        int b = 10;
        a = b * a ;
    }
    return b;
}