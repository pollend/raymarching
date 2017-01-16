//
// Created by michaelpollind on 1/14/17.
//

#ifndef _TEXTURE_H
#define _TEXTURE_H


#include <GL/glew.h>
class Texture {
    private:
        GLuint _textureID;
        int _width;
        int _height;
        int _widthBuffer;
        int _heightBuffer;
        GLint _resourceID;

        const char* _textureName;
    public:
        Texture(const char * path);
        Texture(unsigned int width, unsigned int height);
        ~Texture(void);

        /**
        *returns the file name of the asset
        **/
        const char* GetFilename();

        GLuint GetResourceID();

        /**
        *returns the texcoords value minus the buffer area outside of the texture area
        **/
        float GetWidthScale();

        /**
        *returns the texcoords height
        **/
        float GetHeightScale();

        /**
        *returns width to height ratio of the texture
        **/
        float WidthToHeightRatio();

        /**
        *returns height to width ratio of the texture
        **/
        float HeightToWidthRatio();

};


#endif
