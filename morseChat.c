#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stddef.h>
#include <errno.h>
#include <stdbool.h>
extern int errno ;

const char *characters[] = { " ", 
                             "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
                             "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", 
                             "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", 
                             ",", ".", "?", "!", "@", "&", "(", ")"};

const char *morsecode[] = { " ",
                            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
                            "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
                            ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.","-----",
                            "--..--", ".-.-.-", "..--..","-.-.--",".--.-.",".-...","-.--.","-.--.-"}; 
const char *dot[] = {"."};

int main(int argc, char* argv[])
{	
	int counter = 0; 
	printf("You have given %d arguments\n", argc);
 	for(counter = 0; counter < argc; counter++) 
 	{
  		printf("%d: %s\n", counter, argv[counter]);
 	}
 	if (argc == 3)	
 	{
		if ( ! strcmp(argv[1], "--text"))
		{
	  		char text_input[500] = ""; 
	  		strcpy(text_input, argv[2]);            
	  		int i = 0;
	  		char text_output[5000] = "";        
	  		int length = strlen(text_input);    
	  		for(i = 0; i < length; i++)         
	  		{
	    			int j;                            
	    			for (j = 0; j < 45; j++)
	    			{
	      				if (tolower(text_input[i]) == *characters[j])
	      				{
						strcat(text_output, " ");
						strcat(text_output, morsecode[j]);
	      				}
	    			}			
	  		}
	    		printf("This is text output %s\n",  text_output);
	    	}
	    				
	    	else if ( ! strcmp(argv[1], "--file"))
	    	{
	    		FILE *fptr;
	  
	    		char file_input[1000], c;
	  		strcpy(file_input, argv[2]);
	    		fptr = fopen(file_input, "r");
	    		int errnum;
	    		printf("This is file name %s\n",  file_input);
	    		if (fptr == NULL)
	    		{
	    			errnum = errno;
				printf("ERROR! File can't be opened \n");
				fprintf(stderr, "Value of errno: %d\n", errno);
      				perror("Error printed by perror");
      				fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
				exit(0);
	    		}
	  	

	    		char file_output[1000000];
	    		c = fgetc(fptr);
	    		int t = 0;
	    		int a = 0;
	    		while (c != EOF)
	    		{       
	    			if (c == '\n')
	    			{
	    				t++;
	    			}
				file_output[t] = tolower(c);
				t++;
				c = fgetc(fptr);
	    		}		
	  
	    		file_output[t] = '\0';
	  		int l = strlen(file_output);    
	  		for(int i = 0; i < l; i++)         
	  		{
	    			int j;                            
	    			for (j = 0; j < 45; j++)
	    			{
	      				if (file_output[i] == *characters[j])
	      				{
						strcat(file_output, " ");
						strcat(file_output, morsecode[j]);
	      				}
	    			}
	  		}    
	  	
	  		printf("%s\n", file_output);
	  		
	  	}

	  }
	  	else if (argc == 1)
	  	{
			for(;;)
			{				
				char cl_input[500] = "";
	  			char cl_output[500]= "";
	  			printf("\n");
	  			printf("Please enter the text that you want to convert into morse code:\n ");
				fgets(cl_input, 500, stdin);
				int length = strlen(cl_input);
				if (cl_input[0] == *dot[0])				
				{
					printf("Program has come to an end.\n");
					exit(0);
				}else{
					for(int i = 0; i < (length); i++)         
	  				{        
	  					int j;                   
	    					for (j = 0; j < 45; j++)
	    					{
	      						if (tolower(cl_input[i]) == *characters[j])
	      						{
								strcat(cl_output, " ");
								strcat(cl_output, morsecode[j]);
								
	      						}	
	    					}			
	  				}
	  				printf("%s", cl_output);
	  			}
			}	  	
	  	}		

  return 0;
}

