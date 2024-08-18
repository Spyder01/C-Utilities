#include "events.h"
#include <stdio.h>

// Sample dispatcher method
void sample_dispatcher(void *payload) {
    printf("Dispatcher called with payload: %d\n", *((int *)payload));
}

// Test function for initializing an event bus
void test_InitEventBus() {
    Event *event = InitEventBus("TestEvent");
    if (event == NULL) {
        fprintf(stderr, "Failed to initialize event bus.\n");
        exit(EXIT_FAILURE);
    }
    printf("test_InitEventBus passed.\n");
    FreeEventBus(event);
}

// Test function for initializing an event action
void test_InitEventAction() {
    Event *event = InitEventBus("TestEvent");
    InitEventAction(event, "TestAction");
    ActionStack *stack = ActionMapGet(event->actionMap, "TestAction");
    if (stack == NULL) {
        fprintf(stderr, "Failed to initialize event action.\n");
        exit(EXIT_FAILURE);
    }
    printf("test_InitEventAction passed.\n");
    FreeEventAction(event, "TestAction");
    FreeEventBus(event);
}

// Test function for registering an event listener
void test_RegisterEventListener() {
    Event *event = InitEventBus("TestEvent");
    InitEventAction(event, "TestAction");

    int payload = 42;
    RegisterEventListener(event, "TestAction", sample_dispatcher);

    ActionStack *stack = ActionMapGet(event->actionMap, "TestAction");
    if (stack == NULL || stack->size != 1) {
        fprintf(stderr, "Failed to register event listener.\n");
        exit(EXIT_FAILURE);
    }
    printf("test_RegisterEventListener passed.\n");
    FreeEventAction(event, "TestAction");
    FreeEventBus(event);
}

// Test function for dispatching an event
void test_DispatchEvent() {
    Event *event = InitEventBus("TestEvent");
    InitEventAction(event, "TestAction");

    int payload = 42;
    RegisterEventListener(event, "TestAction", sample_dispatcher);

    DispatchEvent(event, "TestAction", &payload);

    printf("test_DispatchEvent passed.\n");
    FreeEventAction(event, "TestAction");
    FreeEventBus(event);
}

int main() {
    test_InitEventBus();
    test_InitEventAction();
    test_RegisterEventListener();
    test_DispatchEvent();

    return 0;
}

