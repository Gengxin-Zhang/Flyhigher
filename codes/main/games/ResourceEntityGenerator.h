#ifndef RESOURCEENTITYGENERATOR_H
#define RESOURCEENTITYGENERATOR_H


class ResourceEntityGenerator
{
public:
    ResourceEntityGenerator();
    void generate(const int nowResourceEntityNumber);
private:
    void generateLittle();
    void generateLarge();
};

#endif // RESOURCEENTITYGENERATOR_H
