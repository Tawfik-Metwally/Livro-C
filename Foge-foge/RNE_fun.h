//Run and escape functions
#ifndef _RNE_fun_H_
#define _RNE_fun_H_

#define UP 'w'
#define DOWN 's'
#define RIGHT 'd'
#define LEFT 'a'
#define BOMB 'b'

void move(char);
int itsDirection(char);
void explodePill();
void explodePill2(int, int, int, int, int);
void ghosts();
int whereGhostGoes(int, int, int *, int *);
int finish();

#endif