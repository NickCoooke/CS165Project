//
//  Projectile.cpp
//  ProjectileMotion
//
//  Created by Nicholas Cooke on 7/15/17.
//  Copyright © 2017 Nicholas Cooke. All rights reserved.
//

#include "Projectile.h"
#include <cmath>
#include <cctype>
#include <iostream>

using namespace std;
Projectile::Projectile()
{
    sfx = 0;
    sfy = 0;
    sigfig = 0;
    vxi = 0;
    vyi = 0;
}

double Projectile::calcTime() const
{
    return vyi /4.9;
}
double Projectile::calcMaxHeight() const
{
    return vyi * vyi / 19.6;    //used y = 0 + vyi(t) - g/2 * t^2 to solve for
                                //where t = vyi / 9.8 (from vy = 0 so 0 = vyi -gt)
}
double Projectile::calcDisplacement() const
{
    return vxi * (vyi / 4.9); // vxi * t = displacement
}
void Projectile::inputVet(char value [], int S)
{
//Leading Zero
    if (value[0] == '0')
    {
        throw LeadingZero();
    }
    
    int pcount = 0;
    
    for (int i = 0; i < S; i++)
    {
        if (isalpha(value[i])) // CHecking for aphebet characters
            throw HasAlpha();
        
        if (ispunct(value[i])) // Contains symbols outside of '.' and ','
        {
            if (value[i] == '.')
                pcount++;
            //pcount++;
            if (!(value[i] == '.' || value[i] == ',' ))
            {
                
                throw BadSymbol();
                
            }
        
        }
        
    }
    if (pcount > 1)
        throw Pcount();
   // cout << "Punctuation count: " << pcount << endl;
}
void Projectile::setSigFig()
{
    if (sfx < sfy)
        sigfig = sfx;
    else
        sigfig = sfy;
}

