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

#ifndef UTILS_H
#define UTILS_H

#include <SDL.h>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

int aafilledEllipseColor(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint32 color);
int aafilledEllipseRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

int aafilledCircleColor(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rad, Uint32 color);
int aafilledCircleRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

int aafilledPolygonColor(SDL_Renderer * renderer, const Sint16 *vx, const Sint16 *vy, int n, Uint32 color);
int aafilledPolygonRGBA(SDL_Renderer * renderer, const Sint16 *vx, const Sint16 *vy, int n, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

#define NORMAL_FIVE_POINT_STAR_INNER_RAD(OUTER_RAD) (OUTER_RAD * 0.382)
#define PUDGY_FIVE_POINT_STAR_INNER_RAD(OUTER_RAD)  (OUTER_RAD * 0.5)

void fivePointStar(int x, int y, float outerRad, float innerRad, float rotation, Sint16 *vx, Sint16 *vy);

int saveScreenshot(SDL_Renderer *renderer, int w, int h, const char *filename);
int saveScreenshotRect(SDL_Renderer *renderer, const SDL_Rect *rect, const char *filename);

#endif // UTILS_H
