#include <iostream>

class Bottle {
private:
    double vol;
    double fluid_volume;

public:
    Bottle(double v) : vol(v), fluid_volume(0) {}

    double volume() const { return fluid_volume; }

    double fill(double f_vol);

    double pour(double p_vol);
};

double Bottle::fill(double f_vol) {
    double sum = fluid_volume + f_vol;
    if (sum <= vol) {
        fluid_volume += f_vol;
        return f_vol;
    } else {
        double filled = vol - fluid_volume;
        fluid_volume = vol;
        return filled;
    }
}

double Bottle::pour(double p_vol) {
    if (p_vol <= fluid_volume) {
        fluid_volume -= p_vol;
        return p_vol;
    } else {
        double poured = fluid_volume;
        fluid_volume = 0;
        return poured;
    }
}

int main() {
    Bottle bottle(4.5);
    std::cout << bottle.volume() << " ";
    std::cout << bottle.fill(3.5) << " ";
    std::cout << bottle.volume() << " ";
    std::cout << bottle.pour(5.5) << " ";
    std::cout << bottle.volume() << std::endl;
    return 0;
}
