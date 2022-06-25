int a = 1;
int b = 2;
int c = 3;

int main(){
    {
        int a = 3
        {
            int b = 4;
            {
                int c = 5;
                {
                    if(a>2){
                        return a;
                    }
                    else{
                        return b*c;
                    }
                }
            }
        }
    }
}