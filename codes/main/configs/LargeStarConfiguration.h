#ifndef LARGESTARCONFIGURATION_H
#define LARGESTARCONFIGURATION_H

class LargeStarConfiguration {
    public:
        LargeStarConfiguration(const int power, const double radius, const int collectTick);

        ~LargeStarConfiguration();

        int getPower() const;

        double getRadius() const;

        int getCollectTick() const;
    private:
        int power;
        double radius;
        int collectTick;
};

#endif // LARGESTARCONFIGURATION_H

