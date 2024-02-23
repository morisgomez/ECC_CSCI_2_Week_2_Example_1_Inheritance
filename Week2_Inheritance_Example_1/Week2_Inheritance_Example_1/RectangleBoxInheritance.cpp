  double calcArea()
    {
        return length * width;
        //use direct private values bc we are still 
        //inside the constructor.
    }
    void display()
    {
        cout << "area of rec is: " << calcArea() << endl;
    }
}; //end Rectangle class.

class Box : public Rectangle //Box inherites from Rectangle class.
{
private:
    double height;

public:
    Box() //default constructor for Box.
    {
        /*
         we can also do as follows instead of line 74 bc protected private members in parent class.
         length = 0.0;
         width = 0.0;
         */
        height = 0.0;
        //we use the parent default constructor.
        Rectangle(); //brings down length and width.
    }
    //we use the parent constructor w/ 2 arguments.
    //len and width only passed down and hei is for Box.
    //here we can access parent constructor values bc in public accessor.
    Box(double len, double width, double hei):Rectangle(len, width)
    {
        height = hei;
    }
    
    //getters:
    double getHeight()
    {
        return height;
    }
    
    //setters:
    void setHeight(double h)
    {
        height = h;
    }
    
    //other functions:
    double volume()
    {
        //we are accessing the calcArea of parent class inside volume function of sub class.
        //return calcArea() * height;
        //^^this is used when members from parent are private and not
        //protected. so we cannot access directly. but can still
        //access member funnctions.
        
        //note how we dont use getters, for height members it is
        //initialized in sub class.
        return width * length * height;
        //this uses protected members from parent class.
    }
}; //end Box sub-class.

//driver for classes for most programs will be the main function.
int main()
{
    Box boxOne; //use default constructor.

    //create private members of boxOne using setters:
    boxOne.setHeight(100.3);
    boxOne.setWidth(50.2);
    boxOne.setLength(30.4);
    cout << "volume box 1: " << boxOne.volume() << endl; //should be zero.
    
    
    Box boxTwo(10, 7, 4); // l, w, h.
    cout << "volume box 2: " << boxTwo.volume() << endl; //should be 280.
    
    Rectangle recOne(2.6, 9.3); //l, 2.
    recOne.display(); //only using parent class.
    //no need for cout here bc Rectangle class has display function.
    
    //cout << width; ERROR.
    cout << "width of box 2: " << boxTwo.getWidth() << endl;
    return 0;
} //end main driver.