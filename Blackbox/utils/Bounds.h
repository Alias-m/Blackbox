#ifndef BLACKBOX_BOUNDS_H
#define BLACKBOX_BOUNDS_H
class Bounds
{
    protected:
    private:
        bool editable;
        int x;
        int y;
        int width;
        int height;
    public:
        Bounds(const int x, const int y, const int w, const int h);
        inline void setEditable(bool b) {editable = b;}
        inline int getX() {return x;}
        inline int getY() {return y;}
        inline int getWidth() {return width;}
        inline int getHeight() {return height;}
        inline void setX(int v) {if(editable) x = v;}
        inline void setY(int v){if(editable) y = v;}
        inline void setWidth(int v){if(editable) width = v;}
        inline void setHeight(int v){if(editable) height = v;}
};
#endif // BLACKBOX_BOUNDS_H
