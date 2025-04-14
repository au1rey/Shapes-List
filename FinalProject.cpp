/*******************
Name: Audrey Saidel
Student ID: 2589516
Email: audrey.saidel@snhu.edu
Assignment: Final Project
Title: Shapes and Inheritance
Description of File: Main in which users can create lists of shapes
******************/
#include <iostream>
#include <string>
#include <vector>
#include "Shape.h"
using namespace std;

// Function prototypes
void mainMenu(vector<Shape*>& shapes2D, vector<Shape*>& shapes3D, vector<Shape*>& allShapes);
void handle2DShapes(vector<Shape*>& shapes2D);
void handle3DShapes(vector<Shape*>& shapes3D);
void handleAllShapes(vector<Shape*>& allShapes);
void terminateProgram(vector<Shape*>& shapes2D, vector<Shape*>& shapes3D, vector<Shape*>& allShapes);
void invalidOption();
int choose2DShapes();
void add2DShape(int choice, vector<Shape*>& shape2D);
Shape* search2DShapes(vector<Shape*>& shape2D, float goalArea);
int choose3DShapes();
void add3DShape(int choice, vector<Shape*>& shape3D);
Shape* search3DShapes(vector<Shape*>& shape3D, float goalArea);
void addAllShapes(vector<Shape*>& allShapes);
void removeAllShapes(vector<Shape*>& allShapes);
void sortAllShapes(vector<Shape*>& allShapes);
bool insertSwap(Shape* s1, Shape* s2);
void displayAllShapes(vector<Shape*>& allShapes);
void scaleAllShapes(vector<Shape*>& allShapes, float scaleFactor);
void largeSmall2DShapes(vector<Shape*>& shapes2D);
void largeSmall3DShapes(vector<Shape*>& shapes3D);
Shape* searchAllShapes(vector<Shape*>& allShapes);

int main()
{
    vector<Shape*> shapes2D;
    vector<Shape*> shapes3D;
    vector<Shape*> allShapes;
    mainMenu(shapes2D, shapes3D, allShapes);
}
    
// Function definitions

