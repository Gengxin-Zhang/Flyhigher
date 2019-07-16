#ifndef LITTLESTARCONFIGURATION_H
#define LITTLESTARCONFIGURATION_H
class LittleStarConfiguration {
    public:
        LittleStarConfiguration(const int power, const double radius, const int collectTick);

        ~LittleStarConfiguration();

        int getPower() const;

        double getRadius() const;

        int getCollectTick() const;
    private:
        int power;
        double radius;
        int collectTick;
};

#endif // LITTLESTARCONFIGURATION_H
