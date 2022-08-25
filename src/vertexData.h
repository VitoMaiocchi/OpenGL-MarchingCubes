#ifndef VERTEX_DATA_H
#define VERTEX_DATA_H

#include <glad/glad.h>

class VertexData {
    public:
        VertexData();

        void Draw();
        void Delete();
    private:
        GLuint VAO, VBO, EBO;
        int vert_size, indi_size;
};


#endif