//Menus
void mainMenu(vector<Shape*>& shapes2D, vector<Shape*>& shapes3D, vector<Shape*>& allShapes) //Main Menu
{
    int mainChoice = 0;

    while (true) {
        // Main Menu
        cout << "+++++++++++++++++++++++++++++++++++++\n";
        cout << "Main Menu\nSelect one:\n";
        cout << "1. 2D Shape List\n2. 3D Shape List\n3. All Shapes List\n4. Exit\n";
        cout << "+++++++++++++++++++++++++++++++++++++\n";
        cin >> mainChoice;

        switch (mainChoice) {
        case 1:
            handle2DShapes(shapes2D);
            break;
        case 2:
            handle3DShapes(shapes3D);
            break;
        case 3:
            handleAllShapes(allShapes);
            break;
        case 4:
            terminateProgram(shapes2D, shapes3D, allShapes);
            return; 
        default:
            invalidOption();
            break;
        }
    }
}
void handle2DShapes(vector<Shape*>& shapes2D) //Menu for 2D Shapes
{
    Shape* result = nullptr;
    int cShape = 0;
    int choice;
    cout << "2D Shape List Menu:\n";
    cout << "1. Add Shape\n2. Remove Shape\n3. Search for a shape\n4. Display list\n5. Sort list\n6. Scale a Shape\n7. Show largest and smallest shapes\n8. Back to main menu\n";
    cin >> choice;
    cout << endl;
  
    switch (choice) {
    case 1: //Add
        cout << "Add a 2D shape.\n";
        cShape = choose2DShapes();
        add2DShape(cShape, shapes2D);
        break;
    case 2: //Remove
        cout << "Remove a 2D shape.\n";
        removeAllShapes(shapes2D);
        break;
    case 3: //Search
        float goalArea;
        if (shapes2D.empty())
        {
            cout << "No shapes to search through\n";
        }
        else
        {
            cout << "Search for a 2D shape using area.\n";
            cout << "Enter in your goal area.\n";
            cin >> goalArea;
            cout << endl;
            result = search2DShapes(shapes2D, goalArea);
            if (result != nullptr)
            {
                cout << "Shape was found. Display:\n";
                Shape2D* shape2DResult = dynamic_cast<Shape2D*>(result);
                result->Display();
            }
            else
                cout << "Could not find shape\n";
        }
        break;
    case 4: //Display
        cout << "Display 2D shape list.\n";
        displayAllShapes(shapes2D);
        break;
    case 5: //Sort
        cout << "Sort 2D shape list.\n";
        sortAllShapes(shapes2D);
        break;
    case 6: //Scale
        float sf;
        cout << "Scale all of the shapes in the list.\n";
        cout << "Enter scale factor: \n";
        cin >> sf;
        cout << endl;
        scaleAllShapes(shapes2D, sf);
        break;
    case 7: //Large + Small
        largeSmall2DShapes(shapes2D);
        break;
    case 8:
        cout << "Returning to main menu.\n";
        return;
    default:
        invalidOption();
        break;
    }
}
void handle3DShapes(vector<Shape*>& shapes3D) //3D Shape list menu
{
    Shape* result = nullptr;
    int choose = 0;
    int choice;
    cout << "3D Shape List Menu:\n";
    cout << "1. Add Shape\n2. Remove Shape\n3. Search for a shape\n4. Display list\n5. Sort list\n6. Scale a Shape\n7. Show largest and smallest shapes\n8. Back to main menu\n";
    cin >> choice;

    switch (choice) {
    case 1: //Add
        cout << "Add a 3D shape.\n";
        choose = choose3DShapes();
        add3DShape(choose, shapes3D);
        break;
    case 2: //Remove
        cout << "Remove a 3D shape.\n";
        removeAllShapes(shapes3D);
        break;
    case 3: //Search
        float goalVol;
        if (shapes3D.empty())
        {
            cout << "No shapes to search through\n";
        }
        else
        {
            cout << "Search for a 3D shape.\n";
            cout << "Enter in your goal volume.\n";
            cin >> goalVol;
            cout << endl;
            result = search3DShapes(shapes3D, goalVol);
            if (result != nullptr)
            {
                cout << "Shape was found. Display:\n";
                Shape3D* shape3DResult = dynamic_cast<Shape3D*>(result);
                result->Display();
            }
            else
                cout << "Could not find shape\n";
        }
        return;
    case 4: //Display
        cout << "Display 3D shape list.\n";
        displayAllShapes(shapes3D);
        break;
    case 5: //Sort
        cout << "Sort 3D shape list.\n";
        sortAllShapes(shapes3D);
        break;
    case 6: //Scale
        float sf;
        cout << "Scale a 3D shape.\n";
        cout << "Enter scale factor\n";
        cin >> sf;
        cout << endl;
        scaleAllShapes(shapes3D, sf);
        break;
    case 7: //Large + Small
        largeSmall3DShapes(shapes3D);
        break;
    case 8:
        cout << "Returning to main menu.\n";
        return;
    default:
        invalidOption();
        break;
    }
}
void handleAllShapes(vector<Shape*>& allShapes) //All Shapes list menu
{
    Shape* result = nullptr;
    int choice;
    cout << "All Shape List Menu:\n";
    cout << "1. Add Shape\n2. Remove Shape\n3. Search for a shape\n4. Display list\n5. Sort list\n6. Scale a Shape\n7. Show Smallest and Largest\n8. Back to main menu\n";
    cin >> choice;

    switch (choice)
    {
    case 1: //Add
        addAllShapes(allShapes);
        break;

    case 2: //Remove
        cout << "Remove a shape.\n";
        removeAllShapes(allShapes);
        break;

    case 3: //Search
        cout << "Search for a shape.\n";
        result = searchAllShapes(allShapes);

        if (result != nullptr)
        {
            Shape2D* shape2D = dynamic_cast<Shape2D*>(result);
            if (shape2D) //if its a 2D shape
                if (shape2D) //if its a 2D shape
                {
                    cout << "Shape was found. Display:\n";
                    shape2D->Display();
                    cout << endl;
                }
            else //if its a 3D shape
            {
                Shape3D* shape3D = dynamic_cast<Shape3D*>(result);
                if (shape3D)
                {
                    cout << "Shape was found. Display:\n";
                    shape3D->Display();
                    cout << endl;
                }
            }
        }
        else
            cout << "No shape found matching the criteria.\n";
        break;

    case 4: //Display
        cout << "Display shapes\n";
        displayAllShapes(allShapes);
        break;

    case 5: //Sort
        cout << "Sort list.\n";
        sortAllShapes(allShapes);
        break;

    case 6: //Scale
        float sf;
        cout << "Scale shapes.\n";
        cout << "Enter in what you want to scale the shapes by: \n";
        cin >> sf;
        cout << endl;
        scaleAllShapes(allShapes, sf);
        break;

    case 7: //Large + Small
        int ch;
        cout << "Show largest and smallest shapes\n";
        cout << "1. 2D Shapes\n";
        cout << "2. 3D Shapes\n";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            largeSmall2DShapes(allShapes);
                break;

        case 2:
            largeSmall3DShapes(allShapes);
            break;

        default:
            invalidOption();
            break;
        }
        break;

    case 8: //Main menu
        cout << "Return to main menu.\n";
        return;

    default:
        invalidOption();
        break;
    }
}
void terminateProgram(vector<Shape*>& shapes2D, vector<Shape*>& shapes3D, vector<Shape*>& allShapes) //Terminates the program deallocates memory
{
    for (Shape* shape : allShapes) 
    {
        delete shape;
    }
    for (Shape* shape : shapes3D) 
    {
        delete shape;  
    }
    for (Shape* shape : shapes2D) 
    {
        delete shape;  
    }
    cout << "Now exiting the program... Goodbye.\n";
}
void invalidOption() //invalid option
{
    cout << "Invalid option. Try again.\n";
}

