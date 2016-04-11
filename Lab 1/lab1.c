#include "stdio.h"
#include <string.h>

//taking a long time to compile and i don't know why. Is it because of the for loop?
	struct string {
		char str[1024];
	};
	struct string global_c[100];
	int cnt;
	

//Your record keeper program should prompt the user for a command, perform the command, 
//and then prompt for the next command. Your program should support the following 5 commands:

void read (char read_file[]){	//arg is a string
	// Read a record file from disk and represent its contents in memory using data structures of your choosing.
	// This command takes one argument, the name of a record file to be read. This command does not print any output. 
	extern struct string global_c[];
	extern int cnt;
	
	struct string temp;

	printf ("Reading from %s", read_file);

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
	
	fclose(fp);
}

void write (char write_file[]){
 // Write a record file to disk which contains the records currently stored in memory using data structures of your choice. 
 // This command takes one argument, the name of the record file to be written to disk. The command does not print any output. 
	extern struct string global_c[];
	extern int cnt;
	FILE *fp;
	fp = fopen(write_file, "a");
	fclose(fp);
}

void print () {
	 // Print all of the records currently loaded into memory, in order. 
	 // Each record should be printed on a single line and should be prefixed with a unique number 
	 // which indicates its order with respect to the other records. 
	

/*
	for (int i = 0; i <cnt; i++){
		printf("%d %s", i+1, global_c[i].str );
	}
*/
}

void delete () {
	// Deletes a record from the your memory store. This command takes one argument which is the number of the record to be deleted. 
	// Note that the remaining records should be renumbered from 1 so that there is not a gap in the record numbering.

}

void quit() {

}

int main(){

	printf("Starting Program addrs: \n");
	struct string global_c[100];
	int cnt = 0;

	char str[100];
	while (strcmp("quit", str))
	{
	printf ("Your command: ");
	scanf ("%s" , str);		//will only read as many string as you input it
	printf("%s", str);	//will return just one string


}
	read(str);
	print();
  
  
  return 0;
}

