#include "Music.h"

// Global variable to hold the current background song in play.
// If the same song is called to play by a function the backgroundPlay will return.
std::string currentSong = "";

void backgroundPlay(const std::string& song) {
	std::string songPath = "./media/" + song;
	// Ensures the current song is reset by itself.
	if (songPath == currentSong) {
		return;
	}
#ifdef UNICODE
	// Convert std::string to std::wstring
	std::wstring wideSong(songPath.begin(), songPath.end());
	PlaySound(wideSong.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
#else
	PlaySound(songPath.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
#endif
}

void soundEffect(const std::string& effect) {
	std::string effectPath = "./media/" + effect;
	std::thread([](std::string path) {
#ifdef UNICODE
		// Convert std::string to std::wstring
		std::wstring wideEffect(path.begin(), path.end());
		PlaySound(wideEffect.c_str(), NULL, SND_FILENAME | SND_ASYNC);
#else
		PlaySound(songPath.c_str(), NULL, SND_FILENAME | SND_ASYNC);
#endif
		}, effectPath).detach();
}