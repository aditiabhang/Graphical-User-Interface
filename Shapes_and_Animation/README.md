### Shapes & Animation with opengl pop-window : 

- This program is an extension for the Software Radio QT.
- It has an extra Tetrahedron 3D animation program merged using Dock Widget. 
- Implemented a Tetrahedron application presents a 3D tetrahedron, with each face drawn using a different color. 
        
        
    - In the tetrahedron program, the user can rotate the tetrahedron by pressing the mouse button and moving it. 
    - Moreover, The user can set the color of a tetrahedron face by double-clicking it and choosing a color from the QColorDialog that pops up.
- n-gon function is used to draw a circle and other polygonal shapes. Whereas, for drawing a cube I have made use of glVertex3f(x, y, z). 
- For adding colors to all shapes, I have used glColor3f(x, y, z) function.

### New features:

- 3D Tetrahedron shape on separate dock.
- Animation on shape using mouse activity.
- QColorDialog that pops up to select and change color of the side of shape.
- Gradient color on line.
- Heptagon and Octagon (2 shapes extra than expected)

----------------------------------------------
### The folder contains (+ other compiled files): 


1. Shapes Files:
    
    (1) globj.cpp (Shapes cpp file)

    (2) globj.h (Shapes header file)


2. Radio Files:

    (1) window.cpp (Radio cpp file)

    (2) window.h (Radio header file)

3. Tetrahedron Files:

    (1) tetrahedron.cpp

    (2) tetrahedron.h

4. Output Captures:
    
    (1) Shapes_&_Animation.mov (Video capture)

----------------------------------------------
### Commands used to run:

    >> sudo qmake -project
        -> Added 'QT += opengl' in the .pro file
    >> sudo qmake
    >> sudo make
    >> sudo ./Shapes_&_Animation

----------------------------------------------
5. Screenshot:

> Shapes: 

<img width="972" alt="shapes" src="https://user-images.githubusercontent.com/51350594/85622968-4673d000-b62d-11ea-82c4-e138aaf9ae01.png">


> UI
![Shapes_ _Animation](https://user-images.githubusercontent.com/51350594/85618013-c7c76480-b625-11ea-9934-67c78d67a429.png)

----------------------------------------------

6. Small Demo: 

![ezgif com-crop](https://user-images.githubusercontent.com/51350594/85618302-31477300-b626-11ea-9296-b736f912dec7.gif)