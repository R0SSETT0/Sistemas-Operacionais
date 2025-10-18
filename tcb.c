#include "tcb.h"

void myTaskFunction(void *arg) {
    // Example: Print a message and increment a counter
    int *counter = (int *)arg;
    while (1) {
        // Perform task-specific work
        // ...
        (*counter)++;
        // Simulate some work or delay
        for (volatile int i = 0; i < 100000; i++);
    }
}

// Example of creating and initializing a TCB
TCB *createTCB(uint32_t id, void (*func)(void *), void *arg, uint8_t prio, void *stackBase, size_t stackSize) {
    TCB *newTCB = (TCB *)malloc(sizeof(TCB)); // Allocate memory for TCB
    if (newTCB == NULL) {
        return NULL; // Handle allocation error
    }

    newTCB->task_id = id;
    newTCB->state = READY;
    newTCB->taskFunction = func;
    newTCB->taskArgument = arg;
    newTCB->priority = prio;
    newTCB->stackPtr = (void *)((char *)stackBase + stackSize - sizeof(uint32_t)); // Adjust stack pointer
    newTCB->nextTCB = NULL;
    newTCB->prevTCB = NULL;

    // Initialize stack for the task (platform-specific)
    // This typically involves placing initial register values, return address, etc.
    // For simplicity, this is omitted here.

    return newTCB;
}