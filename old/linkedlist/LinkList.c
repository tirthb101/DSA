/**
 * @file LinkList.c
 * @author Tirth Bhatiya
 * @brief This file has basic functions to interact with a linked list 
 * 
 * 
 */
#include <Stdio.h>
#include <stdlib.h>

struct Node{
	int number;
	struct Node* next;
};

struct Node* Initialize(int Value_Of_First);
int Transverse(int tofind, struct Node** origin);
int AddNode(int value_to_Add,struct Node** origin);

int main(){
	char option;
	int value, error;
	struct Node* origin = Initialize(2);
	if(origin == NULL){
		return 1;
	}	
	while(1){
		printf("Enter a charactor:\n");
		option = getchar();

		if(option == 'a'){
			printf("Enter a value to Add:\n");
			scanf("%d", &value);
			error = AddNode(value, &origin);
			if (error == 1){
				printf("Couldn't add the node.\n");
				return 1;
			}
		}
		else if(option == 't'){
			printf("Enter a value to Transverse:\n");
                        scanf("%d", &value);
                        error = Transverse(value, &origin);
			if (error == 1){
                                printf("Couldn't find the node.\n");
                            
                        }else{
				printf("Found the node.\n");
			}

		}
	}
	return 0;	
}


struct Node* Initialize(int value_of_First){
	struct Node* node = malloc(sizeof(struct Node));
	if(node == NULL){
		return NULL;
	}	
	node->number = value_of_First;
	node->next = NULL;
	return node;
}

int AddNode(int value_to_Add,struct Node** origin){
	struct Node* node = malloc(sizeof(struct Node));
	if(node == NULL){
		return 1;
	}
	node->number = value_to_Add;
	node->next = *origin;
	*origin = node;
	return 0;
}

int Transverse(int tofind,struct Node** origin){
	for (struct Node *Origin = *origin; Origin != NULL; Origin = Origin->next){
		if (Origin->number == tofind){
			return 0;
		}
	}
	return 1;
}