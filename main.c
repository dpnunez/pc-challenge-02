#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void readFilesChain(char fileName[]);

int main() {
	readFilesChain("90052");
	return 0;
}

void readFilesChain(char fileName[]) {
	char 
		rootPath[9] = "./files/",
		extension[5] = ".txt",
		fullFilePath[50],
		nextFileName[10],
		ch;
	FILE *fp;
	int counter=0;

	strcat(fullFilePath, rootPath);
	strcat(fullFilePath, fileName);
	strcat(fullFilePath, extension);

	fp = fopen(fullFilePath, "r");

	if (fp == NULL) {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

	while((ch = fgetc(fp)) != EOF)
			if(ch>='0' && ch<='9') {
				nextFileName[counter]=ch;
				counter++;
			}
	

	if(!counter) {
		printf("Ultimo arquivo: %s\n", fullFilePath);
		rewind(fp);
		while((ch = fgetc(fp)) != EOF)
			printf("%c", ch);
		exit(1);
	}
	nextFileName[counter]='\0';

	readFilesChain(nextFileName);
}