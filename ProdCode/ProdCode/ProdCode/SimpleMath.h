#pragma once

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

class DLLEXPORT SimpleMath
{
public:
    SimpleMath();
    ~SimpleMath();

    float add(float x, float y);
    int divide(int a, int b);
};

