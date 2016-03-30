/**
 * @file   inotify.h
 * @author Reginald Lips <reginald.l@gmail.com> - Copyright 2014
 * @date   Tue Jul 15 19:35:23 2014
 *
 * @brief  inotify structures and functions.
 *
 *
 */

#ifndef RINOO_FS_INOTIFY_H_
#define RINOO_FS_INOTIFY_H_

typedef enum e_inotify_type {
	INOTIFY_ACCESS = IN_ACCESS,
	INOTIFY_ATTRIB = IN_ATTRIB,
	INOTIFY_CLOSE = IN_CLOSE,
	INOTIFY_CLOSE_WRITE = IN_CLOSE_WRITE,
	INOTIFY_CLOSE_NOWRITE = IN_CLOSE_NOWRITE,
	INOTIFY_CREATE = IN_CREATE,
	INOTIFY_DELETE = IN_DELETE,
	INOTIFY_DELETE_SELF = IN_DELETE_SELF,
	INOTIFY_MODIFY = IN_MODIFY,
	INOTIFY_MOVE = IN_MOVE,
	INOTIFY_MOVE_SELF = IN_MOVE_SELF,
	INOTIFY_MOVED_FROM = IN_MOVED_FROM,
	INOTIFY_MOVED_TO = IN_MOVED_TO,
	INOTIFY_OPEN = IN_OPEN,
	INOTIFY_DONT_FOLLOW = IN_DONT_FOLLOW,
	//INOTIFY_EXCL_UNLINK = IN_EXCL_UNLINK,
	INOTIFY_MASK_ADD = IN_MASK_ADD,
	INOTIFY_ONESHOT = IN_ONESHOT,
	INOTIFY_ONLYDIR = IN_ONLYDIR,
	INOTIFY_IGNORED = IN_IGNORED,
	INOTIFY_ISDIR = IN_ISDIR,
	INOTIFY_Q_OVERFLOW = IN_Q_OVERFLOW,
	INOTIFY_UNMOUNT = IN_UNMOUNT
} t_inotify_type;

typedef struct s_inotify_watch {
	int wd;
	char *path;
} t_inotify_watch;

typedef struct s_inotify_event {
	t_buffer *path;
	t_inotify_type type;
	t_inotify_watch *watch;
} t_inotify_event;

typedef struct s_inotify {
	t_sched_node node;
	size_t io_calls;
	size_t nb_watches;
	t_inotify_watch *watches[500];
	char read_buffer[4096];
	t_inotify_event event;
} t_inotify;

t_inotify *rinoo_inotify(t_sched *sched);
void rinoo_inotify_destroy(t_inotify *notify);
t_inotify_watch *rinoo_inotify_add_watch(t_inotify *inotify, const char *path, t_inotify_type type, bool recursive);
int rinoo_inotify_rm_watch(t_inotify *inotify, t_inotify_watch *watch);
t_inotify_event *rinoo_inotify_event(t_inotify *inotify);

#endif /* !RINOO_FS_INOTIFY_H_ */
