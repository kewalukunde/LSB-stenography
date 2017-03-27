/*decrypting secret file*/
void decrypt_secret(int size_txt,FILE *fp1,FILE *fp2)
{
    /*taking one by one byte from sorce file
     checking LSB bit and collecting it into a buff*/
    int buff=0,i,j=0,ch,temp;
    for (i=0;i<(size_txt*8);i++)
    {
	j++;
	ch = fgetc(fp1);
	temp = (ch & 1);
	if (temp)
	{
	    buff = (buff<<1) | 1;
	}
	else
	{
	   buff = buff<<1;
	}
	
	if ( j == 8)
	{
   		fputc(buff,fp2);
		j=0;
		buff = 0;
	}
    }
}

/*decrypting intiger*/
void decrypt_num(FILE *fp1,int *size_txt)
{
    int buff=0,i,j=0,ch,temp;
    for (i=0;i<8;i++)
    {
	j++;
	ch = fgetc(fp1);
	temp = (ch & 1);
	if (temp)
	{
	    buff = (buff<<1) | 1;
	}
	else
	{
	   buff = buff<<1;
	}
    }
    *size_txt = buff;
}

/*decrypting string*/
void decrypt_string(FILE *fp1,char *s,int size)
{
    int buff=0,i,j=0,k=0,ch,temp;
    for (i=0;i<(size*8);i++)
    {
	j++;
	ch = fgetc(fp1);
	temp = (ch & 1);
	if (temp)
	{
	    buff = (buff << 1) | 1;
	}
	else
	{
	   buff = buff << 1;
	}
	
	if ( j == 8)
	{
		s[k] =(char)buff; 
		j=0;
		k++;
		buff = 0;
	}
    }
    s[k] = '\0';
}
