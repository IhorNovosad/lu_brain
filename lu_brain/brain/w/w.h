/**
	Copyright © 2020 Oleh Ihorovych Novosad 
*/

///////////////////////////////////////////////////////////////////////////////
// 

	struct lu_neu {
		N_Cell 					neu;
		lu_value 				p;
	};

	lu_size lu_neu_name_get(Lu_Neu);
	void lu_neu_name_set(Lu_Neu, lu_size);

	// asociyuyetsia do s_cell, a ne n_cell
	struct lu_space {
		Lu_Neu 					sigs; 	// velykyy masyv, de sigs[n_neu_1->sid] vidpovidaye za w_sig dlia n_neu_1
										// kozhne vykorystania n_cell miniaye misciamy n_cell->sid z vyshchym n_cell->sid
										// takym chynom my mozhemo vyddaliaty neu z sid sho perevyshchuye pevne znachennia (starinnia neuroniv)

		Lu_Neu 					w;		// peremozhec
	};

	struct w_layer {
		lu_size 				w;
		lu_size 				h;
	};

	struct w_rec {
		// vlasnyk
		Lu_Wave_Mem 			mem; 			

		// poviazanyy z rec
		Lu_Rec 					rec;			

		lu_size 				id;

		lu_size 				cells_w;
		lu_size 				cells_h; 
		lu_size 				cells_d;		
	};

	struct lu_wave_mem {
		Lu_Brain 				brain;

		Arr 					recs;
	}; 

	static Lu_Wave_Mem wave_mem_create(Lu_Wave wave, S_Mem s_mem);
	Lu_Neu lu_wave_mem_name_neu(Lu_Wave_Mem);

	struct lu_wave {
		// Opts
		lu_flags 				flags;
		lu_value 				color;
		lu_value 				contrast;
		lu_value 				breakpoint;

		// Refs
		S_Mem 					s_mem; 
		N_Mem 					n_mem;
		Lu_Story 				story;

		// Internal
		Lu_Wave_Mem 			w_mem;
	};

	Lu_Wave lu_wave_create(Lu_Brain);
	void lu_wave_destroy(Lu_Wave); 

	// Save
	Lu_Wave_Mem lu_wave_save(Lu_Wave, Lu_Story); 
	void lu_wave_save_async(Lu_Wave, Lu_Story);
	static void wave_save_async_internal(Lu_Wave self, Lu_Story story);
	static void wave_data_save(Lu_Wave self, lu_size s_rec_id, Data data, lu_size block_i);

	// Find 
	Lu_Wave_Mem lu_wave_find(Lu_Wave, Lu_Story);
	void lu_wave_find_async(Lu_Wave, Lu_Story);

	// Restore
	Lu_Wave_Mem lu_wave_restore(Lu_Wave, Lu_Neu);
	void lu_wave_restore_async(Lu_Wave, Lu_Story);

	// Other
	Lu_Wave_Mem lu_wave_join(Lu_Wave);
	static Lu_Wave wave_prepare(Lu_Wave);

	// Properties

	lu_flags lu_wave_flags_get(Lu_Wave);
	void lu_wave_flags_set(Lu_Wave, lu_flags);
	void lu_wave_flags_remove(Lu_Wave self, lu_flags flags);

	lu_value lu_wave_color_get(Lu_Wave);
	void lu_wave_color_set(Lu_Wave, lu_value);

	lu_value lu_wave_contrast_get(Lu_Wave);
	void lu_wave_contrast_set(Lu_Wave, lu_value);

	lu_value lu_wave_breakpoint_get(Lu_Wave);
	void lu_wave_breakpoint_set(Lu_Wave, lu_value);



