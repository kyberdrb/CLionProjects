#pragma once

//#ifndef DATA_H
//	#define DATA_H

//#define FALSE 0
//#define TRUE 1

enum { FALSE, TRUE };

//#define WINDOWS

//#ifdef WINDOWS
//	#define MUINT unsigned int
//#else
//	#define MUINT unsigned long
//#endif

void PripravZreby();
void ZrusZreby();

typedef unsigned int MUINT;
typedef unsigned short BOOL;

extern MUINT PocetZrebov;

struct Zreb {
	MUINT cislo;
	char kod;
};
//typedef struct ZrepPtr *Zreb;

extern struct Zreb *zreby;

//#endif