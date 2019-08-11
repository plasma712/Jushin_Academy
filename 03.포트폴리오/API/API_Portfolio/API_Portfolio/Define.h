#pragma once

#define WINCX 800//640
#define WINCY 600//480

#define NULL_CHECK(ptr)	\
if(nullptr == (ptr)) return;

#define NO_EVENT 0
#define DEAD_OBJ 1
#define CHANGE_SCENE 2
#define GRAVITY  9.8f