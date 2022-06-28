int main(){
    int a = 4;
    {
        int b = 1;
        a = b;
    }
    {
        int b = 2;
        int c = 3;
        {
            int d = 4;
        }
        {
            int d = 5;
        }
        a = b;
    }
    return a;
}