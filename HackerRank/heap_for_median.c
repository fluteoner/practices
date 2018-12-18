#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct heap {
    int *hp;
    int capacity;
    int size;
};

void heap_init(struct heap *h, int cap) {
    h->hp = malloc(cap*sizeof(int));
    h->capacity = cap;
    h->size = 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int heap_get_parent_index(int child_index) { return (child_index - 1)/2; }
int heap_get_left_child_index(int parent_index) { return 2*parent_index+1; }
int heap_get_right_child_index(int parent_index) { return 2*parent_index+2; }

bool heap_has_parent(int index) { return (index > 0); }
bool heap_has_left_child(struct heap *h, int index) { return (heap_get_left_child_index(index) < h->size); }
bool heap_has_right_child(struct heap *h, int index) { return (heap_get_right_child_index(index) < h->size); }

int heap_get_size(struct heap *h) { return h->size; }

void heap_print(struct heap *h) {
    int i;
    printf("==== HEAP INFO ====\n");
    printf("CAPACITY = %d, SIZE = %d\n", h->capacity, h->size);
    printf("Elelment = {");
    for (i = 0; i < h->size; i++) {
        printf("%d ", h->hp[i]);
    }
    printf("}\n===================\n");
}

void heap_max_adjust_up(struct heap *h) {
    int index = h->size-1;
    while (heap_has_parent(index)) {
        if (h->hp[index] > h->hp[heap_get_parent_index(index)] ) {
            swap(&(h->hp[index]), &(h->hp[heap_get_parent_index(index)]));
            index = heap_get_parent_index(index);
        } else {
            break;
        }
        
    }
}
                 
void heap_min_adjust_up(struct heap *h) {
    int index = h->size-1;
    while (heap_has_parent(index)) {
        if (h->hp[index] < h->hp[heap_get_parent_index(index)] ) {
            swap(&(h->hp[index]), &(h->hp[heap_get_parent_index(index)]));
            index = heap_get_parent_index(index);
        } else {
            break;
        }
    }
}

void heap_max_adjust_down(struct heap *h) {
    int index = 0, child_index;
    while (heap_has_left_child(h, index)) {
        
        child_index = heap_get_left_child_index(index);
        if (heap_has_right_child(h, index)) {
            child_index = 
                (h->hp[child_index] > h->hp[heap_get_right_child_index(index)]) ?
                child_index :
                heap_get_right_child_index(index);
        }
        if (h->hp[index] < h->hp[child_index]) {
            swap(&(h->hp[index]) , &(h->hp[child_index]));
            index = child_index;
        } else {
            break;
        }
    }
}

void heap_min_adjust_down(struct heap *h) {
    int index = 0, child_index;
    while (heap_has_left_child(h, index)) {
        child_index = heap_get_left_child_index(index);
        if (heap_has_right_child(h, index)) {
            child_index = 
                (h->hp[child_index] < h->hp[heap_get_right_child_index(index)]) ?
                child_index :
                heap_get_right_child_index(index);
        }
        if (h->hp[index] > h->hp[child_index]) {
            swap(&(h->hp[index]) , &(h->hp[child_index]));
            index = child_index;
        } else {
            break;
        }
    }
}

void heap_max_add(struct heap *h, int value) {
    if (h->size >= h->capacity) return;
    h->hp[h->size++] = value;
    heap_max_adjust_up(h);
}

void heap_min_add(struct heap *h, int value) {
    if (h->size >= h->capacity) return;
    h->hp[h->size++] = value;
    heap_min_adjust_up(h);
}

int heap_max_del(struct heap *h) {
    int val = h->hp[0];
    
    if (h->size <= 0) return -1;
    
    h->hp[0] = h->hp[--(h->size)];
    heap_max_adjust_down(h);
    return val;
}

int heap_min_del(struct heap *h) {
    int val = h->hp[0];
    
    if (h->size <= 0) return -1;
    
    h->hp[0] = h->hp[--(h->size)];
    heap_min_adjust_down(h);
    return val;
}

struct median_heap {
    struct heap *max_heap;
    struct heap *min_heap;
    int size;
};

void median_heap_init(struct median_heap *mh, int capacity) {
    mh->max_heap = malloc(sizeof(struct heap));
    mh->min_heap = malloc(sizeof(struct heap));
    heap_init(mh->max_heap, capacity);
    heap_init(mh->min_heap, capacity);
    mh->size = 0;
}

double median_heap_get_median(struct median_heap *mh) {
    //printf("## %d(%d), %d(%d)\n", mh->max_heap->hp[0], heap_get_size(mh->max_heap), mh->min_heap->hp[0], heap_get_size(mh->min_heap));
    if (mh->max_heap->size < mh->min_heap->size) {
        return mh->min_heap->hp[0];
    } else if (mh->max_heap->size > mh->min_heap->size) {
        return mh->max_heap->hp[0];
    } else {
        return (mh->max_heap->hp[0] + mh->min_heap->hp[0])/2.0;
    }
}

void median_heap_add(struct median_heap *mh, int value) {
    int temp;
    
    if (mh->size == 0) {
        heap_max_add(mh->max_heap, value);
        mh->size++;
        return;
    }
    
    if (value < median_heap_get_median(mh)) {
        heap_max_add(mh->max_heap, value);
    } else {
        heap_min_add(mh->min_heap, value);
    }
    
    mh->size++;
    
    if (mh->max_heap->size > mh->min_heap->size + 1) {
        temp = heap_max_del(mh->max_heap);
        heap_min_add(mh->min_heap, temp);
    } else if (mh->min_heap->size > mh->max_heap->size + 1) {
        temp = heap_min_del(mh->min_heap);
        heap_max_add(mh->max_heap, temp);
    }
}



int main() {
    int n;
    struct median_heap mh;
    scanf("%d",&n);
    median_heap_init(&mh, n);
    
    int *a = malloc(sizeof(int) * n);

    for(int a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
       median_heap_add(&mh, a[a_i]);
       printf("%0.1f\n", median_heap_get_median(&mh));
    }

    return 0;
}
