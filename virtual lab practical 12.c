#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
// Stack structure for bracket tracking [cite: 117] 
typedef struct Stack { 
int top; 
unsigned capacity; 
char* array; 
} Stack; 
// Function to create a stack [cite: 123] 
Stack* createStack(unsigned capacity) { 
Stack* stack = (Stack*)malloc(sizeof(Stack)); 
stack->capacity = capacity; 
stack->top = -1; 
stack->array = (char*)malloc(stack->capacity * sizeof(char)); 
return stack; 
} 
// Function to check if brackets match [cite: 148] 
int isMatchingPair(char opening, char closing) { 
return (opening == '(' && closing == ')') || 
(opening == '{' && closing == '}') || 
(opening == '[' && closing == ']'); 
} 
// Function to check if the expression is balanced [cite: 154] 
int isBalanced(char* expr) { 
int n = strlen(expr); 
Stack* stack = createStack(n); 
for (int i = 0; i < n; i++) { 
char ch = expr[i]; 
// Opening brackets ko stack mein push karo [cite: 160, 161] 
if (ch == '(' || ch == '{' || ch == '[') { 
stack->array[++stack->top] = ch; 
}  
// Closing brackets ke liye top se match karo [cite: 164] 
else if (ch == ')' || ch == '}' || ch == ']') { 
if (stack->top == -1 || !isMatchingPair(stack->array[stack->top--], ch)) { 
free(stack->array); 
free(stack); 
return 0; // Unbalanced [cite: 168, 174] 
} 
} 
} 
int result = (stack->top == -1); // Agar stack khali hai toh balanced hai [cite: 178] 
free(stack->array); 
free(stack); 
return result; 
} 
int main() { 
char expr[1001]; // String size constraint handle karne ke liye [cite: 185] 
// --- Riddhi's Details --- 
printf("Name: Riddhi Thorat\n"); 
printf("PRN: 25070521246\n"); 
printf("Section: E(E1)\n"); 
printf("---------------------------\n"); 
printf("Enter the expression: "); 
scanf("%s", expr); // User se input lene ke liye [cite: 188] 
if (isBalanced(expr)) { 
printf("true\n"); // [cite: 190] 
} else { 
printf("false\n"); // [cite: 192] 
} 
return 0; 
}