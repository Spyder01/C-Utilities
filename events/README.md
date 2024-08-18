# Event System

## Overview

This is a simple event system implemented in C that allows you to register, dispatch, and manage events. The system supports registering listeners for specific events and dispatching those events to the registered listeners. It uses a map to associate event names with action stacks, which hold the registered listeners.

## Components

### Header File: `events.h`

- **`Event` Structure**: Contains the event's name and a map of action stacks.
- **Functions**:
  - `Event* InitEventBus(const char* event_name)`: Initializes a new event bus with the given event name.
  - `void InitEventAction(Event *event, const char* name)`: Initializes an action stack for a specific event name if it does not already exist.
  - `void FreeEventAction(Event *event, const char* name)`: Frees the action stack associated with a specific event name.
  - `void RegisterEventListener(Event *event, const char* name, dispatcher_method method)`: Registers a listener for a specific event.
  - `void DispatchEvent(Event* event, const char* name, void* payload)`: Dispatches an event to all registered listeners with the provided payload.
  - `void FreeEventBus(Event *event)`: Frees all resources associated with the event bus.

## Usage

### Initialization

To initialize a new event bus, use the `InitEventBus` function:

```c
Event *eventBus = InitEventBus("MyEventBus");
```

### Registering Listeners

To register a listener for an event, use the `RegisterEventListener` function. You need to define a function with the `dispatcher_method` type:

```c
void myListener(void *payload) {
    // Handle the event
}

RegisterEventListener(eventBus, "MyEvent", myListener);
```

### Dispatching Events

To dispatch an event, use the `DispatchEvent` function:

```c
DispatchEvent(eventBus, "MyEvent", myPayload);
```

### Freeing Resources

To free the resources associated with a specific event or the entire event bus, use the following functions:

```c
FreeEventAction(eventBus, "MyEvent");
FreeEventBus(eventBus);
```

## Notes

- Ensure that `ActionStack` and `ActionMap` implementations correctly handle memory management and cleanup.
- The `ActionMap` used in this system expects non-`const` `char*` for keys. This means string literals or string constants should be duplicated before inserting into the map.
- The `ActionStack` and `ActionMap` macros are assumed to be properly defined in the included `utils/map.h` and `utils/vector.h` files.

## Example

```c
#include "events.h"

// Define your listener
void myListener(void *payload) {
    printf("Event received with payload: %p\n", payload);
}

int main() {
    // Initialize the event bus
    Event *eventBus = InitEventBus("MainBus");

    // Initialize an event action
    InitEventAction(eventBus, "TestEvent");

    // Register a listener for the event
    RegisterEventListener(eventBus, "TestEvent", myListener);

    // Dispatch the event
    DispatchEvent(eventBus, "TestEvent", (void*)0xdeadbeef);

    // Clean up
    FreeEventAction(eventBus, "TestEvent");
    FreeEventBus(eventBus);

    return 0;
}
```

