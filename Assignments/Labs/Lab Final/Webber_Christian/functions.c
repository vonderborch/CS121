#include "labfinal.h"

Records getRecords (FILE *inputFile)
{
	Records tempRecords, newRecords;
	char tempLastName[24];
	int itemNum = 0, i = 0, j = 0, tempLength = 0;
	// get initial data
	while (!feof (inputFile))
	{
		printf (".");
		fscanf (inputFile, "%s", &tempRecords.people[itemNum].lastName);
		fscanf (inputFile, "%s", &tempRecords.people[itemNum].firstName);
		fscanf (inputFile, "%d", &tempRecords.people[itemNum].age);
		itemNum++;
	}
	// cycle through data to get cut of commas
	for (i = 0; i < itemNum; i++)
	{
		printf (".");
		newRecords.people[i].age = tempRecords.people[i].age;
		strcpy (newRecords.people[i].firstName, tempRecords.people[i].firstName);
		tempLength = strlen(tempRecords.people[i].lastName);
		strcpy (tempLastName, tempRecords.people[i].lastName);
		for (j = 0; j < tempLength; j++)
		{
			printf (".");
			if (ispunct(tempLastName[j]))
			{
				tempLastName[j] = '\0';
			}
		}

		strcpy (newRecords.people[i].lastName, tempLastName);
		
		//printf ("%s %s:%d/%d\n", newRecords.people[i].firstName, newRecords.people[i].lastName,
		//	newRecords.people[i].age, tempLength);
	}

	printf (".");
	newRecords.peopleStored = itemNum;
	return newRecords;
}

Records sortRecords (Records recordsToSort)
{
	Person tempPerson;
	int indexC = 0, indexU = recordsToSort.peopleStored, i = 0, lastNames = 0,
		unSorted = recordsToSort.peopleStored * recordsToSort.peopleStored;
	// unSorted is set high so as to make sure that everything gets sorted properly...

	while (unSorted > 1)
	{
		for (indexC = 1; indexC < indexU; indexC++)
		{
			printf (".");
			i = indexC - 1;
			lastNames = strcmp (recordsToSort.people[indexC].lastName, recordsToSort.people[i].lastName);
			if (lastNames > 0)
			{
				tempPerson = recordsToSort.people[indexC];
				recordsToSort.people[indexC] = recordsToSort.people[i];
				recordsToSort.people[i] = tempPerson;
			} else {
				unSorted--;
			}
		}
	}

	return recordsToSort;
}

void saveRecords (FILE *outputFile, Records recordsToSave)
{
	int i = 0;
	for (i = 0; i < recordsToSave.peopleStored; i++)
	{
		printf (".");
		fprintf (outputFile, "%d\t\t%s, %s\n", recordsToSave.people[i].age,
			recordsToSave.people[i].lastName, recordsToSave.people[i].firstName);
	}
}