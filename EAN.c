

#include <stdio.h>
#include "boolean.h"

int main(){
    boolean IsEANValid(long long int x);
    long long int ean;
    boolean valid = false;
    printf("masukkan kode EAN-13\n");
    scanf("%lld",&ean);
    valid = IsEANValid(ean);
    if (valid){
        printf("EAN-13 ini valid\n");
    }
    else{
        printf("EAN-13 ini tidak valid, silahkan periksa ulang\n");
    }
    return 0;
}

boolean IsEANValid(long long int x){
/* untuk menentukan apakah EAN-13 valid */
    int i;
    int sum,digit;
    i = 1;
    sum = 0;
    while (x > 0) {
        digit = x % 10;
        if (i % 2 == 0 ){
            sum = sum + 3*digit;
        }
        else{
            sum = sum + digit;
        }
        x = x/10;
        i = i+1;
    }
    return (sum % 10 == 0 && i == 14);
}