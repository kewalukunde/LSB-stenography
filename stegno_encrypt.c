void get_password(char *str);
int copy_header(FILE *source,FILE *out);
void get_magic_string(char *str);
int compare_size(FILE *secret,FILE *source,int *size_txt,int *size_sorce);

int encryption(char *argv_2,char *argv_3,char *argv_4)
{
    FILE *file_source,*file_secret,*file_out;
    char ext[10],magic_str[10];
    char pass[10];
    short int size;
    int buff,i,j,ch,shift,passward,size_source,size_secret;


    //opening file for read, write opration
    if((file_source = fopen(argv_2,"r")) == NULL)
    {
	printf("\nERROR !! Pass sorce_image_file\n");
	return -1;
    }

    if((file_secret = fopen(argv_3,"r")) == NULL)
    {
	printf("\nERROR !! Pass sorce_txt_file\n");
	return -1;
    }

    //comparing file size of source and secret file
    compare_size(file_secret,file_source,&size_secret,&size_source);
   
    file_out = fopen(argv_4,"w");

    //copy header bytes 
    copy_header(file_source,file_out);

    //taking magic string from user
    get_magic_string(magic_str);

    //encrypting password
    size = strlen(magic_str);
    encrypt_num(size,file_source,file_out);
    encrypt_string(magic_str,file_source,file_out);

    //taking password from user
    get_password(pass);
    
    //encrypting password
    size = strlen(pass);
    encrypt_num(size,file_source,file_out);
    encrypt_string(pass,file_source,file_out);

    //taking secret file extention from user
    printf("\nEnter extention of secret file: ");
    for (i=0;((ext[i] = getchar()) != '\n');i++);
    ext[i]= '\0';

    //encrypting extention
    size = strlen(ext);
    encrypt_num(size,file_source,file_out);
    encrypt_string(ext,file_source,file_out);

    //encrypting size of secret file
    encrypt_num(size_secret,file_source,file_out);

    //encrypting secret file
    encrypt_secret_file(file_source,file_secret,file_out);

    //copying rest of data 
    for(i = 0;(ch = fgetc(file_source)) != EOF ; i++)
    {
	fputc(ch,file_out);
    }

    printf("\n# Output file generated as '%s'\n\n",argv_4);

    //closing files
    fclose(file_source);
    fclose(file_secret);
    fclose(file_out);
}

int copy_header(FILE *source,FILE *out)
{
    int i,heder_size_read=0,heder_size_write=0;
    char buf[8];
    for(i = 0; i < 54; i++)
    {
	heder_size_read += fread(buf,1,1,source);
	heder_size_write += fwrite(buf,1,1,out);
    }

    //checking 54 bytes copyed or not
    if(heder_size_read == heder_size_write)
	printf("\nsuccessfully copied 54 header bytes\n");
    else
    {
	printf("\nfailure of copy 54 header bytes\n");
	return 0;
    }
}

int compare_size(FILE *secret,FILE *source,int *size_secret,int *size_source)
{

    //finding sizeof secret file
    fseek(secret,0L,SEEK_END);
    *size_secret = ftell(secret);
    fseek(secret,0L,SEEK_SET);

    //finding image size
    *size_source = (image_size_func(source))/8;

    //checking image size is big or not
    if (*size_source < *size_secret)
    {
	printf("\nsize of secret massage is more than image file !!\n");
	return 0;
    }
}

int image_size_func(FILE *fptr)
{
    int width, height;
    // Seek to 18th byte
    fseek(fptr, 18, SEEK_SET);

    // Read the width (an int)
    fread(&width, sizeof(int), 1, fptr);

    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr);

    fseek(fptr, 0L, SEEK_SET);

    // Return image capacity
    return width * height * 3;
}

void get_magic_string(char *str)
{
    char m_char;
    int i,flag;

    printf("\nEnter magic string of length 3.");
    printf("\nYou can use '#' '*' '$' only.\n"); 
    while (1)
    {
	flag = 0;	
	printf("\nEnter magic string : ");
	for (i=0;( m_char = getchar()) != '\n';i++)
	{
	    if (m_char == '#')
	    {
		str[i] = m_char;
	    }
	    else if(m_char == '*')
	    {
		str[i] = m_char;
	    }
	    else if(m_char == '$')
	    {
		str[i] = m_char;
	    }
	    else
	    {
		printf("\nyou entered wrong charectors\n");
		for (i=0;((m_char = getchar()) != '\n');i++);
		flag=1;
		i++;
		break;
	    }
	}

	if ((flag == 0) && (i == 3))
	    break;

	if (i > 3 )
	    printf("\nEntered more charecters in magic string\n");	
	else if (i < 3)
	    printf("\nEntered less charecters in magic string\n");	

    }
    str[i] = '\0';
}

void get_password(char *str)
{
    int i;

    while (1)
    {	
	printf("\nEnter password for security of length 5: ");

	for (i=0;((str[i] = getchar()) != '\n');i++);
	str[i]= '\0';

	if (i == 5)
	    break;
	else if (i > 5 )
	    printf("\nEntered more charecters in password\n");	
	else
	    printf("\nEntered less charecters in password\n");	
    }
}
