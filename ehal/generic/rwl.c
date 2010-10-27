#include "rwl.h"

/** Read write structure. */
struct rwl{
	unsigned CPU_TYPE rlock:RWL_RLOCK_BITS;	/**< locked for readers */
	unsigned CPU_TYPE wlock:1;		/**< locked for writing */
	unsigned CPU_TYPE wwantlock:1;		/**< writer wants lock */
};

void rwl_init (struct rwl *l){
	l->rlock = 0;
	l->wlock = 0;
	l->wwantlock = 0;
}

enum RWL_RETURN rwl_rlock (struct rwl *l){
	if (l->wwantlock)		return RWL_WWANTLOCK;
	if (l->wlock)			return RWL_WLOCKED;
	if (l->rlock == RWL_MAX_RLOCKS)	return RWL_MAXR_REACHED;
	l->rlock++;
	return RWL_SUCCESS;
}

void rwl_runlock (struct rwl *l){
	if (l->rlock ) l->rlock--;
}

enum RWL_RETURN rwl_wlock (struct rwl *l){
	l->wwantlock = 1;
	if (l->wlock) return RWL_WLOCKED;
	l->wlock = 1;
	l->wwantlock = 0;
	return RWL_SUCCESS;
}

void rwl_wunlock (struct rwl *l){
	l->wlock = 0;
}
