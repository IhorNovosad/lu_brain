/**
	Copyright © 2019 Oleh Ihorovych Novosad (Novossaad)
*/

#include <stdlib.h>
#include "lib/utils.h"
#include "f_wave.h"
 
///////////////////////////////////////////////////////////////////////////////
// Types and structs

///////////////////////////////////////////////////////////////////////////////
// Prototypes
 
///////////////////////////////////////////////////////////////////////////////
// Init, create and destroy

FWave f_wave_create()
{
	FWave self = (FWave) malloc(sizeof(struct f_wave));

	// Initialize

	return self;
}

void f_wave_destroy(FWave* self)
{
	lu_free((void**) self);
}

///////////////////////////////////////////////////////////////////////////////
// Main public methods



///////////////////////////////////////////////////////////////////////////////
// Other public methods
