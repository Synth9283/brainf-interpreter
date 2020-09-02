#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct {
    int16_t value;
    struct node_t *prev;
    struct node_t *next;
} node_t;

char *loopChars(node_t **currentNode, char *currentChar);
node_t *moveNext(node_t **currentNode);
node_t *movePrev(node_t **currentNode);

int main(int argc, char **argv) {
    node_t *currentNode = malloc(sizeof(node_t));
    currentNode->value = 0;
    currentNode->prev = NULL;
    currentNode->next = NULL;
    char *currentChar = argv[1];

    if (loopChars(&currentNode, currentChar)) { 
        puts("");
        return 0;
    }
    else return 1;
}

char *loopChars(node_t **currentNode, char *currentChar) {
    char *tracerChar = currentChar-1;
    do {
        switch (*currentChar) {
            case '+': (*currentNode)->value++; break;
            case '-': (*currentNode)->value--; break;
            case '>': *currentNode = moveNext(currentNode); break;
            case '<': *currentNode = movePrev(currentNode); break;
            case '[':
                currentChar = loopChars(currentNode, ++currentChar);
                break;
            case ']':
                if ((*currentNode)->value) currentChar = tracerChar;
                else currentChar++;
                break;
            case ',': fgets((int16_t)(*currentNode)->value, sizeof((*currentNode)->value), stdin); break;
            case '.': putchar((*currentNode)->value); break;
            default: return currentChar;
        }

        currentChar++;
    } while ((*(currentChar-1)=='>' || *(currentChar-1)=='<' || *(currentChar-1)==']')?1:(*currentNode)->value);

    return &*currentChar;
}

node_t *moveNext(node_t **currentNode) {
    if ((*currentNode)->prev) return (node_t*)(*currentNode)->prev;
    else {
        node_t *newNode = malloc(sizeof(node_t));
        (*currentNode)->prev = (struct node_t*)newNode;
        newNode->next = (struct node_t*)*currentNode;
        return newNode;
    }
}

node_t *movePrev(node_t **currentNode) {
    if ((*currentNode)->next) return (node_t*)(*currentNode)->next;
    else return *currentNode;
}
