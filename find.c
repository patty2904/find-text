/* Patrycja Chrzaszcz
Last modified: 01/03/20
Using the command line, the program is able to find whole strings (or elements of them) in a text file and replace them with the specified string, if needed.
It displays the text to the console and output file if specified. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LINE_LENGTH 1000
	
int main(int argc, char **argv)
{
	
		char line [LINE_LENGTH];
		char userString[LINE_LENGTH];
		char* replacementString = "";
		char* word;
		int doReplacement = 0;
		char fileName[200];
	
		for(int i = 1; i < argc; i++) 
		{ 

			if (strcmp(argv[i], "-i") == 0) 
			{
				strcpy(fileName, argv[i + 1]); //Get filename from arguments
				i++;
			}
			
			else if (strcmp(argv[i], "-r") == 0)
			{
				strcat(replacementString, argv[i + 1]); //add cl argument into string
				doReplacement = 1; //set flag to 1
				i++;
			}
			
			else if (strcmp(argv[i], "-c") == 0) //leave for -c cl argument in console
			{
				
			}
			
			else 
			{
				strcpy(userString, argv[i]);	//user string to be replaced
			}

		}
		
		FILE *input_file = fopen(fileName, "r");
		char *location_of_search_term;
		FILE *output_file;
		const char delimiter[6] = ".,?' \n";
		
		if (doReplacement == 1) 
		{
			output_file = fopen("output.txt", "w+"); //create output only if -r is input
		}
			
		while(fgets(line, LINE_LENGTH, input_file) != NULL) 
		{
			int len = strlen(line);	//strip line
			if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
			
			word = strtok(line, delimiter); //Get the first word from line
			while(word != NULL) 
			{
				char emptyString[100]; //create empty string for replacement
				emptyString[0] = '\0';
				
				location_of_search_term = strstr(word, userString); //Check if userString is in word 
				if(location_of_search_term != NULL)
				{
					
					if (doReplacement == 1) 
					{
						char char_to_string[2];
						char_to_string[1] = '\0';
						
						for (int i = 0; i < location_of_search_term - word; i++) //gets the length of the characters before the userString
						{
							char_to_string[0] = word[i];
							char_to_string[1] = '\0';
							strcat(emptyString, char_to_string); //copy characters before userString
							i++;
						}
						
						strcat(emptyString, replacementString); //copy search term into the string
						
						for(int j = location_of_search_term - word + strlen(userString); j <= (strlen(word) - 1); j++) //gets length after userString
						{ 
							char_to_string[0] = word[j];
							char_to_string[1] = '\0';
							strcat(emptyString, char_to_string); //copy characters after userString
						}
						
						fprintf(output_file, "%s\n", emptyString);
						
					}
					
					printf("%s %s\n", word, emptyString);
					
				} 
				
				else 
				{
					if (doReplacement == 1) 
					{	
					fprintf(output_file, "%s ", word);
					}
				}
				
				word = strtok(NULL, delimiter); //Go to next word
			}
		}
		
		fclose(input_file);
		
			if (doReplacement == 1)
			{
			fclose(output_file); 
			}
		
 return 0;	
 
}
/* SOURCES
https://stackoverflow.com/questions/4834811/strcat-concat-a-char-onto-a-string REPLACEMENT
https://stackoverflow.com/questions/18838933/why-do-i-first-have-to-strcpy-before-strcat ISSUE WITH REPLACEMENT
https://stackoverflow.com/questions/3889992/how-does-strtok-split-the-string-into-tokens-in-c STRTOK
Workbook
Programming surgeries
Practical sessions
 */