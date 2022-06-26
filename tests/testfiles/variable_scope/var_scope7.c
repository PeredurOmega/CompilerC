int a = 9;

int main(){
    int i = 0, j = 0, k = 0, nb = 10;
    {
        int b = a;
        a = a + 1;
    }
    while(i<nb){
        while(j<nb){
            while (k<nb){
                k++;
                if(a==k){
                    return 1;
                }
            }
            j++;
        }
        i++;
    }
    return 0;
}