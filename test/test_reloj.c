#include "unity.h"
#include "reloj.h"

// void setUp(void) {
//     static const uint8_t INICIAL[] = {1, 2, 3, 4};

//     reloj = ClockCreate(TICKS_PER_SECOND);
//     ClockSetupTime(reloj, INICIAL, sizeof(INICIAL));
// }

void test_start_up(void) {
    static const uint8_t ESPERADO[] = {0, 0, 0, 0, 0, 0};
    uint8_t hora[6];

    clock_t *clock = clockInit(1);

    TEST_ASSERT_FALSE(getCurrentTime(clock, hora, 6));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);
}

void test_check_if_clock_advance() {
    static const uint8_t PRE_TICK[] = {0, 0, 0, 0, 0, 0};
    static const uint8_t POS_TICK[] = {0, 0, 0, 0, 0, 1};

    clock_t* clock = clockInit(1);

    uint8_t hora[6];

    TEST_ASSERT_FALSE(getCurrentTime(clock, hora, 6));

    TEST_ASSERT_EQUAL_UINT8_ARRAY(PRE_TICK, hora, 6);

    incrementTick(hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(POS_TICK, hora, 6);
}

// void test_set_time(void) {
//     static const uint8_t FAKE_TIME
//     set_time(time);
// }

