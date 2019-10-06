// Copyright (c) 2019 Sarun Rattanasiri
// under the 3-Clause BSD License
// https://opensource.org/licenses/BSD-3-Clause

#ifndef __TIME_PRESCALER16_H
#define __TIME_PRESCALER16_H

#include <stdint.h>

typedef struct _time_prescaler16__config {
  uint16_t reload_value;
  void (*target)(void);
} TimePrescaler16_Config;

typedef struct _time_prescaler16__state {
  uint16_t count;
} TimePrescaler16_State;

#define time_prescaler16__init(config, state) \
  do {                                        \
    (state)->count = (config)->reload_value;  \
  } while (0)

void time_prescaler16__tick(TimePrescaler16_Config* config,
                            TimePrescaler16_State* state);

#endif
