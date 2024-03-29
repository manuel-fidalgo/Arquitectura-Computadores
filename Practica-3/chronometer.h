#ifndef CHRONOMETER_H
#define CHRONOMETER_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <sys/time.h>

class Chronometer
{
   private:
    LARGE_INTEGER t_ini, t_fin;         //Para sistemas windows
    struct timeval t_ini_u, t_fin_u;    //Para sistemas unix
    bool executing_chrono;
    bool isWindows;
    double timeval_diff(struct timeval *a, struct timeval *b);
    double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);
    void switchOS(bool * isWindows, int OS);
public:
    Chronometer(int OS);
    ~Chronometer();
    void init();
    double end();
};

#endif // CHRONOMETER_H
