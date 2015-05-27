#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person
{
	char firstName[24];
	char lastName[24];
	int age;
} Person;
typedef struct records
{
	int peopleStored;
	Person people[1000];
} Records;

Records getRecords (FILE *inputFile);
Records sortRecords (Records recordsToSort);
void saveRecords (FILE *outputFile, Records recordsToSave);