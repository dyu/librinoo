/**
 * @file   rinoo_sched_stop.c
 * @author Reginald LIPS <reginald.l@gmail.com> - Copyright 2011
 * @date   Sun Jan  3 16:02:21 2010
 *
 * @brief  Test file for rinoo_sched_stop function
 *
 *
 */
#include	"rinoo/rinoo.h"

void		event_fsm(t_tcpsocket *unused(tcpsock),
			  t_tcpevent unused(event))
{
}

/**
 * This test will check if a scheduler stops correctly.
 *
 * @return 0 if test passed
 */
int		main()
{
  t_rinoosched	*sched;
  t_tcpsocket	*tcpsock;

  sched = rinoo_sched();
  XTEST(sched != NULL);
  tcpsock = tcp_create(sched, 0, 42422, MODE_TCP_SERVER, 0, event_fsm);
  XTEST(tcpsock != NULL);
  rinoo_sched_stop(sched);
  XTEST(sched->stop == 1);
  /* sched_loop should leave immadiately */
  rinoo_sched_loop(sched);
  rinoo_sched_destroy(sched);
  XPASS();
}
