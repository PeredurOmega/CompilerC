int main(){
    int count1 = 1;
    int count2 = 1;
    while (count1 != 4)
    {
        while(count2 >= 4){
            count2 = count2 + 1;
        }
        count1 = count1 + 1;
    }
    return count1*count2;
}
