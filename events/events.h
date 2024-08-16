#include "../vector/vector.h"

#ifndef EVENTS_H
#define EVENTS_H

DEFINE_VECTOR_TYPE(int, ActionStack)

typedef struct {
	char* event_name;
	ActionStack* action_stack;
} Event;

#endif EVENTS_H

