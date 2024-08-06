#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define TIME_SIZE 6
#define SECONDS_IN_AN_HOUR 3600
#define SECONDS_IN_A_MINUTE 60

typedef struct clock_s *clock_ptr;
// typedef void (*clock_event_t)(clock_t);
bool getCurrentTimeBCD(clock_ptr, uint8_t *, int);
clock_ptr clockInit(uint8_t);
void incrementTick(clock_ptr);
void setTime(clock_ptr, uint8_t*, int);