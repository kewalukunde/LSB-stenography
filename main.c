#include "stegno.h"

int main(int argc,char *argv[])
{
    int i;
    char *argv_2,*argv_3,*argv_4;

    switch(argc)
    {
	case 8 :	if(!strcmp(argv[1],"-e"))
			{
			    for (i = 2; i < 8; i++)
			    {
				if (!strcmp(argv[i],"-s"))
				    argv_2 = argv[i+1];

				if (!strcmp(argv[i],"-c"))
				    argv_3 = argv[i+1];

				if (!strcmp(argv[i],"-o"))
				    argv_4 = argv[i+1];
			    }			    
			    encryption(argv_2, argv_3, argv_4);
			    break;
			}

	case 6 :	if(!strcmp(argv[1], "-d"))
			{
			    for (i = 2; i < 6; i++)
			    {
				if (!strcmp(argv[i],"-s"))
				    argv_2 = argv[i+1];

				if (!strcmp(argv[i],"-o"))
				    argv_3 = argv[i+1];
			    }			    

			    dycryption(argv_2, argv_3);
			    break;
			}

	default : printf("Not enought argument passed\n");
    }	
    return 0;
}

