// Copyright (c) 2019 Sarun Rattanasiri
// under the 3-Clause BSD License
// https://opensource.org/licenses/BSD-3-Clause

#ifndef __TIME_PRESCALER8_H
#define __TIME_PRESCALER8_H

#include <stdint.h>

typedef struct _time_prescaler8__config {
  uint8_t reload_value;
  void (*target)(void);
} TimePrescaler8_Config;

typedef struct _time_prescaler8__state {
  uint8_t count;
} TimePrescaler8_State;

#define time_prescaler8__init(config, state) \
  do {                                       \
    (state)->count = (config)->reload_value; \
  } while (0)

void time_prescaler8__tick(TimePrescaler8_Config* config,
                           TimePrescaler8_State* state);

#endif
