#include <stdio.h>
#include <stdlib.h> //for atof()
#include <ctype.h> //for isdigit()
#include <math.h> //for sin(), exp(), pow()

#define MAXOP 100 /*max size of operand or operator*/
#define NUMBER '0' /*signals that a number has been found*/
#define NAME 'n'  /*signals a name of a possible math function has been found*/

#define MAXVAL 100 /*for push()*/

#define BUFSIZE 100 /*for ungetch()*/

int getop(char []);
void push(double);
double pop(void);
void mathFunc(char in[]);

/*global variables for push and pop: */
int sp = 0; /*next free stack position*/
double val[MAXVAL]; /*value stack*/

/*function protorypes for use in getop: */
int getch(void);
void ungetch(int);

/*global variables for getch() and ungetch(): */
char buf[BUFSIZE]; /*buffer for ungetch*/
int bufp = 0;       /*next free position in buf*/

/*This is a reverse Polish calculator. */
int main(void){

    int type;
    int option = 0; //0 indicates no extra command given, just do the math
    double op2;
    double temp1, temp2;
    char s[MAXOP]; //'empty' array that is re-used and re-initialized with new values for evaluation

    while ((type = getop(s)) != EOF){

        switch (type){
        case NUMBER:
            push(atof(s)); //converts string to float
            break;
        case NAME:
            mathFunc(s);
            break;

        case '+':
            push(pop() + pop()); //most recent (top) item on stack + 2nd most recent item on stack
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop(); //most recent (top) item on stack
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: cannot divide by zero!\n");
            break;

        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push((int)pop() % (int)op2);
            else
                printf("error: cannot divide by zero!\n");
            break;

        case 'T': //top of stack?

            temp1 = pop(); //temporarily pop the top of the stack
            printf("\nTop of stack: %f\n", temp1);
            push(temp1); //push value back to top of stack

            break;

        case 'd': //duplicate top of stack;
            temp1 = pop();
            push(temp1);
            push(temp1);

            break;

        case 'c': //clear the stack;
            sp = 0;

            break;

        case 's': //swap top 2 elements of stack
            temp1 = pop();
            temp2 = pop();
            push(temp1);
            push(temp2);
            break;

        case '\n':

            printf("Result: \t%.8g\n", pop());


            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }

    }

return 0;
}


/*push: push f onto value stack */
void push(double f){

    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);

}

/*pop: pop and return the value on the top of stack*/
double pop(void){
    if (sp > 0)
        return val[--sp];
    else{
        printf("error: stack empty. Default 0 value used as next operand\n");
        return 0.0;
    }

}


/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t') //skip blanks and tabs
        ;
    s[1] = '\0'; //???? unsure why this is needed if s[i] = '\0' already exists at end?


    i = 0;

    if(islower(c)){
        while(islower(s[++i] = c = getch())) //checks to see if a string of characters is found
            ;
        s[i] = '\0';

        if(c != EOF)
            ungetch(c); //read one char too far, must step back one
        if(strlen(s) > 1)
            return NAME;
        else
            return c;   //it is just a regular command

    }


    if(!isdigit(c) && c != '.' && c != '-')
        return c;               /*returns non-number (can be operators or something else)*/


    if(c == '-'){
        if(isdigit(c = getch()) || c == '.') //looks ahead of '-' for a digit or a space. if a digit, a negative number has been found
            s[++i] = c; //negative digit after '-' found
        else{
            if (c != EOF) //if non-digit character found after '-', save the character in "un-read" buffer
                ungetch(c);
            return '-';
        }
    }


    if(isdigit(c)) /*collect integer part */
        while(isdigit(s[++i] = c = getch()));

    if(c == '.')    /*collect fraction part*/
        while(isdigit(s[++i] = c = getch()));

    s[i] = '\0';
    if(c != EOF)
        ungetch(c); /*ungetch run when c is no longer a digit (like a blank space)*/

    return NUMBER;

}

void mathFunc(char in[]){

    if (strcmp(in, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(in, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(in, "pow") == 0)
        push(pow(pop(), pop()));
    else if (strcmp(in, "exp") == 0)
        push(exp(pop()));
    else
        printf("error: %s is not a supported command\n", in);


}







int getch(void) /*get a character. if there is something in the buffer (bufp > 0) that needs to be evaluated, return that first for evaluation */
{

    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /*push character back on input*/
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters!\n");
    else
        buf[bufp++] = c; //stores non-digit characters for future evaluation

}


