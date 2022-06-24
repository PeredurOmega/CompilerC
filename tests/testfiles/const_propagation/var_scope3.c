int main(){
    int a = 5;
    {
        int b = 4;
        {
            int c = 3;
            {
                int d = 2;
                {
                    int e = 1;
                    a = e * d * c * b;
                }
            }
        }
    }
    return a;
}