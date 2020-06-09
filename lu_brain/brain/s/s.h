/**
	Copyright © 2020 Oleh Ihorovych Novosad 
*/

#ifndef _LU_S_H
#define _LU_S_H

///////////////////////////////////////////////////////////////////////////////
// S

	struct s_layer {
		lu_size 				lvl;
	};

	struct s_base {
		enum s_type 			type;

		S_Layer 				s_layer;
		N_Mem 					n_mem;

		lu_size 				x;
		lu_size 				y;
	};

	struct s_cb_links {
		S_Cb 					tl;
		S_Cb 					tr;
		S_Cb 					bl;
		S_Cb 					br;
	};

	struct s_cell_links {
		S_Cell				tl;
		S_Cell				tr;
		S_Cell 				bl;
		S_Cell				br;
	};

	union s_cb_parents {
		struct s_cb_links 		cbs;
		struct s_cell_links 	cols;
	};

	struct s_col_conf {
		lu_value 				orig_min;
		lu_value 				orig_max;
		lu_value 				max;

		lu_value 				step;
		lu_value*				steps;  		// preobchysleni kroky
		lu_size 				neu_size;
		lu_size 				nsc; 			// (tilky dlia poshuku) nei sim count
	};

	static inline lu_value s_col_conf_norm(S_Col self, lu_value request);
	static inline lu_size s_col_conf_indx(S_Col self, lu_value val);
	static inline struct lu_size_range s_col_conf_indx_range(S_Col self, lu_value val);
	static inline lu_value s_col_conf_calc_sig(S_Col self, lu_size val_step_i, lu_value val);
	static inline lu_value s_col_conf_step_norm_dist(S_Col self);

	struct s_col {
		struct s_base 			s_base;	

		// conf 
		S_Col_Conf 				conf;

		neu_ix*					neus; 	
		//N_V_Neu 				t1neu; // stop ce maye buty v w_v_col, i ce bude w_v_neu chy shos take
	};

	static inline S_Col s_col_create(Mem mem, S_Cell s_cell, S_Col_Conf s_col_conf);
	// tilky w_save mozhe stvoruvaty neu (lock vseredyni cioho methoda yakyy lokaye tilky dlia cioho input_val - tochnishe val index)
	static inline N_Neu s_col_n_get(S_Col self, lu_value input_val);


	// p or v cell
	struct s_cell {
		struct s_base 			s_base;

		// vlasnyk
		S_Rec 					s_rec; 			

		Arr 					s_cols;    	
	};

	static S_Cell s_cell_create(Mem mem, S_Rec rec, lu_size x, lu_size y);
	static inline S_Col s_cell_s_col_get(S_Cell self, lu_size indx) { return (S_Col) arr_get(self->s_cols, indx); }

	struct s_cb {
		struct s_base 			s_base;

		lu_flags				flags;

		union s_cb_parents 		parents;

		// odyn s_cb mozhe braty uchast tilky v 4roh child s_cb
		struct s_cb_links 		children; 
	};

	struct s_rec {
		// vlasnyk
		S_Mem 					s_mem; 			

		// poviazanyy z rec
		Lu_Rec 					rec;			

		lu_size 				id;

		lu_size 				s_cells_w;
		lu_size 				s_cells_h; 
		S_Cell* 				s_cells;	

		// Ci dani spilni dlia vsih s_cells i s_col
		// i odnakovi dlia znachen i perepadiv
		lu_size 				component_size; 

		struct s_col_conf 		v_conf;
		struct s_col_conf 		p_conf;
	};

	static S_Rec s_rec_create(S_Mem s_mem, Lu_Rec s_rec);

	static inline void s_rec_s_cell_set(S_Rec self, lu_size x, lu_size y, S_Cell s_cell) { self->s_cells[y * self->s_cells_w + x] = s_cell; }
	static inline S_Cell s_rec_s_cell_get(S_Rec self, lu_size x, lu_size y) { return self->s_cells[y * self->s_cells_w + x]; }

	static void s_rec_debug_print(S_Rec self);

	struct s_mem {
		Lu_Brain 				brain;

		Arr 					s_recs;

		N_Mem					n_mem;
	};
	
	static S_Mem s_mem_create(Lu_Brain brain);

	//static N_Col s_mem_n_col_create(S_Mem self, S_Col s_col);
	static inline S_Rec s_mem_s_rec_get(S_Mem self, lu_size indx) { return arr_get(self->s_recs, indx); }

#endif // _LU_S_H
