// Application of Linked List - Insertion of Elements
/*
Polynomial Representation- Polynomials can be represented using linked lists,
where each term in the polynomial is represented as a node in the list.
*/
#include <iostream>
using namespace std;

// Define a structure for a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
    Term* next;
};

// Function to create a new term node
Term* createTerm(int coeff, int exp) {
    Term* newTerm = new Term;
    newTerm->coefficient = coeff;
    newTerm->exponent = exp;
    newTerm->next = nullptr;
    return newTerm;
}

// Function to insert a term into the polynomial
void insertTerm(Term*& poly, int coeff, int exp) {
    Term* newTerm = createTerm(coeff, exp);

    if (poly == nullptr) {
        poly = newTerm;
    } else {
        Term* temp = poly;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
}

// Function to display the polynomial
void displayPolynomial(Term* poly) {
    while (poly != nullptr) {
        cout << poly->coefficient << "x^" << poly->exponent;
        if (poly->next != nullptr) {
            cout << " + ";
        }
        poly = poly->next;
    }
    cout << endl;
}

int main() {
    // Create an empty polynomial
    Term* poly = nullptr;

    // Insert terms into the polynomial
    insertTerm(poly, 3, 2);
    insertTerm(poly, -5, 1);
    insertTerm(poly, 2, 0);

    // Display the polynomial
    cout << "Polynomial: ";
    displayPolynomial(poly);

    return 0;
}
