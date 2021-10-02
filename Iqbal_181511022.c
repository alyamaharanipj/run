//File		: Iqbal_181511022.c

#include"Iqbal_181511022.h"
	
void play_music(){
	mciSendString("PLAY \"main.WAV\"", NULL, 0, NULL);
}

void stop_music(){
	mciSendString("STOP \"main.WAV\"", NULL, 0, NULL);
}

void play_menu(){
	mciSendString("PLAY \"main_menu.WAV\"", NULL, 0, NULL);
}

void stop_menu(){
	mciSendString("STOP \"main_menu.WAV\"", NULL, 0, NULL);
}

void play_coin(){
	mciSendString("PLAY \"coin.WAV\"", NULL, 0, NULL);
}

void stop_coin(){
	mciSendString("STOP \"coin.WAV\"", NULL, 0, NULL);
}

void play_fall(){
	mciSendString("PLAY \"fall.WAV\"", NULL, 0, NULL);
}

void stop_fall(){
	mciSendString("STOP \"fall.WAV\"", NULL, 0, NULL);
}

void play_uh(){
	mciSendString("PLAY \"uh.WAV\"", NULL, 0, NULL);
}

void stop_uh(){
	mciSendString("STOP \"uh.WAV\"", NULL, 0, NULL);
}
