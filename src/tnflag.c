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

#include "tnflag.h"

void TunisiaFlag_init(TunisiaFlag *flag, int length, int x, int y)
{
    // Flag dimensions
    flag->rect.w = length;
    flag->rect.h = TN_FLAG_WIDTH(flag->rect.w);

    // Align center
    flag->rect.x = x - flag->rect.w / 2;
    flag->rect.y = y - flag->rect.h / 2;

    // No border
    flag->border.w = flag->border.h = flag->border.x = flag->border.y = 0;

    // Circle dimensions
    flag->circle.x = x;
    flag->circle.y = y;
    flag->circle.rad = TN_FLAG_CIRCLE_RAD(flag->rect.w);

    // Crescent dimensions
    flag->crescent.outerCircle.x = x;
    flag->crescent.outerCircle.y = y;
    flag->crescent.outerCircle.rad = TN_FLAG_CRESCENT_OUTER_RAD(flag->rect.w);

    flag->crescent.innerCircle.x = x + TN_FLAG_STAR_X_PADDING(flag->rect.w);
    flag->crescent.innerCircle.y = y;
    flag->crescent.innerCircle.rad = TN_FLAG_CRESCENT_INNER_RAD(flag->rect.w);

    // Star dimensions
    float radius = TN_FLAG_STAR_RAD(flag->rect.w);
    float rotation = TN_FLAG_STAR_ROTATION * M_PI / 180;

    fivePointStar(x + TN_FLAG_STAR_X_PADDING(flag->rect.w),
                  y,
                  radius,
                  NORMAL_FIVE_POINT_STAR_INNER_RAD(radius),
                  rotation,
                  flag->star.vx,
                  flag->star.vy);
}

void TunisiaFlag_setBorder(TunisiaFlag *flag, int thickness, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    flag->borderColor.r = r;
    flag->borderColor.g = g;
    flag->borderColor.b = b;
    flag->borderColor.a = a;

    flag->border.w = flag->rect.w + thickness * 2;
    flag->border.h = flag->rect.h + thickness * 2;

    flag->border.x = flag->rect.x - thickness;
    flag->border.y = flag->rect.y - thickness;
}

int TunisiaFlag_render(TunisiaFlag *flag, SDL_Renderer *renderer)
{
    if(flag->border.w != 0 && flag->border.h != 0)
    {
        // Set renderer color to draw the flag border
        SDL_SetRenderDrawColor(renderer,
                               flag->borderColor.r,
                               flag->borderColor.g,
                               flag->borderColor.b,
                               flag->borderColor.a);

        // Draw flag border
        SDL_RenderFillRect(renderer, &flag->border);
    }

    // Set renderer color to draw the flag rect
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x0, 0x0, 0xFF);

    // Draw flag rect
    SDL_RenderFillRect(renderer, &flag->rect);

    // Draw circle
    aafilledCircleRGBA(renderer, flag->circle.x, flag->circle.y, flag->circle.rad, 0xFF, 0xFF, 0xFF, 0xFF);

    // Draw crescent
    aafilledCircleRGBA(renderer, flag->crescent.outerCircle.x, flag->crescent.outerCircle.y, flag->crescent.outerCircle.rad, 0xFF, 0x0, 0x0, 0xFF);
    aafilledCircleRGBA(renderer, flag->crescent.innerCircle.x, flag->crescent.innerCircle.y, flag->crescent.innerCircle.rad, 0xFF, 0xFF, 0xFF, 0xFF);

    // Draw star
    aafilledPolygonRGBA(renderer, flag->star.vx, flag->star.vy, 10, 0xFF, 0x0, 0x0, 0xFF);

    return 0;
}
