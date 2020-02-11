//
//  Projectile.hpp
//  ProjectileMotion
//
//  Created by Nicholas Cooke on 7/15/17.
//  Copyright © 2017 Nicholas Cooke. All rights reserved.
//

#ifndef Projectile_hpp
#define Projectile_hpp

#include <stdio.h>
#include <string>

using namespace std;


class Projectile
{
private:
    //double theta;
    //double vi;
    double vxi; //Velocity x initial
    double vyi; // velocity y initial
    int sigfig;
    int sfx, sfy; // holds sig figs for each input
    
public:
    Projectile();
    // basic setter an getter functions
    void setVxi(double q) { vxi = q; }
    void setVyi(double q) { vyi = q; }
    double getVxi() const { return vxi; }
    double getVyi() const { return vyi; }
    
    // calculation functions
    double calcTime() const;
    double calcMaxHeight() const;
    double calcDisplacement() const;
    
    //input exceptions and validation functions
    void inputVet(char [], int);
    
    class LeadingZero{};
    class HasAlpha{};
    class BadSymbol{};
    class Pcount{};
    
    //basic setter functions for sig figs. watch out for a better way to bundle
    void setSigFigX (int q) { sfx = q; }
    void setSigFigY (int q) { sfy = q; }
    void setSigFig ();
    int getSigFigX () const { return sfx; }
    int getSigFigY () const { return sfy; }
    int getSigFig () const { return sigfig; }
    
   
  };
#endif /* Projectile_hpp */