//2D List Functions
int choose2DShapes() //Menu to select a 2d shape
{
    int choice; 
    cout << "Select a 2D Shape:\n";
    cout << "1. Square\n2. Triangle\n3. Rectangle\n4. Circle\n5. Trapezoid\n6. Ellipse\n7. Sector\n";
    cin >> choice;
    return choice;
} 
void add2DShape(int choice, vector<Shape*>& shape2D) //adds a shape of users choice to the 2d shape vector
{
    float w = 0.0f;
    float h = 0.0f;
    float r = 0.0f;
    Shape* sq1 = nullptr;
    Shape* tr1 = nullptr;
    Shape* rc1 = nullptr;
    Shape* c1 = nullptr;
    Shape* tp1 = nullptr;
    Shape* e1 = nullptr;
    Shape* sc1 = nullptr;

    switch (choice)
    {
    case 1:
        float s;
        cout << "Shape to be added: Square\n";
        cout << "Enter length of the side: ";
        cin >> s;
        cout << endl;
        sq1 = new Square(s);
        cout << "Created new Square. Displaying Info:\n";
        sq1->Display();
        shape2D.push_back(sq1);
        //add to vector
        break;
    case 2:
        cout << "Shape to be added: Triangle\n";
        float b;
        float h;
        cout << "Enter length of the base: ";
        cin >> b;
        cout << endl;
        cout << "Enter length of the height: ";
        cin >> h;
        cout << endl;
        tr1 = new Triangle(b, h);
        cout << "Created new Triangle. Displaying Info:\n";
        tr1->Display();
        shape2D.push_back(tr1);
        break;
    case 3:
        cout << "Shape to be added: Rectangle\n";
        cout << "Enter length of the width: ";
        cin >> b;
        cout << endl;
        cout << "Enter length of the height: ";
        cin >> h;
        cout << endl;
        rc1 = new Rectangle(b, h);
        cout << "Created new Rectangle. Displaying Info:\n";
        rc1->Display();
        shape2D.push_back(rc1);
        break;
    case 4:
        cout << "Shape to be added: Circle\n";
        float r;
        cout << "Enter length of the radius: ";
        cin >> r;
        cout << endl;
        c1 = new Circle(r);
        cout << "Created new Circle. Displaying Info:\n";
        c1->Display();
        shape2D.push_back(c1);
        break;
    case 5:
        cout << "Shape to be added: Trapezoid\n";
        float s1;
        float s2;
        cout << "Enter length of side 1: ";
        cin >> s1;
        cout << endl;
        cout << "Enter length of side 2: ";
        cin >> s2;
        cout << endl;
        cout << "Enter length of the height: ";
        cin >> h;
        cout << endl;
        tp1 = new Trapezoid(s1, s2, h);
        cout << "Created new Trapezoid. Displaying Info:\n";
        tp1->Display();
        shape2D.push_back(tp1);
        break;
    case 6:
        cout << "Shape to be added: Ellipse\n";
        float minor;
        float major;
        cout << "Enter length of semi minor axis: ";
        cin >> minor;
        cout << endl;
        cout << "Enter length of semi major axis: ";
        cin >> major;
        cout << endl;
        e1 = new Ellipse(minor, major);
        cout << "Created new Ellipse. Displaying Info:\n";
        e1->Display();
        shape2D.push_back(e1);
        break;
    case 7:
        cout << "Shape to be added: Sector\n";
        float angle;
        cout << "Enter length of the radius: ";
        cin >> r;
        cout << endl;
        cout << "Enter the angle in degrees: ";
        cin >> angle;
        cout << endl;
        sc1 = new Sector(r, angle);
        cout << "Created new Sector. Displaying Info:\n";
        sc1->Display();
        shape2D.push_back(sc1);
        return;
    default:
        invalidOption();
        break;
    }
}
Shape* search2DShapes(vector<Shape*>& shape2D, float goalArea) //Binary searching by >= area function
{
    if (shape2D.empty())
    {
        cout << "No shapes to search through\n";
        return nullptr;
    }
    sortAllShapes(shape2D);
    int low = 0, high = shape2D.size() - 1;
    
    Shape2D* bestMatch = nullptr;

    while (low <= high) 
    {
        int mid = (high + low) / 2;
        Shape2D* shape = dynamic_cast<Shape2D*>(shape2D[mid]);
        if (shape) 
        {
            float area = shape->Area();

            if (area >= goalArea) 
            {
                bestMatch = shape;
                high = mid - 1;  
            }
            else
                low = mid + 1; 
        }
        else 
            cout << "Shape at index " << mid << " is not a 2D shape." << endl;
    }

    return bestMatch;
}
void largeSmall2DShapes(vector<Shape*>& shapes2D)  //Finds the 2D shape with the largest and smallest volumes 
{
    Shape2D* largestShape = nullptr;
    Shape2D* smallestShape = nullptr;
    float largestArea = 0.0f;
    float smallestArea = FLT_MAX; 
    if (shapes2D.empty())
    {
        cout << "No shapes to output\n";
        return;
    }
    for (Shape* shape : shapes2D) //For all shapes in shapes2D
    {
        Shape2D* shape2D = dynamic_cast<Shape2D*>(shape); //To compare areas convert to Shape2D*
        if (shape2D) 
        {
            float area = shape2D->Area();
            if (area > largestArea) 
            {
                largestArea = area;
                largestShape = shape2D;
            }
            if (area < smallestArea) 
            {
                smallestArea = area;
                smallestShape = shape2D;
            }
        }
    }
    //Results
    if (largestShape) 
    {
        cout << "Largest 2D Shape Display:\n";
        largestShape->Display();
    }
    if (smallestShape) 
    {
        cout << "Smallest 2D Shape Display:\n";
        smallestShape->Display();
    }
}
//3D List Functions
int choose3DShapes() //Allows user to choose which 3D shape they want to add
{
    int choice;
    cout << "Select a 3D Shape:\n";
    cout << "1. Triangular Pyramid\n2. Rectangular Pryramid\n3. Cylinder\n4. Sphere\n";
    cin >> choice;
    cout << endl;
    return choice;
}
void add3DShape(int choice, vector<Shape*>& shape3D) //Adds the designated shape to the shape3d vector
{
    Shape* tp = nullptr;
    Shape* rp = nullptr;
    Shape* cyl = nullptr;
    Shape* sph = nullptr;
    float w = 0.0f;
    float l = 0.0f;
    float py = 0.0f;
    float r = 0.0f;
  
    switch (choice)
    {
    case 1: //TriangularPyr
        float b;
        float h;
        cout << "+++++++++++++++++++++++++++++++++++++\n";
        cout << "Shape to be added: Triangular Pyramid\n";
        cout << "Type the base for each face:\n";
        cin >> b;
        cout << endl;
        cout << "Type the height for each face:\n";
        cin >> h;
        cout << endl;
        cout << "Type the height for the pyramid:\n";
        cin >> py;
        cout << endl;
        tp = new TriangularPyramid(b, h, py);
        shape3D.push_back(tp);
        cout << "Created new Triangular Pyramid. Displaying Info:\n";
        tp->Display();
        cout << "+++++++++++++++++++++++++++++++++++++\n";
        break;

    case 2: //RectangularPyr
        cout << "Shape to be added: Rectangular Pyramid\n";
        cout << "Type the width for the base:\n";
        cin >> w;
        cout << endl;
        cout << "Type the length for the base:\n";
        cin >> l;
        cout << endl;
        cout << "Type the height of the pyramid:\n";
        cin >> py;
        cout << endl;
        rp = new RectangularPyramid(l, w, py);
        shape3D.push_back(rp);
        cout << "Created new Rectangular Pyramid. Displaying Info:\n";
        rp->Display();
        break;

    case 3: //Cylinder
        float cy;
        float r;
        cout << "Shape to be added: Cylinder\n";
        cout << "Type the length of the radius:\n";
        cin >> r;
        cout << endl;
        cout << "Type the height of the cylinder:\n";
        cin >> cy;
        cout << endl;
        cyl = new Cylinder(r, cy);
        shape3D.push_back(cyl);
        cout << "Created new Cylinder. Displaying Info:\n";
        cyl->Display();
        break;

    case 4: //Sphere
        cout << "Shape to be added: Sphere\n";
        cout << "Type the length of the radius:\n";
        cin >> r;
        cout << endl;
        sph = new Sphere(r);
        shape3D.push_back(sph);
        cout << "Created new Sphere. Displaying Info:\n";
        sph->Display();
        break;

    default:
        invalidOption();
        break;
    }

}
Shape* search3DShapes(vector<Shape*>& shape3D, float goalVolume) //Binary search for volume thats >= user input
{
    sortAllShapes(shape3D);
    int low = 0, high = shape3D.size() - 1;
    Shape3D* bestMatch = nullptr;

    while (low <= high) 
    {
        int mid = (high + low) / 2;
        Shape3D* shape = dynamic_cast<Shape3D*>(shape3D[mid]);
        if (shape) 
        {
            float volume = shape->Volume();

            if (volume >= goalVolume) 
            {
                bestMatch = shape;
                high = mid - 1;
            }
            else
                low = mid + 1;  
        }
        else 
            cout << "Shape at index " << mid << " is not a 2D shape." << endl;
    }

    return bestMatch;
}
void largeSmall3DShapes(vector<Shape*>& shapes3D) //Finds the 3D shape with the largest and smallest volumes 
{
    Shape3D* largestShape = nullptr;
    Shape3D* smallestShape = nullptr;
    float largestVolume = 0.0f; 
    float smallestVolume = FLT_MAX; 
    if (shapes3D.empty())
    {
        cout << "No shapes to output\n";
        return;
    }
    for (Shape* shape : shapes3D) 
    {
        Shape3D* shape3D = dynamic_cast<Shape3D*>(shape);
        if (shape3D) 
        {
            float volume = shape3D->Volume();
            if (volume > largestVolume) 
            {
                largestVolume = volume;
                largestShape = shape3D;
            }
            if (volume < smallestVolume) 
            {
                smallestVolume = volume;
                smallestShape = shape3D;
            }
        }
    }

    //Results
    if (largestShape) 
    {
        cout << "Largest 3D Shape Display\n";
        largestShape->Display();
    }

    if (smallestShape) 
    {
        cout << "Smallest 3D Shape Display\n";
        smallestShape->Display();
    }
}
//All Shape List Functions
void addAllShapes(vector<Shape*>& allShapes) //Add either 2d or 3d shape
{
    int c;
    int ch;
    cout << "Add a shape.\n";
    cout << "1. 2D Shape\n2. 3D Shape\n";
    cin >> c;
    switch (c)
    {
    case 1:
        ch = choose2DShapes();
        add2DShape(ch, allShapes);
        break;
    case 2:
        ch = choose3DShapes();
        add3DShape(ch, allShapes);
        break;
    default:
        invalidOption();
        break;
    }
}
void removeAllShapes(vector<Shape*>& allShapes) //Remove shape from list
{
    int position = -1;
    if (allShapes.empty())
    {
        cout << "No shapes to remove\n";
        return;
    }
    while (true) 
    {
        cout << "Enter the position you would like to delete the shape at: ";
        cin >> position;
        if (position >= 0 && position < allShapes.size()) {
            delete allShapes.at(position);
            allShapes.erase(allShapes.begin() + position);
            cout << "Shape removed.\n";
            break;
        }
        else 
        {
            cout << "No shape to remove there. Try again.\n";
        }
    }

}
Shape* searchAllShapes(vector<Shape*>& allShapes) //Search through all shapes
{
    if (allShapes.empty())
    {
        cout << "No shapes to search through\n";
        return nullptr;
    }
    int ch = 0;
    float goal;
    sortAllShapes(allShapes);
    cout << "Search for volume or area?\n";
    cout << "1. Area (2D Shapes)\n2. Volume (3D Shapes)\n";
    cin >> ch;
    cout << endl;
    if (ch == 1)
    {
        cout << "Enter goal area: ";
        cin >> goal;
        cout << endl;
        return search2DShapes(allShapes, goal);

    }
    else if (ch == 2)
    {
        cout << "Enter goal volume: ";
        cin >> goal;
        cout << endl;
        return search3DShapes(allShapes, goal);
    }
    else
        invalidOption();
    
    return nullptr;
}
void sortAllShapes(vector<Shape*>& allShapes) //Sorts all shapes by area or volume, 2D shapes before 3D
{
    if (allShapes.empty())
    {
        cout << "No shapes to sort\n";
        return;
    }
    for (int i = 1; i < allShapes.size(); ++i) 
    {
        Shape* key = allShapes[i];
        int j = i;

        while (j > 0 && insertSwap(allShapes[j - 1], key)) //if comparison function returns true, then swap cus the prev shape is larger
        {
            allShapes[j] = allShapes[j - 1];
            --j;
        }
        allShapes[j] = key;
    }
}
bool insertSwap(Shape* s1, Shape* s2) //Checks if the shapes are 2d or 3d and size comparison
{
    Shape2D* shape2D_s1 = dynamic_cast<Shape2D*>(s1);
    Shape2D* shape2D_s2 = dynamic_cast<Shape2D*>(s2);

    //Compare area if both are 2D
    if (shape2D_s1 && shape2D_s2) 
        return *shape2D_s1 > *shape2D_s2;

    Shape3D* shape3D_s1 = dynamic_cast<Shape3D*>(s1);
    Shape3D* shape3D_s2 = dynamic_cast<Shape3D*>(s2);

    //Compare volume if both are 3D
    if (shape3D_s1 && shape3D_s2)
        return *shape3D_s1 > *shape3D_s2;

    //2D goes before 3D
    if (shape2D_s1 && shape3D_s2) 
        return true;
    //3D goes before 2D
    if (shape3D_s1 && shape2D_s2)
        return false;
}
void scaleAllShapes(vector<Shape*>& allShapes, float scaleFactor) //Scales all the shapes
{
    if (allShapes.empty())
    {
        cout << "No shapes to scale\n";
        return;
    }
    for (Shape* shape : allShapes)
    {
            shape->Scale(scaleFactor); 
    }
}
void displayAllShapes(vector<Shape*>& allShapes) //Display all shapes
{
    if (allShapes.empty())
    {
        cout << "\nNo shapes to display\n\n";
        return;
    }
    for (int i = 0; i < allShapes.size(); ++i)
    {
        cout << "Shape " << i + 1 << ":\n";
        allShapes[i]->Display();
        cout << endl;
    }
}