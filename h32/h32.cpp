/**
 *  @author Put your name here
 *  @date Put the date here
 *  @file h32.cpp
 */
#include <string>
#include <iostream>
using namespace std;

string STUDENT = "WHO AM I?"; // Add your Canvas/occ-email ID


#include "h32.h"

// Add your code here

const Pixel& Image::operator[](unsigned idx) const
{
    return m_pixels.at(idx);
}

Pixel& Image::operator[](unsigned idx)
{
    return m_pixels.at(idx);
}

void Image::translate(int dx, int dy)
{
    Pixel BLACK{0, 0, 0, 255};
    if (dx < 0) dx = width() - abs(dx) % width();
    else        dx = dx % width();

    Image& img = *this; // this image
    for (unsigned row = 0; row < height(); ++row)
    {
        for (int i = 0; i < dx; i++)
        {
            int last = width() - 1;     // position of last column
            int r = row * width();
            auto temp = img[r + last];
            for (int j = last; j > 0; --j)
                img[r + j] = img[r + (j - 1)];
            img[r] = temp;
        }
    }

    if (dy < 0) dy = height() - abs(dy) % height();
    else        dy = dy % height();

    unsigned last = width() * (height() - 1);
    for (int i = 0; i < dy; ++i)            // repeat dy times
    {
        for (unsigned col = 0; col < width(); col++) // every column
        {
            auto temp = img[last + col];
            for (unsigned row = height() - 1; row > 0; row--)
            {
                img[row * width() + col] = img[(row - 1) * width() + col];
            }
            img[col] = temp;
        }
    }

    // Pixel* pixels = &m_pixels[0];
    // // Adjust dx
    // if (dx < 0) dx = width() - abs(dx) % width();
    // else        dx = dx % width();


    // for (unsigned row = 0; row < height(); row++)
    // {
    //     // Address of first pixel in row is pixels + (row * width)
    //     auto r = pixels + (row * width());
    //     for (int i = 0; i < dx; i++)    // do this dx times
    //     {
    //         int last = width() - 1;       // position of last element in row
    //         auto temp = r[last];        // save the last one
    //         for (int j = last; j > 0; j--)  // move backwards from last to front
    //             r[j] = r[j - 1];            // copy each element from left->right
    //         r[0] = temp;                // add last element at front
    //     }
    // }

    // if (dy < 0) dy = height() - abs(dy) % height();
    // else        dy = dy % height();

    // // Calculate the address of the last row
    // auto lastRow = pixels + width() * (height() - 1);

    // for (int i = 0; i < dy; i++)            // do this dy times
    // {
    //     for (unsigned col = 0; col < width(); col++)   // visit every column
    //     {
    //         // Then visit every row in that column
    //         auto temp = lastRow[col];   // save the last pixel in the column

    //         for (int row = height() - 1; row > 0; row--)
    //         {
    //             // Copy the pixel at the row above into the current pixel
    //             pixels[(row * width()) + col] = pixels[(row - 1) * width() + col];
    //         }

    //         pixels[col] = temp;         // copy temp into the top pixel
    //     }
    // }
}

/////////////// STUDENT TESTING ////////////////////

int run()
{
    // Just some samples for class
    cout << "Try some code on your own" << endl;

    return 0;
}