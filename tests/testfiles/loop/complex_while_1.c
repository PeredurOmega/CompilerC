int main(){
    int count1 = 1;
    int count2 = 2;
    while (count1 <= 4)
    {
        while(count2 <= 5){
            count2 = count2 + 1;
        }
        count1 = count1 + 3;
    }
    return count1*count2;
}