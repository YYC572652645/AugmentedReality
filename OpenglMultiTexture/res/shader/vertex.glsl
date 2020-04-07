#version 330 core
in vec4 aPosition;
in vec4 aTextCoord;
out vec4 outTextCoord;

void main()
{
   gl_Position = aPosition;
   outTextCoord = aTextCoord;
};
