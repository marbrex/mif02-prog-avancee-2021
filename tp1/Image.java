/*
Using function time() of bash
with the value of repeat times 10 000 000
JAVA program finishes in ~1s
*/
import java.util.Scanner;

public class Image {
    private int h, w;
    private Pixel[][] tab;

    static class Pixel {
        private int r,g,b;
    
        public Pixel() { r = g = b = 0; }
    
        public int getR() { return r; }
        public int getG() { return g; }
        public int getB() { return b; }
    
        public void setR(int _r) { r = _r; }
        public void setG(int _g) { g = _g; }
        public void setB(int _b) { b = _b; }
    }

    public Image(int height, int width) {
        h = height;
        w = width;
        tab = new Pixel[h][w];
        for (int i=0; i<h; ++i) {
            for (int j=0; j<w; ++j) {
                tab[i][j] = new Pixel();
            }
        }
    }

    public Pixel getPixelAt(int x, int y) {
        return tab[x][y];
    }

    public void setPixelAt(int x, int y, int r, int g, int b) {
        tab[x][y].setR(r);
        tab[x][y].setG(g);
        tab[x][y].setB(b);
    }

    public static void main(String[] args) {
        int h = 5;
        int w = 10;

        int value = 5;
        int repeat = 0;

        Image im = new Image(h, w);

        Scanner myObj = new Scanner(System.in);
        repeat = myObj.nextInt();

        for (int r=0; r<repeat; ++r) {

            for (int i=0; i<h; ++i) {
                for (int j=0; j<w; ++j) {
                    im.setPixelAt(i, j, value, value, value);
                }
            }

            ++value;

        }

        myObj.close();
    }

}