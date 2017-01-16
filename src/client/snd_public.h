

void S_Init( void );
void S_Shutdown( void );

// if origin is NULL, the sound will be dynamically sourced from the entity
void S_StopSound(int entityNum, int entchannel, sfxHandle_t sfxHandle );
void S_StartSound( vec3_t origin, int entnum, int entchannel, sfxHandle_t sfx );
void S_StartLocalSound( sfxHandle_t sfx, int channelNum );

void S_StartBackgroundTrack( const char *intro, const char *loop, qboolean bReturnWithoutStarting );
void S_StopBackgroundTrack( void );

// cinematics and voice-over-network will send raw samples
// 1.0 volume will be direct output of source samples
void S_RawSamples (int samples, int rate, int width, int channels, 
				   const byte *data, float volume);

// stop all sounds and the background track
void S_StopAllSounds( void );

// all continuous looping sounds must be added before calling S_Update
void S_ClearLoopingSounds( qboolean killall );
void S_AddLoopingSound( const void *parent, int entityNum, const vec3_t origin, const vec3_t velocity, sfxHandle_t sfxHandle, int volume );
void S_StopLoopingSound(const void *parent );

// recompute the reletive volumes for all running sounds
// reletive to the given entityNum / orientation
void S_Respatialize( int entityNum, const vec3_t origin, vec3_t axis[3], int inwater );

// let the sound system know where an entity currently is
void S_UpdateEntityPosition( int entityNum, const vec3_t origin );

void S_Update( void );

void S_DisableSounds( void );

void S_BeginRegistration( void );

// RegisterSound will allways return a valid sample, even if it
// has to create a placeholder.  This prevents continuous filesystem
// checks for missing files
sfxHandle_t	S_RegisterSound( const char *name );

void S_ClearSoundBuffer( void );

void SNDDMA_Activate( qboolean activate );

// MME
void S_MMERecord( const char *baseName, float deltaTime );
void S_MMEWavClose( void );
qboolean S_MMEAviImport(byte *out, int *size);
void S_MMEUpdate( float scale );
void S_MMEMusic( const char *musicName, float time, float length );

void S_UpdateScale(float scale);
