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
#ifndef EHAL_RWL
#define EHAL_RWL

#include "cpu.h"


/** What this macro means is that the processor word size in bits minus
 * the the other 2 bits in the struct. This was done to make it fit on
 * a register */
#define RWL_RLOCK_BITS	(CPU_SIZE-2)

/** Max number of simultaneous readers. */
#define RWL_MAX_RLOCKS	(-1U & ( (1<<RWL_RLOCK_BITS)-1 ) )

/** Return Codes for rwl_r and rwl_w functions. */
enum RWL_RETURN {
	RWL_SUCCESS,		/**< Lock obtained. */
	RWL_WLOCKED,		/**< Already locked for writing. */
	RWL_MAXR_REACHED,	/**< Max num of readers. ( rwl_r only ) */
	RWL_WWANTLOCK		/**< Write pending ( rwl_r only ) */
};

/** internal usage structure. */
struct rwl;

/** Initializes the rwl struct
 * @param l - rwl pointer */
void
	rwl_init	(struct rwl *l);

/** Try to get a read lock.
 * @param l - rwl pointer
 * @see rwl_runlock */
enum RWL_RETURN
	rwl_rlock	(struct rwl *l);

/** Perform a unlock.
 *
 * unlock when reach 0 readers.
 * @param l - rwl pointer
 * @see rwl_rlock */
void
	rwl_runlock	(struct rwl *l);

/** Try to get a write lock.
 * @param l - rwl pointer
 * @return #RWL_RETURN
 * @see rwl_wunlock */
enum RWL_RETURN
	rwl_wlock	(struct rwl *l);

/** Perform a unlock.
 * @param l - rwl pointer
 * @see rwl_wlock */
void
	rwl_wunlock	(struct rwl *l);

/** @} */ /* end rwl group */

#endif /* __RWL_H_ */
