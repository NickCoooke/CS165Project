//  main.cpp
//  ProjectileMotion
//
//  Created by Nicholas Cooke on 7/15/17.
//

/* 
 * This was my first attempt at creating a project using c++ objects and colaborating
 * with a partner - NickCoooke
 *
 * This is a program which accepts initial velocity for an ideal projectile and calculate
 * the distabce the it will travel. This program validates user inputs, calculates propper
 * significant figures, and outputs the number of input and output significant figures.
 */

#include <iostream>
#include "projectile.h"
#include <iomanip>
#include <cmath>
#include <cctype>
#include "stackchar.h"
#include <cstdlib>

using namespace std;

int sigfigs(char[]);
bool hasDot(char *);
void displayCString(char []);

void getValue(Projectile&, const char);
void input(Projectile&);


//User interface for the program
int main ()
{
    Projectile object;
    //enter user input section.
    input(object);

   //enter output section. 
    cout << setprecision(object.getSigFig()) << showpoint;
    //cout.precision(object.getSigFig());
    cout << "**********Results**********";
    cout << endl << "Displacement: "<< object.calcDisplacement()
        << endl << "Max height: " <<object.calcMaxHeight() << endl
        << "SIGFIGS: " << object.getSigFig() << endl;
}

//Calls functions to get user input.
void input (Projectile& object)
{
    getValue(object, 'X');
    getValue(object, 'Y');
    object.setSigFig();
}



//Prompts user for input until input is valid. Processes and stores input
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
    int passer = sigfigs(val);
    
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



//calculates significant figures for valid input.
int sigfigs(char value[])
{
    
    int sigFIG = 0, count = 0;
   
    
    //If the input has a "." the sigfigs =...
    if(hasDot(value))
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
    } else {
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



//helper function for sigfig(...). returns true if array contains a '.'
bool hasDot(char array[])
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


//displays contents of an array
void displayCString(char array[])
{
    int i = 0;
    while (array[i] != '\0')
    {
        cout << array[i];
        i++;
    }

}


/*
 * Ideas for future developement
 *  -accept mass in kg and calculate force at launch and landing impact
 *  -allow user to change the end height of the object
 *  -incporperate bouncing and colision physics at the end
 *  -allow user to specify a point realitive to launch opistion that exerts a consistent force 
 *      on projectile
 *  -incporperate with openGL and create visual of projetile 
 */  
