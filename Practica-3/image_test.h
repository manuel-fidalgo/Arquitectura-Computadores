#ifndef IMAGE_TEST_H
#define IMAGE_TEST_H
#include <iostream>;
#include <string>
#include <QImage>
#include <QColor>
#include <QDir>
#include "chronometer.h"

class Image_test
{
private:
    int nTest;
    Chronometer * chrono;
public:
    Image_test();
    double init(QImage q);
    int getNTest();
    void toGreyScale(QImage * q);
};

#endif // IMAGE_TEST_H
