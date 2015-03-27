#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *_ptr_cmd;
char *_ptr_param;
#define TO_SEP_CMD	 (_ptr_param = strsep(&_ptr_cmd, ","))
#define GET_PARAM_H(defparam) (TO_SEP_CMD ? strtoll(_ptr_param, NULL, 16) : defparam)
#define GET_PARAM_D(defparam) (TO_SEP_CMD ? strtoll(_ptr_param, NULL, 10) : defparam)
#define GET_PARAM_S() (TO_SEP_CMD)

void main(int argc, char* argv[])
{
	FILE *fp;
	int i=0,j;
	char str[10][64];
	char tmpstr[64];
	char *rp;

	fp = fopen("test.txt", "r");
	if(NULL == fp)
	{
		printf("Open test.txt Fail\n");
		return;
	}
printf("~1\n");
#if 1
	while(1) {
	      rp = fgets(str[i], 64, fp);
	      if (rp == NULL)
		    break;
	      printf("str = %s, size = %d\n", str[i], sizeof(str[i]));
		printf("%X %X %X %X\n",  str[i][0], str[i][1], str[i][2], str[i][3]);
	if (str[i][0] == 0x0d || str[i][0] == 0x0a) {
		printf("NONE\n");
	} else {
		_ptr_cmd = str[i];

		GET_PARAM_S();
		GET_PARAM_S();
		GET_PARAM_S();
		printf("%s\n", GET_PARAM_S());
	}
	      i++;
	      //if (i >= 5)
	//	    break;
	}
#else
	while(fgets(str[i++], 64, fp));
#endif
	
	printf("~2\n");

	for(i=0; i<5; i++)
	{

	for(j=i+1; j<5; j++)
	{
		if(str[i][0] > str[j][0])
		{
			strcpy(tmpstr, str[i]);
			strcpy(str[i], str[j]);
			strcpy(str[j], tmpstr);			
		}
	}


	}

printf("~3\n");
							
	fclose(fp);			
	fp = fopen("test1.txt", "w");

printf("~4\n");
	for(i=0; i<5; i++)
	      fputs(str[i], fp);
	fclose(fp);
	return;
}

