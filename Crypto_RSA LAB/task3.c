#include <stdio.h>
#include <openssl/bn.h>
#define NBITS 256

//print a big number
void printBN(char *msg, BIGNUM *a){
// Convert the BIGNUM to number string
char * number_str = BN_bn2hex(a);
// Print out the number string
printf("%s %s\n", msg, number_str);
// Free the dynamically allocated memory
OPENSSL_free(number_str);
}

int main(){
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *n = BN_new();
    BIGNUM *d = BN_new();
    BIGNUM *c = BN_new();
    BIGNUM *dec = BN_new();
    //Initialize
    BN_hex2bn(&n,"DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
    BN_hex2bn(&c,"8C0F971DF2F3672B28811407E2DABBE1DA0FEBBBDFC7DCB67396567EA1E2493F");
    BN_hex2bn(&d,"74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
    //encry = m^e mod n
    BN_mod_exp(dec,c,d,n,ctx);
    printBN("encrypt message = ", dec);
    
    return 0;
}
