#include "reloj.h"

struct clock_s {
    uint8_t time[TIME_SIZE];
    uint16_t ticks_count;
    uint16_t ticks_per_second;
    bool valid;
};

static struct clock_s clock;

bool getCurrentTime(clock_t clock_ptr, uint8_t *time, int number_of_elements) {
    memset(time, 0, number_of_elements);
    memcpy(time, clock_ptr->time, sizeof(clock_ptr->time));
    return false;
}

clock_t clockInit(uint8_t t) {
    memset(clock.time, 0, TIME_SIZE);
    clock.ticks_count = 0;
    clock.ticks_per_second = t;
    clock.valid = true;

    return &clock;
}

void setTime(clock_t clock_ptr, uint8_t *time, int size) {
    memcpy(time, clock_ptr->time, sizeof(clock_ptr->time));
}

// void incrementTick(uint8_t *time, uint8_t const size) {
//     static uint8_t time_index = 0;

//     if (time_[size - 1 - time_index] == 9) {
//         time_[size - 1 - time_index] = 0;
//         if(time_[size - 1 - time_index + 1] == 5) {
//             time_[size - 1 - time_index + 1] = 0;
//             time_[size - 1 - time_index + 2] += 1;
//             if(time_[size - 1 - time_index + 2] == 9) {
//                 time_[size - 1 - time_index + 2] = 0;
//                 time_[size - 1 - time_index + 3] += 1;
//             }
//         }
//     } 

//     time_[size - 1 - time_index] += 1;
// }