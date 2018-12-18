#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct node {
    int sub_cnt;
    struct node *sub_node[26];
};

struct node root;

#define CHAR_IDX(c) (c - 'a')

void add(struct node *root, char *name) {
    char *c = name;
    struct node *cur_node = root;
    
    if (c == NULL || *c == '\0') return;
    
    while (*c != '\0') {

        int idx = CHAR_IDX(*c);

        if (cur_node->sub_node[idx]) {
            cur_node->sub_node[idx]->sub_cnt++;
        } else {
            cur_node->sub_node[idx] = malloc(sizeof(struct node));
            cur_node->sub_node[idx]->sub_cnt = 1;
            memset(cur_node->sub_node[idx]->sub_node, 0x0, 26*sizeof(struct node*));
        }
        cur_node = cur_node->sub_node[idx];
        c++;
    }
}

int find(struct node *root, char *name) {
    char *c = name;
    struct node *cur_node = root;
    
    if (c == NULL || *c == '\0') return 0;
    
    while (*c != '\0') {
        int idx = CHAR_IDX(*c);
        if (cur_node->sub_node[idx] == NULL) {
            return 0;
        }
        cur_node = cur_node->sub_node[idx];
        c++;
    }
    return cur_node->sub_cnt;
}

int main(){
    int n; 
    scanf("%d",&n);
    for(int a0 = 0; a0 < n; a0++){
        char* op = (char *)malloc(512000 * sizeof(char));
        char* contact = (char *)malloc(512000 * sizeof(char));
        scanf("%s %s",op,contact);
        
        if (strcmp(op, "add") == 0) {
            add(&root, contact);
        } else if (strcmp(op, "find") == 0) {
            printf("%d\n", find(&root, contact));
        }
        
        free(op);
        free(contact);
    }
    return 0;
}