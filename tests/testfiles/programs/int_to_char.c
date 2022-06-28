// Not Implemented

char int_to_char(int value){
    if(value==1)
        return '1';
    else if(value==2)
        return '2';
    else if(value==3)
        return '3';
    else if(value==4)
        return '4';
    else if(value==5)
        return '5';
    else if(value==6)
        return '6';
    else if(value==7)
        return '7';
    else if(value==8)
        return '8';
    else if(value==9)
        return '9';
    else
        return '0';
}

int main(){
    if(int_to_char(7)=='7'){
        return 1;
    }
    else{
        return 0;
    }
}