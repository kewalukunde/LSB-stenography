#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "encrypt.c"
#include "decryption.c"
#include "stegno_decrypt.c"
#include "stegno_encrypt.c"

/*Encryption procedure*/
int encryption(char *argv_2,char *argv_3,char *argv_4);

/*dycreption procedure*/
int dycryption(char *argv_2,char *argv_3);

/*encryption of secret message*/
void encrypt_secret_file(FILE *fp1,FILE *fp2,FILE *fp3);

/*encryption of intiger*/
void encrypt_num(int num, FILE *fp1,FILE *fp3);

/*encreption of string*/
void encrypt_string(char *s, FILE *fp1,FILE *fp3);

/*decryption of secret*/
void decrypt_secret(int size_txt,FILE *fp1,FILE *fp2);

/*dereption of intiger*/
void decrypt_num(FILE *fp1,int *size_txt);

/*decreption of string*/
void decrypt_string(FILE *fp1,char *s,int size);


