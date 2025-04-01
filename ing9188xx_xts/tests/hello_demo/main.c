/*
 * Copyright (c) 2025 INGCHIPS.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ohos_init.h"
#include "cmsis_os2.h"


#define HELLO_TASK_STACK_SIZE   512
#define HELLO_TASK_PRIO         25
static int index = 0;
#define MS_1000                 1000

static void *HelloTask(const char *arg)
{
    (void)arg;

    while (1) {
        printf("hello world! index=%d\r\n", index++);
        osDelay(MS_1000);
    }
}

void HelloTaskEntry(void)
{
    osThreadAttr_t attr;

    attr.name = "HelloTask";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = HELLO_TASK_STACK_SIZE;
    attr.priority = HELLO_TASK_PRIO;

    if (osThreadNew((osThreadFunc_t)HelloTask, NULL, &attr) == NULL) {
        printf("[HelloDemo] Failed to create HelloTask!\n");
    }
}

SYS_RUN(HelloTaskEntry);
