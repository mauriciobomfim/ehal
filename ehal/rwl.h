#ifndef __RWL_H_
#define __RWL_H_

#ifndef CPU_SIZE
#warning CPU_SIZE undefined, defaulting to 8 bits
#define CPU_SIZE	8
#define CPU_TYPE	unsigned char
#endif

/** @file
 * Read write lock with one writer or multiple readers.
 * 
 * When a writer fails to get a lock it activates a bit flag indicating
 * it. This will make any atempt of a reader to get a lock fail until
 * all readers release the resource and the writer do its job. This is
 * is done to avoid writers starvation.
 *
 * @defgroup rwl read/write lock
 * @{  */

/** What this macro means is that the processor word size in bits minus
 * the the other 2 bits in the struct. This was done to make it fit on
 * a register 
 */
#define RWL_RLOCK_BITS	(CPU_SIZE-2)	/* -2 bits of the structure */

/** Max number of simultaneous readers. */
#define RWL_MAX_RLOCKS	(-1U & ( (1<<RWL_RLOCK_BITS)-1 ) )

/** Return Codes for rwl_r and rwl_w functions. */
enum RWL_RETURN {
	RWL_SUCCESS,		/**< Lock obtained. */
	RWL_WLOCKED,		/**< Already locked for writing. */
	RWL_MAXR_REACHED,	/**< Max num of readers. ( rwl_r only ) */
	RWL_WWANTLOCK		/**< Write pending ( rwl_r only ) */
};

/** Read write structure. */
struct rwl;

/** Initializes the rwl struct
 * @arg l - rwl pointer
 * @return None */
void rwl_init (struct rwl *l);

/** Try to get a read lock.
 * @arg l - rwl pointer
 * @return #RWL_RETURN
 * @see rwl_runlock */
enum RWL_RETURN rwl_rlock (struct rwl *l);

/** Perform a unlock.
 *
 * unlock when reach 0 readers.
 * @arg l - rwl pointer
 * @return None 
 * @see rwl_rlock */
void rwl_runlock (struct rwl *l);

/** Try to get a write lock.
 * @arg l - rwl pointer
 * @return #RWL_RETURN
 * @see rwl_wunlock */
enum RWL_RETURN rwl_wlock (struct rwl *l);

/** Perform a unlock.
 * @arg l - rwl pointer
 * @return None
 * @see rwl_wlock */
void rwl_wunlock (struct rwl *l);

/** @} */ /* end rwl group */

#endif /* __RWL_H_ */
