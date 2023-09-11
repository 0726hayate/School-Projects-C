#include <stdio.h>
#include <math.h>

struct user{

    float num1, num2, uNum, tempnum1, tempnum2;
    char operator, uOperator, var1, var2, bue, varnum1, varnum2, check;
    float store[100];
    int a, b, c, d, e;
    char buave;

};

//function prototype
char choose ();
float binary (struct user b1);
float unary(struct user b1);
struct user optionV(int i, struct user b1);
void end ();

//main function
int main(void)
{

    struct user b1; 
    float result;

    b1.a = 0, b1.b = 0, b1.c = 0, b1.d = 0, b1.e = 0;

//Welcome Message
    puts("Welcome to my Command-Line Calculator (CLC)");
    puts("Developer: Chun Yiu Jason Yau");
    puts("Version 3");
    puts("Date: November 30th, 2022");
    puts("-------------------------------------------\n");


    
// function for B,U,A,V,E options, loops until user chooses E
    do{

        //stores what user chooses (B,U,A,V,E)
        b1.buave = choose();
        
       //check user input to each case
       switch(b1.buave){

            //case for B, binary operations
            case'B':        
            //for binary operations
            result = binary(b1);
            printf("The result is: %f\n", result );

            //ask user to select options again
            break;

            //case for U
            case 'U': 
            //function for unary operations
            result = unary(b1);
            printf("The result is: %f\n", result );
            
            //ask user to choose options again and goes back to begining of loop
            break;

            //case for A
            case 'A':
            
            //advance mode
            do{

                puts("Please select you option ( B, U, E) ");
                scanf("\n%c", &b1.bue);
                while(getchar() != '\n');
                
                switch(b1.bue){

                    case 'B':

                    result = binary(b1);
                    printf("The result is: %f\n", result );

                    break;

                    case 'U':

                    result = unary(b1);
                    printf("The result is: %f\n", result );
                   
                    break;

                    case 'E':
                    puts("returning to main menu");
                    break;

                    default:
                    puts("Please choose an option from the list, option must be in CAPITALS ");
                    break;

                }
            }while(b1.bue != 'E');            

            //ask user to choose options again and goes back to begining of loop
            break;

            //case for V
            case 'V': 
                
                //loops until user chooses a valid variable name
                do{
            
                     //ask user to choose a variable name
                     puts("Please enter a variable name between a and e");
                    //stores operator
                    b1.check = scanf(" %c", &b1.var1);
                    while(getchar() != '\n');
                    
                    if(b1.check == 1 &&b1.var1 != 'a' && b1.var1 != 'b' && b1.var1 != 'c'&& b1.var1 != 'd'&& b1.var1 != 'e' ){
                        puts("invalid input, please make sure the letters are not in capitals");
                    }

                }while( b1.check == 1 &&b1.var1 != 'a' && b1.var1 != 'b' && b1.var1 != 'c'&& b1.var1 != 'd'&& b1.var1 != 'e');
                    
                puts ("Please enter the number: ");
                     
                //stores number in array
                     switch(b1.var1){

                        case 'a':
                        b1 = optionV(1, b1);
                        b1.a = b1.store[1];

                        break;

                        case'b':
                        b1 = optionV(2, b1);
                        b1.b = b1.store[2];

                        break;

                        case'c':
                        b1 = optionV(3, b1);
                        b1.c = b1.store[3];

                        break;

                        case'd':
                        b1 = optionV(4, b1);
                        b1.d = b1.store[4];

                        break;

                        case'e':
                        b1 = optionV(5, b1);
                        b1.e = b1.store[5];

                        break;

                     }                     
            
            //ask user to choose options again and goes back to begining of loop
            break;         

            //case for E, Thank user for using calculator
            case 'E':
            end(b1);
            
            break;

            default:
            //ask user to choose again if invalid input
            puts("Please choose an option from the list, option must be in CAPITALS ");
            //ask user to choose options again and goes back to begining of loop            
            break;
        
        }


      } while (b1.buave != 'E');
    

return 0;

}

char choose (){

    puts("Select one of the following items:");
    puts("B) - Binary Mathematical Operations, such as addition and subtraction.");
    puts("U) - Unary Mathematical Operations, such as square root, and log.");
    puts("A) - Advances Mathematical Operations, using variables, arrays.");
    puts("V) - Define variables and assign them values.");
    puts("E) - Exit");

    char option;

    scanf("\n%c", &option);
    while(getchar() != '\n');

    return option;

}


