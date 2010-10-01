#ifndef _QUEUE_H_
#define _QUEUE_H_

struct queue;

void
queue_init	(struct queue *q,
		unsigned char *buff,
		unsigned char sz);

unsigned char
queue_ocupied	(struct queue *q);

unsigned char
queue_full	(struct queue *q);

unsigned char
queue_empty	(struct queue *q);

unsigned char
queue_peek	(struct queue *q,
		unsigned char *ret);

unsigned char
queue_enq	(struct queue *q,
		unsigned char data);

unsigned char
queue_deq	(struct queue *q,
		unsigned char *ret);

#endif		/* #ifdef __QUEUE_H_ */
