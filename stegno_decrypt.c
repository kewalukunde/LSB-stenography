int dycryption(char *argv_2,char *argv_3)
{
    FILE *file_sorce,*file_out;
    char s[10],pass_dec[10],pass_ent[10],magic_str[10],magic_str1[10];
    int buff=0,i,j=0,ch,size_txt,size,shift,temp;
    int passward,enter_pass;

    //opening file for operetion
    if((file_sorce = fopen(argv_2,"r")) == NULL)
    {
	printf("\nERROR !! Pass source_image_file\n");
	return -1;
    }

    fseek(file_sorce,54,SEEK_SET);
    
    decrypt_num(file_sorce,&size);
    decrypt_string(file_sorce,magic_str,size);
    
    printf("\nEnter magic string : ");
    for (i=0;((magic_str1[i] = getchar()) != '\n');i++);
    magic_str1[i]= '\0';

    temp = strcmp(magic_str1,magic_str);

    if(temp)
    {
	printf("\n# You entered wrong magic string\n");
	return 0;
    }
    else
    {
	printf("\n# Magic string accepted\n");
    }
    
    decrypt_num(file_sorce,&size);
    decrypt_string(file_sorce,pass_dec,size);
    
    printf("\nEnter passward : ");

    scanf("%s",pass_ent); 
    
    temp = strcmp(pass_ent,pass_dec);

    if(temp)
    {
	printf("\n# You entered wrong passward\n");
	return 0;
    }
    else
    {
	printf("\n# Passward accepted\n");
    }

    //decrypting file extention
    decrypt_num(file_sorce,&size);
    decrypt_string(file_sorce,s,size);
    strcat(argv_3,s);

    //opening file with extention
    file_out = fopen(argv_3,"w");

    //decrypting file size
    decrypt_num(file_sorce,&size_txt);

    //decrypting secret file
    decrypt_secret(size_txt,file_sorce,file_out);  

    printf("\n# Output file generated as '%s'\n\n",argv_3);

    //clossing file
    fclose(file_sorce);
    fclose(file_out);

    return 0;
}