//function for binary operations
float binary (struct user b1) {

//user chooses A then B
if(b1.bue == 'B'){

    //ask user if they want to enter a variable or a number
    do{
    puts("Would you like to enter a variable (V) or a number (N)? ");
    b1.check = scanf("%c", &b1.varnum1);
    while(getchar() != '\n');

    if(b1.check == 1 && b1.varnum1 != 'V' && b1.varnum1 != 'N'){
        puts("invalid input, please make sure the letter is in capitals");

    }

    }while(b1.check == 1 && b1.varnum1 != 'V' && b1.varnum1 != 'N');
}

//user chooses to enter a variable
if(b1.bue == 'B' && b1.varnum1 == 'V'){
    
    do{

        puts("Please enter a variable between a and e: ");
        b1.check = scanf(" %c", &b1.var1);
        while(getchar() != '\n');

        if(b1.check == 1 &&b1.var1 != 'a' && b1.var1 != 'b' && b1.var1 != 'c'&& b1.var1 != 'd'&& b1.var1 != 'e' ){
        puts("invalid input");
        }

    }while( b1.check == 1 &&b1.var1 != 'a' && b1.var1 != 'b' && b1.var1 != 'c'&& b1.var1 != 'd'&& b1.var1 != 'e');
    
    switch (b1.var1){

        case 'a':
        b1.tempnum1 = b1.a;
        break;

        case 'b':
        b1.tempnum1 = b1.b;
        break;

        case 'c':
        b1.tempnum1 = b1.c;
        break;

        case 'd':
        b1.tempnum1 = b1.d;
        break;

        case 'e':
        b1.tempnum1 = b1.e;
        break;

    }
    
}

if(b1.varnum1 != 'V'){
//check user input for float
    do{
        //ask user to enter first number
        puts ("Please enter the first number: ");
        b1.check = scanf("\n%f", &b1.num1);
        while(getchar() != '\n');

    if(b1.check == 0){
        puts("invalid input");
                }

    }while(b1.check == 0);
}

//let user choose operator again if input is invalid an stores the valid input
    do{
            
        //ask user to choose operation
        printf("Please enter the operation ( + , - , * , /, %%, P (power), X (maximum), I(minimum): \n");
        //stores operator
        b1.check = scanf(" %c", &b1.operator);
        while(getchar() != '\n');

        if(b1.check == 1 &&b1.operator != '+' && b1.operator != '-' && b1.operator != '*'&& b1.operator != '/'&& b1.operator != '%'&& b1.operator != 'P'&& b1.operator != 'X'&& b1.operator != 'I'){
            puts("invalid input");
            }

            }while( b1.check == 1 &&b1.operator != '+' && b1.operator != '-' && b1.operator != '*'&& b1.operator != '/'&& b1.operator != '%'&& b1.operator != 'P'&& b1.operator != 'X'&& b1.operator != 'I');

if(b1.bue == 'B'){

    //ask user if they want to enter a variable or a number
    do{
    puts("Would you like to enter a variable (V) or a number (N)? ");
    b1.check = scanf("%c", &b1.varnum2);
    while(getchar() != '\n');

    if(b1.check == 1 && b1.varnum2 != 'V' && b1.varnum2 != 'N'){
        puts("invalid input");

    }

    }while(b1.check == 1 && b1.varnum2 != 'V' && b1.varnum2 != 'N');
}

//user chooses to enter a variable
if(b1.bue == 'B' && b1.varnum2 == 'V'){
    
    do{

        puts("Please enter a variable between a and e: ");
        b1.check = scanf(" %c", &b1.var1);
        while(getchar() != '\n');

        if(b1.check == 1 &&b1.var1 != 'a' && b1.var1 != 'b' && b1.var1 != 'c'&& b1.var1 != 'd'&& b1.var1 != 'e' && b1.var1 != 'f' ){
        puts("invalid input");
        }

    //assign user variable to a temporary number
    switch (b1.var1){

        case 'a':
        if( (b1.a == 0) && ((b1.operator == '/') || (b1.operator =='%')) ){
            puts("cannot divide by 0");
            puts("all variables have a default value of 0, if you have not set any values please enter 'f' to get out of the loop");
            b1.tempnum2 = b1.a;
        }
        else {
            b1.tempnum2 = b1.a;}
        break;

        case 'b':
        if( (b1.b == 0) && ((b1.operator == '/') || (b1.operator =='%')) ){
            puts("cannot divide by 0");
            puts("all variables have a default value of 0, if you have not set any values please enter 'f' to get out of the loop");
            b1.tempnum2 = b1.b;
        }
        else {
            b1.tempnum2 = b1.b;}
        break;

        case 'c':
        if( (b1.c == 0) && ((b1.operator == '/') || (b1.operator =='%')) ){
            puts("cannot divide by 0");
            puts("all variables have a default value of 0, if you have not set any values please enter 'f' to get out of the loop");
            b1.tempnum2 = b1.c;
        }
        else {
            b1.tempnum2 = b1.c;}
        break;

        case 'd':
        if( (b1.d == 0) && ((b1.operator == '/') || (b1.operator =='%')) ){
            puts("cannot divide by 0");
            puts("all variables have a default value of 0, if you have not set any values please enter 'f' to get out of the loop");
            b1.tempnum2 = b1.d;
        }
        else {
            b1.tempnum2 = b1.d;}
        break;

        case 'e':
        if( (b1.e == 0) && ((b1.operator == '/') || (b1.operator =='%')) ){
            puts("cannot divide by 0");
            puts("all variables have a default value of 0, if you have not set any values please enter 'f' to get out of the loop");
            b1.tempnum2 = b1.e;
        }
        else {
            b1.tempnum2 = b1.e;}
        break;

        //if user is stuck in a loop
        case 'f':
        b1.tempnum2 = 1;
        break;

    }



    }while( b1.check == 1 &&b1.var1 != 'a' && b1.var1 != 'b' && b1.var1 != 'c'&& b1.var1 != 'd'&& b1.var1 != 'e' && b1.var1 != 'f' || ((b1.tempnum2 == 0) && ((b1.operator == '/') || (b1.operator =='%'))) );
    

    
}


if (b1.varnum2 != 'V'){
    do{

        //ask user for power raised if P is chosen    
        if(b1.operator == 'P'){
        puts("Please enter power raised: ");
        }
        //ask user to enter second number and checks input
        else {
            puts ("Please enter the second number: ");
            }
            
        b1.check = scanf(" \n%f", &b1.num2);
        while(getchar() != '\n');

        //divide by zero error message
        if( (b1.num2 == 0) && ((b1.operator == '/') || (b1.operator =='%')) || (b1.check == 0) ){
            puts("invalid input");
            }
 

        }while(((b1.num2 == 0) && ((b1.operator == '/') || (b1.operator =='%'))) || b1.check == 0 );
}

    //match case with user input and print result
    switch( b1.operator) { 

    //case for +, add 1st and second number and print result
    case'+':

    //1st is var, 2nd is num
    if(b1.bue == 'B' && b1.varnum1 == 'V' && b1.varnum2 != 'V'){  
        return (b1.tempnum1+b1.num2);
    }

    //1st is num, 2nd is var
    else if(b1.bue == 'B' && b1.varnum2 == 'V'&& b1.varnum1 != 'V'){
        return (b1.num1+b1.tempnum2);
    }

      //1st is var, 2nd is var  
    else if(b1.bue == 'B' && b1.varnum1 == 'V' && b1.varnum2 == 'V'){
        return (b1.tempnum1+b1.tempnum2);
    }

    // 1st is num, 2nd is num
    else {
        return (b1.num1+b1.num2);
    }
    break;

   //case for -, subtract 1st and 2nd number and print result
   case '-':

    //1st is var, 2nd is num
   if(b1.bue == 'B' && b1.varnum1 == 'V' && b1.varnum2 != 'V'){  
        return b1.tempnum1-b1.num2;
    }

    //1st is num, 2nd is var
    else if(b1.bue == 'B' && b1.varnum2 == 'V'&& b1.varnum1 != 'V'){
        return b1.num1-b1.tempnum2;
    }

     //1st is var, 2nd is var   
    else if(b1.bue == 'B' && b1.varnum1 == 'V' && b1.varnum2 == 'V'){
        return b1.tempnum1-b1.tempnum2;
    }

    // 1st is num, 2nd is num
    else {
        return b1.num1-b1.num2;
    }
   break;
    
    //case for *, mutiply first and 2nd number and print result
    case '*':
    
    //1st is var, 2nd is num    
    if(b1.bue == 'B' && b1.varnum1 == 'V' && b1.varnum2 != 'V'){  
        return b1.tempnum1*b1.num2;
    }

    //1st is num, 2nd is var
    else if(b1.bue == 'B' && b1.varnum2 == 'V'&& b1.varnum1 != 'V'){
        return b1.num1*b1.tempnum2;
    }

    //1st is var, 2nd is var
    else if(b1.bue == 'B' && b1.varnum1 == 'V' && b1.varnum2 == 'V'){
        return b1.tempnum1*b1.tempnum2;
    }

    // 1st is num, 2nd is num
    else {
        return b1.num1*b1.num2;
    }
    break;

    //case for /, divide first number by second number and print result
    case '/':

    //1st is var, 2nd is num
    if(b1.bue == 'B' && b1.varnum1 == 'V' && b1.varnum2 != 'V'){  
        return b1.tempnum1/b1.num2;
    }

    //1st is num, 2nd is var
    else if(b1.bue == 'B' && b1.varnum2 == 'V'&& b1.varnum1 != 'V'){
        return b1.num1/b1.tempnum2;
    }

    //1st is var, 2nd is var  
    else if(b1.bue == 'B' && b1.varnum1 == 'V' && b1.varnum2 == 'V'){
        return b1.tempnum1/b1.tempnum2;
    }

    // 1st is num, 2nd is num
    else {
        return b1.num1/b1.num2;
    }
    break;

    //case for % modulate first number by second number and print result
    case '%':

    //1st is var, 2nd is num
    if(b1.bue == 'B' && b1.varnum1 == 'V' && b1.varnum2 != 'V'){  
        return fmod(b1.tempnum1, b1.num2);
    }

    //1st is num, 2nd is var
    else if(b1.bue == 'B' && b1.varnum2 == 'V'&& b1.varnum1 != 'V'){
        return fmod(b1.num1, b1.tempnum2);
    }
    
    //1st is var, 2nd is var
    else if(b1.bue == 'B' && b1.varnum1 == 'V' && b1.varnum2 == 'V'){
        return fmod(b1.tempnum1, b1.tempnum2);
    }
    
    //1st is num, 2nd is num
    else {
        return fmod(b1.num1, b1.num2);
    }
    break;
    
    case 'P':
    
    // 1st is var, 2nd is num
    if(b1.bue == 'B' && b1.varnum1 == 'V' && b1.varnum2 != 'V'){  
        return pow(b1.tempnum1, b1.num2);
    }

    //1st is num, 2nd is var
    else if(b1.bue == 'B' && b1.varnum2 == 'V'&& b1.varnum1 != 'V'){
        return pow(b1.num1, b1.tempnum2);
    }
    
    //1st is var, 2nd is var
    else if(b1.bue == 'B' && b1.varnum1 == 'V' && b1.varnum2 == 'V'){
        return pow(b1.tempnum1, b1.tempnum2);
    }

    //1st is num, 2nd is num
    else {
        return pow(b1.num1, b1.num2);
    }
    break;

    //case for X compare first number with second number and print result
    case 'X':

    //1st is var, 2nd is num
    if(b1.bue == 'B' && b1.varnum1 == 'V' && b1.varnum2 != 'V'){  

        if(b1.tempnum1 > b1.num2){
        printf("the maximum is: %f\n", b1.tempnum1);

        }
        else if(b1.tempnum1 < b1.num2){
            printf("the maximum is: %f\n", b1.num2);
        }
        else{
            puts("the numbers are equal");
        }
    }

    //1st is num, 2nd is var
    else if(b1.bue == 'B' && b1.varnum2 == 'V'&& b1.varnum1 != 'V'){
        if(b1.tempnum2 > b1.num1){
        printf("the maximum is: %f\n", b1.tempnum2);

        }
        else if(b1.tempnum2 < b1.num1){
            printf("the maximum is: %f\n", b1.num1);
        }
        else{
            puts("the numbers are equal");
        }
    }
    
    //1st is var, 2nd is var
    else if(b1.bue == 'B' && b1.varnum1 == 'V' && b1.varnum2 == 'V'){
        if(b1.tempnum2 > b1.tempnum1){
        printf("the maximum is: %f\n", b1.tempnum2);

        }
        else if(b1.tempnum2 < b1.tempnum1){
            printf("the maximum is: %f\n", b1.tempnum1);
        }
        else{
            puts("the numbers are equal");
        }
    }

    // 1st is num, 2nd is num
    else{
        if(b1.num1 > b1.num2){
            printf("the maximum is: %f\n", b1.num1);
        }
        else if(b1.num1 < b1.num2){
            printf("the maximum is: %f\n", b1.num2);
        }
        else{
            puts("the numbers are equal");
        }

    }
    break;

    case 'I':
     //1st is var, 2nd is num
    if(b1.bue == 'B' && b1.varnum1 == 'V' && b1.varnum2 != 'V'){  

        if(b1.tempnum1 < b1.num2){
        printf("the minimum is: %f\n", b1.tempnum1);

        }
        else if(b1.tempnum1 > b1.num2){
            printf("the minimum is: %f\n", b1.num2);
        }
        else{
            puts("the numbers are equal");
        }
    }

    //1st is num, 2nd is var
    else if(b1.bue == 'B' && b1.varnum2 == 'V'&& b1.varnum1 != 'V'){
        if(b1.tempnum2 < b1.num1){
        printf("the minimum is: %f\n", b1.tempnum2);

        }
        else if(b1.tempnum2 > b1.num1){
            printf("the minimum is: %f\n", b1.num1);
        }
        else{
            puts("the numbers are equal");
        }
    }
    
    //1st is var, 2nd is var
    else if(b1.bue == 'B' && b1.varnum1 == 'V' && b1.varnum2 == 'V'){
        if(b1.tempnum2 < b1.tempnum1){
        printf("the minimum is: %f\n", b1.tempnum2);

        }
        else if(b1.tempnum2 > b1.tempnum1){
            printf("the minimum is: %f\n", b1.tempnum1);
        }
        else{
            puts("the numbers are equal");
        }
    }

    // 1st is num, 2nd is num
    else{
        if(b1.num1 < b1.num2){
            printf("the minimum is: %f\n", b1.num1);
        }
        else if(b1.num1 > b1.num2){
            printf("the minimum is: %f\n", b1.num2);
        }
        else{
            puts("the numbers are equal");
        }

    }
    break;

    }

}

