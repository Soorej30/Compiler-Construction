/*
BATCH NO. 27
Mayank Agarwal (2014A7PS111P)
Karan Deep Batra(2014A7PS160P)
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashtable.h"
#include "ntort.h"

int hash(char* str)//hash from string to bucket number
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
	    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return (int)(hash % hashtablesize);
}

void printhashtable(hashtable* table) //print hash table
{
	for(int i=0; i<hashtablesize; i++)
	{
		printf("%d -> ",i);
		ntort* pt = table->buckets[i];
		while(pt != NULL)
		{
			printntortnode(pt);
			pt=pt->next;
		}
		printf("\n");
	}
	return;
}

hashtable* makehashtable() //returns pointer to new hash table
{
	hashtable* temp = (hashtable*)malloc(sizeof(hashtable));
	for(int i=0; i<hashtablesize; i++)
		temp->buckets[i] = NULL;
	return temp;
}

int present(hashtable* table, char* str) //checks if str is present in table and returns corresponding mapping to integer
{
	int h = hash(str);
	ntort* pt = table->buckets[h];

	while(pt != NULL)
	{
		if(strcmp(str,pt->str) == 0)
			return pt->val;
		pt = pt->next;
	}
	return 0;
}

void insert(hashtable* table, char* str) //inserts str to table and assigns number according to terminal or non terminal
{
	// printf("%s\n",str);
	static int ntval=1, tval=1;
	int h = hash(str);
	ntort* pt = table->buckets[h];
	int nt;
	if(str[0] == '<')
	{
		nt = 1;
		ntort* newnode = makentortnode(nt, ntval,str);
		ntval++;
		newnode->next = pt;
		table->buckets[h] = newnode;
	}
	else
	{
		nt = 0;
		ntort* newnode = makentortnode(nt, tval,str);
		tval++;
		newnode->next = pt;
		table->buckets[h] = newnode;
	}
	return;
}

ntort* getnodehashtable(hashtable* table, char* str) //finds and returns node from hashtable table
{
	int h = hash(str);
	ntort* pt = table->buckets[h];

	while(pt != NULL)
	{
		if(strcmp(str,pt->str) == 0)
			return pt;
		pt = pt->next;
	}
	return pt;
}