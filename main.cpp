//
//  main.cpp
//  ProjectileMotion
//
//  Created by Nicholas Cooke on 7/15/17.
//  Copyright © 2017 Nicholas Cooke. All rights reserved.
//

#include <iostream>
#include "Projectile.hpp"
#include <iomanip>
#include <cmath>
#include <cctype>
#include "StackChar.hpp"
#include <cstdlib>

using namespace std;

int sigfigs(char[], int);
bool hasDot(char *, int);
void displayCString(char []);

double getInput(Projectile&, const char);
void inputMenu(Projectile&);
void output(Projectile&);

int main ()
{
    Projectile object;
    //double passValue;
    
    //We have no method to account for units (can just put a message in there asking for standard units...
    //overload functions to account for height change
    
    //tasks
        //Set it up so user can imput theta and initial velocity instead of 2 initail velocities
        //set up linked list (bod = (x position, y position, t time, structure pointer)
    
    inputMenu(object);
    output(object);

    cout << endl;
}
//*******************************************************************************************************
void inputMenu (Projectile& object)
{
    double passer;
    bool red = false;
    int choice;
    while (red == false)
    {
        cout << "Enter 1 to input theta and velociy initail\n"
             << "Enter 2 to input velocity x and velocity y\n";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
            {
                
                passer = getInput(object, 'T');
                object.setTheta(passer);
                passer = getInput(object, 'V');
                object.setVi(passer);
                object.setSigFig();
                object.translate();
                cout << "Velocities x, y...\n";
                cout << object.getVxi() << ", " << object.getVyi() << endl;
                
                red = true;
                break;
            }
            case 2:
            {
                passer = getInput(object, 'X');
                object.setVxi(passer);
                passer = getInput(object, 'Y');
                object.setVyi(passer);
                object.setSigFig();
                red = true;
                break;
               
            }
            default:
            {
                cout << "Error in inputMenu";
            }
        }
 
    }
}
//*******************************************************************************************************

void output (Projectile& object)
{
    cout << setprecision(object.getSigFig()) << showpoint;
    //cout.precision(object.getSigFig());
    cout << "**************Results**************";
    cout << endl << "Displacement: "<< object.calcDisplacement()
    << endl << "Max height: " <<object.calcMaxHeight() << endl
    << "SIGFIGS used: " << object.getSigFig() << endl;

}
//*******************************************************************************************************
double getInput(Projectile& object, const char Z)
{
    long S = 16;
    char val[S];
    
    bool status = false;
    while (status == false)
    {
        status = true;
        switch (Z)
        {
            case 'X':
                cout << "Initial Velocity "<< Z <<": ";
                cin >> val;
                break;
        
            case 'Y':
                cout << "Initial Velocity "<< Z <<": ";
                cin >> val;
                break;
             
            case 'T':
                cout << "Insert theta (0 < theta <= 90): ";
                cin >> val;
                break;
             
            case 'V':
                cout << "Initial Velocity " << ": ";
                cin >> val;
                break;
                
            default:
                cout << "Switch in getInput has defualted";
                break;
        }

        S = strlen(val);
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
    double value = atof(val);
    switch (Z)
    {
        case 'X':
            object.setSigFigX(passer);
            cout << "SF" << Z << ": " << passer << endl;
            return value;
            
        case 'Y':
            object.setSigFigY(passer);
            cout << "SF" << Z << ": " << passer << endl;
            return value;
            
        case 'T':
            object.setSigFigX(passer);
            cout << "SF" << Z << ": " << passer << endl;
            return value;
            
        case 'V':
            object.setSigFigY(passer);
            cout << "SF" << Z << ": " << passer << endl;
            return value;
            
        default:
            cout << "Switch in getInput has defualted";
            break;
    }
    return -1;
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


