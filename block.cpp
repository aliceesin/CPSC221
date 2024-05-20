/**
 * @file block.cpp
 * @author Alice Sin, Andrew Xie
 *
 * Implements a rectangular image portion block for CPSC 221 PA1
 *
 * COMPLETE THE FUNCTION BODIES IN THIS FILE AND SUBMIT TO PRAIRIELEARN
 */

#include "block.h"

/**
 *  Sets the values in the data attribute, based on the w x h pixels rectangular region of sourceimg
 *  with the upper-left corner at (left, upper). The orientation of the pixels in the data vector
 *  must match with the orientation of the pixels in the PNG.
 *
 *  @param w - the width (in pixels) of the rectangular subimage region
 *  @param h - the height (in pixels) of the rectangular subimage region
 *  @param upper - the y-coordinate of the subimage region's upper-left corner
 *  @param left - the x-coordinate of the subimage regions's upper-left corner
 *  @param sourceimg - the input PNG image
 *
 *  @pre upper and left (and upper + h - 1, left + w - 1) are valid vector indices
 *  @post pixels contains sourceimg's pixel data starting from (left, upper)
 */
void Block::Build(unsigned int w, unsigned int h, unsigned int upper, unsigned int left, const PNG& sourceimg) {
    // resize vector to the subimage size
    pixels.resize(h, vector<RGBAPixel>(w));

    for (unsigned int x = left; x < w; x++) {
        for (unsigned int y = upper; y < h; y++) {
            RGBAPixel* pixel = sourceimg.getPixel(x, y);
            pixels[y][x] = *pixel;
        }
    }
}

/**
 *  Writes the pixel color data into the target PNG, starting from (left, upper)
 *
 *  @pre block's dimensions are even (multiples of 2)
 *  @pre upper, left are valid image indices
 *  @pre the rectangular region beginning at (left, upper) can completely receive all of the data attribute's color
 *  @post target PNG's subimage region has been filled with data attribute's pixel data
 *  @param scale - integer multiplier for dimensions. 0 = scale by 0.5.
 *                 For 0.5 scale, use an appropriate average color for each pixel.
 *                 For 1 and larger scale, scale each pixel using the original color with no blending.
 */
void Block::Render(unsigned int scale, unsigned int upper, unsigned int left, PNG& targetimg) const {
    // COMPLETE YOUR IMPLEMENTATION BELOW
    if (scale == 0) {
        unsigned int scaledHeight = GetHeight() / 2;
        unsigned int scaledWidth = GetWidth() / 2;

        for (unsigned int x = 0; x < scaledWidth; x++) {
            for (unsigned int y = 0; y < scaledHeight; y++) {
                unsigned int r = 0, g = 0, b = 0, a = 0;
                for (unsigned int dx = 0; dx < 2; dx++) {
                    for (unsigned int dy = 0; dy < 2; dy++) {
                        RGBAPixel pixel = pixels[2 * y + dy][2 * x + dx];
                        r += pixel.r;
                        g += pixel.g;
                        b += pixel.b;
                    }
                }

                r /= 4;
                g /= 4;
                b /= 4;
                
                RGBAPixel* p1 = targetimg.getPixel(x + left, y + upper);
                // p1 = new RGBAPixel(pixels[y][x]);
                p1->r = r;
                p1->g = g;
                p1->b = b;
                
            }
            
        }


    } else {
        
        for (unsigned int x = 0; x < GetWidth(); x++) {
            for (unsigned int y = 0; y < GetHeight(); y++) {
                RGBAPixel pixel = pixels[y][x];
                for (unsigned int dx = 0; dx < scale; dx++) {
                    for (unsigned int dy = 0; dy < scale; dy++) {
                        RGBAPixel* p1 = targetimg.getPixel(left + x * scale + dx, upper + y * scale + dy);
                        *p1 = pixel;
                    }
                }
            }
        }


    }
	
}

/**
 *  Mirror this block's pixel data horizontally (along a vertical axis)
 *
 *  @post pixel data in this Block has been mirrored horizontally
 */
void Block::FlipHorizontal() {
    // COMPLETE YOUR IMPLEMENTATION BELOW
    for (unsigned int y = 0; y < GetHeight(); y++) {
        unsigned int width = GetWidth();
        for (unsigned int x = 0; x < width / 2; x++) {
            std::swap(pixels[y][x], pixels[y][width - x - 1]);
            
        }
    }
}

/**
 *  Returns the width (in pixels) of this Block
 *
 *  @return rectangular Block's width
 */
unsigned int Block::GetWidth() const {
    // REPLACE THE LINE BELOW WITH YOUR IMPLEMENTATION
    if (!pixels.empty()) {
        return pixels[0].size();
    } else {
        return 0;
    }
}

/**
 *  Returns the height (in pixels) of this Block
 *
 *  @return rectangular Block's height
 */
unsigned int Block::GetHeight() const {
    // REPLACE THE LINE BELOW WITH YOUR IMPLEMENTATION
    return pixels.size();
}