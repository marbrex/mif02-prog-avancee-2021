/*
Using function time() of bash
with the value of repeat times 10 000 000
C++ program finishes in ~10s
*/
#include <iostream>

class Pixel {
private:
    int r,g,b;

public:
    Pixel () : r(0), g(0), b(0) {}

    int getR() const { return r; }
    int getG() const { return g; }
    int getB() const { return b; }

    void setR(int _r) { r = _r; }
    void setG(int _g) { g = _g; }
    void setB(int _b) { b = _b; }
};

class Image {
private:
    int h, w;
    Pixel** tab;

public:
    Image(int height, int width) : h(height), w(width) {
        tab = new Pixel*[h];
        for (unsigned int i = 0; i<h; ++i) {
            tab[i] = new Pixel[w];
        }
    }

    Pixel& getPixelAt(int x, int y) const {
        return tab[x][y];
    }

    void setPixelAt(int x, int y, int r, int g, int b) {
        tab[x][y].setR(r);
        tab[x][y].setG(g);
        tab[x][y].setB(b);
    }
};

int main () {

    int h = 5;
    int w = 10;

    int value = 5;
    int repeat = 0;

    Image im(h, w);

    std::cin >> repeat;

    for (unsigned int r=0; r<repeat; ++r) {

        for (unsigned int i=0; i<h; ++i) {
            for (unsigned int j=0; j<w; ++j) {
                im.setPixelAt(i, j, value, value, value);
            }
        }

        ++value;

    }


    return 0;
}