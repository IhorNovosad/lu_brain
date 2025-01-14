/**
	Copyright © 2021 Oleh Ihorovych Novosad 
*/

///////////////////////////////////////////////////////////////////////////////
// Hnn_Cell

	enum hnn_cell_type {
		HNN_CT_0,
		HNN_CT_1,
		HNN_CT_2,
		HNN_CT_3,
		HNN_CT_4
	};

	struct hnn_cell {
		lu_byte type;

		Hnn_Cell top_left;
	};

	static inline Hnn_Cell hnn_cell_init(Hnn_Cell self, lu_byte type)
	{
		lu_assert(self);
		self->type = type;
		self->top_left = NULL;

		return self;
	}

///////////////////////////////////////////////////////////////////////////////
// Hnn_Cell_2

	struct hnn_cell_2 {
		struct hnn_cell super;

		Hnn_Cell top_right;
	};

	static inline Hnn_Cell_2 hnn_cell_2_init(Hnn_Cell_2 self, lu_byte type)
	{
		hnn_cell_init((Hnn_Cell) self, type);

		self->top_right = NULL;

		return self;
	}

///////////////////////////////////////////////////////////////////////////////
// Hnn_Cell_3

	struct hnn_cell_3 {
		struct hnn_cell_2 super;

		Hnn_Cell bottom_left;
	};

	static inline Hnn_Cell_3 hnn_cell_3_init(Hnn_Cell_3 self, lu_byte type)
	{
		hnn_cell_2_init((Hnn_Cell_2) self, type);

		self->bottom_left = NULL;

		return self;
	}

///////////////////////////////////////////////////////////////////////////////
// Hnn_Cell_4

	struct hnn_cell_4 {
		struct hnn_cell_3 super;

		Hnn_Cell bottom_right;
	}; 

	static inline Hnn_Cell_4 hnn_cell_4_init(Hnn_Cell_4 self, lu_byte type)
	{
		hnn_cell_3_init((Hnn_Cell_3) self, type);

		self->bottom_right = NULL;

		return self;
	}

///////////////////////////////////////////////////////////////////////////////
// Macro

#define hnn_cell_type_get(c) (((Hnn_Cell)c)->type)
#define hnn_cell_top_left_get(c) (((Hnn_Cell)c)->top_left)
#define hnn_cell_top_right_get(c) (((Hnn_Cell_2)c)->top_right)
#define hnn_cell_bottom_left_get(c) (((Hnn_Cell_3)c)->bottom_left)
#define hnn_cell_bottom_right_get(c) (((Hnn_Cell_4)c)->bottom_right)