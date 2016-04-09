#include "stdio.h"

//Your record keeper program should prompt the user for a command, perform the command, 
//and then prompt for the next command. Your program should support the following 5 commands:

void read (char read_file[]){	//arg is a string
	// Read a record file from disk and represent its contents in memory using data structures of your choosing.
	// This command takes one argument, the name of a record file to be read. This command does not print any output. 

	printf ("Here you go %s\n", read_file);
	FILE *fp;
	char buff [255];

	fp = fopen(read_file, "r");

	fgets (buff, 255, (FILE*)fp); //don't understand the (FILE*) part

	printf("Current we have this %s\n  ", buff);		//think of printf as your format, they will appear at your % signs specifically.

	fclose(fp);
	
}

void write (char *write_file[]){
 // Write a record file to disk which contains the records currently stored in memory using data structures of your choice. 
 // This command takes one argument, the name of the record file to be written to disk. The command does not print any output. 
}

void print () {
	 // Print all of the records currently loaded into memory, in order. 
	 // Each record should be printed on a single line and should be prefixed with a unique number 
	 // which indicates its order with respect to the other records. 

}

void delete () {
	// Deletes a record from the your memory store. This command takes one argument which is the number of the record to be deleted. 
	// Note that the remaining records should be renumbered from 1 so that there is not a gap in the record numbering.

}

void quit() {

}


int main(){

  printf("Starting Program addrs: \n");
	
	char str[100];
	
	printf ("Now enter your command: ");
	scanf ("%s" , str);		//will only read as many string as you input it
	printf("\nHere's the command, it is : %s", str);	//will return just one string
	printf("\n");

	read(str);
  
  
  return 0;
}

