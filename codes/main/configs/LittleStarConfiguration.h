#ifndef LITTLESTARCONFIGURATION_H
#define LITTLESTARCONFIGURATION_H
class LittleStarConfiguration {
    public:
        LittleStarConfiguration(const int power, const double radius);

        ~LittleStarConfiguration();

        int getPower() const;

        double getRadius() const;

    private:
        int power;
        double radius;
};

#endif // LITTLESTARCONFIGURATION_H
