#include <stdio.h>
#include <stdlib.h>
struct node{
	int expo;
    int coef;
	struct node *next;
};
typedef struct node node;

//Prototype Declaration
node *create(node*);
void displayPolynomial(node*);
node* addPolynomials(node* poly1, node* poly2);
void freeLinkedList(node *);

int main() {
    node* poly1 = NULL;
    node* poly2 = NULL;

    printf("Enter the first polynomial:\n");
    poly1 = create(poly1);

    printf("Enter the second polynomial:\n");
    poly2 = create(poly2);

    node* result = addPolynomials(poly1, poly2);

    displayPolynomial(result);

    // Free memory
    freeLinkedList(poly1);
    freeLinkedList(poly2);
    freeLinkedList(result);

    return 0;
}

//free linkedlist
// void freeLinkedList(node *start) {
//     free(start);
// }
void freeLinkedList(node* start) {
    while (start != NULL) {
        node* temp = start;
        start = start->next;
        free(temp);
    }
}

//create linkedlist
node *create(node *start){
	node  *newNode, *last;
	int degree;

	printf("Enter the highest degree of the polynomial: ");
    scanf("%d", &degree);

    for (int i = degree; i >= 0; i--) {
        int coef;
        printf("Enter the coefficient for x^%d: ", i);
        scanf("%d", &coef);

        if (coef != 0) {
            newNode = (node*)malloc(sizeof(node));
            newNode->coef = coef;
            newNode->expo = i;
            newNode->next = NULL;

            if (start == NULL) {
                start = newNode;
                last = newNode;
            } else {
                last->next = newNode;
                last = newNode;
            }
        }
    }
    return(start);
}

//display the polynomial
void displayPolynomial(node* poly) {
    printf("Resulting Polynomial: ");
    while (poly != NULL) {
        printf("%dx^%d", poly->coef, poly->expo);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

//Adder
node* addPolynomials(node* poly1, node* poly2) {
    node* result = NULL;
    node* last = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        node* newNode = (node*)malloc(sizeof(node));

        if (poly1->expo > poly2->expo) {
            newNode->coef = poly1->coef;
            newNode->expo = poly1->expo;
            poly1 = poly1->next;
        } else if (poly1->expo < poly2->expo) {
            newNode->coef = poly2->coef;
            newNode->expo = poly2->expo;
            poly2 = poly2->next;
        } else {
            newNode->coef = poly1->coef + poly2->coef;
            newNode->expo = poly1->expo;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        newNode->next = NULL;

        if (result == NULL) {
            result = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    // If there are remaining terms in either polynomial
    while (poly1 != NULL) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->coef = poly1->coef;
        newNode->expo = poly1->expo;
        newNode->next = NULL;

        if (result == NULL) {
            result = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }

        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->coef = poly2->coef;
        newNode->expo = poly2->expo;
        newNode->next = NULL;

        if (result == NULL) {
            result = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }

        poly2 = poly2->next;
    }

    return result;
}