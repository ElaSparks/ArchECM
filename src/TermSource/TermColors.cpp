#include "../../include/TermDesign.h"
/**
 * The function sets the color of subsequent output
characters.
 * @file TermColors.cpp
 * @param color - color of characters
 */
void TermDesign::setForegroundColor(colors color)
{
    printf("\E[3%dm", color);
}
/**
 * The function sets the background color of subsequent displayed characters
 * @file TermColors.cpp
 * @param color - color of background
 */
void TermDesign::setBackgroundColor(colors color)
{
    printf("\E[4%dm", color);
}