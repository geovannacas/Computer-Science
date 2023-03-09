#include <stdio.h>

#define MAX_TERMS 50

struct term {
    float coefficient;
    int exponent;
};

void read_polynomial(struct term polynomial[MAX_TERMS], int num_terms) {
    for (int i = 0; i < num_terms; i++) {
        scanf("%f %d", &polynomial[i].coefficient, &polynomial[i].exponent);
    }
}

void print_polynomial(struct term polynomial[MAX_TERMS], int num_terms) {
    int first_term = 1;
    for (int i = 0; i < num_terms; i++) {
        if (polynomial[i].coefficient == 0) {
            continue;
        }
        if (first_term) {
            first_term = 0;
        } else {
            if (polynomial[i].coefficient > 0) {
                printf(" + ");
            } else {
                printf(" - ");
            }
        }
        if (polynomial[i].exponent == 0) {
            printf("%.2f", polynomial[i].coefficient);
        } else if (polynomial[i].exponent == 1) {
            printf("%.2fX", polynomial[i].coefficient);
        } else {
            printf("%.2fX^%d", polynomial[i].coefficient, polynomial[i].exponent);
        }
    }
    printf("\n");
}

void add_polynomials(struct term polynomial1[MAX_TERMS], int num_terms1,
                     struct term polynomial2[MAX_TERMS], int num_terms2,
                     struct term result[MAX_TERMS], int *num_terms_result) {
    int i = 0, j = 0, k = 0;
    while (i < num_terms1 && j < num_terms2) {
        if (polynomial1[i].exponent > polynomial2[j].exponent) {
            result[k].coefficient = polynomial1[i].coefficient;
            result[k].exponent = polynomial1[i].exponent;
            i++;
        } else if (polynomial1[i].exponent < polynomial2[j].exponent) {
            result[k].coefficient = polynomial2[j].coefficient;
            result[k].exponent = polynomial2[j].exponent;
            j++;
        } else {
            result[k].coefficient = polynomial1[i].coefficient + polynomial2[j].coefficient;
            result[k].exponent = polynomial1[i].exponent;
            i++;
            j++;
        }
        k++;
    }
    while (i < num_terms1) {
        result[k].coefficient = polynomial1[i].coefficient;
        result[k].exponent = polynomial1[i].exponent;
        i++;
        k++;
    }
    while (j < num_terms2) {
        result[k].coefficient = polynomial2[j].coefficient;
        result[k].exponent = polynomial2[j].exponent;
        j++;
        k++;
    }
    *num_terms_result = k;
}

void subtract_polynomials(struct term polynomial1[MAX_TERMS], int num_terms1,
                          struct term polynomial2[MAX_TERMS], int num_terms2,
                          struct term result[MAX_TERMS], int *num_terms_result) {
    int i = 0, j = 0, k = 0;
    while (i < num_terms1 && j < num_terms2) {
        if (polynomial1[i].exponent > polynomial2[j].exponent) {
            result[k].coefficient = polynomial1[i].coefficient;
            result[k].exponent = polynomial;
