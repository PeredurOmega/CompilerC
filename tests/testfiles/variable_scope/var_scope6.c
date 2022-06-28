// Not Implemented

int a = 1;
int b = 2;
int c = 3;

int main(){
    {
        a = 3;
        {
            b = 4;
            {
                c = 5;
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