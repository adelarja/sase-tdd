#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define TIME_SIZE 6

typedef struct clock_s *clock_t;

bool getCurrentTime(clock_t, uint8_t *, int);
clock_t clockInit(uint8_t);
void incrementTick(uint8_t*, uint8_t);