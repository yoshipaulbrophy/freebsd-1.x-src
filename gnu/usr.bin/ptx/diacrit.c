/* Diacritics processing for a few character codes.
   Copyright (C) 1990, 1991, 1992, 1993 Free Software Foundation, Inc.
   Francois Pinard <pinard@iro.umontreal.ca>, 1988.

   All this file is a temporary hack, waiting for locales in GNU.
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "diacrit.h"

/* ISO 8859-1 Latin-1 code is used as the underlying character set.  If
   MSDOS is defined, IBM-PC's character set code is used instead.  */

/*--------------------------------------------------------------------.
| For each alphabetic character, returns what it would be without its |
| possible diacritic symbol.					      |
`--------------------------------------------------------------------*/

const char diacrit_base[256] =
{
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      'A',    'B',    'C',    'D',    'E',    'F',    'G',
  'H',    'I',    'J',    'K',    'L',    'M',    'N',    'O',
  'P',    'Q',    'R',    'S',    'T',    'U',    'V',    'W',
  'X',    'Y',    'Z',    0,      0,      0,      0,      0,
  0,      'a',    'b',    'c',    'd',    'e',    'f',    'g',
  'h',    'i',    'j',    'k',    'l',    'm',    'n',    'o',
  'p',    'q',    'r',    's',    't',    'u',    'v',    'w',
  'x',    'y',    'z',    0,      0,      0,      0,      0,

#ifdef MSDOS

  'C',    'u',    'e',    'a',    'a',    'a',    'a',    'c',
  'e',    'e',    'e',    'i',    'i',    'i',    'A',    'A',
  'E',    'e',    'E',    'o',    'o',    'o',    'u',    'u',
  'y',    'O',    'U',    0,      0,      0,      0,      0,
  'a',    'i',    'o',    'u',    'n',    'N',    0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,

#else /* not MSDOS */

  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  'A',    'A',    'A',    'A',    'A',    'A',    'A',    'C',
  'E',    'E',    'E',    'E',    'I',    'I',    'I',    'I',
  0,      'N',    'O',    'O',    'O',    'O',    'O',    0,
  'O',    'U',    'U',    'U',    'U',    'Y',    0,      0,
  'a',    'a',    'a',    'a',    'a',    'a',    'a',    'c',
  'e',    'e',    'e',    'e',    'i',    'i',    'i',    'i',
  0,      'n',    'o',    'o',    'o',    'o',    'o',    0,
  'o',    'u',    'u',    'u',    'u',    'y',    0,      'y',

#endif /* not MSDOS */
};

/*------------------------------------------------------------------------.
| For each alphabetic character, returns a code of what its diacritic is, |
| according to the following codes: 1 (eE) over aA for latin diphtongs; 2 |
| (') acute accent; 3 (`) grave accent; 4 (^) circumflex accent; 5 (")	  |
| umlaut or diaraesis; 6 (~) tilda; 7 (,) cedilla; 8 (o) covering degree  |
| symbol; 9 (|) slashed character.					  |
`------------------------------------------------------------------------*/

const char diacrit_diac[256] =
{
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      4,      0,
  3,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      6,      0,

#ifdef MSDOS

  7,      5,      2,      4,      5,      3,      8,      7,
  4,      5,      3,      5,      4,      3,      5,      8,
  2,      1,      1,      4,      5,      3,      4,      3,
  5,      5,      5,      0,      0,      0,      0,      0,
  2,      2,      2,      2,      6,      6,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,

#else /* not MSDOS */

  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  0,      0,      0,      0,      0,      0,      0,      0,
  3,      2,      4,      6,      5,      8,      1,      7,
  3,      2,      4,      5,      3,      2,      4,      5,
  0,      6,      3,      2,      4,      6,      5,      0,
  9,      3,      2,      4,      5,      2,      0,      0,
  3,      2,      4,      6,      5,      8,      1,      7,
  3,      2,      4,      5,      3,      2,      4,      5,
  0,      6,      3,      2,      4,      6,      5,      0,
  9,      3,      2,      4,      5,      2,      0,      0,

#endif /* not MSDOS */
};