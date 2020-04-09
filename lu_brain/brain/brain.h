/**
	Copyright © 2020 Oleh Ihorovych Novosad 
*/
#ifndef _LU_SRC_BRAIN_H
#define _LU_SRC_BRAIN_H

#include "basic/basic.h"
#include "lib/lib.h"

#include "public_to_private.h"

#include "n_mem/n_mem.h"
#include "recs/recs.h"
#include "story/story.h"
#include "net/net.h"
#include "waves/waves.h"
#include "gate/gate.h"

///////////////////////////////////////////////////////////////////////////////
// Nouns



///////////////////////////////////////////////////////////////////////////////
// Brain API

	struct brain_opts {
		lu_size				id;
		lu_size 			size_in_bytes;			// brain size in bytes including 
													// everything related

		////////////////////////////////////
		// Recs
		Arr					rec_opts;				// recs options

		////////////////////////////////////
		// Gate
		struct gate_opts 	gate_opts;

	};


	struct brain {
		lu_size			id;  		// useful for logs and debugging 
									// in multi-brain env

		Mem 			mem_perm;

		Arr				recs;		// receivers
  
		Gate 			gate;

		N_Mem 			n_mem;
	};	


	static inline Gate brain_gate(Brain self)
	{
		return self->gate;
	}	


#endif // _LU_SRC_BRAIN_H
