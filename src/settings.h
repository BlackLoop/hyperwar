// Background images & tiles
#pragma once

#define BACKGROUND_SIZE_X   15360
#define BACKGROUND_SIZE_Y   10880

#define X_TILES_NB          8
#define Y_TILES_NB          8
#define TILE_WIDTH          1920
#define TILE_HEIGHT         1360

// des trucs crads de fred
#define I_BKGND_WIDTH       8*1920
#define I_BKGND_HEIGHT      8*1360

#define fOverflowX          8*1920// - 1024;
#define fOverflowY          8*1360// - 768;


//#define USE3DPAD
static float s_fCurrentX = -fOverflowX/2.f;
static float s_fCurrentY = -fOverflowY/2.f;

static float s_fTargetX = 0.f;
static float s_fTargetY = 0.f;

static float s_fLastMouseX = 0.f;
static float s_fLastMouseY = 0.f;

static float s_zoom = 0.f;

#define F_TRANS_DELTA   1.5f

#define USE3DPAD
