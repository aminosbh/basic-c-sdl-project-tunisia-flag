/*
 * Copyright (c) 2018, 2019 Amine Ben Hassouna <amine.benhassouna@gmail.com>
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any
 * person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the
 * Software without restriction, including without
 * limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice
 * shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
 * ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
 * SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 * IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef TNFLAG_H
#define TNFLAG_H

#include "utils.h"

// Tunisia flag proportions
// https://en.wikipedia.org/wiki/File:Mesures_drapeau_Tunisie_apres_1999.svg

#define TN_FLAG_LENGTH                              (120)
#define TN_FLAG_DIMENSION(FLAG_LENGTH, DIMENTION)   ((FLAG_LENGTH * DIMENTION) / TN_FLAG_LENGTH)
#define TN_FLAG_WIDTH(FLAG_LENGTH)                  TN_FLAG_DIMENSION(FLAG_LENGTH, 80)
#define TN_FLAG_CIRCLE_RAD(FLAG_LENGTH)             TN_FLAG_DIMENSION(FLAG_LENGTH, 20)
#define TN_FLAG_CRESCENT_OUTER_RAD(FLAG_LENGTH)     TN_FLAG_DIMENSION(FLAG_LENGTH, 15)
#define TN_FLAG_CRESCENT_INNER_RAD(FLAG_LENGTH)     TN_FLAG_DIMENSION(FLAG_LENGTH, 12)
#define TN_FLAG_STAR_RAD(FLAG_LENGTH)               TN_FLAG_DIMENSION(FLAG_LENGTH, 9)
#define TN_FLAG_STAR_X_PADDING(FLAG_LENGTH)         TN_FLAG_DIMENSION(FLAG_LENGTH, 4)
#define TN_FLAG_STAR_ROTATION                       (-54) // -54 Degree <=> -0.3 PI

struct Circle
{
    int x;
    int y;
    int rad;
};
typedef struct Circle Circle;

struct Crescent
{
    Circle outerCircle;
    Circle innerCircle;
};
typedef struct Crescent Crescent;

struct Star
{
    Sint16 vx[10];
    Sint16 vy[10];
};
typedef struct Star Star;

struct TunisiaFlag
{
    SDL_Rect rect;

    SDL_Rect border;
    SDL_Color borderColor;

    Circle circle;
    Crescent crescent;
    Star star;
};
typedef struct TunisiaFlag TunisiaFlag;

void TunisiaFlag_init(TunisiaFlag *flag, int length, int x, int y);
void TunisiaFlag_setBorder(TunisiaFlag *flag, int thickness, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
int TunisiaFlag_render(TunisiaFlag *flag, SDL_Renderer *renderer);

#endif // TNFLAG_H
