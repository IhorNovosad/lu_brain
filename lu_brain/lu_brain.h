/**
	Copyright © 2020 Oleh Ihorovych Novosad
	Ludyna Brain API
*/
#ifndef _LU_BRAIN_PUB_H
#define _LU_BRAIN_PUB_H
 
#include "lu_configs.h"

///////////////////////////////////////////////////////////////////////////////
// Nouns

	typedef struct lu_brain* 			Lu_Brain;
	typedef struct lu_neto*				Lu_Neto;
	typedef struct lu_name* 			Lu_Name;
	typedef struct lu_rec* 				Lu_Rec;
	typedef struct lu_story* 			Lu_Story;
	typedef struct lu_block*			Lu_Block;
	typedef struct lu_wave* 			Lu_Wave;
	typedef struct lu_wave_resp*		Lu_Wave_Resp;
	typedef struct lu_save_resp*		Lu_Save_Resp;
	typedef struct lu_find_resp* 		Lu_Find_Resp;
	typedef struct lu_reception*		Lu_Reception;
	typedef struct lu_restore_resp* 	Lu_Restore_Resp;

	// Options 
	typedef struct lu_brain_opts* 		Lu_Brain_Opts;
	typedef struct lu_rec_opts* 		Lu_Rec_Opts;
	typedef struct lu_save_opts*		Lu_Save_Opts;
	typedef struct lu_find_opts* 		Lu_Find_Opts;
	typedef struct lu_restore_opts*		Lu_Restore_Opts;

	// Enums 
	enum lu_wave_status {
		LU_WS_WORKING,
		LU_WS_COMPLETE,
		LU_WS_ERROR, 
		LU_WS_CANCELED
	};

	enum lu_neto_type {
		LU_NT_STORY,
		LU_NT_BLOCK,
		LU_NT_PERCEPTION
	}; 

///////////////////////////////////////////////////////////////////////////////
// Brain_Opts API

	Lu_Brain_Opts lu_brain_opts_create(lu_size id, lu_size size_in_bytes);
	void lu_brain_opts_destroy(Lu_Brain_Opts);

///////////////////////////////////////////////////////////////////////////////
// Rec_Opts API

	Lu_Rec_Opts lu_rec_opts_create(Lu_Brain_Opts brain_opts, lu_size w, lu_size h, lu_value min, lu_value max);
	void lu_rec_opts_destroy(Lu_Rec_Opts);

///////////////////////////////////////////////////////////////////////////////
// Save_Opts API

	Lu_Save_Opts lu_save_opts_create();
	void lu_save_opts_destroy(Lu_Save_Opts);

///////////////////////////////////////////////////////////////////////////////
// Find_Opts API

	Lu_Find_Opts lu_find_opts_create();
	void lu_find_opts_destroy(Lu_Find_Opts*);

	lu_size lu_find_opts_limit(Lu_Find_Opts);
	void lu_find_opts_limit_set(Lu_Find_Opts);

///////////////////////////////////////////////////////////////////////////////
// Restore_Opts API

	Lu_Restore_Opts lu_restore_opts_create();
	void lu_restore_opts_destroy(Lu_Restore_Opts);

///////////////////////////////////////////////////////////////////////////////
// Brain API

	Lu_Brain lu_brain_create(Lu_Brain_Opts);
	void lu_brain_destroy(Lu_Brain);

	///////////////////////////////////////////////////////////////////////
	// Getters / Setters

	lu_size lu_brain_neto_count(Lu_Brain);
	Lu_Rec lu_brain_rec_get(Lu_Brain, lu_size index); 

///////////////////////////////////////////////////////////////////////////////
// Rec API


///////////////////////////////////////////////////////////////////////////////
// Block API

	Lu_Block lu_block_begin(Lu_Story);
	void lu_block_end(Lu_Story);

///////////////////////////////////////////////////////////////////////////////
// Story API

	Lu_Story lu_story_create(Lu_Brain);
	void lu_story_destroy(Lu_Story*);

	void lu_story_push(Lu_Story, Lu_Rec, lu_value* data);

	Lu_Save_Resp lu_story_save(Lu_Story, Lu_Save_Opts);
	Lu_Wave lu_story_save_async(Lu_Story, Lu_Save_Opts);

	Lu_Find_Resp lu_story_find(Lu_Story, Lu_Find_Opts);
	Lu_Wave lu_story_find_async(Lu_Story, Lu_Find_Opts);

	Lu_Restore_Resp lu_story_restore(Lu_Neto, Lu_Restore_Opts);
	Lu_Wave lu_story_restore_async(Lu_Neto, Lu_Restore_Opts);

///////////////////////////////////////////////////////////////////////////////
// Wave API

	bool lu_wave_is_working(Lu_Wave);
	bool lu_wave_cancel(Lu_Wave);
	lu_size lu_wave_time(Lu_Wave);
	enum lu_wave_status lu_wave_status(Lu_Wave);
	lu_size lu_wave_touched_count(Lu_Wave);
	lu_size lu_wave_excited_count(Lu_Wave);
	Lu_Wave_Resp lu_wave_response(Lu_Wave);

///////////////////////////////////////////////////////////////////////////////
// Name API
	
	Lu_Name lu_name_create(Lu_Brain);
	void lu_name_destroy(Lu_Name);

	void lu_name_link(Lu_Name, Lu_Neto dst);
	void lu_name_unlink(Lu_Name, Lu_Neto dst);
	
///////////////////////////////////////////////////////////////////////////////
// Wave_Resp API

	lu_size lu_wave_resp_time(Lu_Wave_Resp);
	enum lu_wave_status lu_wave_resp_status(Lu_Wave_Resp);
	lu_size lu_wave_resp_neto_touched(Lu_Wave_Resp);
	lu_size lu_wave_resp_neto_excited(Lu_Wave_Resp);

///////////////////////////////////////////////////////////////////////////////
// Neto API

	enum lu_neto_type lu_neto_type(Lu_Neto);
	lu_value lu_neto_p(Lu_Neto);
	Lu_Name*	lu_neto_names(Lu_Neto);
	Lu_Neto* lu_neto_parents(Lu_Neto);
	Lu_Neto* lu_neto_children(Lu_Neto);

///////////////////////////////////////////////////////////////////////////////
// Save_Resp API

	Lu_Neto lu_save_resp_neto(Lu_Save_Resp);

///////////////////////////////////////////////////////////////////////////////
// Find_Resp API

	Lu_Neto* lu_find_resp_netos(Lu_Find_Resp);

///////////////////////////////////////////////////////////////////////////////
// Reception API

	Lu_Rec lu_reception_rec(Lu_Reception);
	lu_value* lu_reception_data(Lu_Reception);

///////////////////////////////////////////////////////////////////////////////
// Restore_Resp API

	Lu_Reception* lu_restore_resp_layers(Lu_Restore_Resp);

#endif // _LU_BRAIN_API_H