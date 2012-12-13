/**
 * @file   socket.h
 * @author Reginald Lips <reginald.l@gmail.com> - Copyright 2012
 * @date   Wed Jan 25 00:28:29 2012
 *
 * @brief  Header file for socket function declarations.
 *
 *
 */

#ifndef		RINOO_NET_SOCKET_H_
# define	RINOO_NET_SOCKET_H_

typedef struct s_rinoosocket
{
	int			fd;
	int			error;
	void			(*run)(struct s_rinoosocket *socket);
	void			(*autodestroy)(struct s_rinoosocket *socket);
	t_rinootask		task;
	struct s_rinoosocket	*parent;
	void			*context;
} t_rinoosocket;

typedef in_addr_t       t_ip;

int rinoo_socket_init(t_rinoosched *sched,
		      t_rinoosocket *socket,
		      int fd,
		      void (*run)(t_rinoosocket *socket),
		      void (*autodestroy)(t_rinoosocket *socket));
int rinoo_socket_set(t_rinoosched *sched, t_rinoosocket *sock, int domain, int type, void (*run)(t_rinoosocket *socket), void (*autodestroy)(t_rinoosocket *socket));
t_rinoosocket *rinoo_socket(t_rinoosched *sched, int domain, int type, void (*run)(t_rinoosocket *socket));
void rinoo_socket_close(t_rinoosocket *socket);
void rinoo_socket_destroy(t_rinoosocket *socket);

void rinoo_socket_error_set(t_rinoosocket *socket, int error);
int rinoo_socket_error_get(t_rinoosocket *socket);
int rinoo_socket_schedule(t_rinoosocket *socket, u32 ms);
int rinoo_socket_unschedule(t_rinoosocket *socket);
int rinoo_socket_timeout(t_rinoosocket *socket, u32 ms);
int rinoo_socket_start(t_rinoosocket *socket);
int rinoo_socket_resume(t_rinoosocket *socket);
int rinoo_socket_release(t_rinoosocket *socket);
int rinoo_socket_waitin(t_rinoosocket *socket);
int rinoo_socket_waitout(t_rinoosocket *socket);

int rinoo_socket_connect(t_rinoosocket *socket, const struct sockaddr *addr, socklen_t addrlen);
int rinoo_socket_bind(t_rinoosocket *socket, const struct sockaddr *addr, socklen_t addrlen);
int rinoo_socket_listen(t_rinoosocket *socket, const struct sockaddr *addr, socklen_t addrlen, int backlog);
t_rinoosocket *rinoo_socket_accept(t_rinoosocket *socket, struct sockaddr *addr, socklen_t *addrlen, void (*run)(t_rinoosocket *socket));
ssize_t rinoo_socket_read(t_rinoosocket *socket, void *buf, size_t count);
ssize_t	rinoo_socket_write(t_rinoosocket *socket, const void *buf, size_t count);
ssize_t rinoo_socket_readb(t_rinoosocket *socket, t_buffer *buffer);
ssize_t rinoo_socket_readline(t_rinoosocket *socket, t_buffer *buffer, const char *delim, size_t maxsize);
ssize_t rinoo_socket_writeb(t_rinoosocket *socket, t_buffer *buffer);

#endif		/* !RINOO_NET_SOCKET */
