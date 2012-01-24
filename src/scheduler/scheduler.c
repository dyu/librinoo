/**
 * @file   scheduler.c
 * @author Reginald Lips <reginald.l@gmail.com> - Copyright 2012
 * @date   Fri Jan  6 16:10:07 2012
 *
 * @brief  Scheduler functions
 *
 *
 */

#include "rinoo/rinoo.h"

t_rinoosched *rinoo_sched()
{
	t_rinoosched *sched;

	sched = calloc(1, sizeof(*sched));
	if (sched == NULL) {
		return NULL;
	}
	if (rinoo_task_driver_init(sched) != 0) {
		rinoo_sched_destroy(sched);
		return NULL;
	}
	return sched;
}

void rinoo_sched_destroy(t_rinoosched *sched)
{
	XASSERTN(sched != NULL);

	rinoo_task_driver_destroy(sched);
	free(sched);
}
