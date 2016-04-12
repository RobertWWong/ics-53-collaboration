#include "stdio.h"
#include <string.h>

//taking a long time to compile and i don't know why. Is it because of the for loop?
	struct string {
		char str[100];
	};
	struct string global_c[100];
	int cnt = 0;
	char endline [1] = "\n";
	

//Your record keeper program should prompt the user for a command, perform the command, 
//and then prompt for the next command. Your program should support the following 5 commands:

void read (char * read_file){	//arg is a string
	// Read a record file from disk and represent its contents in memory using data structures of your choosing.
	// This command takes one argument, the name of a record file to be read. This command does not print any output. 
	extern struct string global_c[];
	extern int cnt;
	
	struct string temp;

	printf ("Reading from %s\n\n", read_file);

	FILE *fp;
	char buff [255];
	fp = fopen(read_file, "r");
	while (fgets (buff, 255, (FILE*)fp))
	{
		strcpy (temp.str, buff);
		global_c [cnt++] = temp;
		printf("Current we have this %s\n", buff);		//think of printf as your format, they will appear at your % signs specifically.
		//fgets (buff, 255, (FILE*)fp); //don't understand the (FILE*) part
	}
	strcat (global_c[cnt - 1].str, endline);
	
	fclose(fp);
}

void write (char * write_file ){
 // Write a record file to disk which contains the records currently stored in memory using data structures of your choice. 
 // This command takes one argument, the name of the record file to be written to disk. The command does not print any output. 
	extern struct string global_c[];
	extern int cnt;
	printf ("writing to %s \n", write_file);

	FILE *fp;
	fp = fopen(write_file, "a");

	int i = 0;
	while (i < cnt){
	//for (; i < cnt; i++)
		fputs (global_c[i].str, fp);	//this will write to the file
		i++;
	}
	fclose(fp);
}

void print () {
	 // Print all of the records currently loaded into memory, in order. 
	 // Each record should be printed on a single line and should be prefixed with a unique number 
	 // which indicates its order with respect to the other records. 

	//for (int i = 0; i <cnt; i++){
	int i = 0;
	while (i <cnt){
		printf("%d %s", i+1, global_c[i].str );
		i++;
	}
	printf("");
}

void delete (int recNum) {
	// Deletes a record from the your memory store. This command takes one argument which is the number of the record to be deleted. 
	// Note that the remaining records should be renumbered from 1 so that there is not a gap in the record numbering.

}

void quit() {

}

char * input(){
	//accept and returns user inputs as strings
	char str[100];
	scanf("%s", str);
	return str;
}

enum CMD {RD = 'r', WD= 'w', PRT= 'p', DEL= 'd', QUIT ='q'};
int main(){

	printf("Starting Program addrs: \n");
	
	char * text ;
	int c;
	while (c != 'q')
	{
	printf("Commands are: \n(r)ead\n(w)rite\n(p)rint\n(d)elete\n(q)uit\n");
	printf ("Your command: ");
	c = getchar();	//will only read as many string as you input it
	enum CMD COM = c;
	switch (COM){
		case RD:
			printf("Enter text file to read:\n");
			text = input();
			read(text);
			break;
		case WD :
			printf("Enter text file to write to:\n");
			text = input();
			write(text);
			break;
		case PRT:
			printf("printing\n");
			print();
			break;
		case DEL:
			printf ("deleteing\n");
			break;
		case QUIT:
			printf("Quiting\n");
			break;
		default:
			printf("Invalid Command\n");

	}
	//printf("%s", str);	//will return just one string


}
  
  
  return 0;
}

