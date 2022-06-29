int a = 10;

int main(){
    {
        int b = 10;
        a = b * a ;
        {
            int c = 10;
            a = a * c;
            {
                int i = 0;
                while(i<5){
                    a = a + 1;
                    i = i + 1;
                }
            }
        }
    }
    return a;
}