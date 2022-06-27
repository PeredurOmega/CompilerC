int main()
{
    int a = 3;
    {
        int a =  5;
        {
            int a =  3;
            {
                int a =  5;
            }
            {
                int a = a + 3;
            }
        }
    }
    return a;
}
