/**
 * app.h
 * EV3 HRP app header
 */

#include "ev3api.h"

#ifndef STACK_SIZE
#define STACK_SIZE      (4096)        /* Default Stack Size*/
#endif /* STACK_SIZE */


#ifndef TOPPERS_MACRO_ONLY


extern void main_task(intptr_t exinf);
.assign task_num = 1
.select any tm_thread from instances of TM_THREAD
.if ( not (empty tm_thread) )
  .assign task_num = tm_thread.number_of_threads
.end if
.if ( task_num > 1 )
  .assign i = 1;
/* sub tasks */
  .while ( i < task_num )
extern void task${i}_start(intptr_t exinf);
    .assign i = i + 1
  .end while
.end if

.if ( te_sys.MaxTimers > 0 )
extern void timer_start(intptr_t extinf);
extern void cyclic_handler(intptr_t extinf);
extern void AlarmMainTIM_tick(void);
.end if

#endif
