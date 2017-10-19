#include <iostream>

using namespace std;

class ant {
    public:
        // Constructor:
        
        ant();          // init: x,y,energy = 0, dir = '^'

        // Accessors:
        
        int GetX();     
        int GetY();
        int GetEnergy();
        char Print();
        
        // Mutator:
        
        void ChangeEnergy(int);
        
        // Methods:
        
        bool Left();
        bool Right();
        bool Forward();
        
        friend ostream &operator<<(ostream &outs, ant &rhs) {
            outs << "(" << rhs.GetX() << "," 
                 << rhs.GetY() << ") " << rhs.Print() 
                 << " " << rhs.GetEnergy();
        }
    private:
        int x,y;
        char dir;
        int energy;
};