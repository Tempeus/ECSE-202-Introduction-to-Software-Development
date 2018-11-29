/*
 ============================================================================
 Name        : ECSE202_A5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

//binary tree of the student record
struct studentRecord {

	// the values of the binary tree
	char First [MAXLEN];
	char Last [MAXLEN];
	int ID;
	int Marks;

	//left and right
	struct studentRecord *left;
	struct studentRecord *right;
};

void addNode(struct studentRecord** root,  struct studentRecord* input, int type){
	// the type number is 1, it will be for ID
	// if the type number is 2, it will be for last name

	//if the root is null
	if ((*root) == NULL){

		//create a root with input value
		(*root) = (struct studentRecord*)malloc(sizeof(struct studentRecord));
		(*root) -> ID = input -> ID;
		(*root) -> Marks = input -> Marks;

		strcpy((*root) -> First, input -> First);
		strcpy((*root) -> Last, input -> Last);

		(*root) -> left = NULL;
		(*root) -> right = NULL;
	}

	else {
		if (type == 1){
			//comparing the student IDs
			// the input is going to be inserted either to LEFT or RIGHT
			if(input -> ID < (**root).ID){
				//insert to the left tree
				addNode(&((*root) -> left), input, type);
			}
			else{
				addNode(&((*root) -> right),input, type);
			}
		}
		else if (type == 2){
			//comparing the last names
			if(strcomp(input -> Last, (*root) -> Last) < 0){
				addNode(&((*root) -> left), input, type);
			}
			else{
				addNode(&((*root) -> right), input, type);
			}
		}
	}
}

//Traversing through the Binary Tree
void traverseID(struct studentRecord* root){
	//if there is left tree --> traverse left
	if (root -> left != NULL){
		traverseID(root -> left);
	}
	//return the middle value
	printf("%d, ", root -> ID);
	// if there is right tree traverse right
	if (root -> right != NULL){
		traverseID(root -> right);
	}
}

int main(int argc, char* argv[]){

	struct studentRecord data, *rootName, *rootID;
	FILE *NamesIDs;
	FILE *Marks;
	if ((NamesIDs = fopen(argv[1],"r")) == NULL){
		// open Names IDs file
		printf("Can't open %s\n", argv[1]);
		return -1;
	}
	if ((Marks = fopen(argv[2],"r")) == NULL){
		//open marks file
		printf("Can't open %s\n", argv[2]);
		return -1;
	}
	//initialization of the two B-Trees
	rootName = NULL;
	rootID = NULL;
	int numrecords = 0;
	while(fscanf(NamesIDs, "%s%s%d", &(data.First[0]),&(data.Last[0]), &(data.ID)) != EOF){
		fscanf(Marks,"%d", &(data.Marks));
		numrecords++;
		addNode(&rootName, &data, 2);
		if (rootName == NULL){
			printf("Error creating name B-Tree, aborted. \n");
			return -1;
		}
		addNode(&rootID, &data, 1); //copy the b-tree sorted by last
		if (rootID == NULL){
			printf("Error creating ID B-Tree, aborted. \n");
			return -1;
		}
	}
	fclose(NamesIDs);
	fclose(Marks);
	traverseID(rootID);


	return 0;
}
