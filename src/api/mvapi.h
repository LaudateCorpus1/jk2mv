#ifndef MVAPI_H
#define MVAPI_H

#ifndef Q3_VM
#	include <stdint.h>
#else
	typedef unsigned char uint8_t;
	typedef unsigned short uint16_t;
	typedef unsigned int uint32_t;
#endif

// -------------------------------------- API Version -------------------------------------- //
// MV_APILEVEL defines the API-Level which implements the following features.
// MV_MIN_VERSION is the minimum required JK2MV version which implements this API-Level.
// All future JK2MV versions are guaranteed to implement this API-Level.
// ----------------------------------------------------------------------------------------- //
#define MV_APILEVEL 3
#define MV_MIN_VERSION "1.4"
// ----------------------------------------------------------------------------------------- //

// ----------------------------------------- SHARED ---------------------------------------- //

typedef enum {
	MVFIX_NONE                = 0,

	/* GAME */
	MVFIX_NAMECRASH           = (1 << 0),
	MVFIX_FORCECRASH          = (1 << 1),
	MVFIX_GALAKING            = (1 << 2),
	MVFIX_BROKENMODEL         = (1 << 3),
	MVFIX_TURRETCRASH         = (1 << 4),
	MVFIX_CHARGEJUMP          = (1 << 5),
	MVFIX_SPEEDHACK           = (1 << 6),
	MVFIX_SABERSTEALING       = (1 << 7),
	MVFIX_PLAYERGHOSTING      = (1 << 8),

	/* CGAME */
	MVFIX_WPGLOWING           = (1 << 16),
} mvfix_t;

typedef enum {
	VERSION_UNDEF = 0,
	VERSION_1_02 = 2,
	VERSION_1_03 = 3,
	VERSION_1_04 = 4,
} mvversion_t;

// ******** SYSCALLS ******** //

// void trap_MVAPI_R_Font_DrawString(int ox, int oy, const char *text, const float *rgba, int setIndex, int iCharLimit, float hScale, float vScale);
#define MVAPI_R_FONT_DRAWSTRING 700              /* asm: -701 */

// int trap_MVAPI_R_Font_StrLenPixels(const char *text, qhandle_t iFontIndex, float hScale, float vScale);
#define MVAPI_R_FONT_STRLENPIXELS 701            /* asm: -702 */

// int trap_MVAPI_R_Font_HeightPixels(qhandle_t iFontIndex, float hScale, float vScale);
#define MVAPI_R_FONT_STRHEIGHTPIXELS 702         /* asm: -703 */

// qboolean trap_MVAPI_ControlFixes(int fixes);
#define MVAPI_CONTROL_FIXES 703                  /* asm: -704 */

// mvversion_t trap_MVAPI_GetVersion(void);
#define MVAPI_GET_VERSION 704                    /* asm: -705 */

// void trap_MVAPI_R_DrawTransformPic(float x, float y, float (*m)[2][2], float s1, float t1, float s2, float t2, qhandle_t hShader);
#define MVAPI_R_DRAWTRANSFORMPIC 707             /* asm: -706 */

// ******** VMCALLS ******** //

// vmMain(MVAPI_AFTER_INIT, ...)
#define MVAPI_AFTER_INIT 100

// ************************** //
// ----------------------------------------- GAME ------------------------------------------ //

typedef enum {
	MV_IPV4
} mviptype_t;

typedef struct {
	mviptype_t type;

	union {
		uint8_t v4[4];
		uint8_t reserved[16];
	} ip;

	uint16_t port;
} mvaddr_t;

#define MVF_NOSPEC		0x01
#define MVF_SPECONLY	0x02

typedef struct {
	uint8_t 	snapshotIgnore[32];
	uint8_t 	snapshotEnforce[32];
	uint32_t	mvFlags;
} mvsharedEntity_t;

// ******** SYSCALLS ******** //

// qboolean trap_MVAPI_SendConnectionlessPacket(const mvaddr_t *addr, const char *message);
#define MVAPI_SEND_CONNECTIONLESSPACKET 700      /* asm: -701 */

// qboolean trap_MVAPI_GetConnectionlessPacket(mvaddr_t *addr, char *buf, unsigned int bufsize);
#define MVAPI_GET_CONNECTIONLESSPACKET 701       /* asm: -702 */

// qboolean trap_MVAPI_LocateGameData(mvsharedEntity_t *mvEnts, int numGEntities, int sizeofmvsharedEntity_t);
#define MVAPI_LOCATE_GAME_DATA 702               /* asm: -703 */

// qboolean trap_MVAPI_DisableStructConversion(qboolean disable);
#define MVAPI_DISABLE_STRUCT_CONVERSION 705		/* asm: -706 */

// ******** VMCALLS ******** //

// vmMain(MVAPI_RECV_CONNECTIONLESSPACKET, ...)
#define MVAPI_RECV_CONNECTIONLESSPACKET 101

// ------------------------------------------ UI ------------------------------------------- //

#define MVSORT_CLIENTS_NOBOTS 5

// -------------------------------------- UI & CGAME --------------------------------------- //

// void trap_R_AddRefEntityToScene2(const refEntity_t *re);
#define MVAPI_R_ADDREFENTITYTOSCENE2 706         /* asm: -707 */

// ----------------------------------------------------------------------------------------- //

#endif /* MVAPI_H */
