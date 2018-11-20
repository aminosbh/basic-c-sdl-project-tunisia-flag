/*
 * Copyright (c) 2018 Amine Ben Hassouna <amine.benhassouna@gmail.com>
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

#include "utils.h"

#include <math.h>
#include <SDL2/SDL2_gfxPrimitives.h>

int aafilledEllipseColor(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint32 color)
{
    Uint8 *c = (Uint8 *)&color;
    return aafilledEllipseRGBA(renderer, x, y, rx, ry, c[0], c[1], c[2], c[3]);
}

int aafilledEllipseRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    if(!aaellipseRGBA(renderer, x, y, rx + 1, ry, r, g, b, a))
        return filledEllipseRGBA(renderer, x, y, rx, ry, r, g, b, a);
    return -1;
}

int aafilledCircleColor(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rad, Uint32 color)
{
    Uint8 *c = (Uint8 *)&color;
    return aafilledCircleRGBA(renderer, x, y, rad, c[0], c[1], c[2], c[3]);
}

int aafilledCircleRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    return aafilledEllipseRGBA(renderer, x, y, rad, rad, r, g, b, a);
}

int aafilledPolygonColor(SDL_Renderer * renderer, const Sint16 *vx, const Sint16 *vy, int n, Uint32 color)
{
    Uint8 *c = (Uint8 *)&color;
    return aafilledPolygonRGBA(renderer, vx, vy, n, c[0], c[1], c[2], c[3]);
}

int aafilledPolygonRGBA(SDL_Renderer * renderer, const Sint16 *vx, const Sint16 *vy, int n, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    if(!aapolygonRGBA(renderer, vx, vy, n, r, g, b, a))
        return filledPolygonRGBA(renderer, vx, vy, n, r, g, b, a);
    return -1;
}

void fivePointStar(int x, int y, float outerRad, float innerRad, float rotation, Sint16 *vx, Sint16 *vy)
{
    float alpha = (2 * M_PI) / 10;

    for(int i = 0; i < 10; i++)
    {
        float omega = alpha * i + rotation;

        float r = innerRad;
        if(i % 2)
            r = outerRad;

        vx[i] = (int) ((r * sin(omega)) + x);
        vy[i] = (int) ((r * cos(omega)) + y);
    }
}

int saveScreenshot(SDL_Renderer *renderer, int w, int h, const char *filename)
{
    SDL_Rect rect = { 0, 0, w, h };
    return saveScreenshotRect(renderer, &rect, filename);
}

int saveScreenshotRect(SDL_Renderer *renderer, const SDL_Rect *rect, const char *filename)
{
    const Uint32 format = SDL_PIXELFORMAT_RGBA32;

    if(!rect)
    {
        fprintf(stderr, "%s requires non null rect argument\n", __FUNCTION__);
        return -1;
    }

    SDL_Surface *surface = SDL_CreateRGBSurfaceWithFormat(0, rect->w, rect->h, 32, format);
    SDL_RenderReadPixels(renderer, rect, format, surface->pixels, surface->pitch);
    SDL_SaveBMP(surface, filename);
    SDL_FreeSurface(surface);

    return 0;
}
