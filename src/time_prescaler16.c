// Copyright (c) 2019 Sarun Rattanasiri
// under the 3-Clause BSD License
// https://opensource.org/licenses/BSD-3-Clause

#include "time_prescaler16.h"

void time_prescaler16__tick(TimePrescaler16_Config* config,
                            TimePrescaler16_State* state) {
  state->count++;
  if (state->count) {
    return;
  }
  if (config->target) {
    config->target();
  }
  state->count = config->reload_value;
}
