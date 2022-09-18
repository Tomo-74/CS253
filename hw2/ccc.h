#ifndef CCC_H
#define CCC_H

typedef struct {
	char* categoryName;
	char* validChars;
} CharacterCategory;

typedef CharacterCategory CharacterCategories[];
static CharacterCategories chrCats = {};

#endif
