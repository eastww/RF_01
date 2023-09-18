/*
 * kfifo.c: port from linux, see next.
 *
 * Copyright (C) 2009 Stefani Seibold <stefani@seibold.net>
 * Copyright (C) 2004 Stelian Pop <stelian@popies.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

/*
 * Howto porting drivers to the new generic fifo API:
 *
 * - Modify the declaration of the "struct kfifo *" object into a
 *   in-place "struct kfifo" object
 * - Init the in-place object with kfifo_alloc() or kfifo_init()
 *   Note: The address of the in-place "struct kfifo" object must be
 *   passed as the first argument to this functions
 * - Replace the use of __kfifo_put into kfifo_in and __kfifo_get
 *   into kfifo_out
 * - Replace the use of kfifo_put into kfifo_in_locked and kfifo_get
 *   into kfifo_out_locked
 *   Note: the spinlock pointer formerly passed to kfifo_init/kfifo_alloc
 *   must be passed now to the kfifo_in_locked and kfifo_out_locked
 *   as the last parameter.
 * - All formerly name __kfifo_* functions has been renamed into kfifo_*
 */

#ifndef _KFIFO_H
#define _KFIFO_H

#include <stddef.h>

struct kfifo{
	unsigned char *buffer;	/* the buffer holding the data */
	unsigned int size;	/* the size of the allocated buffer */
	unsigned int in;	/* data is added at offset (in % size) */
	unsigned int out;	/* data is extracted from off. (out % size) */
};

/*
 * Macros for declaration and initialization of the kfifo datatype
 */


extern void kfifo_init(struct kfifo *fifo, void *buffer,
			unsigned int size);
extern unsigned int kfifo_in(struct kfifo *fifo,
				const void *from, unsigned int len);
extern unsigned int kfifo_out(struct kfifo *fifo,
				void *to, unsigned int len);

/**
 * kfifo_initialized - Check if kfifo is initialized.
 * @fifo: fifo to check
 * Return %true if FIFO is initialized, otherwise %false.
 * Assumes the fifo was 0 before.
 */
static __inline int kfifo_initialized(struct kfifo *fifo)
{
	return fifo->buffer != NULL;
}

/**
 * kfifo_reset - removes the entire FIFO contents
 * @fifo: the fifo to be emptied.
 */
static __inline void kfifo_reset(struct kfifo *fifo)
{
	fifo->in = fifo->out = 0;
}

/**
 * kfifo_reset_out - skip FIFO contents
 * @fifo: the fifo to be emptied.
 */
static __inline void kfifo_reset_out(struct kfifo *fifo)
{
	fifo->out = fifo->in;
}

/**
 * kfifo_size - returns the size of the fifo in bytes
 * @fifo: the fifo to be used.
 */
static __inline unsigned int kfifo_size(struct kfifo *fifo)
{
	return fifo->size;
}

/**
 * kfifo_len - returns the number of used bytes in the FIFO
 * @fifo: the fifo to be used.
 */
static __inline unsigned int kfifo_len(struct kfifo *fifo)
{
	register unsigned int	out;

	out = fifo->out;

	return fifo->in - out;
}

/**
 * kfifo_is_empty - returns true if the fifo is empty
 * @fifo: the fifo to be used.
 */
static __inline int kfifo_is_empty(struct kfifo *fifo)
{
	return fifo->in == fifo->out;
}

/**
 * kfifo_is_full - returns true if the fifo is full
 * @fifo: the fifo to be used.
 */
static __inline int kfifo_is_full(struct kfifo *fifo)
{
	return kfifo_len(fifo) == kfifo_size(fifo);
}

/**
 * kfifo_avail - returns the number of bytes available in the FIFO
 * @fifo: the fifo to be used.
 */
static __inline unsigned int kfifo_avail(struct kfifo *fifo)
{
	return kfifo_size(fifo) - kfifo_len(fifo);
}

extern void kfifo_skip(struct kfifo *fifo, unsigned int len);

/*
 * __kfifo_add_out internal helper function for updating the out offset
 */
static __inline void __kfifo_add_out(struct kfifo *fifo,
				unsigned int off)
{
	fifo->out += off;
}

/*
 * __kfifo_add_in internal helper function for updating the in offset
 */
static __inline void __kfifo_add_in(struct kfifo *fifo,
				unsigned int off)
{
	fifo->in += off;
}

/*
 * __kfifo_off internal helper function for calculating the index of a
 * given offeset
 */
static __inline unsigned int __kfifo_off(struct kfifo *fifo, unsigned int off)
{
	return off & (fifo->size - 1);
}






#endif	/* _KFIFO_H */

