#include <stdbool.h>
#include <string.h>

typedef struct {
    bool arr[1000001];
} MyHashSet;


MyHashSet* myHashSetCreate() {
    MyHashSet* obj = (MyHashSet*)malloc(sizeof(MyHashSet));
    memset(obj->arr, false, sizeof(obj->arr));
    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    obj->arr[key] = true;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    obj->arr[key] = false;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    return obj->arr[key];
}

void myHashSetFree(MyHashSet* obj) {
    free(obj);
}
