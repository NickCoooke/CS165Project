# Physics Calculator: Projectile Motion

> This is my first programming project build the summer of 2017! I was in community college and really exited about physics, programming, and looking to syncronize the two. In reality, it's mainly a simple calculator with a lot of significant figure management overhead! Enjoy! 
---


### Run Locally 
```sh
#  1. Download the repository 
git [clone, fork...] https://github.com/NickCoooke/ProjectileMotion.git
# 2. Compile the Project with  
make 
# 3. run executable 
./a
# 4. (otpional) Clean directory
make clean
```

### Project Structure
**classes**:
- Projectile---- holds initail inputs of funcition
                 has member functions to get and vet input, calculate output, and format output with correct digits
- StackChar----- used in sigfig function in main. purpose is to turn input into a stack for calculating sig figs.
  FileStorage--- creates repository for data recorded with each run of the main program

- input: accepts user input as a c-string
   void input---- condenses function calls to input value into the code
   void getValue- asks for input and catches all invalid inputs thrown by Projectile::inputVet

- output:void output currently just applies significant figures and couts in scientific notation
           ----- could make it not use sceintific notation but then applying sifFigs is more complicated/ harder to show


