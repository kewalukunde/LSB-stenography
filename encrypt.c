/*function for encryption of secret file*/
void encrypt_secret_file(FILE *fp1,FILE *fp2,FILE *fp3)
{
    int buff,i,j,ch;
    int read=0,write=0;
    

    /*taking one by one byte from secret file
    after that checking bits and acording to that
    seting or reseting bits of buff*/ 
    while ((ch = fgetc(fp2)) != EOF)
    {
	for (j=7;j>=0;j--)
	{
	    if (ch & (1<<j))
	    {
		buff =fgetc(fp1);
		buff =((buff & (1<<1)) | 1);
		fputc(buff,fp3);
	    }
	    else
	    {
		buff =fgetc(fp1);
		buff =(buff & (1<<1));
		fputc(buff,fp3);
	    }
	}	
    }
 
    /*checking file encrypted til EOF or not*/
    if (ch == EOF)
	printf("\nSuccessfully encrypted secret message.\n");
    else
	printf("failure encryption of secret message.\n");   	
}

/*encryption of int value*/
void encrypt_num(int num, FILE *fp1,FILE *fp3)
{
    int buff,i,j,ch;
    
    for (j=7;j>=0;j--)
    {
	if (num & (1<<j))
	{
	    buff = fgetc(fp1);
	    buff =(buff & (1<<1)) | 1;
	    fputc(buff,fp3);
	}
	else
	{
	    buff = fgetc(fp1);
	    buff = buff & (1<<1);
	    fputc(buff,fp3);
	}
    }	
}

/*encrypting string*/
void encrypt_string(char *s, FILE *fp1,FILE *fp3)
{
 int buff,i,j,ch;
    
    for (i=0;(ch = s[i]) != '\0';i++)
    {
	for (j=7;j>=0;j--)
	{
	    if (ch & (1<<j))
	    {
		buff = fgetc(fp1);
		buff =(buff & (1<<1)) | 1;
		fputc(buff,fp3);
	    }
	    else
	    {
		buff = fgetc(fp1);
		buff = buff & (1<<1);
		fputc(buff,fp3);
	    }
	}	
    }
}
