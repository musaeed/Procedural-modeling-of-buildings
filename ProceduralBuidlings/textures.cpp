#include "textures.h"

using namespace std;

Textures* Textures::instance = NULL;

Textures::Textures()
{

}

Textures* Textures::getInstance(){

    if(instance == NULL){
        instance = new Textures;
    }

    return instance;
}

GLuint Textures::LoadTexture( const char * filename, int width, int height )
{

    GLuint texture;

    unsigned char * data;

    FILE * file;

    file = fopen( filename, "rb" );

    if ( file == NULL ) return 0;
    data = (unsigned char *)malloc( width * height * 3 );
    //int size = fseek(file,);
    fread( data, width * height * 3, 1, file );
    fclose( file );

    for(int i = 0; i < width * height ; ++i)
    {
        int index = i*3;
        unsigned char B,R;
        B = data[index];
        R = data[index+2];

        data[index] = R;
        data[index+2] = B;

    }

    glPixelStorei(GL_UNPACK_ALIGNMENT,1);
    glGenTextures( 1, &texture );

    glBindTexture( GL_TEXTURE_2D, texture );

    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );

    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR );


    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );

    gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );

    free( data );

    return texture;
}


void Textures::loadTextures(){

   /*cout << "Please download the textures from this link: http://www.filedropper.com/textures " << endl;
    cout << "Set the path of the textures in the commented block of textures.cpp file" << endl;
    cout << "Then you can use Qtcreator to build and run the project" << endl;
    cout << "Thank you!!!" << endl << endl;
    cout << "Please ask me if you run into any issues while running the program" << endl;
    cout << endl;

    QCoreApplication::quit();*/

   textures.push_back(LoadTexture("/home/muhammad/Desktop/textures/tiles_textures_05.bmp", 3112, 2066));
    textures.push_back(LoadTexture("/home/muhammad/Desktop/textures/door_converted.bmp", 436, 520));
    textures.push_back(LoadTexture("/home/muhammad/Desktop/textures/brick.bmp", 2592, 1854));
    textures.push_back(LoadTexture("/home/muhammad/Desktop/textures/window.bmp", 256, 256));
    textures.push_back(LoadTexture("/home/muhammad/Desktop/textures/roof.bmp", 1460, 1460));
    textures.push_back(LoadTexture("/home/muhammad/Desktop/textures/logo_uni-bonn.bmp", 589, 359));
    textures.push_back(LoadTexture("/home/muhammad/Desktop/textures/pillar.bmp", 135, 221));
    textures.push_back(LoadTexture("/home/muhammad/Desktop/textures/darkwall.bmp", 529, 622));


}

vector<unsigned int> Textures::getTextures(){

    return textures;
}
