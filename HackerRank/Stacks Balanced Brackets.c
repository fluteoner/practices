#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char stack[500];
int top_index = -1;

void push(char stack[], char value) {
    if (top_index >= 499) {
        return;
    }
    stack[++top_index] = value;
}

char pop(char stack[]) {
    if (top_index <= -1) return '-';
    return stack[top_index--];
}

bool is_balanced(char expression[]) {
    int i, len = strlen(expression);
    char pop_value;
    for (i = 0; i < len; i++) {
        switch (expression[i]) {
            case '(':
            case '[':
            case '{':
                push(stack, expression[i]);
                break;
            
            case ')':
                pop_value = pop(stack);
                if (pop_value != '(') return false;
                break;
            case ']':
                pop_value = pop(stack);
                if (pop_value != '[') return false;
                break;
            case '}':
                pop_value = pop(stack);
                if (pop_value != '{') return false;
                break;
            default:
                return false;
        }
    }
    if (top_index == -1) return true;
    else return false;
}

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        char* expression = (char *)malloc(512000 * sizeof(char));
        scanf("%s",expression);
         bool answer = is_balanced(expression);
         if(answer)
          printf("YES\n");
         else
          printf("NO\n");
        top_index = -1;
    }
    return 0;
}