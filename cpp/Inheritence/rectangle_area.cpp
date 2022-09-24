#include <iostream>

using namespace std;
class Rectangle{
    protected:
        int width=0, height=0;
    public:
        void read_input(){
            cin >> width >> height;
        }
        
        void display(){
            cout << width << " " << height << "\n";
        }
};

class RectangleArea: public Rectangle{
    public:
        void display(){
           cout << this->width * this->height; 
        }
};


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}