#include "reloj.h"
#include <time.h>

struct clock_s {
    uint8_t time[TIME_SIZE];
    uint16_t ticks_count;
    uint16_t ticks_per_second;
    time_t elapsed_seconds;
    bool valid;
};

static struct clock_s clk;

static void epoch_bcd_to_time_array(clock_ptr);
static void bcd_to_time(clock_ptr);

static void set_bcd_time_in_clock(clock_ptr self) {
    // struct tm *local_time = localtime(&self->elapsed_seconds);

    // self->time[0] = local_time->tm_hour / 10;
    // self->time[1] = local_time->tm_hour % 10;

    // self->time[2] = local_time->tm_min / 10;
    // self->time[3] = local_time->tm_min % 10;

    // self->time[4] = local_time->tm_sec / 10;
    // self->time[5] = local_time->tm_sec % 10;
    self->time[0] = (self->elapsed_seconds / 3600) / 10;
    self->time[1] = (self->elapsed_seconds / 3600) % 10;

    self->time[2] = ((self->elapsed_seconds % 3600) / 60) / 10;
    self->time[3] = ((self->elapsed_seconds % 3600) / 60) % 10;

    self->time[4] = ((self->elapsed_seconds % 3600) % 60) / 10;
    self->time[5] = ((self->elapsed_seconds % 3600) % 60) % 10;
}

static void bcd_to_time(clock_ptr self) {
    uint8_t hour = (self->time[0] * 10) + self->time[1];
    uint8_t minute = (self->time[2] * 10) + self->time[3];
    uint8_t second = (self->time[4] * 10) + self->time[5];

    self->elapsed_seconds = (hour * SECONDS_IN_AN_HOUR) + (minute * SECONDS_IN_A_MINUTE) + second;
}

bool getCurrentTimeBCD(clock_ptr self, uint8_t *time, int number_of_elements) {
    memset(time, 0, number_of_elements);
    set_bcd_time_in_clock(self);
    memcpy(time, self->time, sizeof(self->time));
    return false;
}

clock_ptr clockInit(uint8_t t) {
    memset(clk.time, 0, TIME_SIZE);

    clk.ticks_count = 0;
    clk.ticks_per_second = t;
    clk.elapsed_seconds = time(0);
    clk.valid = true;

    return &clk;
}

void setTime(clock_ptr self, uint8_t *time, int size) {
    memcpy(time, self->time, sizeof(self->time));
    bcd_to_time(self);
}

void incrementTick(clock_ptr self) {
    self->ticks_count += 1;

    if(self->ticks_count == self->ticks_per_second) {
        self->ticks_count = 0;
        self->elapsed_seconds += 1;
    }
}
