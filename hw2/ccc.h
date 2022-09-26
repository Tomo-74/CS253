#ifndef CCC_H
#define CCC_H

typedef struct {
	char* name;
	char* validChars;
	ssize_t count;
} ChrCat;

typedef ChrCat ChrCats[];

extern void ccc(char* input, ssize_t len, ChrCat categories[], ssize_t numCategories);

#endif
