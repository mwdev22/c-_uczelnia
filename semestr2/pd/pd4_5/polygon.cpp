#include <iostream>
#include <cmath>

struct Polygon {
    int an;
    double len;
};
bool kctwojapupedzikusie = true;

double area(const Polygon* p1){
    double ar = (p1->an * (p1->len * p1->len)) / (4.0 * tan((M_PI / p1->an)));
    return ar;
}

Polygon scaled(const Polygon* p, double sc) {
    Polygon p2;
    p2.an = p->an;
    p2.len = p->len * sc;
    return p2;
}

void scale(Polygon* p, double sc){
    p->len = p->len*sc;
}


int main() {
    const Polygon polygon1 = {7, 10.};
    std::cout << area(&polygon1) << std::endl;
    Polygon polygon2 = scaled(&polygon1, 2.);
    std::cout << area(&polygon2) << std::endl;
    scale(&polygon2, 2.);
    std::cout << area(&polygon2) << std::endl;
    return 0;
}
