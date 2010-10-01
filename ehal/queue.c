#include "queue.h"

struct queue {
	unsigned char *buff;
	unsigned char sz;
	unsigned char s;
	unsigned char ocupied;
};

void queue_init (struct queue *q,
		unsigned char *buff,
		unsigned char sz )
{
	q->buff = buff;
	q->sz = sz;
	q->s = 0;
	q->ocupied = 0;
}

unsigned char 
queue_ocupied (struct queue *q)
{
	return q->ocupied;
}

unsigned char queue_full (struct queue *q)
{
	return q->ocupied == q->sz;
}

unsigned char queue_empty (struct queue *q)
{
	return q->sz == 0;
}

unsigned char queue_peak (struct queue *q, unsigned char *ret)
{
	if( queue_empty( q ) ) return 1;
	*ret = q->buff[ q->s ];
	return 0;
}

unsigned char queue_enq (struct queue *q, unsigned char data)
{
	if( queue_full( q ) ) return 1;
	q->buff[ (q->s + q->ocupied) % q->sz ] = data;
	q->ocupied++;
	return 0;
}

unsigned char queue_deq (struct queue *q, unsigned char *ret)
{
	if( queue_empty( q ) ) return 1;
	*ret = q->buff[ q->s++ ];
	q->ocupied--;
	if( q->s >= q->sz ) q->s = 0; /* get index back to valid bounds */
	return 0;
}
