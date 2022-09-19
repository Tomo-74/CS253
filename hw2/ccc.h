#ifndef CCC_H
#define CCC_H

typedef struct {
	char* categoryName;
	char* validChars;
} CharacterCategory;

typedef CharacterCategory CharacterCategories[];

static CharacterCategories chrCats = {};

/* Function declarations */
static int isLetter();
static int isDigit();
static int isVowel();
static int isConsonant();
static int punctuationMarks();
static int isAscender();	// Is one of: t, d, f, h, k, l, and b
static int isDescender();	// Is one of: q, y, p, g, and j
static int isUpper();	// upper case letters
static int isLower();	// lower case letters

static int isCurvy();
// Is one of: B, C, D, G, J, O, P, Q, R, S, U
// Is one of: a, b, c, d, e, f, g, h, j, m, n, o, p, q, r, s, u

static int isStraight();
// Is one of: A, E, F, H, I, K, L, M, N, T, V, W, X, Y, Z
// Is one of: i, k, l, t, v, w, x, y, z

#endif
