#ifndef MUSIC_H
#define MUSIC_H
#define NOMINMAX // Fixes issues with <windows.h> interfering with the max function in other files.
#include <windows.h>
#include <mmsystem.h>
#include <string>
#include <thread>
#pragma comment(lib, "winmm.lib")

void backgroundPlay(const std::string& song);

void soundEffect(const std::string& effect);

#endif