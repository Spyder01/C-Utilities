#include "utils/map.h"
#include "utils/vector.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef EVENTS_H
#define EVENTS_H

typedef void (*dispatcher_method)(void*);
DEFINE_VECTOR_TYPE(dispatcher_method, ActionStack)
DEFINE_MAP(char*, ActionStack, ActionMap, strcmp)

typedef struct {
    char *event_name; 
    ActionMap *actionMap;
} Event;

Event* InitEventBus(const char* event_name) {
    Event *event = (Event *)malloc(sizeof(Event));
    if (!event) {
        fprintf(stderr, "Failed to allocate memory for event.\n");
        exit(EXIT_FAILURE);
    }
    event->event_name = strdup(event_name); // Copy the event name
    event->actionMap = ActionMapInit(10);

    return event;
}

void InitEventAction(Event *event, const char* name) {
    ActionStack *stack = ActionMapGet(event->actionMap, (char*)name); 

    if (stack != NULL) {
        return;
    }
		stack = ActionStackInit(10);
    
    ActionMapInsert(event->actionMap, strdup(name), *stack); 
}

void FreeEventAction(Event *event, const char* name) {
    ActionStack *stack = ActionMapGet(event->actionMap, (char*)name); // Cast to char* to match expected type

    if (stack == NULL) {
        return;
    }

    ActionStackFree(stack);
}

void RegisterEventListener(Event *event, const char* name, dispatcher_method method) {
    ActionStack *stack = ActionMapGet(event->actionMap, (char*)name);

    if (stack == NULL) {
        stack = ActionStackInit(10);
        ActionMapInsert(event->actionMap, strdup(name), *stack); 
    }

    ActionStackAdd(stack, method);
}

void DispatchEvent(Event* event, const char* name, void* payload) {
    ActionStack *stack = ActionMapGet(event->actionMap, (char*)name);

    if (stack == NULL) {
        return;  
    }

    for (int i = 0; i < stack->size; i++) {
        ActionStackGet(stack, i)(payload);
    }
}

void FreeEventBus(Event *event) {
    free(event->event_name);
    ActionMapFree(event->actionMap);
    free(event);
}

#endif

