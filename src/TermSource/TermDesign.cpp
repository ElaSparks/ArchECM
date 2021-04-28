#include "../../include/TermDesign.h"
/**
 * The function completely clears the contents of the terminal by flushing the
 * buffer.
 * @file
 */
void TermDesign::cleanScreen()
{
    printf("\033c");
}
/**
 * The function moves the cursor to the specified coordinate
 * @file
 * @param rows - number of rows
 * @param cols - number of column
 * @return Operation result
 */
int TermDesign::move(int rows, int cols)
{
    if (rows < 0 || cols < 0) {
        return -1;
    }
    printf("\E[%d;%dH", rows, cols);
    return 0;
}