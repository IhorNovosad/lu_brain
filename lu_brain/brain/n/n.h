/**
	Copyright © 2020 Oleh Ihorovych Novosad 
*/

#ifndef _LU_N_H
#define _LU_N_H


///////////////////////////////////////////////////////////////////////////////
// N Net

// serializaciya bude duzhe prostoyu, 
// treba prosto zberehty N Net ta parametry za yakymy buv stvorenyy brain
// vse reshtu perestvoruyetsia. Tak samo perevydilenia pamiati (z mozhlyvym peremishcheniam v inshe misce).


	struct n_com {
		enum n_com_type type;

		union {
			lu_size 		name;			// unique id that represents name from outside of this lib
			lu_value 		value;
		} data;
	};

	// "nasliduvannia" ce yedynyy maksymalno effectyvnyy sposib optymizuvaty pamiat
	// componenty potrebuyut bilshe pamiati.
	struct n_neu {
		S_Cell 					s_cell;
		lu_size 				s_ix;   	// nomer v s_cell

		N_Lin 					b_l; 		// v and h and other links, 0 zavzhdy h
		lu_value 				b_count;

		N_Lin  					d_l;		// v and h and other links, 0 zavzhdy h

		N_Com 					com;		
	};

	lu_size n_neu_name_get(N_Neu self);
	lu_value n_neu_value_get(N_Neu self);

	struct n_lin {
		N_Neu	 				b;			// b i d potribni bo po tomu samomu zviazku my mozhemo jty vverh abo vnyz
		N_Neu					d;

		// ce dva spysky
		// odyn z storony b, inshyy z storony d
		N_Lin	 				b_p;
		N_Lin	 				b_n;

		N_Lin	 				d_p; 		// p i n potribni u vypadku yakshou my vydaliayemo zviazok?
		N_Lin					d_n; 		// yaksho my vydaliayemo zviazok, to my mozhemo podyvytys p ale my neznayemo n
		 		   							// tomu naspravdi i p i n potribni
	};

///////////////////////////////////////////////////////////////////////////////
// N Dopomizhni

	struct n_mem_opts {
		lu_size 				names_size;
	};

	static inline N_Mem_Opts n_mem_opts_init(N_Mem_Opts self)
	{
		self->names_size = LU_NAMES_SIZE;
	}

	static inline N_Mem_Opts n_mem_opts_validate(N_Mem_Opts opts)
	{
		lu_user_assert(opts, "N_Mem_Opts is NULL");
		lu_user_assert(opts->names_size > 0, "names_size should be greater than 0");

		return opts;
	}
	
	struct n_mem {
		// vlasnyk
		Lu_Brain 				brain;

		struct n_mem_opts 		opts;

		// Tut potriben Mem_Table bo teoretychno neu mozhut vydaliatys
		Mem_Table				coms;
		Mem_Table 				cells;
		Mem_Table				lins; 
	};

	static N_Mem n_mem_create(Lu_Brain brain, N_Mem_Opts opts);
	static N_Mem n_mem_tables_alloc(N_Mem self, Mem mem);
	static Mem_Table n_mem_coms_create(N_Mem self, Mem mem);
	static Mem_Table n_mem_neus_create(N_Mem self, Mem mem);
	static Mem_Table n_mem_lins_create(N_Mem self, Mem mem);
	static void n_mem_print_info(N_Mem);
	static N_Com n_mem_com_alloc(N_Mem self);
	static N_Neu n_mem_neu_alloc(N_Mem self);
	static N_Lin n_mem_lin_alloc(N_Mem self);


#endif // _LU_N_H