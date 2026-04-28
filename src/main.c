/*
 * Copyright (c) 2024-2025, Erich Styger
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "platform.h"
#include "McuRTOS.h"
#include "gcov_test.h"
#include <stdio.h>
#if PL_CONFIG_USE_GCOV
  #include "McuCoverage.h"
#endif

int main(void) {
  PL_Init();
  vTaskStartScheduler();

  // Call gcov_test HERE to test the file (NOT where the TODO is)
  // - Case where "j is not zero"
  gcov_test(0);
  // - Case where "j is zero"
  gcov_test(1);
  // - Case where "j is zero", but Calc returns uninitalized res (1st condition fail)
  gcov_test(-1);
  // - Case where "j is zero", but Calc returns uninitalized res (2nd condition fail)
  gcov_test(10);

#if PL_CONFIG_USE_GCOV
  McuCoverage_WriteFiles(); /* write coverage data files */
#endif /* PL_CONFIG_USE_GCOV */
  
  for(;;) {
    /* do not return from main() */
  }
  return 0;
}
