#include <stdio.h>
#include <openssl/bn.h>
#define NBITS 256

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
BIGNUM *p = BN_new();
BIGNUM *q = BN_new();
BIGNUM *e = BN_new();
BIGNUM *d = BN_new();
BIGNUM *res1 = BN_new();
BIGNUM *res2 = BN_new();
BIGNUM *res3 = BN_new();
BIGNUM *one = BN_new();
// initalize p q e
// Assign the first large prime
BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");

// Assign the second large prime
BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");

// Assign the Modulus
BN_hex2bn(&e, "0D88C3");
BN_dec2bn(&one,"1");
//res1 = p-1
BN_sub(res1, p, one);
//res2 = q-1
BN_sub(res2, q, one);
//res3=res1*res2
BN_mul(res3, res1, res2, ctx);
//res=a*b mod n
BN_mod_inverse(d, e, res3, ctx);
//print BN
printBN("d= ",d);
return 0;
}
      
