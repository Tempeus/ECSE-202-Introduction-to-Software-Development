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
//Representative of a Node in a Binary Tree for student records
struct StudentRecord {
    char First[MAXLEN];
    char Last[MAXLEN];
    int ID;
    int Marks;
    struct StudentRecord *left;
    struct StudentRecord *right;
};

//The addNode method for the student record bTree
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
        //the type variable is used to check if the BTree needs to be sorted by ID or by Name
        //type 1 is sorting by ID and type 2 sorts by last name
        if (type == 1) {
            if (new_Node->ID < (*root).ID) {
                root->left = addNode(root->left, new_Node, 1);
            } else root->right = addNode(root->right, new_Node, 1);

        } else {
            if (strcmp(new_Node->Last, (*root).Last) < 0) {
                root->left = addNode(root->left, new_Node, 2);
            } else root->right = addNode(root->right, new_Node, 2);
        }
    }
    return root;
}

//searching the bTree using student ID
struct StudentRecord *search(struct StudentRecord *root, int ID_search) {
    //Base case of this recursion, return root if it's null or the ID_search is at the present root
    if (root == NULL || root->ID == ID_search) return root;
    //If the ID we are searching is less than the root's key: traverse left
    if (root->ID > ID_search) return search(root->left, ID_search);
    //if the ID we are searching is greater than the root's ID: traverse right
    return search(root->right, ID_search);
}

//searching the bTree using student names
struct StudentRecord *searchName(struct StudentRecord *root, char *name_search) {
    //Base case of this recursion, return root if it's null or the name_search is at the present root
    if (root == NULL || strcmp(root->Last, name_search) == 0) return root;
    //If the name we are searching is less than the root's key
    //traverse left
    if (strcmp(root->Last, name_search) > 0) return searchName(root->left, name_search);
    //if the name we are searching is greater than the root's ID traverse right
    return searchName(root->right, name_search);
}
//Traversing through the trees using inorder while also printing a list of all students inorder by name & by ID;
void inorder(struct StudentRecord *root) {
    if (root->left != NULL) inorder(root->left);
    printf("%-10s %-10s %-5d %d \n", root->First, root->Last, root->ID, root->Marks);
    if (root->right != NULL) inorder(root->right);
}

//The main run function including the various available options that the user can pick to print different results.
int main(int argc, char *argv[]) {
    struct StudentRecord data, *rootName, *rootID;
    FILE *NamesIDs;
    FILE *Marks;
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
    int numrecords = 0;
    printf("Building database... \n");
    while (fscanf(NamesIDs, "%s%s%d", &(data.First[0]), &(data.Last[0]), &(data.ID)) != EOF) {
        fscanf(Marks, "%d", &(data.Marks));
        numrecords++;
        
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
    fclose(NamesIDs);
    fclose(Marks);
    //All commands are below maximum 5 characters
	p = 1
    while(p == 1) {
        char str[5];
        printf("\nsdb: ");
        scanf("%s", &str);
        //convert string into upper
        for (int i = 0; str[i]; i++) {
            str[i] = toupper((unsigned char) str[i]);
        }
        //list all students by Last name
        if (strcmp(str, "LN") == 0) {
            printf("\nStudent Record Database sorted by Last Name\n\n");
            inorder(rootName);
        }
        //list all student by ID
        else if (strcmp(str, "LI") == 0) {
            printf("\nStudent Record Database sorted by Student ID\n\n");
            inorder(rootID);
        }
        //find student by name
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
        //find student by ID
        //same thing as searching by name
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
        //Displays all possible commands
        else if ((strcmp(str, "HELP") == 0) | (strcmp(str, "H") == 0) | (strcmp(str, "?") == 0)) {
            printf("LN     List all the records in the database ordered by Last name.\n"
                   "LI     List all the records in the database ordered by student ID.\n"
                   "FN     Prompts for a name and lists the record of the student with the corresponding name.\n"
                   "FI     Prompts for a name and lists the record of the student with the corresponding ID.\n"
                   "HELP   Prints this list\n"
                   "?      Prints this list\n"
                   "Q      Exits the program.");
        }
        else if (strcmp(str, "Q") == 0 || strcmp(str, "QUIT") == 0) {
            break;
        }
        else printf("Error, invalid command.\n");

    }
    printf("Exiting Program...");
    return 0;
}
