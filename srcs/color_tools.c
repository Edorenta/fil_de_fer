#include <iostream>
#include <stdio.h>
#include <math.h>

static  int     dmax(int x, int y)
{
    return (x > y ? x : y);
}

static  int     dmin(int x, int y)
{
    return (x > y ? y : x);
}

int     hex_R(long clr, const char *method)
{
    if (method == "RGB" || method == "ARGB")
        return (clr >> 16 & 0xFF);
    if (method == "RGBA")
        return (clr >> 24 & 0xFF);
}

int     hex_G(long clr, const char *method)
{
    if (method == "RGB" || method == "ARGB")
        return (clr >> 8 & 0xFF);
    if (method == "RGBA")
        return (clr >> 16 & 0xFF);
}

int     hex_B(long clr, const char *method)
{
    if (method == "RGB" || method == "ARGB")
        return (clr & 0xFF);
    if (method == "RGBA")
        return (clr >> 8 & 0xFF);
}

int     hex_A(long clr, const char *method)
{
    if (method == "ARGB")
        return (clr >> 24 & 0xFF);
    if (method == "RGBA")
        return (clr & 0xFF);
}

int     rgb_to_hex(int R, int G, int B)
{   
    return ((R & 0xff) << 16) | ((G & 0xff) << 8) | (B & 0xff);
}

long    rgba_to_hex(int R, int G, int B, int A)
{   
    return ((R & 0xff) << 24) | ((G & 0xff) << 16) | ((B & 0xff) << 8)
           | (A & 0xff);
}

long    argb_to_hex(int R, int G, int B, int A)
{   
    return ((A & 0xff) << 24) | ((R & 0xff) << 16) | ((G & 0xff) << 8)
           | (B & 0xff);
}

int     shade_color(int clr, int pct)
{   
    int R[2];
    int G[2];
    int B[2];
    int tmp;

    R[0] = hex_R(clr, "RGB");
    G[0] = hex_G(clr, "RGB");
    B[0] = hex_B(clr, "RGB");
    tmp = pct < 0 ? 0 : 255;
    pct = pct < 0 ? pct *-1 : pct;
    R[1] = (((tmp - R[0]) * pct) / 100) + R[0];
    G[1] = (((tmp - G[0]) * pct) / 100) + G[0];
    B[1] = (((tmp - B[0]) * pct) / 100) + B[0];
    
    return (rgb_to_hex(R[1], G[1], B[1]));
}

int     blend_color(int clr1, int clr2, int pct)
{
    int R[3];
    int G[3];
    int B[3];
    
    R[0] = dmin(hex_R(clr1, "RGB"), hex_R(clr2, "RGB"));
    G[0] = dmin(hex_G(clr1, "RGB"), hex_G(clr2, "RGB"));
    B[0] = dmin(hex_B(clr1, "RGB"), hex_B(clr2, "RGB"));
    R[1] = dmax(hex_R(clr1, "RGB"), hex_R(clr2, "RGB"));
    G[1] = dmax(hex_G(clr1, "RGB"), hex_G(clr2, "RGB"));
    B[1] = dmax(hex_B(clr1, "RGB"), hex_B(clr2, "RGB"));
    R[2] = ((R[1] - R[0]) * pct) / 100 + R[0];
    G[2] = ((G[1] - G[0]) * pct) / 100 + G[0];
    B[2] = ((B[1] - B[0]) * pct) / 100 + B[0];
    return (rgb_to_hex(R[2], G[2], B[2]));
}

int main()
{
    int color = 0x0033a1af;
    printf("Base Color: %#010x\n", color);
    printf("A: %d\n", hex_A(color, "ARGB"));
    printf("R: %d\n", hex_R(color, "ARGB"));
    printf("G: %d\n", hex_G(color, "ARGB"));
    printf("B: %d\n", hex_B(color, "ARGB"));
    color = shade_color(color, 50);
    printf("New color: %#010x\n", shade_color(color, 50));
    printf("A: %d\n", hex_A(color, "ARGB"));
    printf("R: %d\n", hex_R(color, "ARGB"));
    printf("G: %d\n", hex_G(color, "ARGB"));
    printf("B: %d\n", hex_B(color, "ARGB"));
    return 0;
}