//function for unary operations
float unary (struct user b1){

    //ask user to choose an unary operation
    do{
        puts("Please select an operation (S for squareroot, L for Logrithm, E for exponentiation, C for the smallest integer value greater than or equal to x, F for the largest integer value greater than or equal to x ): ");
        //stores operator
        b1.check = scanf(" %c", &b1.uOperator);
        while(getchar() != '\n');

        if(b1.check == 1 &&b1.uOperator != 'S' && b1.uOperator != 'L' && b1.uOperator != 'E'&& b1.uOperator != 'C'&& b1.uOperator != 'F'){
        puts("invalid input");
        }

        }while(b1.check == 1 &&b1.uOperator != 'S' && b1.uOperator != 'L' && b1.uOperator != 'E'&& b1.uOperator != 'C'&& b1.uOperator != 'F');

//user chooses A then U
if(b1.bue == 'U'){

    //ask user if they want to enter a variable or a number
    do{
    puts("Would you like to enter a variable (V) or a number (N)? ");
    b1.check = scanf("%c", &b1.varnum1);
    while(getchar() != '\n');

    if(b1.check == 1 && b1.varnum1 != 'V' && b1.varnum1 != 'N'){
        puts("invalid input");

    }

    }while(b1.check == 1 && b1.varnum1 != 'V' && b1.varnum1 != 'N');
}

//user chooses to enter a variable and to check for invalid inputs
if(b1.bue == 'U' && b1.varnum1 == 'V'){
    
    do{

        puts("Please enter a variable between a and e: ");
        b1.check = scanf(" %c", &b1.var1);
        while(getchar() != '\n');

        if(b1.check == 1 &&b1.var1 != 'a' && b1.var1 != 'b' && b1.var1 != 'c'&& b1.var1 != 'd'&& b1.var1 != 'e'&& b1.var1 != 'f' ){
        puts("invalid input, please make sure the letters are not in capitals");
        }

        //assigns user variable to a temporary number
        switch (b1.var1){

        case 'a':
        if( ((b1.a <= 0) &&(b1.uOperator =='L') || (b1.a < 0) && (b1.uOperator == 'S')) ){
            puts("invalid input");
            puts("Please enter 'f' to get out of the loop if you are stuck");
            b1.tempnum1 = b1.a;
        }
        else {
            b1.tempnum1 = b1.a;}
        break;

        case 'b':
        if( ((b1.b <= 0) &&(b1.uOperator =='L') || (b1.b < 0) && (b1.uOperator == 'S')) ){
            puts("invalid input");
            puts("Please enter 'f' to get out of the loop if you are stuck");
            b1.tempnum1 = b1.b;
        }
        else {
            b1.tempnum1 = b1.b;}
        break;

        case 'c':
        if( ((b1.c <= 0) &&(b1.uOperator =='L') || (b1.c < 0) && (b1.uOperator == 'S')) ){
            puts("invalid input");
            puts("Please enter 'f' to get out of the loop if you are stuck");
            b1.tempnum1 = b1.c;
        }
        else {
            b1.tempnum1 = b1.c;}
        break;

        case 'd':
        if( ((b1.d <= 0) &&(b1.uOperator =='L') || (b1.d < 0) && (b1.uOperator == 'S')) ){
            puts("invalid input");
            puts("Please enter 'f' to get out of the loop if you are stuck");
            b1.tempnum1 = b1.d;
        }
        else {
            b1.tempnum1 = b1.d;}
        break;

        case 'e':
        if( ((b1.e <= 0) &&(b1.uOperator =='L') || (b1.e < 0) && (b1.uOperator == 'S')) ){
           puts("invalid input");
            puts("Please enter 'f' to get out of the loop if you are stuck");
            b1.tempnum1 = b1.e;
        }
        else {
            b1.tempnum1 = b1.e;}
        break;

        //if user gets stuck in a loop
        case 'f':
        b1.tempnum1 = 1;

    }
    

    }while( b1.check == 1 &&b1.var1 != 'a' && b1.var1 != 'b' && b1.var1 != 'c'&& b1.var1 != 'd'&& b1.var1 != 'e' && b1.var1 != 'f' || ((b1.tempnum1 <= 0) &&(b1.uOperator =='L') || (b1.tempnum1 < 0) && (b1.uOperator == 'S')) );
    
}


if(b1.varnum1 != 'V'){
    do{
        //ask user to enter first number
        puts ("Please enter a number: ");
        b1.check = scanf("\n%f", &b1.uNum);
        while(getchar() != '\n');
                
        //invalid input if negative number for Log and squareroot
        if((b1.check == 0) || ((b1.uNum <= 0) &&(b1.uOperator =='L') || (b1.uNum < 0) && (b1.uOperator == 'S'))){
        puts("invalid input");
        }

        }while((b1.check == 0) || ((b1.uNum <= 0) &&(b1.uOperator =='L') || (b1.uNum < 0) && (b1.uOperator == 'S')));
}


switch(b1.uOperator) {
    case'S':
        
        //1st is var
    if(b1.bue == 'U' && b1.varnum1 == 'V'){  
        
        return sqrt(b1.tempnum1);
    }

    else {
       return sqrt(b1.uNum);
    }

    break;

    case 'L':

    if(b1.bue == 'U' && b1.varnum1 == 'V'){  
        return log(b1.tempnum1);
    }

    else {
        return log(b1.uNum);
    }
        
    break;

    case 'E':

    if(b1.bue == 'U' && b1.varnum1 == 'V'){  
        return exp(b1.tempnum1);
    }

    else {
        return exp(b1.uNum);
    }
    break;

    case 'C':

    if(b1.bue == 'U' && b1.varnum1 == 'V'){  
        return ceil(b1.tempnum1);
    }

    else {
        return ceil(b1.uNum);
    }

    break;

    case 'F':

    if(b1.bue == 'U' && b1.varnum1 == 'V'){  
        return floor(b1.tempnum1);
    }

    else {
        return floor(b1.uNum);
    }

    break;



    }

}

//function for variable numbmer storage
struct user optionV(int i, struct user b1){  

    do{
        b1.check = scanf("\n%f", &b1.store[i]);
        while(getchar() != '\n');

        if(b1.check == 0){
        puts("invalid input");
        }

        }while(b1.check == 0);

        return b1;

}

void end(){

puts("Thanks for using my Simple Calculator. Hope to see you again soon. Goodbye!");

}
