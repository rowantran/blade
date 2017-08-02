#pragma once

struct Vector2 {
    public:
        Vector2() : x(0), y(0) {}
        Vector2(int x, int y) : x(x), y(y) {}
        int x;
        int y;
};