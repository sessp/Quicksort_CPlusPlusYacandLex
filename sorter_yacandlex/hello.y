%{
#include <stdio.h>
#include "y.tab.h"
#include <string.h>
void yyerror(const char *str)
{
        fprintf(stderr,"error: %s\n",str);
}
 
int yywrap()
{
        return 1;
} 
  
main()
{
        yyparse();
} 
%}
%token UNSORTEDLIST
%union {
   char * list;
};
%type<list> UNSORTEDLIST

%%
commands:  
        | commands command
        ;
command: 
	sort
	;
sort:
	UNSORTEDLIST
	{
		//printf("Number list in correct format: %s \n", $1);//$1
                char* unsorted = $1;
		printf("Number list in correct format: %s with length %d \n", unsorted, strlen(unsorted));
		char* split = strtok(unsorted,",[]");
                int* arrayToSort = (int*)malloc(strlen(unsorted) * sizeof(int));
                int elementNum = 0;
		while(split != NULL)
		{
			arrayToSort[elementNum] = atoi(split);
                        //convert using atoi and add to int array.
			split = strtok(NULL, ",[]");
			elementNum++;
			//Convert using atoi, add to our int array + make sure no []
		}
		//Sort using insertion - [?]
		int j,k,i,l;
		for(i = 0; i < elementNum; i++)
		{
		    k = arrayToSort[i];
		    j = i - 1;
		    while(j >= 0 && arrayToSort[j] > k)
		    {
                      arrayToSort[j+1] = arrayToSort[j];
		      j = j - 1;
                    }
                    arrayToSort[j+1] = k;
		}
                for(l = 0; l < elementNum; l++)
		{
		   printf("\n Sorted Array: %d \n", arrayToSort[l]);
		}		
                
                free(arrayToSort);
	};