#ifndef LARGESTARCONFIGURATION_H
#define LARGESTARCONFIGURATION_H

class LargeStarConfiguration {
    public:
        LargeStarConfiguration(const int power, const double radius);

        ~LargeStarConfiguration();

        int getPower() const;

        double getRadius() const;

    private:
        int power;
        double radius;
};

#endif // LARGESTARCONFIGURATION_H

