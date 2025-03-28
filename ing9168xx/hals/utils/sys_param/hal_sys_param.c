#include "hal_sys_param.h"

static const char OHOS_SERIAL[] = {"1234567890"};

const char* HalGetSerial(void)
{
    return OHOS_SERIAL;
}