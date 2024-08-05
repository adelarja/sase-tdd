#include "unity.h"
#include "reloj.h"

void test_start_up(void) {
    static const uint8_t ESPERADO[] = {0, 0, 0, 0, 0, 0};
    
    uint8_t hora[6];

    clockInit(1);

    TEST_ASSERT_FALSE(getCurrentTime(hora, 6));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);
}

