#include "image_test.h"

Image_test::Image_test(){

}
Image_test::Image_test(int OS){
    this->nTest=0;
    this->chrono = new Chronometer(OS);

}
double Image_test::init(QImage q){
    this->nTest++;
    chrono->init();
    toGreyScale(&q);
    QDir().mkdir("output");
    q.save("out.png",0,-1);
    return chrono->end();


}
int Image_test::getNTest(){
    return this->nTest;
}
void Image_test::toGreyScale(QImage *q ){
    for (int ii = 0; ii < q->width(); ii++) {
        for (int jj = 0; jj < q->height(); jj++) {
            int gray = qGray(q->pixel(ii, jj));
            q->setPixel(ii, jj, QColor(gray, gray, gray).rgb());
        }
    }
}
