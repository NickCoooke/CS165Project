//
//  main.cpp
//  ProjectileMotion
//
//  Created by Nicholas Cooke on 7/15/17.
//  Copyright © 2017 Nicholas Cooke. All rights reserved.
//

//MAIN USER INTERFACE? 
#include <iostream>
#include "projectile.h"
#include <iomanip>
#include <cmath>
#include <cctype>
#include "stackchar.h"
#include <cstdlib>

using namespace std;

int sigfigs(char[], int);
bool hasDot(char *, int);
void displayCString(char []);

void getValue(Projectile&, const char);
void input(Projectile&);

int main ()
{
    Projectile object;
    //double passValue;
    
    //We have no method to account for units (can just put a message in there asking for standard units...
    //overload functions to account for height change
    
    //tasks
        //Set it up so user can imput theta and initial velocity instead of 2 initail velocities
        //Set up sigfigs
        //set up data recording
        //set up linked list (bod = (x position, y position, t time, structure pointer)
 
    //incase we want to graph later on
// Imput Section
    
    input(object);


// Output Section
    cout << setprecision(object.getSigFig()) << showpoint;
    //cout.precision(object.getSigFig());
    cout << "**********Results**********";
    cout << endl << "Displacement: "<< object.calcDisplacement()
        << endl << "Max height: " <<object.calcMaxHeight() << endl
        << "SIGFIGS: " << object.getSigFig() << endl;
    
    //cout << "Sig Figs... \nX: " << object.getSigFigX() << endl
    //    << "Y: " << object.getSigFigY() << endl << "Used: " << object.getSigFig() << endl ;
    

    
    //implementing sig figs cout.percision(x) where x = the number of sig figs
    //c-string case conversion 569

    cout << endl;
}
//*******************************************************************************************************
void input (Projectile& object)
{
    getValue(object, 'X');
    getValue(object, 'Y');
    object.setSigFig();
}
void getValue(Projectile& object, const char Z)
{
    int S = 16;
    char val[S];
    
    bool status = false;
    while (status == false)
    {
        status = true;
        cout << "Initail Velocity "<< Z <<": ";
        cin >> val;
        
        try
        {
            object.inputVet(val, S);
        }
        catch(Projectile::LeadingZero)
        {
            cout << "Leading Zero CAUGHT " << endl;
            status = false;
        }
        
        catch(Projectile::HasAlpha)
        {
            cout << "Contains alphabet character" << endl;
            status = false;
        }
        
        catch(Projectile::BadSymbol) //catching all symbols
        {
            cout << "Contains impropper symbol" << endl;
            status = false;
        }
        catch (Projectile::Pcount)
        {
            cout << "Contains impropper period use" << endl;
            status = false;
        }
    
    }
    int passer = sigfigs(val, S);
    
   // cout << fixed;

    double value = atof(val);
    if (Z == 'X')
    {
        object.setVxi(value);
        object.setSigFigX(passer);
        cout << "SF" << Z << ": " << passer << endl;

    }
    if (Z == 'Y')
    {
        object.setVyi(value);
        object.setSigFigY(passer);
        cout << "SF" << Z << ": " << passer << endl;
    }
    
    
}
//*******************************************************************************************************
int sigfigs(char value[], int S)
{
    
    int sigFIG = 0, count = 0;
   
    
    //If the input has a "." the sigfigs =...
    if(hasDot(value, S))
    {
       // cout << "Dot found.";
        while(value[count] != '\0')
        {
            if(isdigit(value[count]))
            {
                sigFIG++;
            }
            count++;
        }
    }
    else
    {
     //   cout << endl << "No dot found" << endl;
        
        
        DynCharStack stac;
        count = 0;
        //enter c string into stack
        //pop values off and check if they are zeros
        //if they are zeros continue to pop
        //else stop, count digits and then apply those digits to sigFIG
        //stack it
        while (value[count] != '\0')
        {
            stac.push(value[count]);
            count++;
        }
        //pop it
        
        // pop values off and check to see if they are zero (perhaps another while loop
        char catcher = 0;
        bool run = true;
        while (run == true && stac.isEmpty() == false)
        {
            run = false;
            stac.pop(catcher);
            
          //  cout << "catcher: " << catcher << endl;
            if (catcher == '0')
            {
                run = true;
            }
            else
            {
                sigFIG++;
                run = false;
                sigFIG += stac.stackSize();
            }
        }
    }
    return sigFIG;
}
//*******************************************************************************************************
bool hasDot(char array[], const int S)
{
    int i = 0;
    bool status = false;
    
    while(array[i] != '\0')
    {
        if(array[i] == '.')
            status = true;
        i++;
    }
    return status;
}
//*******************************************************************************************************
void displayCString(char array[])
{
    int i = 0;
    while (array[i] != '\0')
    {
        cout << array[i];
        i++;
    }

}
//*******************************************************************************************************


