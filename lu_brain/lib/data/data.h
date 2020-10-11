/**
	Copyright © 2020 Oleh Ihorovych Novosad 
*/

///////////////////////////////////////////////////////////////////////////////
// Lu_Data

	struct lu_data {
		lu_size w;
		lu_size h;
		lu_size d;

		lu_p_value values;
	};


///////////////////////////////////////////////////////////////////////////////
// Properties

	static inline void lu_data_value_set(Lu_Data d, lu_size x, lu_size y, lu_size z, lu_value value) { d->values[z * d->w * d->h + y * d->w + x] = value; }
	static inline lu_value lu_data_value_get(Lu_Data d, lu_size x, lu_size y, lu_size z) { return d->values[z * d->w * d->h + y * d->w + x]; }
	static inline lu_bool lu_data_is_empty(Lu_Data self) { return self->values == NULL; }
 
///////////////////////////////////////////////////////////////////////////////
// Init, create, detsroy

	static inline Lu_Data lu_data_set(Lu_Data self, lu_size w, lu_size h, lu_size d, lu_p_value values)
	{
		self->w 		= w;
		self->h 		= h;
		self->d 		= d;
		self->values 	= values;

		return self;
	}

	static inline Lu_Data lu_data_init_default(Lu_Data self)
	{
		lu_data_set(self, 0, 0, 0, NULL);

		return self;
	}

	static Lu_Data lu_data_create_via_deep_copy(Mem, Lu_Data src);
	static void lu_data_destroy(Lu_Data, Mem);

	static inline void lu_data_reset(Lu_Data self)
	{
		lu_data_set(self, 0, 0, 0, NULL);
	}

///////////////////////////////////////////////////////////////////////////////
// Validators

	static inline Lu_Data lu_data_validate_exists(Lu_Data self)
	{
		lu_assert(self);
		lu_assert(self->values);
		lu_assert(self->w > 0);
		lu_assert(self->h > 0);
		lu_assert(self->d > 0);

		return self;
	}

///////////////////////////////////////////////////////////////////////////////
// Copy

	static inline Lu_Data lu_data_shallow_copy(Lu_Data dest, Lu_Data src)
	{
		lu_data_set(dest, src->w, src->h, src->d, src->values);

		return dest;
	}

///////////////////////////////////////////////////////////////////////////////
// Transformations

	static Lu_Data lu_data_create_by_shift(Mem mem, Lu_Data src, lu_int x_shift, lu_int y_shift);


///////////////////////////////////////////////////////////////////////////////
// Debug

	static void lu_data_debug(Lu_Data);