/*
 =================================================================================
 Name        : ECSE202_A6.c
 Author      : Kevin Li
 Version     : 1.0
 Copyright   : 
 Description : This program takes two text files where one include the student
			   names and Id whereas the other one include the grades they received.
			   This program will read those files and sort them in a B-Tree while 
			   also giving the users several options into how they want the info
			   printed.
 =================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 20


//this is for the infinite while loop later on
int p = 1;

//The code underneath is used for the representation of a Node in a Binary Tree for student records
struct StudentRecord {
    char First[MAXLEN];
    char Last[MAXLEN];
    int ID;
    int Marks;
    struct StudentRecord *left;
    struct StudentRecord *right;
};

//The addNode function that is used to create nodes in the student record binary tree
struct StudentRecord *addNode(struct StudentRecord *root, struct StudentRecord *new_Node, int type) {
    //if StudentRecord is empty, it will create a new tree with the new Node as the root.
    if (root == NULL) {
        (root) = (struct StudentRecord *) malloc(sizeof(struct StudentRecord));
        (root)->ID = new_Node->ID;
        (root)->Marks = new_Node->Marks;
        (root)->left = NULL;
        (root)->right = NULL;
        strcpy((root)->First, new_Node->First);
        strcpy((root)->Last, new_Node->Last);
    } else {
        //the type is used to distinguish if the Binary tree must be sorted by the Student ID or by the Student Name
        //type 1 is sorting by ID whereas type 2 sorts by last name
        if (type == 1) { //Type 1: ID
            if (new_Node->ID < (*root).ID) {
                root->left = addNode(root->left, new_Node, 1);
            } else root->right = addNode(root->right, new_Node, 1);

        } else { //Type 2: Last name
            if (strcmp(new_Node->Last, (*root).Last) < 0) {
                root->left = addNode(root->left, new_Node, 2);
            } else root->right = addNode(root->right, new_Node, 2);
        }
    }
    return root;
}

//This recursion is used to search through the bTree using student ID. 
struct StudentRecord *search(struct StudentRecord *root, int sID) {
    if (root == NULL || root->ID == sID) return root;
    //If the ID we are searching is less than the root: traverse left
    if (root->ID > sID) return search(root->left, sID);
    //if the ID we are searching is greater than the root: traverse right
    return search(root->right, sID);
}

//This recursion is used to search the bTree using student names.
struct StudentRecord *searchName(struct StudentRecord *root, char *sName) {
    if (root == NULL || strcasecmp(root->Last, sName) == 0) return root;
    //If the name we are searching is less than the root: traverse left
    if (strcasecmp(root->Last, sName) > 0) return searchName(root->left, sName);
    //if the name we are searching is greater than the root ID: traverse right
    return searchName(root->right, sName);
}
//Traversing through the trees using inorder while also printing a list of all students inorder by name & by ID;
void inorder(struct StudentRecord *root) {
    if (root->left != NULL) inorder(root->left);
	//the numbers after the % is used to organize the listing of the students info by increasing it's spacing
    printf("%-10s %-10s %-5d %d \n", root->First, root->Last, root->ID, root->Marks);
    if (root->right != NULL) inorder(root->right);
}

//The main run function including the various available options that the user can pick to print different results.
int main(int argc, char *argv[]) {
    struct StudentRecord data, *rootName, *rootID;
    FILE *NamesIDs;
    FILE *Marks;
	//implementing error checking if the file cannot be open
    if ((NamesIDs = fopen(argv[1], "r")) == NULL) {
        printf("Can't open %s\n", argv[1]);
        return -1;
    }
    if ((Marks = fopen(argv[2], "r")) == NULL) {
        printf("Can't open %s\n", argv[2]);
        return -2;
    }
    rootName = NULL;
    rootID = NULL;
    int nRecords = 0;
    printf("Building database... \n");

	//Reading the file and building the database for the student record
    while (fscanf(NamesIDs, "%s%s%d", &(data.First[0]), &(data.Last[0]), &(data.ID)) != EOF) {
        fscanf(Marks, "%d", &(data.Marks));
        nRecords++;
        
        rootName = addNode(rootName, &data, 2);
        if (&rootName == NULL) {
            printf("Error creating name B-Tree, aborted. \n");
            return -3;
        }

        rootID = addNode(rootID, &data, 1);
        if (&rootID == NULL) {
            printf("Error creating ID B-Tree, aborted.\n");
            return -4;
        }
    }
    printf("Finished...\n");

	//closing the files since we don't need them anymore
    fclose(NamesIDs);
    fclose(Marks);

    
	//All commands are below maximum 5 characters
	
    while(p == 1) {
        char str[5];
        printf("\nsdb: ");
        scanf("%s", &str);

        //convert string into upper case to remove case sensitivity
        for (int i = 0; str[i]; i++) {
            str[i] = toupper((unsigned char) str[i]);
        }

        //This is to print a list of all students by Last name
        if (strcmp(str, "LN") == 0) {
            printf("\nStudent Record Database sorted by Last Name\n\n");
            inorder(rootName);
        }

        //This is to print a list of all student by ID
        else if (strcmp(str, "LI") == 0) {
            printf("\nStudent Record Database sorted by Student ID\n\n");
            inorder(rootID);
        }

        //This is used to find the student using their last name and returning their ID,  name and grade
        else if (strcmp(str, "FN") == 0) {
            char findName[10];
            printf("Enter name to search: ");
            scanf("%s", &findName);
            struct StudentRecord *found = searchName(rootName, findName);
            if (found == NULL) printf("\nThere is no student with that name.\n");
            else {
                printf("\nStudent name:      %s %s", found->First, found->Last);
                printf("\nTotal ID:          %d", found->ID);
                printf("\nTotal Grade:       %d\n", found->Marks);
            }
        }

        //This is used to find the student using their ID and returning their entire name, ID and Grade
        else if (strcmp(str, "FI") == 0) {
            int findID;
            printf("Enter ID to search: ");
            scanf("%d", &findID);
            struct StudentRecord *found = search(rootID, findID);
            if (found == NULL) printf("\nThere is no student with that ID.\n");
            else {
                printf("\nStudent name:      %s %s", found->First, found->Last);
                printf("\nTotal ID:          %d", found->ID);
                printf("\nTotal Grade:       %d\n", found->Marks);
            }
        }

        //Listing all possible commands and their functions
        else if ((strcmp(str, "HELP") == 0) | (strcmp(str, "H") == 0) | (strcmp(str, "?") == 0)) {
            printf("LN     List all the records in the database ordered by Last name.\n"
                   "LI     List all the records in the database ordered by student ID.\n"
                   "FN     Prompts for a name and lists the record of the student with the corresponding name.\n"
                   "FI     Prompts for a name and lists the record of the student with the corresponding ID.\n"
                   "HELP   Prints this list\n"
                   "?      Prints this list\n"
                   "Q      Exits the program.");
        }

		//Quiting the program
        else if (strcmp(str, "Q") == 0 || strcmp(str, "QUIT") == 0) {
            break;
        }

		//When the user inputs an unrecognized command
        else printf("Error, invalid command.\n");

    }
    printf("Exiting Program...");
    return 0;
}
