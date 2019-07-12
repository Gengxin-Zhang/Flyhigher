/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Color.h"

/**
 * Color implementation
 */

int Color::getAlpha() const{
    return alpha;
}

int Color::getR() const{
    return r;
}

int Color::getG() const{
    return g;
}

int Color::getB() const{
    return b;
}

Color::Color(int alpha, int r, int g, int b) {
    if(alpha < 0){
        this->alpha = 0;
    }else if(alpha > 100){
        this->alpha = 100;
    }else{
        this->alpha  = alpha;
    }
    if(r < 0){
        this->r = 0;
    }else if(r > 100){
        this->r = 100;
    }else{
        this->r  = r;
    }
    if(g < 0){
        this->g = 0;
    }else if(g > 100){
        this->g = 100;
    }else{
        this->g  = g;
    }
    if(b < 0){
        this->b = 0;
    }else if(b > 100){
        this->b = 100;
    }else{
        this->b  = b;
    }
}

Color::Color(const Color& color) {
    alpha = color.alpha;
    r = color.r;
    g = color.g;
    b = color.b;
}

Color::~Color() {

}