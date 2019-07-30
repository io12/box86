#ifndef __SDL2RWOPS_H__
#define __SDL2RWOPS_H__

typedef struct SDL2_RWops_s SDL2_RWops_t;   // the actual SDL1 SDL_RWops
typedef struct x86emu_s x86emu_t;

typedef SDL2_RWops_t* (*sdl2_allocrw)();
typedef void (*sdl2_freerw)(SDL2_RWops_t*);

typedef struct SDL2RWSave_s {
    int   anyEmu;
    void* size;
    void* seek;
    void* read;
    void* write;
    void* close;
    void* s1;
    void* s2;
} SDL2RWSave_t;

// each function will be added to dictionary, and each native functions will be wrapped so they run in emulated world
SDL2_RWops_t* AddNativeRW2(x86emu_t* emu, SDL2_RWops_t* ops);
SDL2_RWops_t* RWNativeStart2(x86emu_t* emu, SDL2_RWops_t* ops);   // put Native RW function, wrapping emulated (callback style) ones if needed
void RWNativeEnd2(SDL2_RWops_t* ops);     // put back emulated function back in place

#endif