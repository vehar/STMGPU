#include <avr/pgmspace.h>

#define MAX_SPEED 1 

// can save ROM and increase speed, but its unfair!
// use it if you know end resolution
#if MAX_SPEED
 #define TFT_W 320
 #define TFT_H 240
#else
 #define TFT_W gpuWidth()
 #define TFT_H gpuHeight()
#endif /* MAX_SPEED */

#define TEST_SAMPLE_SIZE 2000
#define TEST_SAMPLE_SCREENS 2

#define BASE_RADIUS 10

#define MIN_COLOR 32
#define MAX_COLOR 255
#define COLOR_RANGE (((MAX_COLOR + 1) - MIN_COLOR) + MIN_COLOR)
#define RND_COLOR (randNum() % COLOR_RANGE)

// once again little more cheating...
//#define RND_565COLOR(r, g, b)  (color565(r, g, b))
#define RND_565COLOR  (((RND_COLOR & 0xF8) << 8) | ((RND_COLOR & 0xFC) << 3) | (RND_COLOR >> 3))

#define RND_POSX(offset) (randNum() % (TFT_W-offset))
#define RND_POSY(offset) (randNum() % (TFT_H-offset)) 

// --------------------------------------------------------- //

const uint8_t Loremipsum[] PROGMEM = "\
Lorem ipsum dolor sit amet, consectetur adipiscing elit. \
Curabitur adipiscing ante sed nibh tincidunt feugiat. \
Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. \
Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. \
Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. \
In vestibulum purus a tortor imperdiet posuere.\n\n";

const uint8_t textSize2[] PROGMEM = "\
Text size 2\n";

const uint8_t textSize3[] PROGMEM = "\
Even bigger 3\n";

const uint8_t textSize4[] PROGMEM = "\
Seruious txt\n";


void testdrawtext(void);
void testlines(void);
void testfastlines(void);
void testdrawrects(void);
void testfillrects(void);
void testfillcircles(void);
void testroundrects(void);
void testtriangles(void);

void drawRandPixels(void);
void drawRandLines(void);
void drawRandRect(void);
void drawRandFillRect(void);
void drawRandTriangles(void);
void drawRandRoundRect(void);
void drawRandRoundFillRect(void);
void drawRandCircle(void);
void drawRandFillCircle(void);
void matrixScreen(void);

void (*pArrTestFunc[])(void) = {
    testdrawtext,
    testlines,
    testfastlines,
    //testdrawrects,
    testfillrects,
    testfillcircles,
    testroundrects,
    testtriangles,

    drawRandPixels,
    drawRandLines,
    drawRandRect,
    drawRandFillRect,
    drawRandTriangles,
    //drawRandRoundRect,
    //drawRandRoundFillRect,
    drawRandCircle,
    drawRandFillCircle,
    matrixScreen
  };

#define FUNC_TO_TEST_COUNT (sizeof(pArrTestFunc)/sizeof(pArrTestFunc[0]))
