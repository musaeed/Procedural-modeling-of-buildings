# Procedural modeling of buildings

This is an implementation of the paper Procedural modeling of buildings which can be found [here](http://peterwonka.net/Publications/pdfs/2006.SG.Mueller.ProceduralModelingOfBuildings.final.pdf). I implemented this paper as part of the computer graphics lab at the University of Bonn.
### Features
Some of the functions that I implemented from the paper are as follows:

* S
* Comp
* SubDiv
* Texture

All of the above functions and their use is well documented in the paper itself except for the *Texture* function. This fucntion specifies a texture that a certain component will take during rendering from a predefined list of textures. I also have a simple GUI made in QT for making it easier for loading new files and moving the scene around. Some of the features of the GUI are summarized below:
![GIU](https://github.com/musaeed/Procedural-modeling-of-buildings/raw/master/screenshots/gui.png)

An example of the grammar that can be used to render buildings is shown below:

``` 
start->S(10,10,10){box}
box->comp(){left|right|top|bottom|front|back}
left->subDiv("Y",2,2,2,2,2){floor1|floor2|floor3|floor4|floor5}
right->subDiv("Y",2,2,2,2,2){floor1|floor2|floor3|floor4|floor5}
front->subDiv("Y",2,2,2,2,2){floor1|floor2|floor3|floor4|floor5}
back->subDiv("Y",2,2,2,2,2){floor1|floor2|floor3|floor4|floor5}
floor1->subDiv("X",4,2,4){wall|door|wall}
floor2->subDiv("X",2,2,2,2,2){window_area1|window_area1|window_area1|window_area1|window_area1}
floor3->subDiv("X",2,2,2,2,2){window_area1|window_area1|window_area1|window_area1|window_area1}
floor4->subDiv("X",2,2,2,2,2){window_area1|window_area1|window_area1|window_area1|window_area1}
floor5->subDiv("X",2,2,2,2,2){window_area1|window_area1|window_area1|window_area1|window_area1}
window_area1->subDiv("X",0.4,1.6){wall|window}
top->texture("TOP")
wall->texture("WALL")
window->texture("WINDOW")
door->texture("DOOR")
```
The building produced using the grammar above is as follows. Please note that this is a simple example which just creates one building. Much more complex scenes can be created with many buildings in a single scene by extending the grammar. Please refer to the original paper for more details.

![building](https://github.com/musaeed/Procedural-modeling-of-buildings/raw/master/screenshots/building.png)

### Building the project

Please make sure that you have Open GL and GLUT libraries installed on your computer. They can be installed by using the following command.

```bash
sudo apt-get install freeglut3 freeglut3-dev
```

You also need QT libraries installed on your system. The instructions for installing QT can be found [here](https://wiki.qt.io/Install_Qt_5_on_Ubuntu).

After intalling all the previous libraries go into the source code folder and execure the following command.
```bash
qmake .
```

You should get a *Makefile* in your folder after this. Please use it to compile and run the program. For any questions please email me at muhammad.omar555 [at] gmail . com